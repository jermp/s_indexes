Sliced Indexes
==============

A C++ implementation of [*sliced indexes*](https://arxiv.org/abs/1907.01032) [3].

This guide is meant to provide a brief overview of the library and to illustrate its functionalities through some examples.
##### Table of contents
* [Compiling the code](#compiling-the-code)
* [Quick Start](#quick-start)
* [Building a collection of sequences](#building-a-collection-of-sequences)
* [Operations](#operations)
* [Testing](#testing)
* [Tools](#tools)
* [An example microbenchark](#an-example-microbenchmark)
* [Authors](#authors)
* [References](#references)

Compiling the code
------------------

The code is tested on Linux with `gcc` 7.3.0 and on Mac 10.14 with `clang` 10.0.0.
To build the code, [`CMake`](https://cmake.org/) is required.

The code has few external dependencies (for testing, serialization and memory-mapping facilities), so clone the repository with

	$ git clone --recursive https://github.com/jermp/s_indexes.git

If you have cloned the repository without `--recursive`, you will need to perform the following commands before
compiling:

    $ git submodule init
    $ git submodule update

To compile the code for a release environment (see file `CMakeLists.txt` for the used compilation flags), it is sufficient to do the following:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

Hint: Use `make -j4` to compile the library in parallel using, e.g., 4 jobs.

For a testing environment, use the following instead:

    $ mkdir debug_build
    $ cd debug_build
    $ cmake .. -DCMAKE_BUILD_TYPE=Debug -DUSE_SANITIZERS=On
    $ make

Quick Start
-------

For a quick start, see the source file `src/example.cpp`.
After compilation, run this example with

	$ ./example < ../data/test_sequence

which will:

1. read from the standard input using a test
sequence from the directory `data`;
2. build the data structure in memory and perform some operations (decode and select).

By specifying an output file name, it is possible to
serialize the data structure on disk. To perform the
operations, the data structure is then memory mapped
from such file. To do so, type

	$ ./example -o out.bin < ../data/test_sequence

```C++
#include <iostream>

#include "../external/essentials/include/essentials.hpp"
#include "builder.hpp"
#include "s_sequence.hpp"
#include "select.hpp"
#include "decode.hpp"

using namespace sliced;

int main(int argc, char** argv) {
    int mandatory = 1;
    char const* output_filename = nullptr;

    for (int i = mandatory; i != argc; ++i) {
        if (std::string(argv[i]) == "-o") {
            ++i;
            output_filename = argv[i];
        } else if (std::string(argv[i]) == "-h") {
            std::cout << argv[0] << " -o output_filename < input" << std::endl;
            return 1;
        } else {
            std::cout << "unknown option '" << argv[i] << "'" << std::endl;
            return 1;
        }
    }

    std::vector<uint32_t> input;

    {  // read input from std::in
        uint32_t n, x;
        std::cin >> n;
        input.reserve(n);
        for (uint32_t i = 0; i != n; ++i) {
            std::cin >> x;
            input.push_back(x);
        }
    }

    // build the sequence and print statistics
    s_sequence::builder builder;
    auto stats = builder.build(input.data(), input.size());
    stats.print();

    mm::file_source<uint8_t> mm_file;
    uint8_t const* data = nullptr;

    if (output_filename) {  // if an output file is specified, then serialize
        essentials::print_size(builder);
        essentials::save<s_sequence::builder>(builder, output_filename);

        // mmap
        int advice = mm::advice::normal;  // can be also random and sequential
        mm_file.open(output_filename, advice);

        // skip first 8 bytes storing the number of written bytes
        data = mm_file.data() + 8;

    } else {  // otherwise work directly in memory
        data = builder.data();
    }

    // initialize a s_sequence from data, regardless the source
    s_sequence ss(data);

    uint32_t size = ss.size();

    // decode whole list to an output buffer
    std::vector<uint32_t> out(size);
    ss.decode(out.data());
    // check written values
    uint32_t value = 0;
    for (uint32_t i = 0; i != size; ++i) {
        if (input[i] != out[i]) {
            std::cout << "got " << out[i] << " but expected " << input[i]
                      << std::endl;
            return 1;
        }

        ss.select(i, value);  // select i-th element
        if (value != out[i]) {
            std::cout << "got " << value << " but expected " << out[i]
                      << std::endl;
            return 1;
        }
    }

    return 0;
}
```

Building a collection of sequences
----------------------------------

Typically, we want to build all the sequences from
a collection.
In this case, we assume that the input collection
is a binary file with all the sequences being written
as 32-bit integers, as popular for also other libraries
such as [`ds2i`](https://github.com/ot/ds2i).
In particular, each sequence is prefixed by an additional
32-bit integer representing the size of the sequence.
The collection file starts with a singleton sequence
containing the universe of representation of the sequences, i.e., the maximum representable value.

For example, an test input collection with 100 sequences drawn
from a universe of size 1,000,000 can be generated
with

	$ ./gen_clustered_data 100 1000000 test_collection --binary

To build an index from such collection, then use

	$ ./build test_collection --density 0.01 --out test_collection.out

with a density threshold of 0.01 and an output file
`test_collection.out` onto which the data structure is serialized.
You should get an output like:

	universe size: 1000000
	processed 100 sequences, 45911859 integers
	chunks: 1572
	full chunks: 466 (66.5183% of ints)
	empty chunks: 310 (19.7201% of chunks)
	dense chunks: 513 (30.3916% of ints)
	sparse chunks: 283 (3.09016% of ints)
	blocks: 23395
	empty blocks: 14 (0.0598418% of blocks)
	dense blocks: 7614 (2.53826% of ints)
	sparse blocks: 15767 (0.551905% of ints)
	0.00179405 [bpi] for chunks' headers
	0.00540078 [bpi] for blocks' headers
	0.732272 [bpi] for dense chunks
	0.0424549 [bpi] for dense blocks
	0.0468998 [bpi] for sparse blocks
	total bytes: 4757416
	total bpi: 0.828965

from which you can see some statistics about the built data structure.

Operations
----------

Given a single *sliced* sequence, it is possible to execute the
following operations (see also `include/s_sequence.hpp`):

```C++
/* decode the sequence to the output buffer */
size_t decode(uint32_t* out);

/* convert the sequence to an output bitmap */
size_t uncompress(uint64_t* out);

/* select the i-th value */
bool select(uint32_t i, uint32_t& value);

/* check if value is present in the sequence */
bool contains(uint32_t value);

/* returns the minimum value that is >= lower_bound
   if found, otherwise a "not found" value is returned */
uint32_t next_geq(uint32_t lower_bound);
```

Given a collection of (at least 2) *sliced* sequences, it is possible to intersect and merge two sequences
(see also `include/intersection.hpp` and `include/union.hpp`
respectively):

```C++
/* writes the result of the intersection between l and s to the output buffer,
   returning the size of the result */
size_t pairwise_intersection(s_sequence const& l, s_sequence const& r, uint32_t* out);

/* writes the result of the union between l and s to the output buffer,
   returning the size of the result */
size_t pairwise_union(s_sequence const& l, s_sequence const& r, uint32_t* out);
```

The source `src` folder contains programs to benchmark such operations.

#### Example 1.
Use:

	$ ./decode test_collection.out

to decode all the sequences in the collection. You should get something
like:

	decoded 100 sequences
	decoded 45911859 integers
	Elapsed time: 0.034721 [sec]
	Mean per sequence: 347.21 [musec]
	Mean per integer: 0.756253 [ns]

#### Example 2.
To execute some intersection operations, first generate some queries with

	$ ./gen_random_pairwise_queries 1000 100 > test_pairwise_queries

and then run

	$ ./intersect test_collection.out 1000 < test_pairwise_queries

You should get something like:

	performing 1000 pairwise-intersections...
	Mean per run: 136562 [musec]
	Mean per query: 136.562 [musec]

Testing
-------
The subfolder `test` contains testing programs to maintain
the correctness of the implementation.

To run a test, just run the corresponding program without
argument to see the required ones.

For example, to test decoding correctness, use

	$ ./test_decode test_collection.out ../data/test_collection 0.01

which will check every decoded integer against the original input
collection (note that you must provide the *correct* original input collection as well as the *density level* it was used during building).

Tools
-----
The subfolder `tools` contains some programs generating
synthetic data to test the code.

For example, the sequence `data/test_sequence` was generated with

	$ ./gen_clustered_data 1 1000000 test_sequence

A test collection can be generated with

	$ ./gen_clustered_data 100 1000000 test_collection --binary

A test query log can be generated with

	$ ./gen_random_pairwise_queries 1000 100 > test_pairwise_queries

An example microbenchmark
-----
In the following microbenchmark we show the number of bits per integer (bpi) and average microseconds per list intersection query.

We compare Slicing with Roaring [1] and Partitioned Elias-Fano [2].

We use the datasets Census-Income, Census-1881, Weather and Wikileaks shipped with the [CRoaring Library](https://github.com/RoaringBitmap/CRoaring) (see directory `benchmarks/realdata`).
See [1] for a description of such datasets.

To measure the bpi rate, we serialize the data structures and take the written number of bytes.
To measure query timings, we compute 1,000 intersections between
random pairs of lists for 10 times and report the average.

The benchmark was executed on a Linux 4.4.0 server machine with
an Intel i7-7700 CPU (@3.6 GHz) and 64 GB of RAM.
The code was compiled with gcc 7.3.0 with all optimizations
(see also `CMakeLists.txt`).

#### Table 1. Bits per integer
|**Dataset** |**Roaring** | **Slicing**  | **PEF**|
|------------|-----------:|-------------:|-------:|
|Census-Income|	2.74	   |2.23	|2.03|
|Census-1881|	  15.93      |	10.83|	7.28|
|Weather	|     5.43      |	4.05|	3.13|
|Wikileaks|	  16.30      |	10.18|	8.87|

#### Table 2. µsec per list intersection
|**Dataset**  |**Roaring** | **Slicing**  | **PEF**|
|-------------|-----------:|-------------:|-------:|
|Census-Income|	4.68	|11.56|	115.17|
|Census-1881  |	0.15	|0.18	|0.92|
|Weather	    |  13.37	|25.70	|213.00|
|Wikileaks    |	0.86	|0.47	|2.51|

Authors
-------
* [Giulio Ermanno Pibiri](http://pages.di.unipi.it/pibiri/), <giulio.ermanno.pibiri@isti.cnr.it>

References
-------

* [1] Daniel Lemire, Owen Kaser, Nathan Kurz, Luca Deri, Chris O’Hara, François Saint-Jacques, and Gregory Ssi-Yan-Kai. 2018. *Roaring bitmaps: Implementation of an optimized software library*. Software: Practice and Experience 48, 4,
867–895.
* [2] Giuseppe Ottaviano and Rossano Venturini. *Partitioned Elias-Fano Indexes*. 2014. In Proceedings of the 37th International
Conference on Research and Development in Information Retrieval. 273–282.
* [3] Giulio Ermanno Pibiri. *On Slicing Sorted Integer Sequences*. 2019. arXiv preprint. https://arxiv.org/abs/1907.01032