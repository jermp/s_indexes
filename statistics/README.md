LOGs
====

The building logs of the test collections I have used
in the [DCC21 paper](http://pages.di.unipi.it/pibiri/papers/DCC21.pdf) and in the [CSUR20 paper](http://pages.di.unipi.it/pibiri/papers/CSUR20.pdf).

(**Note**:
As of 29/11/2021, the data is hosted on the machine
`rubino.isti.cnr.it`.)

### GOV2

	./build /data/pibiri/inverted_indexes/gov2/gov2.docs --size 4096
	
	processed 39177 sequences, 5322883266 integers
	chunks: 14584293
	full chunks: 16850 (20.7459% of ints)
	empty chunks: 6050670 (41.4876% of chunks)
	dense chunks: 23094 (16.5787% of ints)
	sparse chunks: 8493679 (62.6754% of ints)
	blocks: 1730604715
	empty blocks: 1448054662 (83.6733% of blocks)
	dense blocks: 24883799 (39.2579% of ints)
	sparse blocks: 257666254 (23.4175% of ints)
	0.10571 [bpi] for chunks' headers
	0.462056 [bpi] for blocks' headers
	0.284336 [bpi] for dense chunks
	1.19677 [bpi] for dense blocks
	2.26066 [bpi] for sparse blocks
	total bytes: 2867702750
	total bpi: 4.31
	== sparse blocks cardinalities (%) ==
	sparse blocks with card. 1: 37.0784
	sparse blocks with card. 2: 16.8982
	sparse blocks with card. 3: 9.31683
	sparse blocks with card. 4: 6.35772
	sparse blocks with card. 5: 4.45869
	sparse blocks with card. 6: 3.52247
	sparse blocks with card. 7: 2.75907
	sparse blocks with card. 8: 2.32714
	sparse blocks with card. 9: 1.93117
	sparse blocks with card. 10: 1.68538
	sparse blocks with card. 11: 1.45538
	sparse blocks with card. 12: 1.30263
	sparse blocks with card. 13: 1.15714
	sparse blocks with card. 14: 1.0597
	sparse blocks with card. 15: 0.923251
	sparse blocks with card. 16: 0.845651
	sparse blocks with card. 17: 0.762453
	sparse blocks with card. 18: 0.707495
	sparse blocks with card. 19: 0.645523
	sparse blocks with card. 20: 0.602053
	sparse blocks with card. 21: 0.554561
	sparse blocks with card. 22: 0.520409
	sparse blocks with card. 23: 0.479391
	sparse blocks with card. 24: 0.456116
	sparse blocks with card. 25: 0.419653
	sparse blocks with card. 26: 0.39885
	sparse blocks with card. 27: 0.372647
	sparse blocks with card. 28: 0.355733
	sparse blocks with card. 29: 0.331016
	sparse blocks with card. 30: 0.315309
	expected_value 4.8376

### CLUEWEB09

	./build /data/pibiri/inverted_indexes/clueweb09/clueweb09.docs --size 4096
	processed 96722 sequences, 14858833259 integers
	chunks: 73708490
	full chunks: 712 (0.314033% of ints)
	empty chunks: 9567963 (12.9808% of chunks)
	dense chunks: 84429 (18.1015% of ints)
	sparse chunks: 64055386 (81.5844% of ints)
	blocks: 13193655562
	empty blocks: 11602569856 (87.9405% of blocks)
	dense blocks: 81969097 (40.6435% of ints)
	sparse blocks: 1509116609 (40.9409% of ints)
	0.284753 [bpi] for chunks' headers
	0.900773 [bpi] for blocks' headers
	0.37238 [bpi] for dense chunks
	1.41223 [bpi] for dense blocks
	4.08778 [bpi] for sparse blocks
	total bytes: 13109831357
	total bpi: 7.05834
	== sparse blocks cardinalities ==
	sparse blocks with card. 1: 44.7271
	sparse blocks with card. 2: 16.6118
	sparse blocks with card. 3: 8.78565
	sparse blocks with card. 4: 5.62635
	sparse blocks with card. 5: 3.95064
	sparse blocks with card. 6: 2.97293
	sparse blocks with card. 7: 2.33253
	sparse blocks with card. 8: 1.89428
	sparse blocks with card. 9: 1.57672
	sparse blocks with card. 10: 1.33721
	sparse blocks with card. 11: 1.15285
	sparse blocks with card. 12: 1.007
	sparse blocks with card. 13: 0.886867
	sparse blocks with card. 14: 0.789197
	sparse blocks with card. 15: 0.706788
	sparse blocks with card. 16: 0.63642
	sparse blocks with card. 17: 0.576949
	sparse blocks with card. 18: 0.525569
	sparse blocks with card. 19: 0.480632
	sparse blocks with card. 20: 0.441609
	sparse blocks with card. 21: 0.405493
	sparse blocks with card. 22: 0.374707
	sparse blocks with card. 23: 0.34701
	sparse blocks with card. 24: 0.322115
	sparse blocks with card. 25: 0.299859
	sparse blocks with card. 26: 0.279846
	sparse blocks with card. 27: 0.261542
	sparse blocks with card. 28: 0.244726
	sparse blocks with card. 29: 0.229736
	sparse blocks with card. 30: 0.21593
	expected_value 4.03106

### CCNEWS

	./build /data/pibiri/inverted_indexes/ccnews/ccnews.docs --size 4096
	processed 76474 sequences, 19691599096 integers
	chunks: 50843195
	full chunks: 0 (0% of ints)
	empty chunks: 705012 (1.38664% of chunks)
	dense chunks: 305016 (35.0479% of ints)
	sparse chunks: 49833167 (64.9521% of ints)
	blocks: 11663479982
	empty blocks: 9166422811 (78.5908% of blocks)
	dense blocks: 69783424 (19.2146% of ints)
	sparse blocks: 2427273747 (45.7375% of ints)
	0.167937 [bpi] for chunks' headers
	1.04282 [bpi] for blocks' headers
	1.01513 [bpi] for dense chunks
	0.907217 [bpi] for dense blocks
	4.64511 [bpi] for sparse blocks
	total bytes: 19146292668
	total bpi: 7.77846
	== sparse blocks cardinalities ==
	sparse blocks with card. 1: 48.664
	sparse blocks with card. 2: 16.0906
	sparse blocks with card. 3: 8.2801
	sparse blocks with card. 4: 5.20906
	sparse blocks with card. 5: 3.64636
	sparse blocks with card. 6: 2.72647
	sparse blocks with card. 7: 2.1312
	sparse blocks with card. 8: 1.72098
	sparse blocks with card. 9: 1.42338
	sparse blocks with card. 10: 1.2096
	sparse blocks with card. 11: 1.02886
	sparse blocks with card. 12: 0.892043
	sparse blocks with card. 13: 0.782081
	sparse blocks with card. 14: 0.692526
	sparse blocks with card. 15: 0.61889
	sparse blocks with card. 16: 0.555878
	sparse blocks with card. 17: 0.502896
	sparse blocks with card. 18: 0.456959
	sparse blocks with card. 19: 0.417581
	sparse blocks with card. 20: 0.384045
	sparse blocks with card. 21: 0.352351
	sparse blocks with card. 22: 0.325372
	sparse blocks with card. 23: 0.300598
	sparse blocks with card. 24: 0.278709
	sparse blocks with card. 25: 0.2598
	sparse blocks with card. 26: 0.241133
	sparse blocks with card. 27: 0.224351
	sparse blocks with card. 28: 0.208523
	sparse blocks with card. 29: 0.194349
	sparse blocks with card. 30: 0.181276
	expected_value 3.71052
