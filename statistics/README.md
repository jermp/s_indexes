LOGs
====

The building logs of the test collections I have used
in the [DCC21 paper](http://pages.di.unipi.it/pibiri/papers/DCC21.pdf) and in the [CSUR20 paper](http://pages.di.unipi.it/pibiri/papers/CSUR20.pdf).

(**Note**:
As of 29/11/2021, the data is hosted on the machine
`rubino.isti.cnr.it`.)

### GOV2

	./build /data/pibiri/inverted_indexes/gov2/gov2.docs --size 4096
	
	universe size: 24622347
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
	== distribution of blocks in sparse chunks (62.6754% of ints) ==
	sparse chunks with 1 blocks: 8.43082%; avg_num_integers_per_block = 1.87869; avg_num_integers_per_chunk = 1
	Elias-Fano avg. bpi 18 vs. 8
	 -- total integers covered 0.0403252%
	sparse chunks with 2 blocks: 6.50792%; avg_num_integers_per_block = 2.38464; avg_num_integers_per_chunk = 4
	Elias-Fano avg. bpi 16 vs. 8
	 -- total integers covered 0.119347%
	sparse chunks with 3 blocks: 5.3986%; avg_num_integers_per_block = 2.40731; avg_num_integers_per_chunk = 7
	Elias-Fano avg. bpi 16 vs. 8
	 -- total integers covered 0.21861%
	sparse chunks with 4 blocks: 4.75217%; avg_num_integers_per_block = 2.65841; avg_num_integers_per_chunk = 10
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 0.347264%
	sparse chunks with 5 blocks: 4.21258%; avg_num_integers_per_block = 2.62353; avg_num_integers_per_chunk = 13
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 0.487952%
	sparse chunks with 6 blocks: 3.80019%; avg_num_integers_per_block = 2.81759; avg_num_integers_per_chunk = 16
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 0.651516%
	sparse chunks with 7 blocks: 3.46053%; avg_num_integers_per_block = 2.97751; avg_num_integers_per_chunk = 20
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 0.835146%
	sparse chunks with 8 blocks: 3.16275%; avg_num_integers_per_block = 2.91154; avg_num_integers_per_chunk = 23
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 1.0227%
	sparse chunks with 9 blocks: 2.91606%; avg_num_integers_per_block = 3.17653; avg_num_integers_per_chunk = 28
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 1.23495%
	sparse chunks with 10 blocks: 2.67452%; avg_num_integers_per_block = 3.2036; avg_num_integers_per_chunk = 32
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 1.45309%
	sparse chunks with 11 blocks: 2.47538%; avg_num_integers_per_block = 3.06067; avg_num_integers_per_chunk = 33
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 1.66527%
	sparse chunks with 12 blocks: 2.27634%; avg_num_integers_per_block = 3.07892; avg_num_integers_per_chunk = 36
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 1.8794%
	sparse chunks with 13 blocks: 2.09444%; avg_num_integers_per_block = 3.03759; avg_num_integers_per_chunk = 39
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 2.08996%
	sparse chunks with 14 blocks: 1.93008%; avg_num_integers_per_block = 3.35438; avg_num_integers_per_chunk = 46
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 2.32073%
	sparse chunks with 15 blocks: 1.78167%; avg_num_integers_per_block = 3.11038; avg_num_integers_per_chunk = 46
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 2.53236%
	sparse chunks with 16 blocks: 1.65496%; avg_num_integers_per_block = 4.09892; avg_num_integers_per_chunk = 65
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 2.80869%
	sparse chunks with 17 blocks: 1.53507%; avg_num_integers_per_block = 3.3519; avg_num_integers_per_chunk = 56
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.03139%
	sparse chunks with 18 blocks: 1.42579%; avg_num_integers_per_block = 3.80983; avg_num_integers_per_chunk = 68
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 3.28033%
	sparse chunks with 19 blocks: 1.3161%; avg_num_integers_per_block = 4.11188; avg_num_integers_per_chunk = 78
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 3.5421%
	sparse chunks with 20 blocks: 1.22949%; avg_num_integers_per_block = 3.81417; avg_num_integers_per_chunk = 76
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 3.78089%
	sparse chunks with 21 blocks: 1.16169%; avg_num_integers_per_block = 3.92804; avg_num_integers_per_chunk = 82
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 4.02486%
	sparse chunks with 22 blocks: 1.08828%; avg_num_integers_per_block = 3.75269; avg_num_integers_per_chunk = 82
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 4.25361%
	sparse chunks with 23 blocks: 1.01548%; avg_num_integers_per_block = 3.87916; avg_num_integers_per_chunk = 89
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 4.48428%
	sparse chunks with 24 blocks: 0.957277%; avg_num_integers_per_block = 3.90223; avg_num_integers_per_chunk = 93
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 4.71253%
	sparse chunks with 25 blocks: 0.903625%; avg_num_integers_per_block = 4.34526; avg_num_integers_per_chunk = 108
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 4.96245%
	sparse chunks with 26 blocks: 0.845546%; avg_num_integers_per_block = 3.9397; avg_num_integers_per_chunk = 102
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.18295%
	sparse chunks with 27 blocks: 0.798394%; avg_num_integers_per_block = 4.09284; avg_num_integers_per_chunk = 110
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.40758%
	sparse chunks with 28 blocks: 0.752442%; avg_num_integers_per_block = 4.05316; avg_num_integers_per_chunk = 113
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.62499%
	sparse chunks with 29 blocks: 0.709363%; avg_num_integers_per_block = 4.11019; avg_num_integers_per_chunk = 119
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.84026%
	sparse chunks with 30 blocks: 0.683391%; avg_num_integers_per_block = 4.27526; avg_num_integers_per_chunk = 128
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 6.06341%
	sparse chunks with 31 blocks: 0.649907%; avg_num_integers_per_block = 4.41862; avg_num_integers_per_chunk = 136
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 6.29006%
	sparse chunks with 32 blocks: 0.617871%; avg_num_integers_per_block = 4.62673; avg_num_integers_per_chunk = 148
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 6.52296%
	sparse chunks with 33 blocks: 0.589462%; avg_num_integers_per_block = 4.45136; avg_num_integers_per_chunk = 146
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 6.74341%
	sparse chunks with 34 blocks: 0.560193%; avg_num_integers_per_block = 4.38195; avg_num_integers_per_chunk = 148
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 6.9559%
	sparse chunks with 35 blocks: 0.536623%; avg_num_integers_per_block = 4.39931; avg_num_integers_per_chunk = 153
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 7.16627%
	sparse chunks with 36 blocks: 0.513299%; avg_num_integers_per_block = 5.12244; avg_num_integers_per_chunk = 184
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 7.40726%
	sparse chunks with 37 blocks: 0.49644%; avg_num_integers_per_block = 4.99802; avg_num_integers_per_chunk = 184
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 7.64099%
	sparse chunks with 38 blocks: 0.474341%; avg_num_integers_per_block = 4.73956; avg_num_integers_per_chunk = 180
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 7.85849%
	sparse chunks with 39 blocks: 0.461072%; avg_num_integers_per_block = 4.85806; avg_num_integers_per_chunk = 189
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 8.0809%
	sparse chunks with 40 blocks: 0.440186%; avg_num_integers_per_block = 4.83781; avg_num_integers_per_chunk = 193
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 8.29777%
	sparse chunks with 41 blocks: 0.426812%; avg_num_integers_per_block = 4.82694; avg_num_integers_per_chunk = 197
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 8.51282%
	sparse chunks with 42 blocks: 0.417098%; avg_num_integers_per_block = 5.48239; avg_num_integers_per_chunk = 230
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 8.75734%
	sparse chunks with 43 blocks: 0.39454%; avg_num_integers_per_block = 5.19642; avg_num_integers_per_chunk = 223
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 8.98179%
	sparse chunks with 44 blocks: 0.380448%; avg_num_integers_per_block = 5.34611; avg_num_integers_per_chunk = 235
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.20963%
	sparse chunks with 45 blocks: 0.367579%; avg_num_integers_per_block = 5.50507; avg_num_integers_per_chunk = 247
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.44146%
	sparse chunks with 46 blocks: 0.357466%; avg_num_integers_per_block = 5.46697; avg_num_integers_per_chunk = 251
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.67034%
	sparse chunks with 47 blocks: 0.342408%; avg_num_integers_per_block = 6.31736; avg_num_integers_per_chunk = 296
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 9.92917%
	sparse chunks with 48 blocks: 0.327502%; avg_num_integers_per_block = 5.47182; avg_num_integers_per_chunk = 262
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 10.1482%
	sparse chunks with 49 blocks: 0.320815%; avg_num_integers_per_block = 5.72353; avg_num_integers_per_chunk = 280
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 10.3772%
	sparse chunks with 50 blocks: 0.311326%; avg_num_integers_per_block = 5.58005; avg_num_integers_per_chunk = 279
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 10.5984%
	sparse chunks with 51 blocks: 0.304579%; avg_num_integers_per_block = 6.93224; avg_num_integers_per_chunk = 353
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 10.8725%
	sparse chunks with 52 blocks: 0.292688%; avg_num_integers_per_block = 5.89901; avg_num_integers_per_chunk = 306
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 11.1011%
	sparse chunks with 53 blocks: 0.284105%; avg_num_integers_per_block = 7.20157; avg_num_integers_per_chunk = 381
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 11.3772%
	sparse chunks with 54 blocks: 0.276135%; avg_num_integers_per_block = 5.90266; avg_num_integers_per_chunk = 318
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 11.6013%
	sparse chunks with 55 blocks: 0.272261%; avg_num_integers_per_block = 7.20037; avg_num_integers_per_chunk = 396
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 11.8758%
	sparse chunks with 56 blocks: 0.264715%; avg_num_integers_per_block = 6.15388; avg_num_integers_per_chunk = 344
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 12.108%
	sparse chunks with 57 blocks: 0.256367%; avg_num_integers_per_block = 6.22382; avg_num_integers_per_chunk = 354
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 12.3396%
	sparse chunks with 58 blocks: 0.252341%; avg_num_integers_per_block = 6.15805; avg_num_integers_per_chunk = 357
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 12.5691%
	sparse chunks with 59 blocks: 0.244193%; avg_num_integers_per_block = 6.20628; avg_num_integers_per_chunk = 366
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 12.7967%
	sparse chunks with 60 blocks: 0.241497%; avg_num_integers_per_block = 7.81683; avg_num_integers_per_chunk = 469
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 13.0851%
	sparse chunks with 61 blocks: 0.234033%; avg_num_integers_per_block = 6.21743; avg_num_integers_per_chunk = 379
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 13.3111%
	sparse chunks with 62 blocks: 0.229206%; avg_num_integers_per_block = 6.85074; avg_num_integers_per_chunk = 424
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 13.5589%
	sparse chunks with 63 blocks: 0.226945%; avg_num_integers_per_block = 6.79393; avg_num_integers_per_chunk = 428
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 13.8062%
	sparse chunks with 64 blocks: 0.225532%; avg_num_integers_per_block = 7.35438; avg_num_integers_per_chunk = 470
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.0765%
	sparse chunks with 65 blocks: 0.220505%; avg_num_integers_per_block = 11.1654; avg_num_integers_per_chunk = 725
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 14.4839%
	sparse chunks with 66 blocks: 0.210804%; avg_num_integers_per_block = 6.96896; avg_num_integers_per_chunk = 459
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.7308%
	sparse chunks with 67 blocks: 0.206024%; avg_num_integers_per_block = 6.51796; avg_num_integers_per_chunk = 436
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.9598%
	sparse chunks with 68 blocks: 0.202916%; avg_num_integers_per_block = 6.79374; avg_num_integers_per_chunk = 461
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.1985%
	sparse chunks with 69 blocks: 0.199019%; avg_num_integers_per_block = 6.95865; avg_num_integers_per_chunk = 480
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.4418%
	sparse chunks with 70 blocks: 0.194745%; avg_num_integers_per_block = 7.23526; avg_num_integers_per_chunk = 506
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.6929%
	sparse chunks with 71 blocks: 0.189576%; avg_num_integers_per_block = 7.47033; avg_num_integers_per_chunk = 530
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 15.9489%
	sparse chunks with 72 blocks: 0.182171%; avg_num_integers_per_block = 7.47337; avg_num_integers_per_chunk = 538
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 16.1985%
	sparse chunks with 73 blocks: 0.178297%; avg_num_integers_per_block = 7.17262; avg_num_integers_per_chunk = 523
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 16.4361%
	sparse chunks with 74 blocks: 0.175766%; avg_num_integers_per_block = 7.08268; avg_num_integers_per_chunk = 524
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 16.6707%
	sparse chunks with 75 blocks: 0.173317%; avg_num_integers_per_block = 8.43193; avg_num_integers_per_chunk = 632
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 16.9497%
	sparse chunks with 76 blocks: 0.173164%; avg_num_integers_per_block = 13.3051; avg_num_integers_per_chunk = 1011
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 17.3955%
	sparse chunks with 77 blocks: 0.167113%; avg_num_integers_per_block = 7.31247; avg_num_integers_per_chunk = 563
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 17.6351%
	sparse chunks with 78 blocks: 0.164146%; avg_num_integers_per_block = 7.52417; avg_num_integers_per_chunk = 586
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 17.8804%
	sparse chunks with 79 blocks: 0.163639%; avg_num_integers_per_block = 9.08974; avg_num_integers_per_chunk = 718
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 18.1795%
	sparse chunks with 80 blocks: 0.158118%; avg_num_integers_per_block = 7.77915; avg_num_integers_per_chunk = 622
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 18.4301%
	sparse chunks with 81 blocks: 0.152584%; avg_num_integers_per_block = 7.56182; avg_num_integers_per_chunk = 612
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 18.668%
	sparse chunks with 82 blocks: 0.150382%; avg_num_integers_per_block = 7.25903; avg_num_integers_per_chunk = 595
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 18.8959%
	sparse chunks with 83 blocks: 0.147427%; avg_num_integers_per_block = 7.63553; avg_num_integers_per_chunk = 633
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 19.1338%
	sparse chunks with 84 blocks: 0.146591%; avg_num_integers_per_block = 7.38436; avg_num_integers_per_chunk = 620
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 19.3653%
	sparse chunks with 85 blocks: 0.140952%; avg_num_integers_per_block = 7.53846; avg_num_integers_per_chunk = 640
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 19.5952%
	sparse chunks with 86 blocks: 0.140516%; avg_num_integers_per_block = 9.61364; avg_num_integers_per_chunk = 826
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 19.891%
	sparse chunks with 87 blocks: 0.139327%; avg_num_integers_per_block = 8.16633; avg_num_integers_per_chunk = 710
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 20.143%
	sparse chunks with 88 blocks: 0.136949%; avg_num_integers_per_block = 10.6212; avg_num_integers_per_chunk = 934
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 20.4689%
	sparse chunks with 89 blocks: 0.135736%; avg_num_integers_per_block = 8.64767; avg_num_integers_per_chunk = 769
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 20.7349%
	sparse chunks with 90 blocks: 0.133382%; avg_num_integers_per_block = 8.50966; avg_num_integers_per_chunk = 765
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 20.995%
	sparse chunks with 91 blocks: 0.131863%; avg_num_integers_per_block = 10.2849; avg_num_integers_per_chunk = 935
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.3092%
	sparse chunks with 92 blocks: 0.13012%; avg_num_integers_per_block = 8.65408; avg_num_integers_per_chunk = 796
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.5729%
	sparse chunks with 93 blocks: 0.130862%; avg_num_integers_per_block = 10.6583; avg_num_integers_per_chunk = 991
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.9032%
	sparse chunks with 94 blocks: 0.129732%; avg_num_integers_per_block = 12.5867; avg_num_integers_per_chunk = 1183
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 22.294%
	sparse chunks with 95 blocks: 0.124398%; avg_num_integers_per_block = 10.2169; avg_num_integers_per_chunk = 970
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.6014%
	sparse chunks with 96 blocks: 0.121914%; avg_num_integers_per_block = 9.15158; avg_num_integers_per_chunk = 878
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.8741%
	sparse chunks with 97 blocks: 0.12122%; avg_num_integers_per_block = 9.06804; avg_num_integers_per_chunk = 879
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.1455%
	sparse chunks with 98 blocks: 0.117122%; avg_num_integers_per_block = 8.96154; avg_num_integers_per_chunk = 878
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.4074%
	sparse chunks with 99 blocks: 0.114744%; avg_num_integers_per_block = 9.40453; avg_num_integers_per_chunk = 931
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.6794%
	sparse chunks with 100 blocks: 0.114721%; avg_num_integers_per_block = 10.245; avg_num_integers_per_chunk = 1024
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 23.9786%
	sparse chunks with 101 blocks: 0.115462%; avg_num_integers_per_block = 13.5433; avg_num_integers_per_chunk = 1367
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 24.3807%
	sparse chunks with 102 blocks: 0.111624%; avg_num_integers_per_block = 10.7745; avg_num_integers_per_chunk = 1098
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 24.693%
	sparse chunks with 103 blocks: 0.109164%; avg_num_integers_per_block = 10.5766; avg_num_integers_per_chunk = 1089
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 24.9958%
	sparse chunks with 104 blocks: 0.107951%; avg_num_integers_per_block = 9.80325; avg_num_integers_per_chunk = 1019
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.276%
	sparse chunks with 105 blocks: 0.103712%; avg_num_integers_per_block = 10.2047; avg_num_integers_per_chunk = 1071
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 25.5589%
	sparse chunks with 106 blocks: 0.106503%; avg_num_integers_per_block = 13.7874; avg_num_integers_per_chunk = 1461
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 25.9552%
	sparse chunks with 107 blocks: 0.1029%; avg_num_integers_per_block = 9.49584; avg_num_integers_per_chunk = 1016
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.2214%
	sparse chunks with 108 blocks: 0.0998625%; avg_num_integers_per_block = 9.83543; avg_num_integers_per_chunk = 1062
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 26.4915%
	sparse chunks with 109 blocks: 0.0984379%; avg_num_integers_per_block = 9.45967; avg_num_integers_per_chunk = 1031
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 26.7499%
	sparse chunks with 110 blocks: 0.0978728%; avg_num_integers_per_block = 9.28219; avg_num_integers_per_chunk = 1021
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.0043%
	sparse chunks with 111 blocks: 0.0980965%; avg_num_integers_per_block = 10.3003; avg_num_integers_per_chunk = 1143
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 27.2899%
	sparse chunks with 112 blocks: 0.0977786%; avg_num_integers_per_block = 10.0576; avg_num_integers_per_chunk = 1126
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 27.5703%
	sparse chunks with 113 blocks: 0.0928926%; avg_num_integers_per_block = 9.21452; avg_num_integers_per_chunk = 1041
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 27.8165%
	sparse chunks with 114 blocks: 0.096248%; avg_num_integers_per_block = 10.8907; avg_num_integers_per_chunk = 1241
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 28.1208%
	sparse chunks with 115 blocks: 0.093234%; avg_num_integers_per_block = 9.79111; avg_num_integers_per_chunk = 1125
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 28.388%
	sparse chunks with 116 blocks: 0.092975%; avg_num_integers_per_block = 10.3811; avg_num_integers_per_chunk = 1204
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 28.6731%
	sparse chunks with 117 blocks: 0.0939287%; avg_num_integers_per_block = 10.2454; avg_num_integers_per_chunk = 1198
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 28.9597%
	sparse chunks with 118 blocks: 0.0904202%; avg_num_integers_per_block = 10.1427; avg_num_integers_per_chunk = 1196
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 29.2353%
	sparse chunks with 119 blocks: 0.0886306%; avg_num_integers_per_block = 10.6151; avg_num_integers_per_chunk = 1263
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 29.5203%
	sparse chunks with 120 blocks: 0.0909971%; avg_num_integers_per_block = 10.3179; avg_num_integers_per_chunk = 1238
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 29.8072%
	sparse chunks with 121 blocks: 0.0896549%; avg_num_integers_per_block = 10.1004; avg_num_integers_per_chunk = 1222
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 30.0861%
	sparse chunks with 122 blocks: 0.0870177%; avg_num_integers_per_block = 10.764; avg_num_integers_per_chunk = 1313
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 30.3771%
	sparse chunks with 123 blocks: 0.0926218%; avg_num_integers_per_block = 23.4721; avg_num_integers_per_chunk = 2887
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 31.0579%
	sparse chunks with 124 blocks: 0.0867586%; avg_num_integers_per_block = 10.6309; avg_num_integers_per_chunk = 1318
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.349%
	sparse chunks with 125 blocks: 0.0858992%; avg_num_integers_per_block = 11.6311; avg_num_integers_per_chunk = 1453
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.667%
	sparse chunks with 126 blocks: 0.0840507%; avg_num_integers_per_block = 10.6859; avg_num_integers_per_chunk = 1346
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.9551%
	sparse chunks with 127 blocks: 0.0849573%; avg_num_integers_per_block = 13.4102; avg_num_integers_per_chunk = 1703
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.3235%
	sparse chunks with 128 blocks: 0.0836504%; avg_num_integers_per_block = 11.9639; avg_num_integers_per_chunk = 1531
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.6496%
	sparse chunks with 129 blocks: 0.0811662%; avg_num_integers_per_block = 11.5127; avg_num_integers_per_chunk = 1485
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.9565%
	sparse chunks with 130 blocks: 0.0816725%; avg_num_integers_per_block = 11.8628; avg_num_integers_per_chunk = 1542
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.2772%
	sparse chunks with 131 blocks: 0.0787762%; avg_num_integers_per_block = 10.9462; avg_num_integers_per_chunk = 1433
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.5648%
	sparse chunks with 132 blocks: 0.0788469%; avg_num_integers_per_block = 10.8735; avg_num_integers_per_chunk = 1435
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.8529%
	sparse chunks with 133 blocks: 0.0786232%; avg_num_integers_per_block = 11.0908; avg_num_integers_per_chunk = 1475
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.1482%
	sparse chunks with 134 blocks: 0.0785525%; avg_num_integers_per_block = 11.096; avg_num_integers_per_chunk = 1486
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.4455%
	sparse chunks with 135 blocks: 0.0798594%; avg_num_integers_per_block = 12.2456; avg_num_integers_per_chunk = 1653
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.7817%
	sparse chunks with 136 blocks: 0.0772339%; avg_num_integers_per_block = 11.7477; avg_num_integers_per_chunk = 1597
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.0958%
	sparse chunks with 137 blocks: 0.0766335%; avg_num_integers_per_block = 12.9333; avg_num_integers_per_chunk = 1771
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.4415%
	sparse chunks with 138 blocks: 0.0789411%; avg_num_integers_per_block = 14.5654; avg_num_integers_per_chunk = 2010
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.8455%
	sparse chunks with 139 blocks: 0.0775753%; avg_num_integers_per_block = 11.7756; avg_num_integers_per_chunk = 1636
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 36.1688%
	sparse chunks with 140 blocks: 0.0745025%; avg_num_integers_per_block = 11.3622; avg_num_integers_per_chunk = 1590
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 36.4705%
	sparse chunks with 141 blocks: 0.0741375%; avg_num_integers_per_block = 11.2176; avg_num_integers_per_chunk = 1581
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 36.769%
	sparse chunks with 142 blocks: 0.0738314%; avg_num_integers_per_block = 12.1509; avg_num_integers_per_chunk = 1725
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 37.0934%
	sparse chunks with 143 blocks: 0.0751853%; avg_num_integers_per_block = 12.4277; avg_num_integers_per_chunk = 1777
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 37.4336%
	sparse chunks with 144 blocks: 0.0765393%; avg_num_integers_per_block = 14.1885; avg_num_integers_per_chunk = 2043
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 37.8317%
	sparse chunks with 145 blocks: 0.0727364%; avg_num_integers_per_block = 11.7513; avg_num_integers_per_chunk = 1703
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 38.1472%
	sparse chunks with 146 blocks: 0.0726423%; avg_num_integers_per_block = 12.0672; avg_num_integers_per_chunk = 1761
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 38.4731%
	sparse chunks with 147 blocks: 0.0708645%; avg_num_integers_per_block = 11.9662; avg_num_integers_per_chunk = 1759
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 38.7904%
	sparse chunks with 148 blocks: 0.0703582%; avg_num_integers_per_block = 12.7457; avg_num_integers_per_chunk = 1886
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 39.1283%
	sparse chunks with 149 blocks: 0.0710175%; avg_num_integers_per_block = 12.2277; avg_num_integers_per_chunk = 1821
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 39.4578%
	sparse chunks with 150 blocks: 0.070629%; avg_num_integers_per_block = 12.4204; avg_num_integers_per_chunk = 1863
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 39.7928%
	sparse chunks with 151 blocks: 0.0692868%; avg_num_integers_per_block = 12.2566; avg_num_integers_per_chunk = 1850
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 40.1192%
	sparse chunks with 152 blocks: 0.0681095%; avg_num_integers_per_block = 12.1673; avg_num_integers_per_chunk = 1849
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 40.4399%
	sparse chunks with 153 blocks: 0.0698049%; avg_num_integers_per_block = 12.3423; avg_num_integers_per_chunk = 1888
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 40.7755%
	sparse chunks with 154 blocks: 0.067615%; avg_num_integers_per_block = 13.13; avg_num_integers_per_chunk = 2022
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 41.1236%
	sparse chunks with 155 blocks: 0.0663199%; avg_num_integers_per_block = 12.4955; avg_num_integers_per_chunk = 1936
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 41.4507%
	sparse chunks with 156 blocks: 0.0670499%; avg_num_integers_per_block = 13.541; avg_num_integers_per_chunk = 2112
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 41.8113%
	sparse chunks with 157 blocks: 0.0659785%; avg_num_integers_per_block = 12.6156; avg_num_integers_per_chunk = 1980
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 42.144%
	sparse chunks with 158 blocks: 0.0646481%; avg_num_integers_per_block = 13.518; avg_num_integers_per_chunk = 2135
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 42.4955%
	sparse chunks with 159 blocks: 0.064342%; avg_num_integers_per_block = 12.9169; avg_num_integers_per_chunk = 2053
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 42.8319%
	sparse chunks with 160 blocks: 0.0637062%; avg_num_integers_per_block = 13.3854; avg_num_integers_per_chunk = 2141
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 43.1793%
	sparse chunks with 161 blocks: 0.0643302%; avg_num_integers_per_block = 13.8062; avg_num_integers_per_chunk = 2222
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 43.5434%
	sparse chunks with 162 blocks: 0.0636238%; avg_num_integers_per_block = 13.5578; avg_num_integers_per_chunk = 2196
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 43.8991%
	sparse chunks with 163 blocks: 0.0623758%; avg_num_integers_per_block = 13.4135; avg_num_integers_per_chunk = 2186
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 44.2463%
	sparse chunks with 164 blocks: 0.0622816%; avg_num_integers_per_block = 13.5729; avg_num_integers_per_chunk = 2225
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 44.5993%
	sparse chunks with 165 blocks: 0.0602213%; avg_num_integers_per_block = 14.0455; avg_num_integers_per_chunk = 2317
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 44.9546%
	sparse chunks with 166 blocks: 0.0607982%; avg_num_integers_per_block = 14.2147; avg_num_integers_per_chunk = 2359
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 45.3199%
	sparse chunks with 167 blocks: 0.062211%; avg_num_integers_per_block = 14.1897; avg_num_integers_per_chunk = 2369
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 45.6952%
	sparse chunks with 168 blocks: 0.0604096%; avg_num_integers_per_block = 14.1348; avg_num_integers_per_chunk = 2374
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 46.0604%
	sparse chunks with 169 blocks: 0.0590321%; avg_num_integers_per_block = 14.1031; avg_num_integers_per_chunk = 2383
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 46.4186%
	sparse chunks with 170 blocks: 0.0592558%; avg_num_integers_per_block = 14.9505; avg_num_integers_per_chunk = 2541
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 46.8021%
	sparse chunks with 171 blocks: 0.057843%; avg_num_integers_per_block = 14.571; avg_num_integers_per_chunk = 2491
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 47.169%
	sparse chunks with 172 blocks: 0.0558651%; avg_num_integers_per_block = 14.6281; avg_num_integers_per_chunk = 2516
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 47.5269%
	sparse chunks with 173 blocks: 0.0564184%; avg_num_integers_per_block = 14.3666; avg_num_integers_per_chunk = 2485
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 47.8839%
	sparse chunks with 174 blocks: 0.055194%; avg_num_integers_per_block = 13.937; avg_num_integers_per_chunk = 2425
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 48.2246%
	sparse chunks with 175 blocks: 0.0547584%; avg_num_integers_per_block = 14.1183; avg_num_integers_per_chunk = 2470
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 48.5691%
	sparse chunks with 176 blocks: 0.0558062%; avg_num_integers_per_block = 14.1985; avg_num_integers_per_chunk = 2498
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 48.9241%
	sparse chunks with 177 blocks: 0.0550763%; avg_num_integers_per_block = 15.0313; avg_num_integers_per_chunk = 2660
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 49.2972%
	sparse chunks with 178 blocks: 0.0549703%; avg_num_integers_per_block = 14.4471; avg_num_integers_per_chunk = 2571
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 49.6571%
	sparse chunks with 179 blocks: 0.0544287%; avg_num_integers_per_block = 15.11; avg_num_integers_per_chunk = 2704
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 50.0319%
	sparse chunks with 180 blocks: 0.053581%; avg_num_integers_per_block = 15.2034; avg_num_integers_per_chunk = 2736
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 50.4052%
	sparse chunks with 181 blocks: 0.0561594%; avg_num_integers_per_block = 15.2106; avg_num_integers_per_chunk = 2753
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 50.7988%
	sparse chunks with 182 blocks: 0.0548761%; avg_num_integers_per_block = 14.9581; avg_num_integers_per_chunk = 2722
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 51.1792%
	sparse chunks with 183 blocks: 0.0553941%; avg_num_integers_per_block = 14.8062; avg_num_integers_per_chunk = 2709
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 51.5613%
	sparse chunks with 184 blocks: 0.0546406%; avg_num_integers_per_block = 14.9425; avg_num_integers_per_chunk = 2749
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 51.9438%
	sparse chunks with 185 blocks: 0.0554059%; avg_num_integers_per_block = 14.657; avg_num_integers_per_chunk = 2711
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 52.3263%
	sparse chunks with 186 blocks: 0.0576193%; avg_num_integers_per_block = 14.3099; avg_num_integers_per_chunk = 2661
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 52.7168%
	sparse chunks with 187 blocks: 0.0586201%; avg_num_integers_per_block = 14.326; avg_num_integers_per_chunk = 2678
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 53.1166%
	sparse chunks with 188 blocks: 0.0592087%; avg_num_integers_per_block = 14.6975; avg_num_integers_per_chunk = 2763
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 53.5331%
	sparse chunks with 189 blocks: 0.0592087%; avg_num_integers_per_block = 14.1785; avg_num_integers_per_chunk = 2679
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 53.937%
	sparse chunks with 190 blocks: 0.0587849%; avg_num_integers_per_block = 14.4433; avg_num_integers_per_chunk = 2744
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 54.3478%
	sparse chunks with 191 blocks: 0.060857%; avg_num_integers_per_block = 14.3357; avg_num_integers_per_chunk = 2738
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 54.772%
	sparse chunks with 192 blocks: 0.0617989%; avg_num_integers_per_block = 14.2518; avg_num_integers_per_chunk = 2736
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 55.2025%
	sparse chunks with 193 blocks: 0.0617754%; avg_num_integers_per_block = 13.9147; avg_num_integers_per_chunk = 2685
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 55.6249%
	sparse chunks with 194 blocks: 0.0631175%; avg_num_integers_per_block = 14.0998; avg_num_integers_per_chunk = 2735
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 56.0645%
	sparse chunks with 195 blocks: 0.0631528%; avg_num_integers_per_block = 14.1166; avg_num_integers_per_chunk = 2752
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 56.5071%
	sparse chunks with 196 blocks: 0.0636473%; avg_num_integers_per_block = 14.2204; avg_num_integers_per_chunk = 2787
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 56.9587%
	sparse chunks with 197 blocks: 0.0649777%; avg_num_integers_per_block = 14.6323; avg_num_integers_per_chunk = 2882
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 57.4356%
	sparse chunks with 198 blocks: 0.0621874%; avg_num_integers_per_block = 15.0062; avg_num_integers_per_chunk = 2971
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 57.906%
	sparse chunks with 199 blocks: 0.0612102%; avg_num_integers_per_block = 15.1971; avg_num_integers_per_chunk = 3024
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 58.3773%
	sparse chunks with 200 blocks: 0.06008%; avg_num_integers_per_block = 15.5322; avg_num_integers_per_chunk = 3106
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 58.8525%
	sparse chunks with 201 blocks: 0.0593265%; avg_num_integers_per_block = 16.5533; avg_num_integers_per_chunk = 3327
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 59.355%
	sparse chunks with 202 blocks: 0.0593971%; avg_num_integers_per_block = 17.1677; avg_num_integers_per_chunk = 3467
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 59.8794%
	sparse chunks with 203 blocks: 0.0550998%; avg_num_integers_per_block = 17.9907; avg_num_integers_per_chunk = 3652
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 60.3918%
	sparse chunks with 204 blocks: 0.0546995%; avg_num_integers_per_block = 17.7846; avg_num_integers_per_chunk = 3628
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 60.897%
	sparse chunks with 205 blocks: 0.0522271%; avg_num_integers_per_block = 18.1078; avg_num_integers_per_chunk = 3712
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 61.3906%
	sparse chunks with 206 blocks: 0.0500725%; avg_num_integers_per_block = 18.9877; avg_num_integers_per_chunk = 3911
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 61.8893%
	sparse chunks with 207 blocks: 0.0487421%; avg_num_integers_per_block = 19.2272; avg_num_integers_per_chunk = 3980
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 62.3832%
	sparse chunks with 208 blocks: 0.048436%; avg_num_integers_per_block = 20.2247; avg_num_integers_per_chunk = 4206
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 62.9019%
	sparse chunks with 209 blocks: 0.0471645%; avg_num_integers_per_block = 19.7699; avg_num_integers_per_chunk = 4131
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 63.3981%
	sparse chunks with 210 blocks: 0.0468819%; avg_num_integers_per_block = 20.7554; avg_num_integers_per_chunk = 4358
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 63.9183%
	sparse chunks with 211 blocks: 0.0450335%; avg_num_integers_per_block = 19.9689; avg_num_integers_per_chunk = 4213
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 64.4014%
	sparse chunks with 212 blocks: 0.0436678%; avg_num_integers_per_block = 21.0659; avg_num_integers_per_chunk = 4465
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 64.8979%
	sparse chunks with 213 blocks: 0.0440092%; avg_num_integers_per_block = 21.3004; avg_num_integers_per_chunk = 4536
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 65.4063%
	sparse chunks with 214 blocks: 0.0440327%; avg_num_integers_per_block = 22.4844; avg_num_integers_per_chunk = 4811
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 65.9457%
	sparse chunks with 215 blocks: 0.0445508%; avg_num_integers_per_block = 22.8196; avg_num_integers_per_chunk = 4906
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 66.5022%
	sparse chunks with 216 blocks: 0.0454573%; avg_num_integers_per_block = 23.3756; avg_num_integers_per_chunk = 5049
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 67.0865%
	sparse chunks with 217 blocks: 0.0443153%; avg_num_integers_per_block = 23.7247; avg_num_integers_per_chunk = 5148
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 67.6674%
	sparse chunks with 218 blocks: 0.0454338%; avg_num_integers_per_block = 24.1372; avg_num_integers_per_chunk = 5261
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 68.276%
	sparse chunks with 219 blocks: 0.0442918%; avg_num_integers_per_block = 24.4787; avg_num_integers_per_chunk = 5360
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 68.8805%
	sparse chunks with 220 blocks: 0.0431144%; avg_num_integers_per_block = 25.1323; avg_num_integers_per_chunk = 5529
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 69.4875%
	sparse chunks with 221 blocks: 0.0434676%; avg_num_integers_per_block = 25.271; avg_num_integers_per_chunk = 5584
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 70.1055%
	sparse chunks with 222 blocks: 0.0445272%; avg_num_integers_per_block = 25.0183; avg_num_integers_per_chunk = 5554
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 70.7352%
	sparse chunks with 223 blocks: 0.0433263%; avg_num_integers_per_block = 26.2024; avg_num_integers_per_chunk = 5843
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 71.3797%
	sparse chunks with 224 blocks: 0.0434323%; avg_num_integers_per_block = 27.0758; avg_num_integers_per_chunk = 6064
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 72.0503%
	sparse chunks with 225 blocks: 0.0427023%; avg_num_integers_per_block = 26.5275; avg_num_integers_per_chunk = 5968
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 72.6992%
	sparse chunks with 226 blocks: 0.0431733%; avg_num_integers_per_block = 27.1095; avg_num_integers_per_chunk = 6126
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 73.3727%
	sparse chunks with 227 blocks: 0.0435618%; avg_num_integers_per_block = 28.2336; avg_num_integers_per_chunk = 6409
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 74.0835%
	sparse chunks with 228 blocks: 0.045057%; avg_num_integers_per_block = 28.0546; avg_num_integers_per_chunk = 6396
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 74.8172%
	sparse chunks with 229 blocks: 0.0421019%; avg_num_integers_per_block = 29.5304; avg_num_integers_per_chunk = 6762
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 75.5421%
	sparse chunks with 230 blocks: 0.0438679%; avg_num_integers_per_block = 30.1965; avg_num_integers_per_chunk = 6945
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 76.3178%
	sparse chunks with 231 blocks: 0.0447745%; avg_num_integers_per_block = 31.3817; avg_num_integers_per_chunk = 7249
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 77.1442%
	sparse chunks with 232 blocks: 0.0418076%; avg_num_integers_per_block = 30.8644; avg_num_integers_per_chunk = 7160
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 77.9063%
	sparse chunks with 233 blocks: 0.0420666%; avg_num_integers_per_block = 30.7192; avg_num_integers_per_chunk = 7157
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 78.6729%
	sparse chunks with 234 blocks: 0.0406302%; avg_num_integers_per_block = 30.9748; avg_num_integers_per_chunk = 7248
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 79.4227%
	sparse chunks with 235 blocks: 0.0401475%; avg_num_integers_per_block = 32.4342; avg_num_integers_per_chunk = 7622
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 80.2017%
	sparse chunks with 236 blocks: 0.0413484%; avg_num_integers_per_block = 33.3342; avg_num_integers_per_chunk = 7866
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 81.0299%
	sparse chunks with 237 blocks: 0.0419842%; avg_num_integers_per_block = 33.36; avg_num_integers_per_chunk = 7906
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 81.875%
	sparse chunks with 238 blocks: 0.0423845%; avg_num_integers_per_block = 34.3277; avg_num_integers_per_chunk = 8169
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 82.7566%
	sparse chunks with 239 blocks: 0.0436089%; avg_num_integers_per_block = 35.9237; avg_num_integers_per_chunk = 8585
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 83.7099%
	sparse chunks with 240 blocks: 0.0434088%; avg_num_integers_per_block = 37.9927; avg_num_integers_per_chunk = 9118
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 84.7176%
	sparse chunks with 241 blocks: 0.0411718%; avg_num_integers_per_block = 37.4418; avg_num_integers_per_chunk = 9023
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 85.6635%
	sparse chunks with 242 blocks: 0.0403006%; avg_num_integers_per_block = 37.8929; avg_num_integers_per_chunk = 9170
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 86.6043%
	sparse chunks with 243 blocks: 0.0386287%; avg_num_integers_per_block = 39.7224; avg_num_integers_per_chunk = 9652
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 87.5536%
	sparse chunks with 244 blocks: 0.0402299%; avg_num_integers_per_block = 40.3114; avg_num_integers_per_chunk = 9835
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 88.5611%
	sparse chunks with 245 blocks: 0.0369922%; avg_num_integers_per_block = 40.6091; avg_num_integers_per_chunk = 9949
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 89.4981%
	sparse chunks with 246 blocks: 0.0361916%; avg_num_integers_per_block = 42.1156; avg_num_integers_per_chunk = 10360
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 90.4527%
	sparse chunks with 247 blocks: 0.0342961%; avg_num_integers_per_block = 42.4374; avg_num_integers_per_chunk = 10482
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 91.368%
	sparse chunks with 248 blocks: 0.0344962%; avg_num_integers_per_block = 41.2493; avg_num_integers_per_chunk = 10229
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 92.2664%
	sparse chunks with 249 blocks: 0.0318354%; avg_num_integers_per_block = 40.3861; avg_num_integers_per_chunk = 10056
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 93.0815%
	sparse chunks with 250 blocks: 0.0334955%; avg_num_integers_per_block = 41.0309; avg_num_integers_per_chunk = 10257
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 93.9563%
	sparse chunks with 251 blocks: 0.0347082%; avg_num_integers_per_block = 39.979; avg_num_integers_per_chunk = 10034
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 94.843%
	sparse chunks with 252 blocks: 0.0323064%; avg_num_integers_per_block = 38.6379; avg_num_integers_per_chunk = 9736
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 95.6439%
	sparse chunks with 253 blocks: 0.0348848%; avg_num_integers_per_block = 38.4977; avg_num_integers_per_chunk = 9739
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 96.5089%
	sparse chunks with 254 blocks: 0.036639%; avg_num_integers_per_block = 38.6227; avg_num_integers_per_chunk = 9810
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 97.424%
	sparse chunks with 255 blocks: 0.039394%; avg_num_integers_per_block = 38.2554; avg_num_integers_per_chunk = 9755
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 98.4024%
	sparse chunks with 256 blocks: 0.0886071%; avg_num_integers_per_block = 27.6633; avg_num_integers_per_chunk = 7081
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 100%
	expected_value 33.2659



### CLUEWEB09

	./build /data/pibiri/inverted_indexes/clueweb09/clueweb09.docs --size 4096

	universe size: 50131015
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
	== sparse blocks cardinalities (%) ==
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
	== distribution of blocks in sparse chunks (81.5844% of ints) ==
	sparse chunks with 1 blocks: 12.0655%; avg_num_integers_per_block = 1.88218; avg_num_integers_per_chunk = 1
	Elias-Fano avg. bpi 18 vs. 8
	 -- total integers covered 0.119997%
	sparse chunks with 2 blocks: 10.5397%; avg_num_integers_per_block = 2.12684; avg_num_integers_per_chunk = 4
	Elias-Fano avg. bpi 16 vs. 8
	 -- total integers covered 0.356893%
	sparse chunks with 3 blocks: 8.79335%; avg_num_integers_per_block = 2.1969; avg_num_integers_per_chunk = 6
	Elias-Fano avg. bpi 16 vs. 8
	 -- total integers covered 0.663124%
	sparse chunks with 4 blocks: 7.20938%; avg_num_integers_per_block = 2.23565; avg_num_integers_per_chunk = 8
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 1.00379%
	sparse chunks with 5 blocks: 5.87046%; avg_num_integers_per_block = 2.25722; avg_num_integers_per_chunk = 11
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 1.35388%
	sparse chunks with 6 blocks: 4.80485%; avg_num_integers_per_block = 2.30638; avg_num_integers_per_chunk = 13
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 1.70522%
	sparse chunks with 7 blocks: 3.97076%; avg_num_integers_per_block = 2.33814; avg_num_integers_per_chunk = 16
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.04862%
	sparse chunks with 8 blocks: 3.32757%; avg_num_integers_per_block = 2.34957; avg_num_integers_per_chunk = 18
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.37912%
	sparse chunks with 9 blocks: 2.82172%; avg_num_integers_per_block = 2.36368; avg_num_integers_per_chunk = 21
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.6963%
	sparse chunks with 10 blocks: 2.42389%; avg_num_integers_per_block = 2.3922; avg_num_integers_per_chunk = 23
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 3.00269%
	sparse chunks with 11 blocks: 2.11029%; avg_num_integers_per_block = 2.44086; avg_num_integers_per_chunk = 26
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 3.30208%
	sparse chunks with 12 blocks: 1.85061%; avg_num_integers_per_block = 2.48232; avg_num_integers_per_chunk = 29
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 3.59337%
	sparse chunks with 13 blocks: 1.64077%; avg_num_integers_per_block = 2.4845; avg_num_integers_per_chunk = 32
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.87339%
	sparse chunks with 14 blocks: 1.46712%; avg_num_integers_per_block = 2.52249; avg_num_integers_per_chunk = 35
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.14716%
	sparse chunks with 15 blocks: 1.31967%; avg_num_integers_per_block = 2.59751; avg_num_integers_per_chunk = 38
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.41886%
	sparse chunks with 16 blocks: 1.19459%; avg_num_integers_per_block = 2.59926; avg_num_integers_per_chunk = 41
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.68137%
	sparse chunks with 17 blocks: 1.08709%; avg_num_integers_per_block = 2.60429; avg_num_integers_per_chunk = 44
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.93568%
	sparse chunks with 18 blocks: 0.993267%; avg_num_integers_per_block = 2.62856; avg_num_integers_per_chunk = 47
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 5.18401%
	sparse chunks with 19 blocks: 0.9117%; avg_num_integers_per_block = 2.63384; avg_num_integers_per_chunk = 50
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 5.42509%
	sparse chunks with 20 blocks: 0.840087%; avg_num_integers_per_block = 2.65782; avg_num_integers_per_chunk = 53
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 5.66105%
	sparse chunks with 21 blocks: 0.776956%; avg_num_integers_per_block = 2.68738; avg_num_integers_per_chunk = 56
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 5.89274%
	sparse chunks with 22 blocks: 0.721724%; avg_num_integers_per_block = 2.70941; avg_num_integers_per_chunk = 59
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 6.12006%
	sparse chunks with 23 blocks: 0.674704%; avg_num_integers_per_block = 2.70545; avg_num_integers_per_chunk = 62
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 6.3419%
	sparse chunks with 24 blocks: 0.628723%; avg_num_integers_per_block = 2.70128; avg_num_integers_per_chunk = 64
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.55728%
	sparse chunks with 25 blocks: 0.590828%; avg_num_integers_per_block = 2.72868; avg_num_integers_per_chunk = 68
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.77025%
	sparse chunks with 26 blocks: 0.555068%; avg_num_integers_per_block = 2.81427; avg_num_integers_per_chunk = 73
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.98486%
	sparse chunks with 27 blocks: 0.523742%; avg_num_integers_per_block = 2.82118; avg_num_integers_per_chunk = 76
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.19566%
	sparse chunks with 28 blocks: 0.494158%; avg_num_integers_per_block = 2.77733; avg_num_integers_per_chunk = 77
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.39872%
	sparse chunks with 29 blocks: 0.467789%; avg_num_integers_per_block = 2.84271; avg_num_integers_per_chunk = 82
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.60249%
	sparse chunks with 30 blocks: 0.442111%; avg_num_integers_per_block = 2.84532; avg_num_integers_per_chunk = 85
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.8019%
	sparse chunks with 31 blocks: 0.423121%; avg_num_integers_per_block = 2.82777; avg_num_integers_per_chunk = 87
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.99789%
	sparse chunks with 32 blocks: 0.4022%; avg_num_integers_per_block = 2.83208; avg_num_integers_per_chunk = 90
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.19049%
	sparse chunks with 33 blocks: 0.382546%; avg_num_integers_per_block = 2.814; avg_num_integers_per_chunk = 92
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.3782%
	sparse chunks with 34 blocks: 0.364722%; avg_num_integers_per_block = 2.84677; avg_num_integers_per_chunk = 96
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.56473%
	sparse chunks with 35 blocks: 0.349694%; avg_num_integers_per_block = 2.85015; avg_num_integers_per_chunk = 99
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.74906%
	sparse chunks with 36 blocks: 0.335986%; avg_num_integers_per_block = 2.95834; avg_num_integers_per_chunk = 106
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.93814%
	sparse chunks with 37 blocks: 0.322127%; avg_num_integers_per_block = 2.88534; avg_num_integers_per_chunk = 106
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 9.11985%
	sparse chunks with 38 blocks: 0.310814%; avg_num_integers_per_block = 2.9312; avg_num_integers_per_chunk = 111
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 9.30278%
	sparse chunks with 39 blocks: 0.298481%; avg_num_integers_per_block = 2.93406; avg_num_integers_per_chunk = 114
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 9.48326%
	sparse chunks with 40 blocks: 0.287053%; avg_num_integers_per_block = 2.93458; avg_num_integers_per_chunk = 117
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 9.6613%
	sparse chunks with 41 blocks: 0.27689%; avg_num_integers_per_block = 2.9448; avg_num_integers_per_chunk = 120
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 9.83795%
	sparse chunks with 42 blocks: 0.268126%; avg_num_integers_per_block = 2.94529; avg_num_integers_per_chunk = 123
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 10.0132%
	sparse chunks with 43 blocks: 0.257419%; avg_num_integers_per_block = 2.98161; avg_num_integers_per_chunk = 128
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.1876%
	sparse chunks with 44 blocks: 0.250219%; avg_num_integers_per_block = 2.98636; avg_num_integers_per_chunk = 131
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.3613%
	sparse chunks with 45 blocks: 0.24138%; avg_num_integers_per_block = 2.98733; avg_num_integers_per_chunk = 134
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.5328%
	sparse chunks with 46 blocks: 0.234016%; avg_num_integers_per_block = 3.0444; avg_num_integers_per_chunk = 140
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.706%
	sparse chunks with 47 blocks: 0.226946%; avg_num_integers_per_block = 3.03428; avg_num_integers_per_chunk = 142
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.877%
	sparse chunks with 48 blocks: 0.220472%; avg_num_integers_per_block = 3.03065; avg_num_integers_per_chunk = 145
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.0464%
	sparse chunks with 49 blocks: 0.214037%; avg_num_integers_per_block = 3.03435; avg_num_integers_per_chunk = 148
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.2146%
	sparse chunks with 50 blocks: 0.207013%; avg_num_integers_per_block = 3.06426; avg_num_integers_per_chunk = 153
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.3822%
	sparse chunks with 51 blocks: 0.201608%; avg_num_integers_per_block = 3.03704; avg_num_integers_per_chunk = 154
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.5472%
	sparse chunks with 52 blocks: 0.196784%; avg_num_integers_per_block = 3.07988; avg_num_integers_per_chunk = 160
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.7137%
	sparse chunks with 53 blocks: 0.190345%; avg_num_integers_per_block = 3.09452; avg_num_integers_per_chunk = 164
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.8787%
	sparse chunks with 54 blocks: 0.185529%; avg_num_integers_per_block = 3.12591; avg_num_integers_per_chunk = 168
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.0442%
	sparse chunks with 55 blocks: 0.179936%; avg_num_integers_per_block = 3.14533; avg_num_integers_per_chunk = 172
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.2086%
	sparse chunks with 56 blocks: 0.17623%; avg_num_integers_per_block = 3.15506; avg_num_integers_per_chunk = 176
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.3732%
	sparse chunks with 57 blocks: 0.171686%; avg_num_integers_per_block = 3.15951; avg_num_integers_per_chunk = 180
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.5366%
	sparse chunks with 58 blocks: 0.167488%; avg_num_integers_per_block = 3.1901; avg_num_integers_per_chunk = 185
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.7003%
	sparse chunks with 59 blocks: 0.162528%; avg_num_integers_per_block = 3.26479; avg_num_integers_per_chunk = 192
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.8657%
	sparse chunks with 60 blocks: 0.158644%; avg_num_integers_per_block = 3.21654; avg_num_integers_per_chunk = 192
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.0275%
	sparse chunks with 61 blocks: 0.154487%; avg_num_integers_per_block = 3.25577; avg_num_integers_per_chunk = 198
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.1896%
	sparse chunks with 62 blocks: 0.150763%; avg_num_integers_per_block = 3.27684; avg_num_integers_per_chunk = 203
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.3515%
	sparse chunks with 63 blocks: 0.147237%; avg_num_integers_per_block = 3.25127; avg_num_integers_per_chunk = 204
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.5108%
	sparse chunks with 64 blocks: 0.14347%; avg_num_integers_per_block = 3.26646; avg_num_integers_per_chunk = 209
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.6693%
	sparse chunks with 65 blocks: 0.140592%; avg_num_integers_per_block = 3.28803; avg_num_integers_per_chunk = 213
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.8281%
	sparse chunks with 66 blocks: 0.138054%; avg_num_integers_per_block = 3.319; avg_num_integers_per_chunk = 219
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.9879%
	sparse chunks with 67 blocks: 0.134521%; avg_num_integers_per_block = 3.31815; avg_num_integers_per_chunk = 222
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 14.1459%
	sparse chunks with 68 blocks: 0.131271%; avg_num_integers_per_block = 3.32311; avg_num_integers_per_chunk = 225
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 14.3027%
	sparse chunks with 69 blocks: 0.127938%; avg_num_integers_per_block = 3.35898; avg_num_integers_per_chunk = 231
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 14.4593%
	sparse chunks with 70 blocks: 0.125961%; avg_num_integers_per_block = 3.37935; avg_num_integers_per_chunk = 236
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 14.6168%
	sparse chunks with 71 blocks: 0.122327%; avg_num_integers_per_block = 3.41205; avg_num_integers_per_chunk = 242
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 14.7734%
	sparse chunks with 72 blocks: 0.120824%; avg_num_integers_per_block = 3.4152; avg_num_integers_per_chunk = 245
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 14.9304%
	sparse chunks with 73 blocks: 0.116896%; avg_num_integers_per_block = 3.52248; avg_num_integers_per_chunk = 257
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.0892%
	sparse chunks with 74 blocks: 0.115495%; avg_num_integers_per_block = 3.45311; avg_num_integers_per_chunk = 255
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 15.2451%
	sparse chunks with 75 blocks: 0.112777%; avg_num_integers_per_block = 3.45815; avg_num_integers_per_chunk = 259
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.3997%
	sparse chunks with 76 blocks: 0.110759%; avg_num_integers_per_block = 3.46903; avg_num_integers_per_chunk = 263
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.554%
	sparse chunks with 77 blocks: 0.1083%; avg_num_integers_per_block = 3.48539; avg_num_integers_per_chunk = 268
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.7076%
	sparse chunks with 78 blocks: 0.106758%; avg_num_integers_per_block = 3.50626; avg_num_integers_per_chunk = 273
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.8618%
	sparse chunks with 79 blocks: 0.103915%; avg_num_integers_per_block = 3.54711; avg_num_integers_per_chunk = 280
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.0157%
	sparse chunks with 80 blocks: 0.102071%; avg_num_integers_per_block = 3.54308; avg_num_integers_per_chunk = 283
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.1686%
	sparse chunks with 81 blocks: 0.100538%; avg_num_integers_per_block = 3.55634; avg_num_integers_per_chunk = 288
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.3216%
	sparse chunks with 82 blocks: 0.0990814%; avg_num_integers_per_block = 3.62394; avg_num_integers_per_chunk = 297
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.4772%
	sparse chunks with 83 blocks: 0.097322%; avg_num_integers_per_block = 3.63093; avg_num_integers_per_chunk = 301
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.6322%
	sparse chunks with 84 blocks: 0.0953722%; avg_num_integers_per_block = 3.61035; avg_num_integers_per_chunk = 303
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.785%
	sparse chunks with 85 blocks: 0.0943777%; avg_num_integers_per_block = 3.63541; avg_num_integers_per_chunk = 309
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.9391%
	sparse chunks with 86 blocks: 0.0920969%; avg_num_integers_per_block = 3.68322; avg_num_integers_per_chunk = 316
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.0933%
	sparse chunks with 87 blocks: 0.0897536%; avg_num_integers_per_block = 3.70153; avg_num_integers_per_chunk = 322
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.246%
	sparse chunks with 88 blocks: 0.0880894%; avg_num_integers_per_block = 3.68166; avg_num_integers_per_chunk = 323
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.3968%
	sparse chunks with 89 blocks: 0.0872308%; avg_num_integers_per_block = 3.69549; avg_num_integers_per_chunk = 328
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.5484%
	sparse chunks with 90 blocks: 0.0850498%; avg_num_integers_per_block = 3.7603; avg_num_integers_per_chunk = 338
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.7005%
	sparse chunks with 91 blocks: 0.0838056%; avg_num_integers_per_block = 3.75605; avg_num_integers_per_chunk = 341
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.8518%
	sparse chunks with 92 blocks: 0.083075%; avg_num_integers_per_block = 3.76714; avg_num_integers_per_chunk = 346
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.004%
	sparse chunks with 93 blocks: 0.0818573%; avg_num_integers_per_block = 3.78634; avg_num_integers_per_chunk = 352
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.1563%
	sparse chunks with 94 blocks: 0.080215%; avg_num_integers_per_block = 3.79072; avg_num_integers_per_chunk = 356
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.3073%
	sparse chunks with 95 blocks: 0.0782323%; avg_num_integers_per_block = 3.82621; avg_num_integers_per_chunk = 363
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.4576%
	sparse chunks with 96 blocks: 0.077817%; avg_num_integers_per_block = 3.86105; avg_num_integers_per_chunk = 370
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.61%
	sparse chunks with 97 blocks: 0.0765884%; avg_num_integers_per_block = 3.86695; avg_num_integers_per_chunk = 375
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.7618%
	sparse chunks with 98 blocks: 0.0751272%; avg_num_integers_per_block = 3.8964; avg_num_integers_per_chunk = 381
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.9134%
	sparse chunks with 99 blocks: 0.0738673%; avg_num_integers_per_block = 3.90319; avg_num_integers_per_chunk = 386
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.0642%
	sparse chunks with 100 blocks: 0.0732351%; avg_num_integers_per_block = 3.90011; avg_num_integers_per_chunk = 390
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.2151%
	sparse chunks with 101 blocks: 0.072392%; avg_num_integers_per_block = 3.93536; avg_num_integers_per_chunk = 397
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.3672%
	sparse chunks with 102 blocks: 0.0707247%; avg_num_integers_per_block = 3.96496; avg_num_integers_per_chunk = 404
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.5183%
	sparse chunks with 103 blocks: 0.0696507%; avg_num_integers_per_block = 3.98153; avg_num_integers_per_chunk = 410
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.6692%
	sparse chunks with 104 blocks: 0.0686515%; avg_num_integers_per_block = 4.02769; avg_num_integers_per_chunk = 418
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.8212%
	sparse chunks with 105 blocks: 0.0680317%; avg_num_integers_per_block = 4.03493; avg_num_integers_per_chunk = 423
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.9735%
	sparse chunks with 106 blocks: 0.0672496%; avg_num_integers_per_block = 4.05324; avg_num_integers_per_chunk = 429
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.1261%
	sparse chunks with 107 blocks: 0.0659008%; avg_num_integers_per_block = 4.078; avg_num_integers_per_chunk = 436
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.2781%
	sparse chunks with 108 blocks: 0.0652748%; avg_num_integers_per_block = 4.11673; avg_num_integers_per_chunk = 444
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.4314%
	sparse chunks with 109 blocks: 0.0642522%; avg_num_integers_per_block = 4.11518; avg_num_integers_per_chunk = 448
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.5837%
	sparse chunks with 110 blocks: 0.0628565%; avg_num_integers_per_block = 4.18016; avg_num_integers_per_chunk = 459
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.7364%
	sparse chunks with 111 blocks: 0.0623788%; avg_num_integers_per_block = 4.18053; avg_num_integers_per_chunk = 464
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.8894%
	sparse chunks with 112 blocks: 0.0612767%; avg_num_integers_per_block = 4.16305; avg_num_integers_per_chunk = 466
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 21.0404%
	sparse chunks with 113 blocks: 0.0611955%; avg_num_integers_per_block = 4.23732; avg_num_integers_per_chunk = 478
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 21.1952%
	sparse chunks with 114 blocks: 0.0600387%; avg_num_integers_per_block = 4.21922; avg_num_integers_per_chunk = 480
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 21.3478%
	sparse chunks with 115 blocks: 0.059141%; avg_num_integers_per_block = 4.27738; avg_num_integers_per_chunk = 491
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 21.5015%
	sparse chunks with 116 blocks: 0.0582433%; avg_num_integers_per_block = 4.30215; avg_num_integers_per_chunk = 499
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 21.6551%
	sparse chunks with 117 blocks: 0.0578812%; avg_num_integers_per_block = 4.32856; avg_num_integers_per_chunk = 506
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 21.81%
	sparse chunks with 118 blocks: 0.0570959%; avg_num_integers_per_block = 4.29979; avg_num_integers_per_chunk = 507
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 21.9631%
	sparse chunks with 119 blocks: 0.0566291%; avg_num_integers_per_block = 4.37678; avg_num_integers_per_chunk = 520
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.1189%
	sparse chunks with 120 blocks: 0.0556612%; avg_num_integers_per_block = 4.38724; avg_num_integers_per_chunk = 526
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.2738%
	sparse chunks with 121 blocks: 0.0546262%; avg_num_integers_per_block = 4.41434; avg_num_integers_per_chunk = 534
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.4279%
	sparse chunks with 122 blocks: 0.0548276%; avg_num_integers_per_block = 4.45672; avg_num_integers_per_chunk = 543
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.5855%
	sparse chunks with 123 blocks: 0.0537519%; avg_num_integers_per_block = 4.47849; avg_num_integers_per_chunk = 550
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.7419%
	sparse chunks with 124 blocks: 0.0534865%; avg_num_integers_per_block = 4.47533; avg_num_integers_per_chunk = 554
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.8987%
	sparse chunks with 125 blocks: 0.0519722%; avg_num_integers_per_block = 4.54872; avg_num_integers_per_chunk = 568
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.0549%
	sparse chunks with 126 blocks: 0.0521377%; avg_num_integers_per_block = 4.53543; avg_num_integers_per_chunk = 571
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.2123%
	sparse chunks with 127 blocks: 0.0515179%; avg_num_integers_per_block = 4.56066; avg_num_integers_per_chunk = 579
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.37%
	sparse chunks with 128 blocks: 0.0509309%; avg_num_integers_per_block = 4.60574; avg_num_integers_per_chunk = 589
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.5287%
	sparse chunks with 129 blocks: 0.0504579%; avg_num_integers_per_block = 4.61738; avg_num_integers_per_chunk = 595
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.6875%
	sparse chunks with 130 blocks: 0.0500223%; avg_num_integers_per_block = 4.62065; avg_num_integers_per_chunk = 600
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.8462%
	sparse chunks with 131 blocks: 0.0495743%; avg_num_integers_per_block = 4.73706; avg_num_integers_per_chunk = 620
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.0088%
	sparse chunks with 132 blocks: 0.0484237%; avg_num_integers_per_block = 4.72715; avg_num_integers_per_chunk = 623
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.1685%
	sparse chunks with 133 blocks: 0.0486423%; avg_num_integers_per_block = 4.76931; avg_num_integers_per_chunk = 634
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.3315%
	sparse chunks with 134 blocks: 0.0483191%; avg_num_integers_per_block = 4.80576; avg_num_integers_per_chunk = 643
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.4959%
	sparse chunks with 135 blocks: 0.0472622%; avg_num_integers_per_block = 4.83413; avg_num_integers_per_chunk = 652
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.6589%
	sparse chunks with 136 blocks: 0.0471592%; avg_num_integers_per_block = 4.85741; avg_num_integers_per_chunk = 660
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.8235%
	sparse chunks with 137 blocks: 0.0462069%; avg_num_integers_per_block = 4.88444; avg_num_integers_per_chunk = 669
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.9869%
	sparse chunks with 138 blocks: 0.0454919%; avg_num_integers_per_block = 4.85469; avg_num_integers_per_chunk = 669
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.1479%
	sparse chunks with 139 blocks: 0.045431%; avg_num_integers_per_block = 4.88384; avg_num_integers_per_chunk = 678
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.3109%
	sparse chunks with 140 blocks: 0.04483%; avg_num_integers_per_block = 4.97189; avg_num_integers_per_chunk = 696
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.4758%
	sparse chunks with 141 blocks: 0.0445724%; avg_num_integers_per_block = 5.00272; avg_num_integers_per_chunk = 705
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.6419%
	sparse chunks with 142 blocks: 0.0441337%; avg_num_integers_per_block = 5.03466; avg_num_integers_per_chunk = 714
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.8086%
	sparse chunks with 143 blocks: 0.0438136%; avg_num_integers_per_block = 5.03102; avg_num_integers_per_chunk = 719
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.9752%
	sparse chunks with 144 blocks: 0.0436809%; avg_num_integers_per_block = 5.11032; avg_num_integers_per_chunk = 735
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.145%
	sparse chunks with 145 blocks: 0.0431221%; avg_num_integers_per_block = 5.1612; avg_num_integers_per_chunk = 748
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.3156%
	sparse chunks with 146 blocks: 0.0426631%; avg_num_integers_per_block = 5.1617; avg_num_integers_per_chunk = 753
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.4854%
	sparse chunks with 147 blocks: 0.0418138%; avg_num_integers_per_block = 5.16219; avg_num_integers_per_chunk = 758
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.6531%
	sparse chunks with 148 blocks: 0.0420214%; avg_num_integers_per_block = 5.21477; avg_num_integers_per_chunk = 771
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.8245%
	sparse chunks with 149 blocks: 0.0412893%; avg_num_integers_per_block = 5.24932; avg_num_integers_per_chunk = 782
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.9951%
	sparse chunks with 150 blocks: 0.0407959%; avg_num_integers_per_block = 5.2676; avg_num_integers_per_chunk = 790
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.1655%
	sparse chunks with 151 blocks: 0.0409474%; avg_num_integers_per_block = 5.26154; avg_num_integers_per_chunk = 794
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.3374%
	sparse chunks with 152 blocks: 0.0402433%; avg_num_integers_per_block = 5.38538; avg_num_integers_per_chunk = 818
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.5114%
	sparse chunks with 153 blocks: 0.0398561%; avg_num_integers_per_block = 5.41986; avg_num_integers_per_chunk = 829
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.6861%
	sparse chunks with 154 blocks: 0.0401231%; avg_num_integers_per_block = 5.44819; avg_num_integers_per_chunk = 839
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.8639%
	sparse chunks with 155 blocks: 0.0399077%; avg_num_integers_per_block = 5.547; avg_num_integers_per_chunk = 859
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.0452%
	sparse chunks with 156 blocks: 0.0391396%; avg_num_integers_per_block = 5.5057; avg_num_integers_per_chunk = 858
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.2229%
	sparse chunks with 157 blocks: 0.038946%; avg_num_integers_per_block = 5.50648; avg_num_integers_per_chunk = 864
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.4008%
	sparse chunks with 158 blocks: 0.0388773%; avg_num_integers_per_block = 5.61921; avg_num_integers_per_chunk = 887
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.5832%
	sparse chunks with 159 blocks: 0.0387649%; avg_num_integers_per_block = 5.60523; avg_num_integers_per_chunk = 891
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.7657%
	sparse chunks with 160 blocks: 0.0382341%; avg_num_integers_per_block = 5.69011; avg_num_integers_per_chunk = 910
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.9497%
	sparse chunks with 161 blocks: 0.0384558%; avg_num_integers_per_block = 5.74615; avg_num_integers_per_chunk = 925
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 29.1376%
	sparse chunks with 162 blocks: 0.0378251%; avg_num_integers_per_block = 5.74293; avg_num_integers_per_chunk = 930
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 29.3236%
	sparse chunks with 163 blocks: 0.0372693%; avg_num_integers_per_block = 5.80111; avg_num_integers_per_chunk = 945
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 29.5098%
	sparse chunks with 164 blocks: 0.0373208%; avg_num_integers_per_block = 5.82473; avg_num_integers_per_chunk = 955
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 29.6982%
	sparse chunks with 165 blocks: 0.0373364%; avg_num_integers_per_block = 5.90237; avg_num_integers_per_chunk = 973
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 29.8903%
	sparse chunks with 166 blocks: 0.0367073%; avg_num_integers_per_block = 5.95406; avg_num_integers_per_chunk = 988
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 30.082%
	sparse chunks with 167 blocks: 0.0367182%; avg_num_integers_per_block = 6.03297; avg_num_integers_per_chunk = 1007
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 30.2775%
	sparse chunks with 168 blocks: 0.0361125%; avg_num_integers_per_block = 6.07487; avg_num_integers_per_chunk = 1020
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 30.4722%
	sparse chunks with 169 blocks: 0.0354599%; avg_num_integers_per_block = 6.13182; avg_num_integers_per_chunk = 1036
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 30.6664%
	sparse chunks with 170 blocks: 0.0355224%; avg_num_integers_per_block = 6.16712; avg_num_integers_per_chunk = 1048
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 30.8632%
	sparse chunks with 171 blocks: 0.0359564%; avg_num_integers_per_block = 6.2046; avg_num_integers_per_chunk = 1060
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.0648%
	sparse chunks with 172 blocks: 0.0353413%; avg_num_integers_per_block = 6.22539; avg_num_integers_per_chunk = 1070
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.2647%
	sparse chunks with 173 blocks: 0.0349729%; avg_num_integers_per_block = 6.29777; avg_num_integers_per_chunk = 1089
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.4661%
	sparse chunks with 174 blocks: 0.0346278%; avg_num_integers_per_block = 6.36644; avg_num_integers_per_chunk = 1107
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.6688%
	sparse chunks with 175 blocks: 0.0343749%; avg_num_integers_per_block = 6.3134; avg_num_integers_per_chunk = 1104
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.8695%
	sparse chunks with 176 blocks: 0.0345154%; avg_num_integers_per_block = 6.41261; avg_num_integers_per_chunk = 1128
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.0753%
	sparse chunks with 177 blocks: 0.0347262%; avg_num_integers_per_block = 6.4373; avg_num_integers_per_chunk = 1139
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.2844%
	sparse chunks with 178 blocks: 0.0343827%; avg_num_integers_per_block = 6.49714; avg_num_integers_per_chunk = 1156
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.4945%
	sparse chunks with 179 blocks: 0.0339909%; avg_num_integers_per_block = 6.61361; avg_num_integers_per_chunk = 1183
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.7071%
	sparse chunks with 180 blocks: 0.0338051%; avg_num_integers_per_block = 6.66973; avg_num_integers_per_chunk = 1200
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.9216%
	sparse chunks with 181 blocks: 0.0339082%; avg_num_integers_per_block = 6.72223; avg_num_integers_per_chunk = 1216
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.1396%
	sparse chunks with 182 blocks: 0.0336131%; avg_num_integers_per_block = 6.83539; avg_num_integers_per_chunk = 1244
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.3605%
	sparse chunks with 183 blocks: 0.0333696%; avg_num_integers_per_block = 6.89455; avg_num_integers_per_chunk = 1261
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.583%
	sparse chunks with 184 blocks: 0.0332743%; avg_num_integers_per_block = 6.98345; avg_num_integers_per_chunk = 1284
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.8089%
	sparse chunks with 185 blocks: 0.0335475%; avg_num_integers_per_block = 7.0638; avg_num_integers_per_chunk = 1306
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.0406%
	sparse chunks with 186 blocks: 0.0330074%; avg_num_integers_per_block = 7.0894; avg_num_integers_per_chunk = 1318
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.2705%
	sparse chunks with 187 blocks: 0.0329465%; avg_num_integers_per_block = 7.1223; avg_num_integers_per_chunk = 1331
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.5024%
	sparse chunks with 188 blocks: 0.0330776%; avg_num_integers_per_block = 7.28735; avg_num_integers_per_chunk = 1370
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.7419%
	sparse chunks with 189 blocks: 0.0325968%; avg_num_integers_per_block = 7.31329; avg_num_integers_per_chunk = 1382
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.9799%
	sparse chunks with 190 blocks: 0.0330932%; avg_num_integers_per_block = 7.38977; avg_num_integers_per_chunk = 1404
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.2255%
	sparse chunks with 191 blocks: 0.0330152%; avg_num_integers_per_block = 7.52022; avg_num_integers_per_chunk = 1436
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.476%
	sparse chunks with 192 blocks: 0.0327186%; avg_num_integers_per_block = 7.64354; avg_num_integers_per_chunk = 1467
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.7298%
	sparse chunks with 193 blocks: 0.0327357%; avg_num_integers_per_block = 7.71109; avg_num_integers_per_chunk = 1488
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.9872%
	sparse chunks with 194 blocks: 0.0332962%; avg_num_integers_per_block = 7.72929; avg_num_integers_per_chunk = 1499
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 36.251%
	sparse chunks with 195 blocks: 0.0325952%; avg_num_integers_per_block = 7.90399; avg_num_integers_per_chunk = 1541
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 36.5165%
	sparse chunks with 196 blocks: 0.0329699%; avg_num_integers_per_block = 7.95338; avg_num_integers_per_chunk = 1558
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 36.788%
	sparse chunks with 197 blocks: 0.0326015%; avg_num_integers_per_block = 8.10042; avg_num_integers_per_chunk = 1595
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 37.0629%
	sparse chunks with 198 blocks: 0.0326764%; avg_num_integers_per_block = 8.16991; avg_num_integers_per_chunk = 1617
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 37.3422%
	sparse chunks with 199 blocks: 0.0330776%; avg_num_integers_per_block = 8.26528; avg_num_integers_per_chunk = 1644
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 37.6297%
	sparse chunks with 200 blocks: 0.0329059%; avg_num_integers_per_block = 8.3463; avg_num_integers_per_chunk = 1669
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 37.92%
	sparse chunks with 201 blocks: 0.0331978%; avg_num_integers_per_block = 8.54814; avg_num_integers_per_chunk = 1718
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 38.2214%
	sparse chunks with 202 blocks: 0.0327357%; avg_num_integers_per_block = 8.65812; avg_num_integers_per_chunk = 1748
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 38.5239%
	sparse chunks with 203 blocks: 0.0328903%; avg_num_integers_per_block = 8.78654; avg_num_integers_per_chunk = 1783
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 38.8339%
	sparse chunks with 204 blocks: 0.0333477%; avg_num_integers_per_block = 8.81238; avg_num_integers_per_chunk = 1797
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 39.1506%
	sparse chunks with 205 blocks: 0.033368%; avg_num_integers_per_block = 8.94232; avg_num_integers_per_chunk = 1833
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 39.4739%
	sparse chunks with 206 blocks: 0.0334289%; avg_num_integers_per_block = 9.12973; avg_num_integers_per_chunk = 1880
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 39.8061%
	sparse chunks with 207 blocks: 0.0332946%; avg_num_integers_per_block = 9.25635; avg_num_integers_per_chunk = 1916
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 40.1432%
	sparse chunks with 208 blocks: 0.0332166%; avg_num_integers_per_block = 9.37208; avg_num_integers_per_chunk = 1949
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 40.4853%
	sparse chunks with 209 blocks: 0.0338036%; avg_num_integers_per_block = 9.9843; avg_num_integers_per_chunk = 2086
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 40.858%
	sparse chunks with 210 blocks: 0.0335709%; avg_num_integers_per_block = 9.86575; avg_num_integers_per_chunk = 2071
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 41.2256%
	sparse chunks with 211 blocks: 0.0337146%; avg_num_integers_per_block = 9.99905; avg_num_integers_per_chunk = 2109
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 41.6014%
	sparse chunks with 212 blocks: 0.0338676%; avg_num_integers_per_block = 10.0696; avg_num_integers_per_chunk = 2134
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 41.9834%
	sparse chunks with 213 blocks: 0.0340049%; avg_num_integers_per_block = 10.1768; avg_num_integers_per_chunk = 2167
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 42.3729%
	sparse chunks with 214 blocks: 0.0342251%; avg_num_integers_per_block = 10.3789; avg_num_integers_per_chunk = 2221
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 42.7746%
	sparse chunks with 215 blocks: 0.0344905%; avg_num_integers_per_block = 10.5533; avg_num_integers_per_chunk = 2268
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 43.1881%
	sparse chunks with 216 blocks: 0.0350462%; avg_num_integers_per_block = 10.69; avg_num_integers_per_chunk = 2309
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 43.6157%
	sparse chunks with 217 blocks: 0.0347902%; avg_num_integers_per_block = 10.9256; avg_num_integers_per_chunk = 2370
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 44.0516%
	sparse chunks with 218 blocks: 0.0350275%; avg_num_integers_per_block = 11.1806; avg_num_integers_per_chunk = 2437
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 44.5027%
	sparse chunks with 219 blocks: 0.0353132%; avg_num_integers_per_block = 11.393; avg_num_integers_per_chunk = 2495
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 44.9683%
	sparse chunks with 220 blocks: 0.0359954%; avg_num_integers_per_block = 11.5766; avg_num_integers_per_chunk = 2546
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 45.4527%
	sparse chunks with 221 blocks: 0.0361468%; avg_num_integers_per_block = 12.4487; avg_num_integers_per_chunk = 2751
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 45.9781%
	sparse chunks with 222 blocks: 0.0353179%; avg_num_integers_per_block = 12.1031; avg_num_integers_per_chunk = 2686
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 46.4796%
	sparse chunks with 223 blocks: 0.0359673%; avg_num_integers_per_block = 12.2272; avg_num_integers_per_chunk = 2726
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 46.9978%
	sparse chunks with 224 blocks: 0.035705%; avg_num_integers_per_block = 12.507; avg_num_integers_per_chunk = 2801
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 47.5263%
	sparse chunks with 225 blocks: 0.0361921%; avg_num_integers_per_block = 12.8728; avg_num_integers_per_chunk = 2896
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 48.0802%
	sparse chunks with 226 blocks: 0.0366027%; avg_num_integers_per_block = 13.0999; avg_num_integers_per_chunk = 2960
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 48.6528%
	sparse chunks with 227 blocks: 0.0369243%; avg_num_integers_per_block = 13.3456; avg_num_integers_per_chunk = 3029
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 49.2439%
	sparse chunks with 228 blocks: 0.0374832%; avg_num_integers_per_block = 13.5955; avg_num_integers_per_chunk = 3099
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 49.8579%
	sparse chunks with 229 blocks: 0.0380296%; avg_num_integers_per_block = 13.9978; avg_num_integers_per_chunk = 3205
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 50.502%
	sparse chunks with 230 blocks: 0.0385619%; avg_num_integers_per_block = 14.294; avg_num_integers_per_chunk = 3287
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 51.1719%
	sparse chunks with 231 blocks: 0.0392114%; avg_num_integers_per_block = 14.9501; avg_num_integers_per_chunk = 3453
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 51.8874%
	sparse chunks with 232 blocks: 0.039739%; avg_num_integers_per_block = 15.1856; avg_num_integers_per_chunk = 3523
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 52.6272%
	sparse chunks with 233 blocks: 0.0403541%; avg_num_integers_per_block = 15.6035; avg_num_integers_per_chunk = 3635
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 53.4024%
	sparse chunks with 234 blocks: 0.041194%; avg_num_integers_per_block = 15.8383; avg_num_integers_per_chunk = 3706
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 54.2092%
	sparse chunks with 235 blocks: 0.0420605%; avg_num_integers_per_block = 16.3055; avg_num_integers_per_chunk = 3831
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 55.0608%
	sparse chunks with 236 blocks: 0.042763%; avg_num_integers_per_block = 16.7595; avg_num_integers_per_chunk = 3955
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 55.9545%
	sparse chunks with 237 blocks: 0.0431361%; avg_num_integers_per_block = 17.4077; avg_num_integers_per_chunk = 4125
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 56.8948%
	sparse chunks with 238 blocks: 0.0444584%; avg_num_integers_per_block = 17.9017; avg_num_integers_per_chunk = 4260
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 57.8957%
	sparse chunks with 239 blocks: 0.0454794%; avg_num_integers_per_block = 18.5796; avg_num_integers_per_chunk = 4440
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 58.9629%
	sparse chunks with 240 blocks: 0.0462865%; avg_num_integers_per_block = 19.1838; avg_num_integers_per_chunk = 4604
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 60.0889%
	sparse chunks with 241 blocks: 0.0477634%; avg_num_integers_per_block = 20.0773; avg_num_integers_per_chunk = 4838
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 61.3101%
	sparse chunks with 242 blocks: 0.0490185%; avg_num_integers_per_block = 20.509; avg_num_integers_per_chunk = 4963
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 62.5956%
	sparse chunks with 243 blocks: 0.0500192%; avg_num_integers_per_block = 21.3793; avg_num_integers_per_chunk = 5195
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 63.9687%
	sparse chunks with 244 blocks: 0.0513774%; avg_num_integers_per_block = 22.1922; avg_num_integers_per_chunk = 5414
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 65.4388%
	sparse chunks with 245 blocks: 0.0535755%; avg_num_integers_per_block = 22.7445; avg_num_integers_per_chunk = 5572
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 67.0163%
	sparse chunks with 246 blocks: 0.055004%; avg_num_integers_per_block = 23.9396; avg_num_integers_per_chunk = 5889
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 68.7279%
	sparse chunks with 247 blocks: 0.0575814%; avg_num_integers_per_block = 25.0112; avg_num_integers_per_chunk = 6177
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 70.6075%
	sparse chunks with 248 blocks: 0.0589443%; avg_num_integers_per_block = 25.8931; avg_num_integers_per_chunk = 6421
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 72.6076%
	sparse chunks with 249 blocks: 0.0611861%; avg_num_integers_per_block = 27.1668; avg_num_integers_per_chunk = 6764
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 74.7946%
	sparse chunks with 250 blocks: 0.0650109%; avg_num_integers_per_block = 28.4799; avg_num_integers_per_chunk = 7119
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 77.2405%
	sparse chunks with 251 blocks: 0.0671044%; avg_num_integers_per_block = 29.7594; avg_num_integers_per_chunk = 7469
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 79.8891%
	sparse chunks with 252 blocks: 0.0719268%; avg_num_integers_per_block = 31.2609; avg_num_integers_per_chunk = 7877
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 82.8831%
	sparse chunks with 253 blocks: 0.0761091%; avg_num_integers_per_block = 32.3278; avg_num_integers_per_chunk = 8178
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 86.1723%
	sparse chunks with 254 blocks: 0.0832092%; avg_num_integers_per_block = 33.5485; avg_num_integers_per_chunk = 8521
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 89.919%
	sparse chunks with 255 blocks: 0.0885421%; avg_num_integers_per_block = 34.4655; avg_num_integers_per_chunk = 8788
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 94.0309%
	sparse chunks with 256 blocks: 0.124239%; avg_num_integers_per_block = 35.5181; avg_num_integers_per_chunk = 9092
	Elias-Fano avg. bpi 5 vs. 8
	 -- total integers covered 100%
	expected_value 24.8392


### CCNEWS

	./build /data/pibiri/inverted_indexes/ccnews/ccnews.docs --size 4096

	universe size: 43530315
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
	== sparse blocks cardinalities (%) ==
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
	== distribution of blocks in sparse chunks (64.9521% of ints) ==
	sparse chunks with 1 blocks: 1.60782%; avg_num_integers_per_block = 1.77792; avg_num_integers_per_chunk = 1
	Elias-Fano avg. bpi 18 vs. 8
	 -- total integers covered 0.0111377%
	sparse chunks with 2 blocks: 2.18452%; avg_num_integers_per_block = 1.67549; avg_num_integers_per_chunk = 3
	Elias-Fano avg. bpi 17 vs. 8
	 -- total integers covered 0.0396593%
	sparse chunks with 3 blocks: 2.80325%; avg_num_integers_per_block = 1.49778; avg_num_integers_per_chunk = 4
	Elias-Fano avg. bpi 16 vs. 8
	 -- total integers covered 0.088736%
	sparse chunks with 4 blocks: 3.35123%; avg_num_integers_per_block = 1.40301; avg_num_integers_per_chunk = 5
	Elias-Fano avg. bpi 16 vs. 8
	 -- total integers covered 0.162013%
	sparse chunks with 5 blocks: 3.75659%; avg_num_integers_per_block = 1.34285; avg_num_integers_per_chunk = 6
	Elias-Fano avg. bpi 16 vs. 8
	 -- total integers covered 0.260287%
	sparse chunks with 6 blocks: 3.96242%; avg_num_integers_per_block = 1.3059; avg_num_integers_per_chunk = 7
	Elias-Fano avg. bpi 16 vs. 8
	 -- total integers covered 0.381253%
	sparse chunks with 7 blocks: 3.97046%; avg_num_integers_per_block = 1.28467; avg_num_integers_per_chunk = 8
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 0.520369%
	sparse chunks with 8 blocks: 3.82272%; avg_num_integers_per_block = 1.27508; avg_num_integers_per_chunk = 10
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 0.672299%
	sparse chunks with 9 blocks: 3.58141%; avg_num_integers_per_block = 1.28418; avg_num_integers_per_chunk = 11
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 0.833573%
	sparse chunks with 10 blocks: 3.29244%; avg_num_integers_per_block = 1.28383; avg_num_integers_per_chunk = 12
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 0.998265%
	sparse chunks with 11 blocks: 2.99723%; avg_num_integers_per_block = 1.28145; avg_num_integers_per_chunk = 14
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 1.16288%
	sparse chunks with 12 blocks: 2.71094%; avg_num_integers_per_block = 1.29407; avg_num_integers_per_chunk = 15
	Elias-Fano avg. bpi 15 vs. 8
	 -- total integers covered 1.3269%
	sparse chunks with 13 blocks: 2.45087%; avg_num_integers_per_block = 1.29739; avg_num_integers_per_chunk = 16
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 1.48795%
	sparse chunks with 14 blocks: 2.21807%; avg_num_integers_per_block = 1.29818; avg_num_integers_per_chunk = 18
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 1.64502%
	sparse chunks with 15 blocks: 2.02742%; avg_num_integers_per_block = 1.31838; avg_num_integers_per_chunk = 19
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 1.80123%
	sparse chunks with 16 blocks: 1.84684%; avg_num_integers_per_block = 1.31456; avg_num_integers_per_chunk = 21
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 1.95258%
	sparse chunks with 17 blocks: 1.7024%; avg_num_integers_per_block = 1.32809; avg_num_integers_per_chunk = 22
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.10234%
	sparse chunks with 18 blocks: 1.5608%; avg_num_integers_per_block = 1.32439; avg_num_integers_per_chunk = 23
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.24731%
	sparse chunks with 19 blocks: 1.44135%; avg_num_integers_per_block = 1.33208; avg_num_integers_per_chunk = 25
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.38944%
	sparse chunks with 20 blocks: 1.34445%; avg_num_integers_per_block = 1.34959; avg_num_integers_per_chunk = 26
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.53083%
	sparse chunks with 21 blocks: 1.24709%; avg_num_integers_per_block = 1.34949; avg_num_integers_per_chunk = 28
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.66853%
	sparse chunks with 22 blocks: 1.16607%; avg_num_integers_per_block = 1.34814; avg_num_integers_per_chunk = 29
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.80328%
	sparse chunks with 23 blocks: 1.09497%; avg_num_integers_per_block = 1.35976; avg_num_integers_per_chunk = 31
	Elias-Fano avg. bpi 14 vs. 8
	 -- total integers covered 2.93671%
	sparse chunks with 24 blocks: 1.02456%; avg_num_integers_per_block = 1.35471; avg_num_integers_per_chunk = 32
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.0665%
	sparse chunks with 25 blocks: 0.970191%; avg_num_integers_per_block = 1.36777; avg_num_integers_per_chunk = 34
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.19575%
	sparse chunks with 26 blocks: 0.914834%; avg_num_integers_per_block = 1.38583; avg_num_integers_per_chunk = 36
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.32418%
	sparse chunks with 27 blocks: 0.862387%; avg_num_integers_per_block = 1.37688; avg_num_integers_per_chunk = 37
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.4491%
	sparse chunks with 28 blocks: 0.816446%; avg_num_integers_per_block = 1.39436; avg_num_integers_per_chunk = 39
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.57329%
	sparse chunks with 29 blocks: 0.778722%; avg_num_integers_per_block = 1.38882; avg_num_integers_per_chunk = 40
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.69549%
	sparse chunks with 30 blocks: 0.739437%; avg_num_integers_per_block = 1.4002; avg_num_integers_per_chunk = 42
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.81651%
	sparse chunks with 31 blocks: 0.707436%; avg_num_integers_per_block = 1.41871; avg_num_integers_per_chunk = 43
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 3.93774%
	sparse chunks with 32 blocks: 0.675538%; avg_num_integers_per_block = 1.44911; avg_num_integers_per_chunk = 46
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.05979%
	sparse chunks with 33 blocks: 0.642325%; avg_num_integers_per_block = 1.4465; avg_num_integers_per_chunk = 47
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.17925%
	sparse chunks with 34 blocks: 0.618094%; avg_num_integers_per_block = 1.43811; avg_num_integers_per_chunk = 48
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.297%
	sparse chunks with 35 blocks: 0.591251%; avg_num_integers_per_block = 1.44092; avg_num_integers_per_chunk = 50
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.41318%
	sparse chunks with 36 blocks: 0.569825%; avg_num_integers_per_block = 1.45353; avg_num_integers_per_chunk = 52
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.52936%
	sparse chunks with 37 blocks: 0.54773%; avg_num_integers_per_block = 1.45354; avg_num_integers_per_chunk = 53
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.64413%
	sparse chunks with 38 blocks: 0.529188%; avg_num_integers_per_block = 1.48861; avg_num_integers_per_chunk = 56
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.76076%
	sparse chunks with 39 blocks: 0.509055%; avg_num_integers_per_block = 1.47783; avg_num_integers_per_chunk = 57
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.87508%
	sparse chunks with 40 blocks: 0.491315%; avg_num_integers_per_block = 1.47796; avg_num_integers_per_chunk = 59
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 4.98825%
	sparse chunks with 41 blocks: 0.474586%; avg_num_integers_per_block = 1.48208; avg_num_integers_per_chunk = 60
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 5.10061%
	sparse chunks with 42 blocks: 0.458111%; avg_num_integers_per_block = 1.48091; avg_num_integers_per_chunk = 62
	Elias-Fano avg. bpi 13 vs. 8
	 -- total integers covered 5.21162%
	sparse chunks with 43 blocks: 0.444282%; avg_num_integers_per_block = 1.513; avg_num_integers_per_chunk = 65
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.32424%
	sparse chunks with 44 blocks: 0.427653%; avg_num_integers_per_block = 1.49363; avg_num_integers_per_chunk = 65
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.43375%
	sparse chunks with 45 blocks: 0.41491%; avg_num_integers_per_block = 1.49801; avg_num_integers_per_chunk = 67
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.54272%
	sparse chunks with 46 blocks: 0.402058%; avg_num_integers_per_block = 1.5019; avg_num_integers_per_chunk = 69
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.65095%
	sparse chunks with 47 blocks: 0.393308%; avg_num_integers_per_block = 1.52878; avg_num_integers_per_chunk = 71
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.76106%
	sparse chunks with 48 blocks: 0.381539%; avg_num_integers_per_block = 1.53208; avg_num_integers_per_chunk = 73
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.87038%
	sparse chunks with 49 blocks: 0.372298%; avg_num_integers_per_block = 1.53328; avg_num_integers_per_chunk = 75
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 5.97936%
	sparse chunks with 50 blocks: 0.35959%; avg_num_integers_per_block = 1.53108; avg_num_integers_per_chunk = 76
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.08662%
	sparse chunks with 51 blocks: 0.351926%; avg_num_integers_per_block = 1.54856; avg_num_integers_per_chunk = 78
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.19491%
	sparse chunks with 52 blocks: 0.342585%; avg_num_integers_per_block = 1.57347; avg_num_integers_per_chunk = 81
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.30412%
	sparse chunks with 53 blocks: 0.333461%; avg_num_integers_per_block = 1.55167; avg_num_integers_per_chunk = 82
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.41097%
	sparse chunks with 54 blocks: 0.323798%; avg_num_integers_per_block = 1.56141; avg_num_integers_per_chunk = 84
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.51734%
	sparse chunks with 55 blocks: 0.317658%; avg_num_integers_per_block = 1.56621; avg_num_integers_per_chunk = 86
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.62396%
	sparse chunks with 56 blocks: 0.309328%; avg_num_integers_per_block = 1.58729; avg_num_integers_per_chunk = 88
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.73108%
	sparse chunks with 57 blocks: 0.309286%; avg_num_integers_per_block = 2.03701; avg_num_integers_per_chunk = 116
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.871%
	sparse chunks with 58 blocks: 0.294721%; avg_num_integers_per_block = 1.5986; avg_num_integers_per_chunk = 92
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 6.97747%
	sparse chunks with 59 blocks: 0.289685%; avg_num_integers_per_block = 1.57921; avg_num_integers_per_chunk = 93
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.08263%
	sparse chunks with 60 blocks: 0.282021%; avg_num_integers_per_block = 1.58568; avg_num_integers_per_chunk = 95
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.18718%
	sparse chunks with 61 blocks: 0.277584%; avg_num_integers_per_block = 1.59579; avg_num_integers_per_chunk = 97
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.29246%
	sparse chunks with 62 blocks: 0.271594%; avg_num_integers_per_block = 1.60757; avg_num_integers_per_chunk = 99
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.39793%
	sparse chunks with 63 blocks: 0.266068%; avg_num_integers_per_block = 1.62401; avg_num_integers_per_chunk = 102
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.50399%
	sparse chunks with 64 blocks: 0.260664%; avg_num_integers_per_block = 1.6245; avg_num_integers_per_chunk = 103
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.60958%
	sparse chunks with 65 blocks: 0.254774%; avg_num_integers_per_block = 1.62263; avg_num_integers_per_chunk = 105
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.71428%
	sparse chunks with 66 blocks: 0.250955%; avg_num_integers_per_block = 1.62644; avg_num_integers_per_chunk = 107
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.81924%
	sparse chunks with 67 blocks: 0.245333%; avg_num_integers_per_block = 1.6448; avg_num_integers_per_chunk = 110
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 7.92457%
	sparse chunks with 68 blocks: 0.241486%; avg_num_integers_per_block = 1.64191; avg_num_integers_per_chunk = 111
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.02962%
	sparse chunks with 69 blocks: 0.23607%; avg_num_integers_per_block = 1.63236; avg_num_integers_per_chunk = 112
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.13322%
	sparse chunks with 70 blocks: 0.230882%; avg_num_integers_per_block = 1.64312; avg_num_integers_per_chunk = 115
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.23669%
	sparse chunks with 71 blocks: 0.227547%; avg_num_integers_per_block = 1.64278; avg_num_integers_per_chunk = 116
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.3401%
	sparse chunks with 72 blocks: 0.223213%; avg_num_integers_per_block = 1.65331; avg_num_integers_per_chunk = 119
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.44362%
	sparse chunks with 73 blocks: 0.219258%; avg_num_integers_per_block = 1.67315; avg_num_integers_per_chunk = 122
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.54797%
	sparse chunks with 74 blocks: 0.215666%; avg_num_integers_per_block = 1.66794; avg_num_integers_per_chunk = 123
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.65168%
	sparse chunks with 75 blocks: 0.211486%; avg_num_integers_per_block = 1.67909; avg_num_integers_per_chunk = 125
	Elias-Fano avg. bpi 12 vs. 8
	 -- total integers covered 8.75545%
	sparse chunks with 76 blocks: 0.207749%; avg_num_integers_per_block = 1.68422; avg_num_integers_per_chunk = 128
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 8.85906%
	sparse chunks with 77 blocks: 0.204342%; avg_num_integers_per_block = 1.70189; avg_num_integers_per_chunk = 131
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 8.96339%
	sparse chunks with 78 blocks: 0.200555%; avg_num_integers_per_block = 1.72071; avg_num_integers_per_chunk = 134
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.06827%
	sparse chunks with 79 blocks: 0.195613%; avg_num_integers_per_block = 1.71615; avg_num_integers_per_chunk = 135
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.1716%
	sparse chunks with 80 blocks: 0.192286%; avg_num_integers_per_block = 1.7239; avg_num_integers_per_chunk = 137
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.27492%
	sparse chunks with 81 blocks: 0.190018%; avg_num_integers_per_block = 1.72579; avg_num_integers_per_chunk = 139
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.37841%
	sparse chunks with 82 blocks: 0.186615%; avg_num_integers_per_block = 1.72775; avg_num_integers_per_chunk = 141
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.48142%
	sparse chunks with 83 blocks: 0.1841%; avg_num_integers_per_block = 1.73573; avg_num_integers_per_chunk = 144
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.58476%
	sparse chunks with 84 blocks: 0.181%; avg_num_integers_per_block = 1.75195; avg_num_integers_per_chunk = 147
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.68854%
	sparse chunks with 85 blocks: 0.176908%; avg_num_integers_per_block = 1.75634; avg_num_integers_per_chunk = 149
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.79144%
	sparse chunks with 86 blocks: 0.174504%; avg_num_integers_per_block = 1.7746; avg_num_integers_per_chunk = 152
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.89521%
	sparse chunks with 87 blocks: 0.171364%; avg_num_integers_per_block = 1.78827; avg_num_integers_per_chunk = 155
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 9.99909%
	sparse chunks with 88 blocks: 0.168637%; avg_num_integers_per_block = 1.77551; avg_num_integers_per_chunk = 156
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.1017%
	sparse chunks with 89 blocks: 0.166271%; avg_num_integers_per_block = 1.77807; avg_num_integers_per_chunk = 158
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.2043%
	sparse chunks with 90 blocks: 0.163748%; avg_num_integers_per_block = 1.8038; avg_num_integers_per_chunk = 162
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.3078%
	sparse chunks with 91 blocks: 0.16117%; avg_num_integers_per_block = 1.7981; avg_num_integers_per_chunk = 163
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.4106%
	sparse chunks with 92 blocks: 0.159263%; avg_num_integers_per_block = 1.81268; avg_num_integers_per_chunk = 166
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.5141%
	sparse chunks with 93 blocks: 0.156436%; avg_num_integers_per_block = 1.81804; avg_num_integers_per_chunk = 169
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.6171%
	sparse chunks with 94 blocks: 0.15529%; avg_num_integers_per_block = 1.82162; avg_num_integers_per_chunk = 171
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.7207%
	sparse chunks with 95 blocks: 0.151293%; avg_num_integers_per_block = 1.84754; avg_num_integers_per_chunk = 175
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.8242%
	sparse chunks with 96 blocks: 0.14994%; avg_num_integers_per_block = 1.83948; avg_num_integers_per_chunk = 176
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 10.9274%
	sparse chunks with 97 blocks: 0.147789%; avg_num_integers_per_block = 1.83376; avg_num_integers_per_chunk = 177
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.0298%
	sparse chunks with 98 blocks: 0.146362%; avg_num_integers_per_block = 1.85308; avg_num_integers_per_chunk = 181
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.1333%
	sparse chunks with 99 blocks: 0.14519%; avg_num_integers_per_block = 1.88647; avg_num_integers_per_chunk = 186
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.239%
	sparse chunks with 100 blocks: 0.143539%; avg_num_integers_per_block = 1.88383; avg_num_integers_per_chunk = 188
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.3443%
	sparse chunks with 101 blocks: 0.142204%; avg_num_integers_per_block = 1.88935; avg_num_integers_per_chunk = 190
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.4501%
	sparse chunks with 102 blocks: 0.140952%; avg_num_integers_per_block = 1.9037; avg_num_integers_per_chunk = 194
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.5567%
	sparse chunks with 103 blocks: 0.13784%; avg_num_integers_per_block = 1.89766; avg_num_integers_per_chunk = 195
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.6617%
	sparse chunks with 104 blocks: 0.136899%; avg_num_integers_per_block = 1.91717; avg_num_integers_per_chunk = 199
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.768%
	sparse chunks with 105 blocks: 0.136064%; avg_num_integers_per_block = 1.93918; avg_num_integers_per_chunk = 203
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.876%
	sparse chunks with 106 blocks: 0.133237%; avg_num_integers_per_block = 1.91741; avg_num_integers_per_chunk = 203
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 11.9815%
	sparse chunks with 107 blocks: 0.131071%; avg_num_integers_per_block = 1.94077; avg_num_integers_per_chunk = 207
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.0875%
	sparse chunks with 108 blocks: 0.129354%; avg_num_integers_per_block = 1.96051; avg_num_integers_per_chunk = 211
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.1942%
	sparse chunks with 109 blocks: 0.127552%; avg_num_integers_per_block = 1.9512; avg_num_integers_per_chunk = 212
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.2999%
	sparse chunks with 110 blocks: 0.126757%; avg_num_integers_per_block = 1.95386; avg_num_integers_per_chunk = 214
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.4061%
	sparse chunks with 111 blocks: 0.124523%; avg_num_integers_per_block = 1.97151; avg_num_integers_per_chunk = 218
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.5123%
	sparse chunks with 112 blocks: 0.12411%; avg_num_integers_per_block = 1.98742; avg_num_integers_per_chunk = 222
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.6199%
	sparse chunks with 113 blocks: 0.122736%; avg_num_integers_per_block = 2.00817; avg_num_integers_per_chunk = 226
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.7284%
	sparse chunks with 114 blocks: 0.120484%; avg_num_integers_per_block = 2.01974; avg_num_integers_per_chunk = 230
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.8365%
	sparse chunks with 115 blocks: 0.119368%; avg_num_integers_per_block = 2.01239; avg_num_integers_per_chunk = 231
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 12.9441%
	sparse chunks with 116 blocks: 0.118684%; avg_num_integers_per_block = 2.01774; avg_num_integers_per_chunk = 234
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.0524%
	sparse chunks with 117 blocks: 0.116605%; avg_num_integers_per_block = 2.04214; avg_num_integers_per_chunk = 238
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.1609%
	sparse chunks with 118 blocks: 0.116352%; avg_num_integers_per_block = 2.05148; avg_num_integers_per_chunk = 242
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.2707%
	sparse chunks with 119 blocks: 0.114952%; avg_num_integers_per_block = 2.07508; avg_num_integers_per_chunk = 246
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.3813%
	sparse chunks with 120 blocks: 0.113551%; avg_num_integers_per_block = 2.05353; avg_num_integers_per_chunk = 246
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.4903%
	sparse chunks with 121 blocks: 0.113687%; avg_num_integers_per_block = 2.0951; avg_num_integers_per_chunk = 253
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.6026%
	sparse chunks with 122 blocks: 0.112214%; avg_num_integers_per_block = 2.07822; avg_num_integers_per_chunk = 253
	Elias-Fano avg. bpi 11 vs. 8
	 -- total integers covered 13.7134%
	sparse chunks with 123 blocks: 0.110717%; avg_num_integers_per_block = 2.10608; avg_num_integers_per_chunk = 259
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 13.8252%
	sparse chunks with 124 blocks: 0.108897%; avg_num_integers_per_block = 2.10861; avg_num_integers_per_chunk = 261
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 13.9361%
	sparse chunks with 125 blocks: 0.109832%; avg_num_integers_per_block = 2.12848; avg_num_integers_per_chunk = 266
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.05%
	sparse chunks with 126 blocks: 0.108317%; avg_num_integers_per_block = 2.13089; avg_num_integers_per_chunk = 268
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.1633%
	sparse chunks with 127 blocks: 0.106638%; avg_num_integers_per_block = 2.1401; avg_num_integers_per_chunk = 271
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.2762%
	sparse chunks with 128 blocks: 0.104262%; avg_num_integers_per_block = 2.13509; avg_num_integers_per_chunk = 273
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.3872%
	sparse chunks with 129 blocks: 0.104822%; avg_num_integers_per_block = 2.16145; avg_num_integers_per_chunk = 278
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.5011%
	sparse chunks with 130 blocks: 0.104338%; avg_num_integers_per_block = 2.15561; avg_num_integers_per_chunk = 280
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.615%
	sparse chunks with 131 blocks: 0.101826%; avg_num_integers_per_block = 2.17906; avg_num_integers_per_chunk = 285
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.7283%
	sparse chunks with 132 blocks: 0.102444%; avg_num_integers_per_block = 2.20223; avg_num_integers_per_chunk = 290
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.8443%
	sparse chunks with 133 blocks: 0.10061%; avg_num_integers_per_block = 2.18969; avg_num_integers_per_chunk = 291
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 14.9585%
	sparse chunks with 134 blocks: 0.0997488%; avg_num_integers_per_block = 2.20566; avg_num_integers_per_chunk = 295
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.0733%
	sparse chunks with 135 blocks: 0.099811%; avg_num_integers_per_block = 2.22956; avg_num_integers_per_chunk = 300
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.1904%
	sparse chunks with 136 blocks: 0.0982599%; avg_num_integers_per_block = 2.24726; avg_num_integers_per_chunk = 305
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.3074%
	sparse chunks with 137 blocks: 0.0981977%; avg_num_integers_per_block = 2.25706; avg_num_integers_per_chunk = 309
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.4257%
	sparse chunks with 138 blocks: 0.0968793%; avg_num_integers_per_block = 2.27015; avg_num_integers_per_chunk = 313
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.5439%
	sparse chunks with 139 blocks: 0.0957575%; avg_num_integers_per_block = 2.27128; avg_num_integers_per_chunk = 315
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.6617%
	sparse chunks with 140 blocks: 0.0952639%; avg_num_integers_per_block = 2.27609; avg_num_integers_per_chunk = 318
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.78%
	sparse chunks with 141 blocks: 0.0944772%; avg_num_integers_per_block = 2.29857; avg_num_integers_per_chunk = 324
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 15.8993%
	sparse chunks with 142 blocks: 0.0943849%; avg_num_integers_per_block = 2.30701; avg_num_integers_per_chunk = 327
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.0198%
	sparse chunks with 143 blocks: 0.0925889%; avg_num_integers_per_block = 2.32534; avg_num_integers_per_chunk = 332
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.1397%
	sparse chunks with 144 blocks: 0.0928578%; avg_num_integers_per_block = 2.36337; avg_num_integers_per_chunk = 340
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.2629%
	sparse chunks with 145 blocks: 0.0910719%; avg_num_integers_per_block = 2.3555; avg_num_integers_per_chunk = 341
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.3841%
	sparse chunks with 146 blocks: 0.0907327%; avg_num_integers_per_block = 2.36864; avg_num_integers_per_chunk = 345
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.5063%
	sparse chunks with 147 blocks: 0.0907026%; avg_num_integers_per_block = 2.39441; avg_num_integers_per_chunk = 351
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.6307%
	sparse chunks with 148 blocks: 0.088999%; avg_num_integers_per_block = 2.4042; avg_num_integers_per_chunk = 355
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.7541%
	sparse chunks with 149 blocks: 0.0882846%; avg_num_integers_per_block = 2.4049; avg_num_integers_per_chunk = 358
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 16.8773%
	sparse chunks with 150 blocks: 0.0881642%; avg_num_integers_per_block = 2.44343; avg_num_integers_per_chunk = 366
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.0032%
	sparse chunks with 151 blocks: 0.0875842%; avg_num_integers_per_block = 2.44699; avg_num_integers_per_chunk = 369
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.1293%
	sparse chunks with 152 blocks: 0.0858605%; avg_num_integers_per_block = 2.45014; avg_num_integers_per_chunk = 372
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.2539%
	sparse chunks with 153 blocks: 0.0860571%; avg_num_integers_per_block = 2.50263; avg_num_integers_per_chunk = 382
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.3823%
	sparse chunks with 154 blocks: 0.0853187%; avg_num_integers_per_block = 2.49118; avg_num_integers_per_chunk = 383
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.5098%
	sparse chunks with 155 blocks: 0.0852705%; avg_num_integers_per_block = 2.54311; avg_num_integers_per_chunk = 394
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.6408%
	sparse chunks with 156 blocks: 0.0843334%; avg_num_integers_per_block = 2.51778; avg_num_integers_per_chunk = 392
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.7699%
	sparse chunks with 157 blocks: 0.0846986%; avg_num_integers_per_block = 2.56229; avg_num_integers_per_chunk = 402
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 17.9026%
	sparse chunks with 158 blocks: 0.0831113%; avg_num_integers_per_block = 2.5625; avg_num_integers_per_chunk = 404
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.0337%
	sparse chunks with 159 blocks: 0.0828645%; avg_num_integers_per_block = 2.58337; avg_num_integers_per_chunk = 410
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.1663%
	sparse chunks with 160 blocks: 0.0827621%; avg_num_integers_per_block = 2.5961; avg_num_integers_per_chunk = 415
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.3003%
	sparse chunks with 161 blocks: 0.0824792%; avg_num_integers_per_block = 2.62516; avg_num_integers_per_chunk = 422
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.4361%
	sparse chunks with 162 blocks: 0.0815601%; avg_num_integers_per_block = 2.66817; avg_num_integers_per_chunk = 432
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.5735%
	sparse chunks with 163 blocks: 0.0807394%; avg_num_integers_per_block = 2.64203; avg_num_integers_per_chunk = 430
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.7089%
	sparse chunks with 164 blocks: 0.0818812%; avg_num_integers_per_block = 2.65462; avg_num_integers_per_chunk = 435
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.8478%
	sparse chunks with 165 blocks: 0.0805106%; avg_num_integers_per_block = 2.67697; avg_num_integers_per_chunk = 441
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 18.9864%
	sparse chunks with 166 blocks: 0.0799628%; avg_num_integers_per_block = 2.72368; avg_num_integers_per_chunk = 452
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.1272%
	sparse chunks with 167 blocks: 0.080322%; avg_num_integers_per_block = 2.70574; avg_num_integers_per_chunk = 451
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.2687%
	sparse chunks with 168 blocks: 0.0783575%; avg_num_integers_per_block = 2.75491; avg_num_integers_per_chunk = 462
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.41%
	sparse chunks with 169 blocks: 0.078809%; avg_num_integers_per_block = 2.75408; avg_num_integers_per_chunk = 465
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.5529%
	sparse chunks with 170 blocks: 0.0773421%; avg_num_integers_per_block = 2.77103; avg_num_integers_per_chunk = 471
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.6948%
	sparse chunks with 171 blocks: 0.0781427%; avg_num_integers_per_block = 2.78935; avg_num_integers_per_chunk = 476
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.84%
	sparse chunks with 172 blocks: 0.0789635%; avg_num_integers_per_block = 2.84837; avg_num_integers_per_chunk = 489
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 19.9908%
	sparse chunks with 173 blocks: 0.0780705%; avg_num_integers_per_block = 2.84392; avg_num_integers_per_chunk = 491
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.1404%
	sparse chunks with 174 blocks: 0.0765595%; avg_num_integers_per_block = 2.86902; avg_num_integers_per_chunk = 499
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.2893%
	sparse chunks with 175 blocks: 0.0782551%; avg_num_integers_per_block = 2.88528; avg_num_integers_per_chunk = 504
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.4433%
	sparse chunks with 176 blocks: 0.0763568%; avg_num_integers_per_block = 2.90411; avg_num_integers_per_chunk = 511
	Elias-Fano avg. bpi 10 vs. 8
	 -- total integers covered 20.5954%
	sparse chunks with 177 blocks: 0.0757969%; avg_num_integers_per_block = 2.93523; avg_num_integers_per_chunk = 519
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 20.7488%
	sparse chunks with 178 blocks: 0.0763427%; avg_num_integers_per_block = 2.94908; avg_num_integers_per_chunk = 524
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 20.9049%
	sparse chunks with 179 blocks: 0.0754096%; avg_num_integers_per_block = 2.94598; avg_num_integers_per_chunk = 527
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.0599%
	sparse chunks with 180 blocks: 0.0740952%; avg_num_integers_per_block = 3.00349; avg_num_integers_per_chunk = 540
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.2159%
	sparse chunks with 181 blocks: 0.0739688%; avg_num_integers_per_block = 3.01943; avg_num_integers_per_chunk = 546
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.3734%
	sparse chunks with 182 blocks: 0.0745869%; avg_num_integers_per_block = 3.03241; avg_num_integers_per_chunk = 551
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.5338%
	sparse chunks with 183 blocks: 0.0736317%; avg_num_integers_per_block = 3.04728; avg_num_integers_per_chunk = 557
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.6938%
	sparse chunks with 184 blocks: 0.0733507%; avg_num_integers_per_block = 3.07375; avg_num_integers_per_chunk = 565
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 21.8554%
	sparse chunks with 185 blocks: 0.0738484%; avg_num_integers_per_block = 3.11168; avg_num_integers_per_chunk = 575
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.0211%
	sparse chunks with 186 blocks: 0.0726524%; avg_num_integers_per_block = 3.15051; avg_num_integers_per_chunk = 585
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.187%
	sparse chunks with 187 blocks: 0.0736457%; avg_num_integers_per_block = 3.14308; avg_num_integers_per_chunk = 587
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.3556%
	sparse chunks with 188 blocks: 0.0730598%; avg_num_integers_per_block = 3.21294; avg_num_integers_per_chunk = 604
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.5276%
	sparse chunks with 189 blocks: 0.0724718%; avg_num_integers_per_block = 3.22362; avg_num_integers_per_chunk = 609
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.6996%
	sparse chunks with 190 blocks: 0.0732926%; avg_num_integers_per_block = 3.23631; avg_num_integers_per_chunk = 614
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 22.8752%
	sparse chunks with 191 blocks: 0.0729675%; avg_num_integers_per_block = 3.29176; avg_num_integers_per_chunk = 628
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.0539%
	sparse chunks with 192 blocks: 0.0720805%; avg_num_integers_per_block = 3.287; avg_num_integers_per_chunk = 631
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.2312%
	sparse chunks with 193 blocks: 0.0720604%; avg_num_integers_per_block = 3.34889; avg_num_integers_per_chunk = 646
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.4126%
	sparse chunks with 194 blocks: 0.0723474%; avg_num_integers_per_block = 3.35425; avg_num_integers_per_chunk = 650
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.5961%
	sparse chunks with 195 blocks: 0.0724798%; avg_num_integers_per_block = 3.39928; avg_num_integers_per_chunk = 662
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.7833%
	sparse chunks with 196 blocks: 0.0721006%; avg_num_integers_per_block = 3.45567; avg_num_integers_per_chunk = 677
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 23.9735%
	sparse chunks with 197 blocks: 0.0727688%; avg_num_integers_per_block = 3.50842; avg_num_integers_per_chunk = 691
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.1695%
	sparse chunks with 198 blocks: 0.0734671%; avg_num_integers_per_block = 3.53219; avg_num_integers_per_chunk = 699
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.3697%
	sparse chunks with 199 blocks: 0.0735113%; avg_num_integers_per_block = 3.51133; avg_num_integers_per_chunk = 698
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.5698%
	sparse chunks with 200 blocks: 0.073116%; avg_num_integers_per_block = 3.64708; avg_num_integers_per_chunk = 729
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.7776%
	sparse chunks with 201 blocks: 0.0733066%; avg_num_integers_per_block = 3.65843; avg_num_integers_per_chunk = 735
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 24.9876%
	sparse chunks with 202 blocks: 0.0727849%; avg_num_integers_per_block = 3.63771; avg_num_integers_per_chunk = 734
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.196%
	sparse chunks with 203 blocks: 0.0730036%; avg_num_integers_per_block = 3.68494; avg_num_integers_per_chunk = 748
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.4088%
	sparse chunks with 204 blocks: 0.0730257%; avg_num_integers_per_block = 3.75956; avg_num_integers_per_chunk = 766
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.627%
	sparse chunks with 205 blocks: 0.0732023%; avg_num_integers_per_block = 3.80686; avg_num_integers_per_chunk = 780
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 25.8496%
	sparse chunks with 206 blocks: 0.0741093%; avg_num_integers_per_block = 3.84767; avg_num_integers_per_chunk = 792
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.0785%
	sparse chunks with 207 blocks: 0.0736638%; avg_num_integers_per_block = 3.88419; avg_num_integers_per_chunk = 804
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.3092%
	sparse chunks with 208 blocks: 0.0741755%; avg_num_integers_per_block = 3.93488; avg_num_integers_per_chunk = 818
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.5458%
	sparse chunks with 209 blocks: 0.0742698%; avg_num_integers_per_block = 3.95262; avg_num_integers_per_chunk = 826
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 26.7848%
	sparse chunks with 210 blocks: 0.0754477%; avg_num_integers_per_block = 4.05115; avg_num_integers_per_chunk = 850
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.0349%
	sparse chunks with 211 blocks: 0.0752732%; avg_num_integers_per_block = 4.06596; avg_num_integers_per_chunk = 857
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.2865%
	sparse chunks with 212 blocks: 0.0756504%; avg_num_integers_per_block = 4.14932; avg_num_integers_per_chunk = 879
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.5458%
	sparse chunks with 213 blocks: 0.0753795%; avg_num_integers_per_block = 4.22715; avg_num_integers_per_chunk = 900
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 27.8102%
	sparse chunks with 214 blocks: 0.0764692%; avg_num_integers_per_block = 4.33756; avg_num_integers_per_chunk = 928
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.0868%
	sparse chunks with 215 blocks: 0.0765815%; avg_num_integers_per_block = 4.34091; avg_num_integers_per_chunk = 933
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.3653%
	sparse chunks with 216 blocks: 0.0775307%; avg_num_integers_per_block = 4.40587; avg_num_integers_per_chunk = 951
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.6527%
	sparse chunks with 217 blocks: 0.077322%; avg_num_integers_per_block = 4.47675; avg_num_integers_per_chunk = 971
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 28.9454%
	sparse chunks with 218 blocks: 0.0785461%; avg_num_integers_per_block = 4.50094; avg_num_integers_per_chunk = 981
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 29.2457%
	sparse chunks with 219 blocks: 0.0786946%; avg_num_integers_per_block = 4.62525; avg_num_integers_per_chunk = 1012
	Elias-Fano avg. bpi 9 vs. 8
	 -- total integers covered 29.5563%
	sparse chunks with 220 blocks: 0.0789896%; avg_num_integers_per_block = 4.66317; avg_num_integers_per_chunk = 1025
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 29.872%
	sparse chunks with 221 blocks: 0.07972%; avg_num_integers_per_block = 4.73489; avg_num_integers_per_chunk = 1046
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 30.197%
	sparse chunks with 222 blocks: 0.0805488%; avg_num_integers_per_block = 4.86091; avg_num_integers_per_chunk = 1079
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 30.5357%
	sparse chunks with 223 blocks: 0.0810023%; avg_num_integers_per_block = 4.90105; avg_num_integers_per_chunk = 1092
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 30.8806%
	sparse chunks with 224 blocks: 0.0828224%; avg_num_integers_per_block = 5.04146; avg_num_integers_per_chunk = 1129
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.245%
	sparse chunks with 225 blocks: 0.083013%; avg_num_integers_per_block = 5.15591; avg_num_integers_per_chunk = 1160
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 31.6202%
	sparse chunks with 226 blocks: 0.0845722%; avg_num_integers_per_block = 5.22383; avg_num_integers_per_chunk = 1180
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.0093%
	sparse chunks with 227 blocks: 0.085118%; avg_num_integers_per_block = 5.39089; avg_num_integers_per_chunk = 1223
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.4151%
	sparse chunks with 228 blocks: 0.0870244%; avg_num_integers_per_block = 5.5196; avg_num_integers_per_chunk = 1258
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 32.8418%
	sparse chunks with 229 blocks: 0.0875862%; avg_num_integers_per_block = 5.67595; avg_num_integers_per_chunk = 1299
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.2854%
	sparse chunks with 230 blocks: 0.0884431%; avg_num_integers_per_block = 5.74584; avg_num_integers_per_chunk = 1321
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 33.7408%
	sparse chunks with 231 blocks: 0.0909816%; avg_num_integers_per_block = 5.88037; avg_num_integers_per_chunk = 1358
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.2223%
	sparse chunks with 232 blocks: 0.0912986%; avg_num_integers_per_block = 6.03167; avg_num_integers_per_chunk = 1399
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 34.7201%
	sparse chunks with 233 blocks: 0.0931307%; avg_num_integers_per_block = 6.15711; avg_num_integers_per_chunk = 1434
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.2406%
	sparse chunks with 234 blocks: 0.0949107%; avg_num_integers_per_block = 6.35058; avg_num_integers_per_chunk = 1486
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 35.7901%
	sparse chunks with 235 blocks: 0.0959702%; avg_num_integers_per_block = 6.53279; avg_num_integers_per_chunk = 1535
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 36.3642%
	sparse chunks with 236 blocks: 0.098294%; avg_num_integers_per_block = 6.76082; avg_num_integers_per_chunk = 1595
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 36.9753%
	sparse chunks with 237 blocks: 0.102046%; avg_num_integers_per_block = 6.91264; avg_num_integers_per_chunk = 1638
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 37.6266%
	sparse chunks with 238 blocks: 0.104274%; avg_num_integers_per_block = 7.17338; avg_num_integers_per_chunk = 1707
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 38.3203%
	sparse chunks with 239 blocks: 0.106762%; avg_num_integers_per_block = 7.48697; avg_num_integers_per_chunk = 1789
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 39.0646%
	sparse chunks with 240 blocks: 0.111424%; avg_num_integers_per_block = 7.7775; avg_num_integers_per_chunk = 1866
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 39.8749%
	sparse chunks with 241 blocks: 0.113463%; avg_num_integers_per_block = 8.06199; avg_num_integers_per_chunk = 1942
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 40.7339%
	sparse chunks with 242 blocks: 0.11867%; avg_num_integers_per_block = 8.38389; avg_num_integers_per_chunk = 2028
	Elias-Fano avg. bpi 8 vs. 8
	 -- total integers covered 41.672%
	sparse chunks with 243 blocks: 0.123745%; avg_num_integers_per_block = 8.80267; avg_num_integers_per_chunk = 2139
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 42.7033%
	sparse chunks with 244 blocks: 0.127997%; avg_num_integers_per_block = 9.15584; avg_num_integers_per_chunk = 2234
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 43.8174%
	sparse chunks with 245 blocks: 0.134425%; avg_num_integers_per_block = 9.68411; avg_num_integers_per_chunk = 2372
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 45.0601%
	sparse chunks with 246 blocks: 0.142219%; avg_num_integers_per_block = 10.1846; avg_num_integers_per_chunk = 2505
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 46.4483%
	sparse chunks with 247 blocks: 0.150336%; avg_num_integers_per_block = 10.7796; avg_num_integers_per_chunk = 2662
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 48.0079%
	sparse chunks with 248 blocks: 0.161633%; avg_num_integers_per_block = 11.3539; avg_num_integers_per_chunk = 2815
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 49.7812%
	sparse chunks with 249 blocks: 0.174165%; avg_num_integers_per_block = 12.1477; avg_num_integers_per_chunk = 3024
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 51.8338%
	sparse chunks with 250 blocks: 0.190112%; avg_num_integers_per_block = 12.9308; avg_num_integers_per_chunk = 3232
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 54.2283%
	sparse chunks with 251 blocks: 0.209963%; avg_num_integers_per_block = 13.7849; avg_num_integers_per_chunk = 3459
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 57.0588%
	sparse chunks with 252 blocks: 0.237488%; avg_num_integers_per_block = 14.9371; avg_num_integers_per_chunk = 3764
	Elias-Fano avg. bpi 7 vs. 8
	 -- total integers covered 60.5418%
	sparse chunks with 253 blocks: 0.276669%; avg_num_integers_per_block = 16.2217; avg_num_integers_per_chunk = 4104
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 64.9659%
	sparse chunks with 254 blocks: 0.336942%; avg_num_integers_per_block = 17.6199; avg_num_integers_per_chunk = 4475
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 70.8412%
	sparse chunks with 255 blocks: 0.446863%; avg_num_integers_per_block = 19.1829; avg_num_integers_per_chunk = 4891
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 79.358%
	sparse chunks with 256 blocks: 0.996577%; avg_num_integers_per_block = 20.7662; avg_num_integers_per_chunk = 5316
	Elias-Fano avg. bpi 6 vs. 8
	 -- total integers covered 100%
	expected_value 50.1083
