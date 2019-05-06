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

		➜  build git:(master) ✗ ./decode gov2.no_full_blocks.bin2                                                                                                                         
		decoded 13276 sequences                                                                                                                                                           
		decoded 5066748826 integers                                                                                                                                                       
		Elapsed time: 2.87556 [sec]
		Mean per sequence: 216.598 [musec]
		Mean per integer: 0.567535 [ns]
		Roaring: 0.529489 [ns]
		
		➜  build git:(master) ✗ ./decode clueweb09.no_full_blocks.bin2
		decoded 21924 sequences
		decoded 13864451283 integers
		Elapsed time: 9.13543 [sec]
		Mean per sequence: 416.686 [musec]
		Mean per integer: 0.65891 [ns]
		Roaring: 0.700808 [ns]
		
		➜  build git:(master) ✗ ./decode ccnews.no_full_blocks.bin2
		decoded 23085 sequences
		decoded 18969946075 integers
		Elapsed time: 12.1735 [sec]
		Mean per sequence: 527.336 [musec]
		Mean per integer: 0.641728 [ns]
		Roaring: 0.685912 [ns]
		
- Uncompressing

		➜  build git:(master) ✗ ./uncompress gov2.no_full_blocks.bin2                                                                                                                     
		decoded 13276 sequences                                                                                                                                                           
		decoded 5066748826 integers                                                                                                                                                       
		Elapsed time: 1.79108 [sec]
		Mean per sequence: 134.911 [musec]
		Mean per integer: 0.353496 [ns]
		
		➜  build git:(master) ✗ ./uncompress clueweb09.no_full_blocks.bin2                                                                                                                
		decoded 21924 sequences                                                                                                                                                           
		decoded 13864451283 integers                                                                                                                                                      
		Elapsed time: 9.87102 [sec]
		Mean per sequence: 450.238 [musec]
		Mean per integer: 0.711966 [ns]


		➜  build git:(master) ✗ ./uncompress ccnews.no_full_blocks.bin2
		decoded 23085 sequences
		decoded 18969946075 integers
		Elapsed time: 14.3469 [sec]
		Mean per sequence: 621.48 [musec]
		Mean per integer: 0.756295 [ns]

- Intersection

		➜  build git:(master) ✗ ./intersect gov2.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/gov2/random.queries.u13276.1K                                     
		reading queries...                                                                                                                                                                
		DONE
		performing 1000 pairwise-intersections...                                                                                                                                         
		163312853
		Mean per run: 130174 [musec]
		Mean per query: 130.174 [musec]
		Roaring: 98 [musec]
		
		➜  build git:(master) ✗ ./intersect clueweb09.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/clueweb09/random.queries.u21924.1K
		reading queries...
		DONE
		performing 1000 pairwise-intersections...                                                                                                                                         
		122236213
		Mean per run: 360178 [musec]
		Mean per query: 360.178 [musec]
		Roaring: 231 [musec]
	   
		➜  build git:(master) ✗ ./intersect ccnews.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/ccnews/random.queries.u23085.1K                                 
		reading queries...                                                                                                                                                                
		DONE                                                                                                                                                                            
		performing 1000 pairwise-intersections...
		415462927
		Mean per run: 792785 [musec]
		Mean per query: 792.785 [musec]
		Roaring: 350 [musec]
		         
- Union

		➜  build git:(master) ✗ ./union gov2.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/gov2/random.queries.u13276.1K
		reading queries...
		DONE
		performing 1000 pairwise-unions...
		8211899850
		Mean per run: 581382 [musec]                                                                                                                                                      
		Mean per query: 581.382 [musec] 
		Roaring: 677.746000 [musecs]
		
		➜  build git:(master) ✗ ./union clueweb09.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/clueweb09/random.queries.u21924.1K
		reading queries...
		DONE
		performing 1000 pairwise-unions...
		14380225728
		Mean per run: 1.29741e+06 [musec]
		Mean per query: 1297.41 [musec]
		Roaring: 1635.801100 [musecs]
		
		➜  build git:(master) ✗ ./union ccnews.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/ccnews/random.queries.u23085.1K
		reading queries...
		DONE
		performing 1000 pairwise-unions...
		20505167914
		Mean per run: 2.25071e+06 [musec]
		Mean per query: 2250.71 [musec]
		Roaring: 2153.428200 [musecs]
		
- Select

		➜  build git:(master) ✗ ./select gov2.no_full_blocks.bin3 13276000 < gov2.select_queries2                     
		reading queries...
		DONE
		performing 13276000 select queries...
		636846348152652
		Mean per run: 2.36133e+06 [musec]
		Mean per query: 0.177865 [musec]
		Roaring: 0.287290 [musecs]
		
		➜  build git:(master) ✗ ./select clueweb09.no_full_blocks.bin3 21924000 < clueweb09.select_queries
		reading queries...
		DONE
		performing 21924000 select queries...
		1951476283887376
		Mean per run: 7.28288e+06 [musec]
		Mean per query: 0.332188 [musec]
		Roaring: 0.456158 [musecs]
		
		➜  build git:(master) ✗ ./select ccnews.no_full_blocks.bin3 23085000 < ccnews.select_queries
		reading queries...
		DONE
		performing 23085000 select queries...
		1944166548915776
		Mean per run: 8.17139e+06 [musec]
		Mean per query: 0.353969 [musec]
		Roaring: 0.438018 [musecs]		
		
- Contains

		➜  build git:(master) ✗ ./contains gov2.no_full_blocks.bin3 13276000 < gov2.contains_queries                                                                             [12/1953]
		reading queries...                                                                                                                                                                
		DONE                                                                                                                                                                              
		performing 13276000 contains queries...                                                                                                                                           
		53104000                                                                                                                                                                          
		Mean per run: 1.77412e+06 [musec]                                                                                                                                                 
		Mean per query: 0.133634 [musec] 
		
		➜  build git:(master) ✗ ./contains clueweb09.no_full_blocks.bin3 21924000 < clueweb09.contains_queries
		reading queries...
		DONE
		performing 21924000 contains queries...
		87696000
		Mean per run: 5.49955e+06 [musec]
		Mean per query: 0.250846 [musec]
		
		➜  build git:(master) ✗ ./contains ccnews.no_full_blocks.bin3 23085000 < ccnews.contains_queries
		reading queries...
		DONE
		performing 23085000 contains queries...
		92340000
		Mean per run: 6.42931e+06 [musec]
		Mean per query: 0.278506 [musec]