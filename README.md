Sliced Indexes
--------------

- Building
	
		GOV2
		processed 13276 sequences, 5066748826 integers
		chunks: 4611821
		full chunks: 16850 (21.7947% of ints)
		empty chunks: 1557705 (33.7764% of chunks)
		dense chunks: 19686 (16.0473% of ints)
		sparse chunks: 3017580 (62.158% of ints)
		blocks: 772500480
		empty blocks: 560911704 (72.6099% of blocks)
		dense blocks: 24731408 (40.9162% of ints)
		sparse blocks: 186857368 (21.2418% of ints)
		0.0289752 [bpi] for chunks' headers
		0.304929 [bpi] for blocks' headers
		0.254629 [bpi] for dense chunks
		1.24957 [bpi] for dense blocks
		1.99438 [bpi] for sparse blocks
		total bpi: 3.83248

		CLUEWEB09
		processed 21924 sequences, 13864451283 integers                                                                                                
		chunks: 14220978
		full chunks: 712 (0.336556% of ints)
		empty chunks: 118978 (0.836637% of chunks)
		dense chunks: 45352 (13.7609% of ints)
		sparse chunks: 14055936 (85.9026% of ints)
		blocks: 3598319616
		empty blocks: 2389304628 (66.4006% of blocks)
		dense blocks: 88144466 (47.2667% of ints)
		sparse blocks: 1120870522 (38.6359% of ints)
		0.0488477 [bpi] for chunks' headers
		0.519071 [bpi] for blocks' headers
		0.214375 [bpi] for dense chunks
		1.62754 [bpi] for dense blocks
		3.73763 [bpi] for sparse blocks
		total bpi: 6.14746
    
    	CCNEWS
		processed 23085 sequences, 18969946075 integers
		chunks: 15010868
		empty chunks: 4580 (0.0305112% of chunks)
		dense chunks: 146406 (22.6026% of ints)
		sparse chunks: 14859882 (77.3974% of ints)
		very sparse chunks: 0 (0% of ints)
		blocks: 3804129792
		empty blocks: 1820584913 (47.8581% of blocks)
		dense blocks: 106213467 (33.2166% of ints)
		sparse blocks: 1877331412 (44.1808% of ints)
		0.0379902 [bpi] for chunks' headers
		0.401069 [bpi] for blocks' headers
		0.505793 [bpi] for dense chunks
		1.43335 [bpi] for dense blocks
		4.32617 [bpi] for sparse blocks
		total bpi: 6.70438
		
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