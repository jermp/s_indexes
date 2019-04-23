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
		Elapsed time: 6.48553 [sec]
		Mean per sequence: 488.516 [musec]
		Mean per integer: 1.28002 [ns]

		➜  build git:(master) ✗ ./decode clueweb09.bin 
		'N6sliced7s_indexE' - bytes = 10598030953 (100%)
		    'St6vectorImSaImEE' - bytes = 175400 (0.00165502%)
		    'St6vectorIhSaIhEE' - bytes = 10597855553 (99.9983%)
		decoded 21924 sequences
		decoded 13864451283 integers
		Elapsed time: 28.0271 [sec]
		Mean per sequence: 1278.37 [musec]
		Mean per integer: 2.02151 [ns]
		
- Uncompressing

		➜  build git:(master) ✗ ./uncompress gov2.bin
		'N6sliced7s_indexE' - bytes = 2384950631 (100%)
		    'St6vectorImSaImEE' - bytes = 106216 (0.00445359%)
		    'St6vectorIhSaIhEE' - bytes = 2384844415 (99.9955%)
		decoded 13276 sequences
		decoded 5066748826 integers
		Elapsed time: 2.65825 [sec]
		Mean per sequence: 200.23 [musec]
		Mean per integer: 0.524646 [ns]
		
		➜  build git:(master) ✗ ./uncompress clueweb09.bin 
		'N6sliced7s_indexE' - bytes = 10598030953 (100%)
		    'St6vectorImSaImEE' - bytes = 175400 (0.00165502%)
		    'St6vectorIhSaIhEE' - bytes = 10597855553 (99.9983%)
		decoded 21924 sequences
		decoded 13864451283 integers
		Elapsed time: 15.0284 [sec]
		Mean per sequence: 685.477 [musec]
		Mean per integer: 1.08395 [ns]