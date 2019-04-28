Sliced Indexes
--------------

- Building
	
		➜  build git:(master) ./build /data2/inverted_indexes/gov2/gov2.sorted-text.bin.docs 0.001 -o gov2.bin                                                                            
		universe size: 24622347                                                                                                                                                           
		processed 1000 sequences
		processed 2000 sequences
		processed 3000 sequences
		processed 4000 sequences
		processed 5000 sequences
		processed 6000 sequences
		processed 7000 sequences
		processed 8000 sequences
		processed 9000 sequences
		processed 10000 sequences
		processed 11000 sequences
		processed 12000 sequences
		processed 13000 sequences
		processed 13276 sequences, 5066748826 integers
		chunks: 4611821
		full chunks: 16850 (21.7947% of ints)
		empty chunks: 1557705 (33.7764% of chunks)
		dense chunks: 19434 (15.9206% of ints)
		sparse chunks: 3017832 (62.2847% of ints)
		blocks: 772564992
		full blocks: 1326334 (6.70137% of ints)
		empty blocks: 560911707 (72.6038% of blocks)
		dense blocks: 23468998 (34.3412% of ints)
		sparse blocks: 186857953 (21.2421% of ints)
		0.0289752 [bpi] for chunks' headers
		0.304955 [bpi] for blocks' headers
		0.25137 [bpi] for dense chunks
		1.18578 [bpi] for dense blocks
		1.9944 [bpi] for sparse blocks
		total bpi: 3.76548
		'N6sliced7s_indexE' - bytes = 2384950631 (100%)
		    'St6vectorImSaImEE' - bytes = 106216 (0.00445359%)
		    'St6vectorIhSaIhEE' - bytes = 2384844415 (99.9955%)

		➜  build git:(master) ./build /data2/inverted_indexes/clueweb09/clueweb.sorted-text.bin.docs 0.001 -o clueweb09.bin 
		universe size: 50131015
		processed 1000 sequences
		processed 2000 sequences
		processed 3000 sequences
		processed 4000 sequences
		processed 5000 sequences
		processed 6000 sequences
		processed 7000 sequences
		processed 8000 sequences
		processed 9000 sequences
		processed 10000 sequences
		processed 11000 sequences
		processed 12000 sequences
		processed 13000 sequences
		processed 14000 sequences
		processed 15000 sequences
		processed 16000 sequences
		processed 17000 sequences
		processed 18000 sequences
		processed 19000 sequences
		processed 20000 sequences
		processed 21000 sequences
		processed 21924 sequences, 13864451283 integers
		chunks: 14220978
		full chunks: 712 (0.336556% of ints)
		empty chunks: 118978 (0.836637% of chunks)
		dense chunks: 43925 (13.4839% of ints)
		sparse chunks: 14057363 (86.1795% of ints)
		blocks: 3598684928
		full blocks: 1752750 (3.23636% of ints)
		empty blocks: 2389304696 (66.3938% of blocks)
		dense blocks: 86751160 (44.3064% of ints)
		sparse blocks: 1120876322 (38.6368% of ints)
		0.0488477 [bpi] for chunks' headers
		0.519124 [bpi] for blocks' headers
		0.207629 [bpi] for dense chunks
		1.60182 [bpi] for dense blocks
		3.73771 [bpi] for sparse blocks
		total bpi: 6.11512
		'N6sliced7s_indexE' - bytes = 10598030953 (100%)
		    'St6vectorImSaImEE' - bytes = 175400 (0.00165502%)
		    'St6vectorIhSaIhEE' - bytes = 10597855553 (99.9983%)
    
- Decoding

		➜  build git:(master) ✗ ./decode gov2.bin
		'N6sliced7s_indexE' - bytes = 2384950631 (100%)
		    'St6vectorImSaImEE' - bytes = 106216 (0.00445359%)
		    'St6vectorIhSaIhEE' - bytes = 2384844415 (99.9955%)
		decoded 13276 sequences
		decoded 5066748826 integers
		Elapsed time: 3.59512 [sec]
		Mean per sequence: 270.799 [musec]
		Mean per integer: 0.709552 [ns]

		➜  build git:(master) ✗ ./decode clueweb09.bin 
		'N6sliced7s_indexE' - bytes = 10598030953 (100%)
		    'St6vectorImSaImEE' - bytes = 175400 (0.00165502%)
		    'St6vectorIhSaIhEE' - bytes = 10597855553 (99.9983%)
		decoded 21924 sequences
		decoded 13864451283 integers
		Elapsed time: 14.7659 [sec]
		Mean per sequence: 673.503 [musec]
		Mean per integer: 1.06502 [ns]
		
- Uncompressing

		➜  build git:(master) ✗ ./uncompress gov2.bin
		'N6sliced7s_indexE' - bytes = 2384950631 (100%)
		    'St6vectorImSaImEE' - bytes = 106216 (0.00445359%)
		    'St6vectorIhSaIhEE' - bytes = 2384844415 (99.9955%)
		decoded 13276 sequences
		decoded 5066748826 integers
		Elapsed time: 2.98373 [sec]
		Mean per sequence: 224.746 [musec]
		Mean per integer: 0.588885 [ns]
		
		➜  build git:(master) ✗ ./uncompress clueweb09.bin 
		'N6sliced7s_indexE' - bytes = 10598030953 (100%)
		    'St6vectorImSaImEE' - bytes = 175400 (0.00165502%)
		    'St6vectorIhSaIhEE' - bytes = 10597855553 (99.9983%)
		decoded 21924 sequences
		decoded 13864451283 integers
		Elapsed time: 16.7491 [sec]
		Mean per sequence: 763.962 [musec]
		Mean per integer: 1.20806 [ns]
		
- Intersection

		➜  build git:(master) ✗ ./intersect gov2.bin 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/gov2/random.queries.u13276.1K          
		reading queries...
		DONE
		'N6sliced7s_indexE' - bytes = 2384950631 (100%)
		    'St6vectorImSaImEE' - bytes = 106216 (0.00445359%)
		    'St6vectorIhSaIhEE' - bytes = 2384844415 (99.9955%)
		performing 1000 pairwise-intersections...
		148466230
		Mean per run: 303990 [musec]
		Mean per query: 303.99 [musec]
		
		➜  build git:(master) ✗ ./intersect clueweb09.bin 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/clueweb09/random.queries.u21924.1K
		reading queries...
		DONE
		'N6sliced7s_indexE' - bytes = 10598030953 (100%)
		    'St6vectorImSaImEE' - bytes = 175400 (0.00165502%)
		    'St6vectorIhSaIhEE' - bytes = 10597855553 (99.9983%)
		performing 1000 pairwise-intersections...
		111123830
		Mean per run: 855742 [musec]
		Mean per query: 855.741 [musec]

		➜  build git:(master) ✗ ./intersect ccnews.no_full_blocks.bin 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/ccnews/random.queries.u23085.1K
		reading queries...
		DONE
		performing 1000 pairwise-intersections...
		377693570
		Mean per run: 1.61105e+06 [musec]
		Mean per query: 1611.05 [musec]

- Perf counts

		 Performance counter stats for './intersect gov2.bin 1000':
		
		         4,374,008      cache-misses                                                
		    13,461,398,604      instructions              #    0.98  insn per cycle         
		    13,680,127,694      cycles                                                      
		       487,012,368      branch-misses  
		       
		 Performance counter stats for './benchmarks/pair_wise_intersect gov2.roaring.0.001.bin 1000':
		
		        12,302,166      cache-misses                                                
		     7,631,824,065      instructions              #    1.54  insn per cycle         
		     4,941,581,066      cycles                                                      
		        53,220,853      branch-misses  