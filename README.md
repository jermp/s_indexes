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
		Elapsed time: 2.90988 [sec]                                                                                                                                                       
		Mean per sequence: 219.183 [musec]                                                                                                                                                
		Mean per integer: 0.574309 [ns] 

		➜  build git:(master) ✗ ./decode clueweb09.no_full_blocks.bin2
		decoded 21924 sequences
		decoded 13864451283 integers
		Elapsed time: 9.3739 [sec]
		Mean per sequence: 427.563 [musec]
		Mean per integer: 0.67611 [ns]
		
		➜  build git:(master) ✗ ./decode ccnews.no_full_blocks.bin2
		decoded 23085 sequences
		decoded 18969946075 integers
		Elapsed time: 12.5827 [sec]
		Mean per sequence: 545.06 [musec]
		Mean per integer: 0.663297 [ns]
		
- Uncompressing

		➜  build git:(master) ✗ ./uncompress gov2.no_full_blocks.bin2                                                                                                                     
		decoded 13276 sequences                                                                                                                                                           
		decoded 5066748826 integers                                                                                                                                                       
		Elapsed time: 2.09263 [sec]                                                                                                                                                       
		Mean per sequence: 157.625 [musec]                                                                                                                                                
		Mean per integer: 0.413012 [ns] 
		
		➜  build git:(master) ✗ ./uncompress clueweb09.no_full_blocks.bin2                                                                                                                
		decoded 21924 sequences                                                                                                                                                           
		decoded 13864451283 integers                                                                                                                                                      
		Elapsed time: 11.4784 [sec]                                                                                                                                                       
		Mean per sequence: 523.553 [musec]                                                                                                                                                
		Mean per integer: 0.8279 [ns]


		➜  build git:(master) ✗ ./uncompress ccnews.no_full_blocks.bin2
		decoded 23085 sequences
		decoded 18969946075 integers
		Elapsed time: 19.1121 [sec]
		Mean per sequence: 827.901 [musec]
		Mean per integer: 1.00749 [ns]

- Intersection

		➜  build git:(master) ✗ ./intersect gov2.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/gov2/random.queries.u13276.1K                                     
		reading queries...                                                                                                                                                                
		DONE
		performing 1000 pairwise-intersections...
		163312853
		Mean per run: 209903 [musec]
		Mean per query: 209.903 [musec]
		
		➜  build git:(master) ✗ ./intersect clueweb09.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/clueweb09/random.queries.u21924.1K
		reading queries...
		DONE
		performing 1000 pairwise-intersections...
		122236213
		Mean per run: 548128 [musec]
		Mean per query: 548.128 [musec]

		➜  build git:(master) ✗ ./intersect ccnews.no_full_blocks.bin2 1000 < ~/CRoaring/benchmarks/realdata/ds2i/queries/ccnews/random.queries.u23085.1K                                 
		reading queries...                                                                                                                                                                
		DONE                                                                                                                                                                              
		performing 1000 pairwise-intersections...                                                                                                                                         
		415462927                                                                                                                                                                         
		Mean per run: 1.33303e+06 [musec]                                                                                                                                                 
		Mean per query: 1333.03 [musec] 

- Perf counts

		 Performance counter stats for './intersect gov2.no_full_blocks.bin2 1000':

	       2418.997283      task-clock (msec)         #    1.000 CPUs utilized          
	                 6      context-switches          #    0.002 K/sec                  
	                 0      cpu-migrations            #    0.000 K/sec                  
	            57,384      page-faults               #    0.024 M/sec                  
	    10,451,372,048      cycles                    #    4.321 GHz                    
	    10,152,808,190      instructions              #    0.97  insn per cycle         
	     2,391,319,695      branches                  #  988.558 M/sec                  
	       354,306,037      branch-misses             #   14.82% of all branches        
	
	       2.419265647 seconds time elapsed


		       
		 Performance counter stats for './benchmarks/pair_wise_intersect gov2.roaring.0.001.bin 1000':
	
	       1168.235343      task-clock (msec)         #    1.000 CPUs utilized          
	                 0      context-switches          #    0.000 K/sec                  
	                 0      cpu-migrations            #    0.000 K/sec                  
	            38,624      page-faults               #    0.033 M/sec                  
	     5,088,787,837      cycles                    #    4.356 GHz                    
	     8,392,528,078      instructions              #    1.65  insn per cycle         
	     1,214,822,936      branches                  # 1039.879 M/sec                  
	        58,543,845      branch-misses             #    4.82% of all branches        
	
	       1.168439193 seconds time elapsed