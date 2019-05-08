Sliced Indexes
--------------

Below experimental results for Gov2, Clueweb09 and CCNews.

All lists whose density is > 0.001 were considered.

- Building

		GOV2 (d = 0.0001)
		processed 85893 sequences, 5390038277 integers
		chunks: 21519120
		full chunks: 16850 (20.4875% of ints)
		empty chunks: 10521930 (48.8957% of chunks)
		dense chunks: 23094 (16.3721% of ints)
		sparse chunks: 10957246 (63.1404% of ints)
		blocks: 2162460812
		empty blocks: 1853185897 (85.698% of blocks)
		dense blocks: 25055202 (39.0037% of ints)
		sparse blocks: 284219713 (24.1367% of ints)
		0.134573 [bpi] for chunks' headers
		0.496219 [bpi] for blocks' headers
		0.280794 [bpi] for dense chunks
		1.19 [bpi] for dense blocks
		2.35278 [bpi] for sparse blocks
		total bytes: 3001837604
		total bpi: 4.45539

		GOV2 (d = 0.001)
		processed 13276 sequences, 5066748826 integers
		chunks: 4611821
		full chunks: 16850 (21.7947% of ints)
		empty chunks: 1557705 (33.7764% of chunks)
		dense chunks: 23081 (17.4136% of ints)
		sparse chunks: 3014185 (60.7917% of ints)
		blocks: 667844436
		empty blocks: 457120838 (68.4472% of blocks)
		dense blocks: 23943484 (39.5826% of ints)
		sparse blocks: 186780114 (21.2091% of ints)
		0.0397521 [bpi] for chunks' headers
		0.370521 [bpi] for blocks' headers
		0.298542 [bpi] for dense chunks
		1.20976 [bpi] for dense blocks
		1.99164 [bpi] for sparse blocks
		total bytes: 2476613040
		total bpi: 3.91038

		GOV2 (d = 0.01)
		processed 3513 sequences, 4347653438 integers
		chunks: 1311927
		full chunks: 16713 (25.193% of ints)
		empty chunks: 362208 (27.6089% of chunks)
		dense chunks: 21009 (18.8613% of ints)
		sparse chunks: 911997 (55.9457% of ints)
		blocks: 211234855
		empty blocks: 102848622 (48.6892% of blocks)
		dense blocks: 20893566 (40.0391% of ints)
		sparse blocks: 87492667 (15.9067% of ints)
		0.0144035 [bpi] for chunks' headers
		0.237884 [bpi] for blocks' headers
		0.316687 [bpi] for dense chunks
		1.23026 [bpi] for dense blocks
		1.43353 [bpi] for sparse blocks
		total bytes: 1756894432
		total bpi: 3.23281


		CLUEWEB09    
		processed 21924 sequences, 13864451283 integers
		chunks: 14220978
		full chunks: 712 (0.336556% of ints)
		empty chunks: 118978 (0.836637% of chunks)
		dense chunks: 84428 (19.3996% of ints)
		sparse chunks: 14016860 (80.2639% of ints)
		blocks: 3464202407
		empty blocks: 2265160718 (65.3877% of blocks)
		dense blocks: 79113925 (41.7708% of ints)
		sparse blocks: 1119927764 (38.4931% of ints)
		0.0670807 [bpi] for chunks' headers
		0.737515 [bpi] for blocks' headers
		0.399083 [bpi] for dense chunks
		1.4608 [bpi] for dense blocks
		3.72566 [bpi] for sparse blocks
		total bytes: 11074648021
		total bpi: 6.39024

    	CCNEWS
		processed 23085 sequences, 18969946075 integers
		chunks: 15010868
		full chunks: 0 (0% of ints)
		empty chunks: 4580 (0.0305112% of chunks)
		dense chunks: 305016 (36.3812% of ints)
		sparse chunks: 14701272 (63.6188% of ints)
		blocks: 3717284783
		empty blocks: 1774286703 (47.7307% of blocks)
		dense blocks: 69579620 (19.8884% of ints)
		sparse blocks: 1873418460 (43.7303% of ints)
		0.05217 [bpi] for chunks' headers
		0.848744 [bpi] for blocks' headers
		1.05375 [bpi] for dense chunks
		0.938979 [bpi] for dense blocks
		4.28848 [bpi] for sparse blocks
		total bytes: 17030745141
		total bpi: 7.1822
		
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
		Mean per run: 2.2946e+06 [musec]
		Mean per query: 0.172838 [musec]
		Roaring: 0.287290 [musecs]
		
		➜  build git:(master) ✗ ./select clueweb09.no_full_blocks.bin3 21924000 < clueweb09.select_queries
		reading queries...
		DONE
		performing 21924000 select queries...
		1951476283887376
		Mean per run: 7.19159e+06 [musec]
		Mean per query: 0.328023 [musec]
		Roaring: 0.456158 [musecs]
		
		➜  build git:(master) ✗ ./select ccnews.no_full_blocks.bin3 23085000 < ccnews.select_queries
		reading queries...
		DONE
		performing 23085000 select queries...
		1944166548915776
		Mean per run: 8.15949e+06 [musec]
		Mean per query: 0.353454 [musec]
		Roaring: 0.438018 [musecs]		
		
- Contains

		➜  build git:(master) ✗ ./contains gov2.no_full_blocks.bin3 13276000 < gov2.contains_queries                                                                             [12/1953]
		reading queries...                                                                                                                                                                
		DONE                                                                                                                                                                              
		performing 13276000 contains queries...                                                                                                                                           
		53104000                                                                                                                                                                          
		Mean per run: 1.23467e+06 [musec]
		Mean per query: 0.0930005 [musec]
		Roaring: 0.067059 [musecs]
		
		➜  build git:(master) ✗ ./contains clueweb09.no_full_blocks.bin3 21924000 < clueweb09.contains_queries
		reading queries...
		DONE
		performing 21924000 contains queries...
		87696000
		Mean per run: 2.5195e+06 [musec]
		Mean per query: 0.11492 [musec]
		Roaring: 0.104661 [musecs]
		
		➜  build git:(master) ✗ ./contains ccnews.no_full_blocks.bin3 23085000 < ccnews.contains_queries
		reading queries...
		DONE
		performing 23085000 contains queries...
		92340000
		Mean per run: 3.51994e+06 [musec]
		Mean per query: 0.152477 [musec]
		Roaring: 0.121576 [musecs]
		
- Nextgeq

		➜  build git:(master) ✗ ./next_geq gov2.no_full_blocks.bin3 13276000 < gov2.contains_queries
		reading queries...
		DONE
		performing 13276000 next_geq queries...
		636846348152652
		Mean per run: 1.18542e+06 [musec]
		Mean per query: 0.0892906 [musec]
		Roaring: 0.089513 [musecs]
		
		➜  build git:(master) ✗ ./next_geq clueweb09.no_full_blocks.bin3 21924000 < clueweb09.contains_queries
		reading queries...
		DONE
		performing 21924000 next_geq queries...
		1951476283887376
		Mean per run: 2.40277e+06 [musec]
		Mean per query: 0.109595 [musec]
		Roaring: 0.118386 [musecs]

		➜  build git:(master) ✗ ./next_geq ccnews.no_full_blocks.bin3 23085000 < ccnews.contains_queries 
		reading queries...
		DONE
		performing 23085000 next_geq queries...
		1944166548915776
		Mean per run: 3.08929e+06 [musec]
		Mean per query: 0.133822 [musec]
		Roaring: 0.135233 [musecs]
