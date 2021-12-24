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
	== distribution of blocks in sparse chunks ==
	sparse chunks with 1 blocks: 8.43082%; avg_num_integers_per_block = 1.87869
	sparse chunks with 2 blocks: 6.50792%; avg_num_integers_per_block = 2.38464
	sparse chunks with 3 blocks: 5.3986%; avg_num_integers_per_block = 2.40731
	sparse chunks with 4 blocks: 4.75217%; avg_num_integers_per_block = 2.65841
	sparse chunks with 5 blocks: 4.21258%; avg_num_integers_per_block = 2.62353
	sparse chunks with 6 blocks: 3.80019%; avg_num_integers_per_block = 2.81759
	sparse chunks with 7 blocks: 3.46053%; avg_num_integers_per_block = 2.97751
	sparse chunks with 8 blocks: 3.16275%; avg_num_integers_per_block = 2.91154
	sparse chunks with 9 blocks: 2.91606%; avg_num_integers_per_block = 3.17653
	sparse chunks with 10 blocks: 2.67452%; avg_num_integers_per_block = 3.2036
	sparse chunks with 11 blocks: 2.47538%; avg_num_integers_per_block = 3.06067
	sparse chunks with 12 blocks: 2.27634%; avg_num_integers_per_block = 3.07892
	sparse chunks with 13 blocks: 2.09444%; avg_num_integers_per_block = 3.03759
	sparse chunks with 14 blocks: 1.93008%; avg_num_integers_per_block = 3.35438
	sparse chunks with 15 blocks: 1.78167%; avg_num_integers_per_block = 3.11038
	sparse chunks with 16 blocks: 1.65496%; avg_num_integers_per_block = 4.09892
	sparse chunks with 17 blocks: 1.53507%; avg_num_integers_per_block = 3.3519
	sparse chunks with 18 blocks: 1.42579%; avg_num_integers_per_block = 3.80983
	sparse chunks with 19 blocks: 1.3161%; avg_num_integers_per_block = 4.11188
	sparse chunks with 20 blocks: 1.22949%; avg_num_integers_per_block = 3.81417
	sparse chunks with 21 blocks: 1.16169%; avg_num_integers_per_block = 3.92804
	sparse chunks with 22 blocks: 1.08828%; avg_num_integers_per_block = 3.75269
	sparse chunks with 23 blocks: 1.01548%; avg_num_integers_per_block = 3.87916
	sparse chunks with 24 blocks: 0.957277%; avg_num_integers_per_block = 3.90223
	sparse chunks with 25 blocks: 0.903625%; avg_num_integers_per_block = 4.34526
	sparse chunks with 26 blocks: 0.845546%; avg_num_integers_per_block = 3.9397
	sparse chunks with 27 blocks: 0.798394%; avg_num_integers_per_block = 4.09284
	sparse chunks with 28 blocks: 0.752442%; avg_num_integers_per_block = 4.05316
	sparse chunks with 29 blocks: 0.709363%; avg_num_integers_per_block = 4.11019
	sparse chunks with 30 blocks: 0.683391%; avg_num_integers_per_block = 4.27526
	sparse chunks with 31 blocks: 0.649907%; avg_num_integers_per_block = 4.41862
	sparse chunks with 32 blocks: 0.617871%; avg_num_integers_per_block = 4.62673
	sparse chunks with 33 blocks: 0.589462%; avg_num_integers_per_block = 4.45136
	sparse chunks with 34 blocks: 0.560193%; avg_num_integers_per_block = 4.38195
	sparse chunks with 35 blocks: 0.536623%; avg_num_integers_per_block = 4.39931
	sparse chunks with 36 blocks: 0.513299%; avg_num_integers_per_block = 5.12244
	sparse chunks with 37 blocks: 0.49644%; avg_num_integers_per_block = 4.99802
	sparse chunks with 38 blocks: 0.474341%; avg_num_integers_per_block = 4.73956
	sparse chunks with 39 blocks: 0.461072%; avg_num_integers_per_block = 4.85806
	sparse chunks with 40 blocks: 0.440186%; avg_num_integers_per_block = 4.83781
	sparse chunks with 41 blocks: 0.426812%; avg_num_integers_per_block = 4.82694
	sparse chunks with 42 blocks: 0.417098%; avg_num_integers_per_block = 5.48239
	sparse chunks with 43 blocks: 0.39454%; avg_num_integers_per_block = 5.19642
	sparse chunks with 44 blocks: 0.380448%; avg_num_integers_per_block = 5.34611
	sparse chunks with 45 blocks: 0.367579%; avg_num_integers_per_block = 5.50507
	sparse chunks with 46 blocks: 0.357466%; avg_num_integers_per_block = 5.46697
	sparse chunks with 47 blocks: 0.342408%; avg_num_integers_per_block = 6.31736
	sparse chunks with 48 blocks: 0.327502%; avg_num_integers_per_block = 5.47182
	sparse chunks with 49 blocks: 0.320815%; avg_num_integers_per_block = 5.72353
	sparse chunks with 50 blocks: 0.311326%; avg_num_integers_per_block = 5.58005
	sparse chunks with 51 blocks: 0.304579%; avg_num_integers_per_block = 6.93224
	sparse chunks with 52 blocks: 0.292688%; avg_num_integers_per_block = 5.89901
	sparse chunks with 53 blocks: 0.284105%; avg_num_integers_per_block = 7.20157
	sparse chunks with 54 blocks: 0.276135%; avg_num_integers_per_block = 5.90266
	sparse chunks with 55 blocks: 0.272261%; avg_num_integers_per_block = 7.20037
	sparse chunks with 56 blocks: 0.264715%; avg_num_integers_per_block = 6.15388
	sparse chunks with 57 blocks: 0.256367%; avg_num_integers_per_block = 6.22382
	sparse chunks with 58 blocks: 0.252341%; avg_num_integers_per_block = 6.15805
	sparse chunks with 59 blocks: 0.244193%; avg_num_integers_per_block = 6.20628
	sparse chunks with 60 blocks: 0.241497%; avg_num_integers_per_block = 7.81683
	sparse chunks with 61 blocks: 0.234033%; avg_num_integers_per_block = 6.21743
	sparse chunks with 62 blocks: 0.229206%; avg_num_integers_per_block = 6.85074
	sparse chunks with 63 blocks: 0.226945%; avg_num_integers_per_block = 6.79393
	sparse chunks with 64 blocks: 0.225532%; avg_num_integers_per_block = 7.35438
	sparse chunks with 65 blocks: 0.220505%; avg_num_integers_per_block = 11.1654
	sparse chunks with 66 blocks: 0.210804%; avg_num_integers_per_block = 6.96896
	sparse chunks with 67 blocks: 0.206024%; avg_num_integers_per_block = 6.51796
	sparse chunks with 68 blocks: 0.202916%; avg_num_integers_per_block = 6.79374
	sparse chunks with 69 blocks: 0.199019%; avg_num_integers_per_block = 6.95865
	sparse chunks with 70 blocks: 0.194745%; avg_num_integers_per_block = 7.23526
	sparse chunks with 71 blocks: 0.189576%; avg_num_integers_per_block = 7.47033
	sparse chunks with 72 blocks: 0.182171%; avg_num_integers_per_block = 7.47337
	sparse chunks with 73 blocks: 0.178297%; avg_num_integers_per_block = 7.17262
	sparse chunks with 74 blocks: 0.175766%; avg_num_integers_per_block = 7.08268
	sparse chunks with 75 blocks: 0.173317%; avg_num_integers_per_block = 8.43193
	sparse chunks with 76 blocks: 0.173164%; avg_num_integers_per_block = 13.3051
	sparse chunks with 77 blocks: 0.167113%; avg_num_integers_per_block = 7.31247
	sparse chunks with 78 blocks: 0.164146%; avg_num_integers_per_block = 7.52417
	sparse chunks with 79 blocks: 0.163639%; avg_num_integers_per_block = 9.08974
	sparse chunks with 80 blocks: 0.158118%; avg_num_integers_per_block = 7.77915
	sparse chunks with 81 blocks: 0.152584%; avg_num_integers_per_block = 7.56182
	sparse chunks with 82 blocks: 0.150382%; avg_num_integers_per_block = 7.25903
	sparse chunks with 83 blocks: 0.147427%; avg_num_integers_per_block = 7.63553
	sparse chunks with 84 blocks: 0.146591%; avg_num_integers_per_block = 7.38436
	sparse chunks with 85 blocks: 0.140952%; avg_num_integers_per_block = 7.53846
	sparse chunks with 86 blocks: 0.140516%; avg_num_integers_per_block = 9.61364
	sparse chunks with 87 blocks: 0.139327%; avg_num_integers_per_block = 8.16633
	sparse chunks with 88 blocks: 0.136949%; avg_num_integers_per_block = 10.6212
	sparse chunks with 89 blocks: 0.135736%; avg_num_integers_per_block = 8.64767
	sparse chunks with 90 blocks: 0.133382%; avg_num_integers_per_block = 8.50966
	sparse chunks with 91 blocks: 0.131863%; avg_num_integers_per_block = 10.2849
	sparse chunks with 92 blocks: 0.13012%; avg_num_integers_per_block = 8.65408
	sparse chunks with 93 blocks: 0.130862%; avg_num_integers_per_block = 10.6583
	sparse chunks with 94 blocks: 0.129732%; avg_num_integers_per_block = 12.5867
	sparse chunks with 95 blocks: 0.124398%; avg_num_integers_per_block = 10.2169
	sparse chunks with 96 blocks: 0.121914%; avg_num_integers_per_block = 9.15158
	sparse chunks with 97 blocks: 0.12122%; avg_num_integers_per_block = 9.06804
	sparse chunks with 98 blocks: 0.117122%; avg_num_integers_per_block = 8.96154
	sparse chunks with 99 blocks: 0.114744%; avg_num_integers_per_block = 9.40453
	sparse chunks with 100 blocks: 0.114721%; avg_num_integers_per_block = 10.245
	sparse chunks with 101 blocks: 0.115462%; avg_num_integers_per_block = 13.5433
	sparse chunks with 102 blocks: 0.111624%; avg_num_integers_per_block = 10.7745
	sparse chunks with 103 blocks: 0.109164%; avg_num_integers_per_block = 10.5766
	sparse chunks with 104 blocks: 0.107951%; avg_num_integers_per_block = 9.80325
	sparse chunks with 105 blocks: 0.103712%; avg_num_integers_per_block = 10.2047
	sparse chunks with 106 blocks: 0.106503%; avg_num_integers_per_block = 13.7874
	sparse chunks with 107 blocks: 0.1029%; avg_num_integers_per_block = 9.49584
	sparse chunks with 108 blocks: 0.0998625%; avg_num_integers_per_block = 9.83543
	sparse chunks with 109 blocks: 0.0984379%; avg_num_integers_per_block = 9.45967
	sparse chunks with 110 blocks: 0.0978728%; avg_num_integers_per_block = 9.28219
	sparse chunks with 111 blocks: 0.0980965%; avg_num_integers_per_block = 10.3003
	sparse chunks with 112 blocks: 0.0977786%; avg_num_integers_per_block = 10.0576
	sparse chunks with 113 blocks: 0.0928926%; avg_num_integers_per_block = 9.21452
	sparse chunks with 114 blocks: 0.096248%; avg_num_integers_per_block = 10.8907
	sparse chunks with 115 blocks: 0.093234%; avg_num_integers_per_block = 9.79111
	sparse chunks with 116 blocks: 0.092975%; avg_num_integers_per_block = 10.3811
	sparse chunks with 117 blocks: 0.0939287%; avg_num_integers_per_block = 10.2454
	sparse chunks with 118 blocks: 0.0904202%; avg_num_integers_per_block = 10.1427
	sparse chunks with 119 blocks: 0.0886306%; avg_num_integers_per_block = 10.6151
	sparse chunks with 120 blocks: 0.0909971%; avg_num_integers_per_block = 10.3179
	sparse chunks with 121 blocks: 0.0896549%; avg_num_integers_per_block = 10.1004
	sparse chunks with 122 blocks: 0.0870177%; avg_num_integers_per_block = 10.764
	sparse chunks with 123 blocks: 0.0926218%; avg_num_integers_per_block = 23.4721
	sparse chunks with 124 blocks: 0.0867586%; avg_num_integers_per_block = 10.6309
	sparse chunks with 125 blocks: 0.0858992%; avg_num_integers_per_block = 11.6311
	sparse chunks with 126 blocks: 0.0840507%; avg_num_integers_per_block = 10.6859
	sparse chunks with 127 blocks: 0.0849573%; avg_num_integers_per_block = 13.4102
	sparse chunks with 128 blocks: 0.0836504%; avg_num_integers_per_block = 11.9639
	sparse chunks with 129 blocks: 0.0811662%; avg_num_integers_per_block = 11.5127
	sparse chunks with 130 blocks: 0.0816725%; avg_num_integers_per_block = 11.8628
	sparse chunks with 131 blocks: 0.0787762%; avg_num_integers_per_block = 10.9462
	sparse chunks with 132 blocks: 0.0788469%; avg_num_integers_per_block = 10.8735
	sparse chunks with 133 blocks: 0.0786232%; avg_num_integers_per_block = 11.0908
	sparse chunks with 134 blocks: 0.0785525%; avg_num_integers_per_block = 11.096
	sparse chunks with 135 blocks: 0.0798594%; avg_num_integers_per_block = 12.2456
	sparse chunks with 136 blocks: 0.0772339%; avg_num_integers_per_block = 11.7477
	sparse chunks with 137 blocks: 0.0766335%; avg_num_integers_per_block = 12.9333
	sparse chunks with 138 blocks: 0.0789411%; avg_num_integers_per_block = 14.5654
	sparse chunks with 139 blocks: 0.0775753%; avg_num_integers_per_block = 11.7756
	sparse chunks with 140 blocks: 0.0745025%; avg_num_integers_per_block = 11.3622
	sparse chunks with 141 blocks: 0.0741375%; avg_num_integers_per_block = 11.2176
	sparse chunks with 142 blocks: 0.0738314%; avg_num_integers_per_block = 12.1509
	sparse chunks with 143 blocks: 0.0751853%; avg_num_integers_per_block = 12.4277
	sparse chunks with 144 blocks: 0.0765393%; avg_num_integers_per_block = 14.1885
	sparse chunks with 145 blocks: 0.0727364%; avg_num_integers_per_block = 11.7513
	sparse chunks with 146 blocks: 0.0726423%; avg_num_integers_per_block = 12.0672
	sparse chunks with 147 blocks: 0.0708645%; avg_num_integers_per_block = 11.9662
	sparse chunks with 148 blocks: 0.0703582%; avg_num_integers_per_block = 12.7457
	sparse chunks with 149 blocks: 0.0710175%; avg_num_integers_per_block = 12.2277
	sparse chunks with 150 blocks: 0.070629%; avg_num_integers_per_block = 12.4204
	sparse chunks with 151 blocks: 0.0692868%; avg_num_integers_per_block = 12.2566
	sparse chunks with 152 blocks: 0.0681095%; avg_num_integers_per_block = 12.1673
	sparse chunks with 153 blocks: 0.0698049%; avg_num_integers_per_block = 12.3423
	sparse chunks with 154 blocks: 0.067615%; avg_num_integers_per_block = 13.13
	sparse chunks with 155 blocks: 0.0663199%; avg_num_integers_per_block = 12.4955
	sparse chunks with 156 blocks: 0.0670499%; avg_num_integers_per_block = 13.541
	sparse chunks with 157 blocks: 0.0659785%; avg_num_integers_per_block = 12.6156
	sparse chunks with 158 blocks: 0.0646481%; avg_num_integers_per_block = 13.518
	sparse chunks with 159 blocks: 0.064342%; avg_num_integers_per_block = 12.9169
	sparse chunks with 160 blocks: 0.0637062%; avg_num_integers_per_block = 13.3854
	sparse chunks with 161 blocks: 0.0643302%; avg_num_integers_per_block = 13.8062
	sparse chunks with 162 blocks: 0.0636238%; avg_num_integers_per_block = 13.5578
	sparse chunks with 163 blocks: 0.0623758%; avg_num_integers_per_block = 13.4135
	sparse chunks with 164 blocks: 0.0622816%; avg_num_integers_per_block = 13.5729
	sparse chunks with 165 blocks: 0.0602213%; avg_num_integers_per_block = 14.0455
	sparse chunks with 166 blocks: 0.0607982%; avg_num_integers_per_block = 14.2147
	sparse chunks with 167 blocks: 0.062211%; avg_num_integers_per_block = 14.1897
	sparse chunks with 168 blocks: 0.0604096%; avg_num_integers_per_block = 14.1348
	sparse chunks with 169 blocks: 0.0590321%; avg_num_integers_per_block = 14.1031
	sparse chunks with 170 blocks: 0.0592558%; avg_num_integers_per_block = 14.9505
	sparse chunks with 171 blocks: 0.057843%; avg_num_integers_per_block = 14.571
	sparse chunks with 172 blocks: 0.0558651%; avg_num_integers_per_block = 14.6281
	sparse chunks with 173 blocks: 0.0564184%; avg_num_integers_per_block = 14.3666
	sparse chunks with 174 blocks: 0.055194%; avg_num_integers_per_block = 13.937
	sparse chunks with 175 blocks: 0.0547584%; avg_num_integers_per_block = 14.1183
	sparse chunks with 176 blocks: 0.0558062%; avg_num_integers_per_block = 14.1985
	sparse chunks with 177 blocks: 0.0550763%; avg_num_integers_per_block = 15.0313
	sparse chunks with 178 blocks: 0.0549703%; avg_num_integers_per_block = 14.4471
	sparse chunks with 179 blocks: 0.0544287%; avg_num_integers_per_block = 15.11
	sparse chunks with 180 blocks: 0.053581%; avg_num_integers_per_block = 15.2034
	sparse chunks with 181 blocks: 0.0561594%; avg_num_integers_per_block = 15.2106
	sparse chunks with 182 blocks: 0.0548761%; avg_num_integers_per_block = 14.9581
	sparse chunks with 183 blocks: 0.0553941%; avg_num_integers_per_block = 14.8062
	sparse chunks with 184 blocks: 0.0546406%; avg_num_integers_per_block = 14.9425
	sparse chunks with 185 blocks: 0.0554059%; avg_num_integers_per_block = 14.657
	sparse chunks with 186 blocks: 0.0576193%; avg_num_integers_per_block = 14.3099
	sparse chunks with 187 blocks: 0.0586201%; avg_num_integers_per_block = 14.326
	sparse chunks with 188 blocks: 0.0592087%; avg_num_integers_per_block = 14.6975
	sparse chunks with 189 blocks: 0.0592087%; avg_num_integers_per_block = 14.1785
	sparse chunks with 190 blocks: 0.0587849%; avg_num_integers_per_block = 14.4433
	sparse chunks with 191 blocks: 0.060857%; avg_num_integers_per_block = 14.3357
	sparse chunks with 192 blocks: 0.0617989%; avg_num_integers_per_block = 14.2518
	sparse chunks with 193 blocks: 0.0617754%; avg_num_integers_per_block = 13.9147
	sparse chunks with 194 blocks: 0.0631175%; avg_num_integers_per_block = 14.0998
	sparse chunks with 195 blocks: 0.0631528%; avg_num_integers_per_block = 14.1166
	sparse chunks with 196 blocks: 0.0636473%; avg_num_integers_per_block = 14.2204
	sparse chunks with 197 blocks: 0.0649777%; avg_num_integers_per_block = 14.6323
	sparse chunks with 198 blocks: 0.0621874%; avg_num_integers_per_block = 15.0062
	sparse chunks with 199 blocks: 0.0612102%; avg_num_integers_per_block = 15.1971
	sparse chunks with 200 blocks: 0.06008%; avg_num_integers_per_block = 15.5322
	sparse chunks with 201 blocks: 0.0593265%; avg_num_integers_per_block = 16.5533
	sparse chunks with 202 blocks: 0.0593971%; avg_num_integers_per_block = 17.1677
	sparse chunks with 203 blocks: 0.0550998%; avg_num_integers_per_block = 17.9907
	sparse chunks with 204 blocks: 0.0546995%; avg_num_integers_per_block = 17.7846
	sparse chunks with 205 blocks: 0.0522271%; avg_num_integers_per_block = 18.1078
	sparse chunks with 206 blocks: 0.0500725%; avg_num_integers_per_block = 18.9877
	sparse chunks with 207 blocks: 0.0487421%; avg_num_integers_per_block = 19.2272
	sparse chunks with 208 blocks: 0.048436%; avg_num_integers_per_block = 20.2247
	sparse chunks with 209 blocks: 0.0471645%; avg_num_integers_per_block = 19.7699
	sparse chunks with 210 blocks: 0.0468819%; avg_num_integers_per_block = 20.7554
	sparse chunks with 211 blocks: 0.0450335%; avg_num_integers_per_block = 19.9689
	sparse chunks with 212 blocks: 0.0436678%; avg_num_integers_per_block = 21.0659
	sparse chunks with 213 blocks: 0.0440092%; avg_num_integers_per_block = 21.3004
	sparse chunks with 214 blocks: 0.0440327%; avg_num_integers_per_block = 22.4844
	sparse chunks with 215 blocks: 0.0445508%; avg_num_integers_per_block = 22.8196
	sparse chunks with 216 blocks: 0.0454573%; avg_num_integers_per_block = 23.3756
	sparse chunks with 217 blocks: 0.0443153%; avg_num_integers_per_block = 23.7247
	sparse chunks with 218 blocks: 0.0454338%; avg_num_integers_per_block = 24.1372
	sparse chunks with 219 blocks: 0.0442918%; avg_num_integers_per_block = 24.4787
	sparse chunks with 220 blocks: 0.0431144%; avg_num_integers_per_block = 25.1323
	sparse chunks with 221 blocks: 0.0434676%; avg_num_integers_per_block = 25.271
	sparse chunks with 222 blocks: 0.0445272%; avg_num_integers_per_block = 25.0183
	sparse chunks with 223 blocks: 0.0433263%; avg_num_integers_per_block = 26.2024
	sparse chunks with 224 blocks: 0.0434323%; avg_num_integers_per_block = 27.0758
	sparse chunks with 225 blocks: 0.0427023%; avg_num_integers_per_block = 26.5275
	sparse chunks with 226 blocks: 0.0431733%; avg_num_integers_per_block = 27.1095
	sparse chunks with 227 blocks: 0.0435618%; avg_num_integers_per_block = 28.2336
	sparse chunks with 228 blocks: 0.045057%; avg_num_integers_per_block = 28.0546
	sparse chunks with 229 blocks: 0.0421019%; avg_num_integers_per_block = 29.5304
	sparse chunks with 230 blocks: 0.0438679%; avg_num_integers_per_block = 30.1965
	sparse chunks with 231 blocks: 0.0447745%; avg_num_integers_per_block = 31.3817
	sparse chunks with 232 blocks: 0.0418076%; avg_num_integers_per_block = 30.8644
	sparse chunks with 233 blocks: 0.0420666%; avg_num_integers_per_block = 30.7192
	sparse chunks with 234 blocks: 0.0406302%; avg_num_integers_per_block = 30.9748
	sparse chunks with 235 blocks: 0.0401475%; avg_num_integers_per_block = 32.4342
	sparse chunks with 236 blocks: 0.0413484%; avg_num_integers_per_block = 33.3342
	sparse chunks with 237 blocks: 0.0419842%; avg_num_integers_per_block = 33.36
	sparse chunks with 238 blocks: 0.0423845%; avg_num_integers_per_block = 34.3277
	sparse chunks with 239 blocks: 0.0436089%; avg_num_integers_per_block = 35.9237
	sparse chunks with 240 blocks: 0.0434088%; avg_num_integers_per_block = 37.9927
	sparse chunks with 241 blocks: 0.0411718%; avg_num_integers_per_block = 37.4418
	sparse chunks with 242 blocks: 0.0403006%; avg_num_integers_per_block = 37.8929
	sparse chunks with 243 blocks: 0.0386287%; avg_num_integers_per_block = 39.7224
	sparse chunks with 244 blocks: 0.0402299%; avg_num_integers_per_block = 40.3114
	sparse chunks with 245 blocks: 0.0369922%; avg_num_integers_per_block = 40.6091
	sparse chunks with 246 blocks: 0.0361916%; avg_num_integers_per_block = 42.1156
	sparse chunks with 247 blocks: 0.0342961%; avg_num_integers_per_block = 42.4374
	sparse chunks with 248 blocks: 0.0344962%; avg_num_integers_per_block = 41.2493
	sparse chunks with 249 blocks: 0.0318354%; avg_num_integers_per_block = 40.3861
	sparse chunks with 250 blocks: 0.0334955%; avg_num_integers_per_block = 41.0309
	sparse chunks with 251 blocks: 0.0347082%; avg_num_integers_per_block = 39.979
	sparse chunks with 252 blocks: 0.0323064%; avg_num_integers_per_block = 38.6379
	sparse chunks with 253 blocks: 0.0348848%; avg_num_integers_per_block = 38.4977
	sparse chunks with 254 blocks: 0.036639%; avg_num_integers_per_block = 38.6227
	sparse chunks with 255 blocks: 0.039394%; avg_num_integers_per_block = 38.2554
	sparse chunks with 256 blocks: 0.0886071%; avg_num_integers_per_block = 27.6633
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
	== distribution of blocks in sparse chunks ==
	sparse chunks with 1 blocks: 12.0655%; avg_num_integers_per_block = 1.88218
	sparse chunks with 2 blocks: 10.5397%; avg_num_integers_per_block = 2.12684
	sparse chunks with 3 blocks: 8.79335%; avg_num_integers_per_block = 2.1969
	sparse chunks with 4 blocks: 7.20938%; avg_num_integers_per_block = 2.23565
	sparse chunks with 5 blocks: 5.87046%; avg_num_integers_per_block = 2.25722
	sparse chunks with 6 blocks: 4.80485%; avg_num_integers_per_block = 2.30638
	sparse chunks with 7 blocks: 3.97076%; avg_num_integers_per_block = 2.33814
	sparse chunks with 8 blocks: 3.32757%; avg_num_integers_per_block = 2.34957
	sparse chunks with 9 blocks: 2.82172%; avg_num_integers_per_block = 2.36368
	sparse chunks with 10 blocks: 2.42389%; avg_num_integers_per_block = 2.3922
	sparse chunks with 11 blocks: 2.11029%; avg_num_integers_per_block = 2.44086
	sparse chunks with 12 blocks: 1.85061%; avg_num_integers_per_block = 2.48232
	sparse chunks with 13 blocks: 1.64077%; avg_num_integers_per_block = 2.4845
	sparse chunks with 14 blocks: 1.46712%; avg_num_integers_per_block = 2.52249
	sparse chunks with 15 blocks: 1.31967%; avg_num_integers_per_block = 2.59751
	sparse chunks with 16 blocks: 1.19459%; avg_num_integers_per_block = 2.59926
	sparse chunks with 17 blocks: 1.08709%; avg_num_integers_per_block = 2.60429
	sparse chunks with 18 blocks: 0.993267%; avg_num_integers_per_block = 2.62856
	sparse chunks with 19 blocks: 0.9117%; avg_num_integers_per_block = 2.63384
	sparse chunks with 20 blocks: 0.840087%; avg_num_integers_per_block = 2.65782
	sparse chunks with 21 blocks: 0.776956%; avg_num_integers_per_block = 2.68738
	sparse chunks with 22 blocks: 0.721724%; avg_num_integers_per_block = 2.70941
	sparse chunks with 23 blocks: 0.674704%; avg_num_integers_per_block = 2.70545
	sparse chunks with 24 blocks: 0.628723%; avg_num_integers_per_block = 2.70128
	sparse chunks with 25 blocks: 0.590828%; avg_num_integers_per_block = 2.72868
	sparse chunks with 26 blocks: 0.555068%; avg_num_integers_per_block = 2.81427
	sparse chunks with 27 blocks: 0.523742%; avg_num_integers_per_block = 2.82118
	sparse chunks with 28 blocks: 0.494158%; avg_num_integers_per_block = 2.77733
	sparse chunks with 29 blocks: 0.467789%; avg_num_integers_per_block = 2.84271
	sparse chunks with 30 blocks: 0.442111%; avg_num_integers_per_block = 2.84532
	sparse chunks with 31 blocks: 0.423121%; avg_num_integers_per_block = 2.82777
	sparse chunks with 32 blocks: 0.4022%; avg_num_integers_per_block = 2.83208
	sparse chunks with 33 blocks: 0.382546%; avg_num_integers_per_block = 2.814
	sparse chunks with 34 blocks: 0.364722%; avg_num_integers_per_block = 2.84677
	sparse chunks with 35 blocks: 0.349694%; avg_num_integers_per_block = 2.85015
	sparse chunks with 36 blocks: 0.335986%; avg_num_integers_per_block = 2.95834
	sparse chunks with 37 blocks: 0.322127%; avg_num_integers_per_block = 2.88534
	sparse chunks with 38 blocks: 0.310814%; avg_num_integers_per_block = 2.9312
	sparse chunks with 39 blocks: 0.298481%; avg_num_integers_per_block = 2.93406
	sparse chunks with 40 blocks: 0.287053%; avg_num_integers_per_block = 2.93458
	sparse chunks with 41 blocks: 0.27689%; avg_num_integers_per_block = 2.9448
	sparse chunks with 42 blocks: 0.268126%; avg_num_integers_per_block = 2.94529
	sparse chunks with 43 blocks: 0.257419%; avg_num_integers_per_block = 2.98161
	sparse chunks with 44 blocks: 0.250219%; avg_num_integers_per_block = 2.98636
	sparse chunks with 45 blocks: 0.24138%; avg_num_integers_per_block = 2.98733
	sparse chunks with 46 blocks: 0.234016%; avg_num_integers_per_block = 3.0444
	sparse chunks with 47 blocks: 0.226946%; avg_num_integers_per_block = 3.03428
	sparse chunks with 48 blocks: 0.220472%; avg_num_integers_per_block = 3.03065
	sparse chunks with 49 blocks: 0.214037%; avg_num_integers_per_block = 3.03435
	sparse chunks with 50 blocks: 0.207013%; avg_num_integers_per_block = 3.06426
	sparse chunks with 51 blocks: 0.201608%; avg_num_integers_per_block = 3.03704
	sparse chunks with 52 blocks: 0.196784%; avg_num_integers_per_block = 3.07988
	sparse chunks with 53 blocks: 0.190345%; avg_num_integers_per_block = 3.09452
	sparse chunks with 54 blocks: 0.185529%; avg_num_integers_per_block = 3.12591
	sparse chunks with 55 blocks: 0.179936%; avg_num_integers_per_block = 3.14533
	sparse chunks with 56 blocks: 0.17623%; avg_num_integers_per_block = 3.15506
	sparse chunks with 57 blocks: 0.171686%; avg_num_integers_per_block = 3.15951
	sparse chunks with 58 blocks: 0.167488%; avg_num_integers_per_block = 3.1901
	sparse chunks with 59 blocks: 0.162528%; avg_num_integers_per_block = 3.26479
	sparse chunks with 60 blocks: 0.158644%; avg_num_integers_per_block = 3.21654
	sparse chunks with 61 blocks: 0.154487%; avg_num_integers_per_block = 3.25577
	sparse chunks with 62 blocks: 0.150763%; avg_num_integers_per_block = 3.27684
	sparse chunks with 63 blocks: 0.147237%; avg_num_integers_per_block = 3.25127
	sparse chunks with 64 blocks: 0.14347%; avg_num_integers_per_block = 3.26646
	sparse chunks with 65 blocks: 0.140592%; avg_num_integers_per_block = 3.28803
	sparse chunks with 66 blocks: 0.138054%; avg_num_integers_per_block = 3.319
	sparse chunks with 67 blocks: 0.134521%; avg_num_integers_per_block = 3.31815
	sparse chunks with 68 blocks: 0.131271%; avg_num_integers_per_block = 3.32311
	sparse chunks with 69 blocks: 0.127938%; avg_num_integers_per_block = 3.35898
	sparse chunks with 70 blocks: 0.125961%; avg_num_integers_per_block = 3.37935
	sparse chunks with 71 blocks: 0.122327%; avg_num_integers_per_block = 3.41205
	sparse chunks with 72 blocks: 0.120824%; avg_num_integers_per_block = 3.4152
	sparse chunks with 73 blocks: 0.116896%; avg_num_integers_per_block = 3.52248
	sparse chunks with 74 blocks: 0.115495%; avg_num_integers_per_block = 3.45311
	sparse chunks with 75 blocks: 0.112777%; avg_num_integers_per_block = 3.45815
	sparse chunks with 76 blocks: 0.110759%; avg_num_integers_per_block = 3.46903
	sparse chunks with 77 blocks: 0.1083%; avg_num_integers_per_block = 3.48539
	sparse chunks with 78 blocks: 0.106758%; avg_num_integers_per_block = 3.50626
	sparse chunks with 79 blocks: 0.103915%; avg_num_integers_per_block = 3.54711
	sparse chunks with 80 blocks: 0.102071%; avg_num_integers_per_block = 3.54308
	sparse chunks with 81 blocks: 0.100538%; avg_num_integers_per_block = 3.55634
	sparse chunks with 82 blocks: 0.0990814%; avg_num_integers_per_block = 3.62394
	sparse chunks with 83 blocks: 0.097322%; avg_num_integers_per_block = 3.63093
	sparse chunks with 84 blocks: 0.0953722%; avg_num_integers_per_block = 3.61035
	sparse chunks with 85 blocks: 0.0943777%; avg_num_integers_per_block = 3.63541
	sparse chunks with 86 blocks: 0.0920969%; avg_num_integers_per_block = 3.68322
	sparse chunks with 87 blocks: 0.0897536%; avg_num_integers_per_block = 3.70153
	sparse chunks with 88 blocks: 0.0880894%; avg_num_integers_per_block = 3.68166
	sparse chunks with 89 blocks: 0.0872308%; avg_num_integers_per_block = 3.69549
	sparse chunks with 90 blocks: 0.0850498%; avg_num_integers_per_block = 3.7603
	sparse chunks with 91 blocks: 0.0838056%; avg_num_integers_per_block = 3.75605
	sparse chunks with 92 blocks: 0.083075%; avg_num_integers_per_block = 3.76714
	sparse chunks with 93 blocks: 0.0818573%; avg_num_integers_per_block = 3.78634
	sparse chunks with 94 blocks: 0.080215%; avg_num_integers_per_block = 3.79072
	sparse chunks with 95 blocks: 0.0782323%; avg_num_integers_per_block = 3.82621
	sparse chunks with 96 blocks: 0.077817%; avg_num_integers_per_block = 3.86105
	sparse chunks with 97 blocks: 0.0765884%; avg_num_integers_per_block = 3.86695
	sparse chunks with 98 blocks: 0.0751272%; avg_num_integers_per_block = 3.8964
	sparse chunks with 99 blocks: 0.0738673%; avg_num_integers_per_block = 3.90319
	sparse chunks with 100 blocks: 0.0732351%; avg_num_integers_per_block = 3.90011
	sparse chunks with 101 blocks: 0.072392%; avg_num_integers_per_block = 3.93536
	sparse chunks with 102 blocks: 0.0707247%; avg_num_integers_per_block = 3.96496
	sparse chunks with 103 blocks: 0.0696507%; avg_num_integers_per_block = 3.98153
	sparse chunks with 104 blocks: 0.0686515%; avg_num_integers_per_block = 4.02769
	sparse chunks with 105 blocks: 0.0680317%; avg_num_integers_per_block = 4.03493
	sparse chunks with 106 blocks: 0.0672496%; avg_num_integers_per_block = 4.05324
	sparse chunks with 107 blocks: 0.0659008%; avg_num_integers_per_block = 4.078
	sparse chunks with 108 blocks: 0.0652748%; avg_num_integers_per_block = 4.11673
	sparse chunks with 109 blocks: 0.0642522%; avg_num_integers_per_block = 4.11518
	sparse chunks with 110 blocks: 0.0628565%; avg_num_integers_per_block = 4.18016
	sparse chunks with 111 blocks: 0.0623788%; avg_num_integers_per_block = 4.18053
	sparse chunks with 112 blocks: 0.0612767%; avg_num_integers_per_block = 4.16305
	sparse chunks with 113 blocks: 0.0611955%; avg_num_integers_per_block = 4.23732
	sparse chunks with 114 blocks: 0.0600387%; avg_num_integers_per_block = 4.21922
	sparse chunks with 115 blocks: 0.059141%; avg_num_integers_per_block = 4.27738
	sparse chunks with 116 blocks: 0.0582433%; avg_num_integers_per_block = 4.30215
	sparse chunks with 117 blocks: 0.0578812%; avg_num_integers_per_block = 4.32856
	sparse chunks with 118 blocks: 0.0570959%; avg_num_integers_per_block = 4.29979
	sparse chunks with 119 blocks: 0.0566291%; avg_num_integers_per_block = 4.37678
	sparse chunks with 120 blocks: 0.0556612%; avg_num_integers_per_block = 4.38724
	sparse chunks with 121 blocks: 0.0546262%; avg_num_integers_per_block = 4.41434
	sparse chunks with 122 blocks: 0.0548276%; avg_num_integers_per_block = 4.45672
	sparse chunks with 123 blocks: 0.0537519%; avg_num_integers_per_block = 4.47849
	sparse chunks with 124 blocks: 0.0534865%; avg_num_integers_per_block = 4.47533
	sparse chunks with 125 blocks: 0.0519722%; avg_num_integers_per_block = 4.54872
	sparse chunks with 126 blocks: 0.0521377%; avg_num_integers_per_block = 4.53543
	sparse chunks with 127 blocks: 0.0515179%; avg_num_integers_per_block = 4.56066
	sparse chunks with 128 blocks: 0.0509309%; avg_num_integers_per_block = 4.60574
	sparse chunks with 129 blocks: 0.0504579%; avg_num_integers_per_block = 4.61738
	sparse chunks with 130 blocks: 0.0500223%; avg_num_integers_per_block = 4.62065
	sparse chunks with 131 blocks: 0.0495743%; avg_num_integers_per_block = 4.73706
	sparse chunks with 132 blocks: 0.0484237%; avg_num_integers_per_block = 4.72715
	sparse chunks with 133 blocks: 0.0486423%; avg_num_integers_per_block = 4.76931
	sparse chunks with 134 blocks: 0.0483191%; avg_num_integers_per_block = 4.80576
	sparse chunks with 135 blocks: 0.0472622%; avg_num_integers_per_block = 4.83413
	sparse chunks with 136 blocks: 0.0471592%; avg_num_integers_per_block = 4.85741
	sparse chunks with 137 blocks: 0.0462069%; avg_num_integers_per_block = 4.88444
	sparse chunks with 138 blocks: 0.0454919%; avg_num_integers_per_block = 4.85469
	sparse chunks with 139 blocks: 0.045431%; avg_num_integers_per_block = 4.88384
	sparse chunks with 140 blocks: 0.04483%; avg_num_integers_per_block = 4.97189
	sparse chunks with 141 blocks: 0.0445724%; avg_num_integers_per_block = 5.00272
	sparse chunks with 142 blocks: 0.0441337%; avg_num_integers_per_block = 5.03466
	sparse chunks with 143 blocks: 0.0438136%; avg_num_integers_per_block = 5.03102
	sparse chunks with 144 blocks: 0.0436809%; avg_num_integers_per_block = 5.11032
	sparse chunks with 145 blocks: 0.0431221%; avg_num_integers_per_block = 5.1612
	sparse chunks with 146 blocks: 0.0426631%; avg_num_integers_per_block = 5.1617
	sparse chunks with 147 blocks: 0.0418138%; avg_num_integers_per_block = 5.16219
	sparse chunks with 148 blocks: 0.0420214%; avg_num_integers_per_block = 5.21477
	sparse chunks with 149 blocks: 0.0412893%; avg_num_integers_per_block = 5.24932
	sparse chunks with 150 blocks: 0.0407959%; avg_num_integers_per_block = 5.2676
	sparse chunks with 151 blocks: 0.0409474%; avg_num_integers_per_block = 5.26154
	sparse chunks with 152 blocks: 0.0402433%; avg_num_integers_per_block = 5.38538
	sparse chunks with 153 blocks: 0.0398561%; avg_num_integers_per_block = 5.41986
	sparse chunks with 154 blocks: 0.0401231%; avg_num_integers_per_block = 5.44819
	sparse chunks with 155 blocks: 0.0399077%; avg_num_integers_per_block = 5.547
	sparse chunks with 156 blocks: 0.0391396%; avg_num_integers_per_block = 5.5057
	sparse chunks with 157 blocks: 0.038946%; avg_num_integers_per_block = 5.50648
	sparse chunks with 158 blocks: 0.0388773%; avg_num_integers_per_block = 5.61921
	sparse chunks with 159 blocks: 0.0387649%; avg_num_integers_per_block = 5.60523
	sparse chunks with 160 blocks: 0.0382341%; avg_num_integers_per_block = 5.69011
	sparse chunks with 161 blocks: 0.0384558%; avg_num_integers_per_block = 5.74615
	sparse chunks with 162 blocks: 0.0378251%; avg_num_integers_per_block = 5.74293
	sparse chunks with 163 blocks: 0.0372693%; avg_num_integers_per_block = 5.80111
	sparse chunks with 164 blocks: 0.0373208%; avg_num_integers_per_block = 5.82473
	sparse chunks with 165 blocks: 0.0373364%; avg_num_integers_per_block = 5.90237
	sparse chunks with 166 blocks: 0.0367073%; avg_num_integers_per_block = 5.95406
	sparse chunks with 167 blocks: 0.0367182%; avg_num_integers_per_block = 6.03297
	sparse chunks with 168 blocks: 0.0361125%; avg_num_integers_per_block = 6.07487
	sparse chunks with 169 blocks: 0.0354599%; avg_num_integers_per_block = 6.13182
	sparse chunks with 170 blocks: 0.0355224%; avg_num_integers_per_block = 6.16712
	sparse chunks with 171 blocks: 0.0359564%; avg_num_integers_per_block = 6.2046
	sparse chunks with 172 blocks: 0.0353413%; avg_num_integers_per_block = 6.22539
	sparse chunks with 173 blocks: 0.0349729%; avg_num_integers_per_block = 6.29777
	sparse chunks with 174 blocks: 0.0346278%; avg_num_integers_per_block = 6.36644
	sparse chunks with 175 blocks: 0.0343749%; avg_num_integers_per_block = 6.3134
	sparse chunks with 176 blocks: 0.0345154%; avg_num_integers_per_block = 6.41261
	sparse chunks with 177 blocks: 0.0347262%; avg_num_integers_per_block = 6.4373
	sparse chunks with 178 blocks: 0.0343827%; avg_num_integers_per_block = 6.49714
	sparse chunks with 179 blocks: 0.0339909%; avg_num_integers_per_block = 6.61361
	sparse chunks with 180 blocks: 0.0338051%; avg_num_integers_per_block = 6.66973
	sparse chunks with 181 blocks: 0.0339082%; avg_num_integers_per_block = 6.72223
	sparse chunks with 182 blocks: 0.0336131%; avg_num_integers_per_block = 6.83539
	sparse chunks with 183 blocks: 0.0333696%; avg_num_integers_per_block = 6.89455
	sparse chunks with 184 blocks: 0.0332743%; avg_num_integers_per_block = 6.98345
	sparse chunks with 185 blocks: 0.0335475%; avg_num_integers_per_block = 7.0638
	sparse chunks with 186 blocks: 0.0330074%; avg_num_integers_per_block = 7.0894
	sparse chunks with 187 blocks: 0.0329465%; avg_num_integers_per_block = 7.1223
	sparse chunks with 188 blocks: 0.0330776%; avg_num_integers_per_block = 7.28735
	sparse chunks with 189 blocks: 0.0325968%; avg_num_integers_per_block = 7.31329
	sparse chunks with 190 blocks: 0.0330932%; avg_num_integers_per_block = 7.38977
	sparse chunks with 191 blocks: 0.0330152%; avg_num_integers_per_block = 7.52022
	sparse chunks with 192 blocks: 0.0327186%; avg_num_integers_per_block = 7.64354
	sparse chunks with 193 blocks: 0.0327357%; avg_num_integers_per_block = 7.71109
	sparse chunks with 194 blocks: 0.0332962%; avg_num_integers_per_block = 7.72929
	sparse chunks with 195 blocks: 0.0325952%; avg_num_integers_per_block = 7.90399
	sparse chunks with 196 blocks: 0.0329699%; avg_num_integers_per_block = 7.95338
	sparse chunks with 197 blocks: 0.0326015%; avg_num_integers_per_block = 8.10042
	sparse chunks with 198 blocks: 0.0326764%; avg_num_integers_per_block = 8.16991
	sparse chunks with 199 blocks: 0.0330776%; avg_num_integers_per_block = 8.26528
	sparse chunks with 200 blocks: 0.0329059%; avg_num_integers_per_block = 8.3463
	sparse chunks with 201 blocks: 0.0331978%; avg_num_integers_per_block = 8.54814
	sparse chunks with 202 blocks: 0.0327357%; avg_num_integers_per_block = 8.65812
	sparse chunks with 203 blocks: 0.0328903%; avg_num_integers_per_block = 8.78654
	sparse chunks with 204 blocks: 0.0333477%; avg_num_integers_per_block = 8.81238
	sparse chunks with 205 blocks: 0.033368%; avg_num_integers_per_block = 8.94232
	sparse chunks with 206 blocks: 0.0334289%; avg_num_integers_per_block = 9.12973
	sparse chunks with 207 blocks: 0.0332946%; avg_num_integers_per_block = 9.25635
	sparse chunks with 208 blocks: 0.0332166%; avg_num_integers_per_block = 9.37208
	sparse chunks with 209 blocks: 0.0338036%; avg_num_integers_per_block = 9.9843
	sparse chunks with 210 blocks: 0.0335709%; avg_num_integers_per_block = 9.86575
	sparse chunks with 211 blocks: 0.0337146%; avg_num_integers_per_block = 9.99905
	sparse chunks with 212 blocks: 0.0338676%; avg_num_integers_per_block = 10.0696
	sparse chunks with 213 blocks: 0.0340049%; avg_num_integers_per_block = 10.1768
	sparse chunks with 214 blocks: 0.0342251%; avg_num_integers_per_block = 10.3789
	sparse chunks with 215 blocks: 0.0344905%; avg_num_integers_per_block = 10.5533
	sparse chunks with 216 blocks: 0.0350462%; avg_num_integers_per_block = 10.69
	sparse chunks with 217 blocks: 0.0347902%; avg_num_integers_per_block = 10.9256
	sparse chunks with 218 blocks: 0.0350275%; avg_num_integers_per_block = 11.1806
	sparse chunks with 219 blocks: 0.0353132%; avg_num_integers_per_block = 11.393
	sparse chunks with 220 blocks: 0.0359954%; avg_num_integers_per_block = 11.5766
	sparse chunks with 221 blocks: 0.0361468%; avg_num_integers_per_block = 12.4487
	sparse chunks with 222 blocks: 0.0353179%; avg_num_integers_per_block = 12.1031
	sparse chunks with 223 blocks: 0.0359673%; avg_num_integers_per_block = 12.2272
	sparse chunks with 224 blocks: 0.035705%; avg_num_integers_per_block = 12.507
	sparse chunks with 225 blocks: 0.0361921%; avg_num_integers_per_block = 12.8728
	sparse chunks with 226 blocks: 0.0366027%; avg_num_integers_per_block = 13.0999
	sparse chunks with 227 blocks: 0.0369243%; avg_num_integers_per_block = 13.3456
	sparse chunks with 228 blocks: 0.0374832%; avg_num_integers_per_block = 13.5955
	sparse chunks with 229 blocks: 0.0380296%; avg_num_integers_per_block = 13.9978
	sparse chunks with 230 blocks: 0.0385619%; avg_num_integers_per_block = 14.294
	sparse chunks with 231 blocks: 0.0392114%; avg_num_integers_per_block = 14.9501
	sparse chunks with 232 blocks: 0.039739%; avg_num_integers_per_block = 15.1856
	sparse chunks with 233 blocks: 0.0403541%; avg_num_integers_per_block = 15.6035
	sparse chunks with 234 blocks: 0.041194%; avg_num_integers_per_block = 15.8383
	sparse chunks with 235 blocks: 0.0420605%; avg_num_integers_per_block = 16.3055
	sparse chunks with 236 blocks: 0.042763%; avg_num_integers_per_block = 16.7595
	sparse chunks with 237 blocks: 0.0431361%; avg_num_integers_per_block = 17.4077
	sparse chunks with 238 blocks: 0.0444584%; avg_num_integers_per_block = 17.9017
	sparse chunks with 239 blocks: 0.0454794%; avg_num_integers_per_block = 18.5796
	sparse chunks with 240 blocks: 0.0462865%; avg_num_integers_per_block = 19.1838
	sparse chunks with 241 blocks: 0.0477634%; avg_num_integers_per_block = 20.0773
	sparse chunks with 242 blocks: 0.0490185%; avg_num_integers_per_block = 20.509
	sparse chunks with 243 blocks: 0.0500192%; avg_num_integers_per_block = 21.3793
	sparse chunks with 244 blocks: 0.0513774%; avg_num_integers_per_block = 22.1922
	sparse chunks with 245 blocks: 0.0535755%; avg_num_integers_per_block = 22.7445
	sparse chunks with 246 blocks: 0.055004%; avg_num_integers_per_block = 23.9396
	sparse chunks with 247 blocks: 0.0575814%; avg_num_integers_per_block = 25.0112
	sparse chunks with 248 blocks: 0.0589443%; avg_num_integers_per_block = 25.8931
	sparse chunks with 249 blocks: 0.0611861%; avg_num_integers_per_block = 27.1668
	sparse chunks with 250 blocks: 0.0650109%; avg_num_integers_per_block = 28.4799
	sparse chunks with 251 blocks: 0.0671044%; avg_num_integers_per_block = 29.7594
	sparse chunks with 252 blocks: 0.0719268%; avg_num_integers_per_block = 31.2609
	sparse chunks with 253 blocks: 0.0761091%; avg_num_integers_per_block = 32.3278
	sparse chunks with 254 blocks: 0.0832092%; avg_num_integers_per_block = 33.5485
	sparse chunks with 255 blocks: 0.0885421%; avg_num_integers_per_block = 34.4655
	sparse chunks with 256 blocks: 0.124239%; avg_num_integers_per_block = 35.5181
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
	== distribution of blocks in sparse chunks ==
	sparse chunks with 1 blocks: 1.60782%; avg_num_integers_per_block = 1.77792
	sparse chunks with 2 blocks: 2.18452%; avg_num_integers_per_block = 1.67549
	sparse chunks with 3 blocks: 2.80325%; avg_num_integers_per_block = 1.49778
	sparse chunks with 4 blocks: 3.35123%; avg_num_integers_per_block = 1.40301
	sparse chunks with 5 blocks: 3.75659%; avg_num_integers_per_block = 1.34285
	sparse chunks with 6 blocks: 3.96242%; avg_num_integers_per_block = 1.3059
	sparse chunks with 7 blocks: 3.97046%; avg_num_integers_per_block = 1.28467
	sparse chunks with 8 blocks: 3.82272%; avg_num_integers_per_block = 1.27508
	sparse chunks with 9 blocks: 3.58141%; avg_num_integers_per_block = 1.28418
	sparse chunks with 10 blocks: 3.29244%; avg_num_integers_per_block = 1.28383
	sparse chunks with 11 blocks: 2.99723%; avg_num_integers_per_block = 1.28145
	sparse chunks with 12 blocks: 2.71094%; avg_num_integers_per_block = 1.29407
	sparse chunks with 13 blocks: 2.45087%; avg_num_integers_per_block = 1.29739
	sparse chunks with 14 blocks: 2.21807%; avg_num_integers_per_block = 1.29818
	sparse chunks with 15 blocks: 2.02742%; avg_num_integers_per_block = 1.31838
	sparse chunks with 16 blocks: 1.84684%; avg_num_integers_per_block = 1.31456
	sparse chunks with 17 blocks: 1.7024%; avg_num_integers_per_block = 1.32809
	sparse chunks with 18 blocks: 1.5608%; avg_num_integers_per_block = 1.32439
	sparse chunks with 19 blocks: 1.44135%; avg_num_integers_per_block = 1.33208
	sparse chunks with 20 blocks: 1.34445%; avg_num_integers_per_block = 1.34959
	sparse chunks with 21 blocks: 1.24709%; avg_num_integers_per_block = 1.34949
	sparse chunks with 22 blocks: 1.16607%; avg_num_integers_per_block = 1.34814
	sparse chunks with 23 blocks: 1.09497%; avg_num_integers_per_block = 1.35976
	sparse chunks with 24 blocks: 1.02456%; avg_num_integers_per_block = 1.35471
	sparse chunks with 25 blocks: 0.970191%; avg_num_integers_per_block = 1.36777
	sparse chunks with 26 blocks: 0.914834%; avg_num_integers_per_block = 1.38583
	sparse chunks with 27 blocks: 0.862387%; avg_num_integers_per_block = 1.37688
	sparse chunks with 28 blocks: 0.816446%; avg_num_integers_per_block = 1.39436
	sparse chunks with 29 blocks: 0.778722%; avg_num_integers_per_block = 1.38882
	sparse chunks with 30 blocks: 0.739437%; avg_num_integers_per_block = 1.4002
	sparse chunks with 31 blocks: 0.707436%; avg_num_integers_per_block = 1.41871
	sparse chunks with 32 blocks: 0.675538%; avg_num_integers_per_block = 1.44911
	sparse chunks with 33 blocks: 0.642325%; avg_num_integers_per_block = 1.4465
	sparse chunks with 34 blocks: 0.618094%; avg_num_integers_per_block = 1.43811
	sparse chunks with 35 blocks: 0.591251%; avg_num_integers_per_block = 1.44092
	sparse chunks with 36 blocks: 0.569825%; avg_num_integers_per_block = 1.45353
	sparse chunks with 37 blocks: 0.54773%; avg_num_integers_per_block = 1.45354
	sparse chunks with 38 blocks: 0.529188%; avg_num_integers_per_block = 1.48861
	sparse chunks with 39 blocks: 0.509055%; avg_num_integers_per_block = 1.47783
	sparse chunks with 40 blocks: 0.491315%; avg_num_integers_per_block = 1.47796
	sparse chunks with 41 blocks: 0.474586%; avg_num_integers_per_block = 1.48208
	sparse chunks with 42 blocks: 0.458111%; avg_num_integers_per_block = 1.48091
	sparse chunks with 43 blocks: 0.444282%; avg_num_integers_per_block = 1.513
	sparse chunks with 44 blocks: 0.427653%; avg_num_integers_per_block = 1.49363
	sparse chunks with 45 blocks: 0.41491%; avg_num_integers_per_block = 1.49801
	sparse chunks with 46 blocks: 0.402058%; avg_num_integers_per_block = 1.5019
	sparse chunks with 47 blocks: 0.393308%; avg_num_integers_per_block = 1.52878
	sparse chunks with 48 blocks: 0.381539%; avg_num_integers_per_block = 1.53208
	sparse chunks with 49 blocks: 0.372298%; avg_num_integers_per_block = 1.53328
	sparse chunks with 50 blocks: 0.35959%; avg_num_integers_per_block = 1.53108
	sparse chunks with 51 blocks: 0.351926%; avg_num_integers_per_block = 1.54856
	sparse chunks with 52 blocks: 0.342585%; avg_num_integers_per_block = 1.57347
	sparse chunks with 53 blocks: 0.333461%; avg_num_integers_per_block = 1.55167
	sparse chunks with 54 blocks: 0.323798%; avg_num_integers_per_block = 1.56141
	sparse chunks with 55 blocks: 0.317658%; avg_num_integers_per_block = 1.56621
	sparse chunks with 56 blocks: 0.309328%; avg_num_integers_per_block = 1.58729
	sparse chunks with 57 blocks: 0.309286%; avg_num_integers_per_block = 2.03701
	sparse chunks with 58 blocks: 0.294721%; avg_num_integers_per_block = 1.5986
	sparse chunks with 59 blocks: 0.289685%; avg_num_integers_per_block = 1.57921
	sparse chunks with 60 blocks: 0.282021%; avg_num_integers_per_block = 1.58568
	sparse chunks with 61 blocks: 0.277584%; avg_num_integers_per_block = 1.59579
	sparse chunks with 62 blocks: 0.271594%; avg_num_integers_per_block = 1.60757
	sparse chunks with 63 blocks: 0.266068%; avg_num_integers_per_block = 1.62401
	sparse chunks with 64 blocks: 0.260664%; avg_num_integers_per_block = 1.6245
	sparse chunks with 65 blocks: 0.254774%; avg_num_integers_per_block = 1.62263
	sparse chunks with 66 blocks: 0.250955%; avg_num_integers_per_block = 1.62644
	sparse chunks with 67 blocks: 0.245333%; avg_num_integers_per_block = 1.6448
	sparse chunks with 68 blocks: 0.241486%; avg_num_integers_per_block = 1.64191
	sparse chunks with 69 blocks: 0.23607%; avg_num_integers_per_block = 1.63236
	sparse chunks with 70 blocks: 0.230882%; avg_num_integers_per_block = 1.64312
	sparse chunks with 71 blocks: 0.227547%; avg_num_integers_per_block = 1.64278
	sparse chunks with 72 blocks: 0.223213%; avg_num_integers_per_block = 1.65331
	sparse chunks with 73 blocks: 0.219258%; avg_num_integers_per_block = 1.67315
	sparse chunks with 74 blocks: 0.215666%; avg_num_integers_per_block = 1.66794
	sparse chunks with 75 blocks: 0.211486%; avg_num_integers_per_block = 1.67909
	sparse chunks with 76 blocks: 0.207749%; avg_num_integers_per_block = 1.68422
	sparse chunks with 77 blocks: 0.204342%; avg_num_integers_per_block = 1.70189
	sparse chunks with 78 blocks: 0.200555%; avg_num_integers_per_block = 1.72071
	sparse chunks with 79 blocks: 0.195613%; avg_num_integers_per_block = 1.71615
	sparse chunks with 80 blocks: 0.192286%; avg_num_integers_per_block = 1.7239
	sparse chunks with 81 blocks: 0.190018%; avg_num_integers_per_block = 1.72579
	sparse chunks with 82 blocks: 0.186615%; avg_num_integers_per_block = 1.72775
	sparse chunks with 83 blocks: 0.1841%; avg_num_integers_per_block = 1.73573
	sparse chunks with 84 blocks: 0.181%; avg_num_integers_per_block = 1.75195
	sparse chunks with 85 blocks: 0.176908%; avg_num_integers_per_block = 1.75634
	sparse chunks with 86 blocks: 0.174504%; avg_num_integers_per_block = 1.7746
	sparse chunks with 87 blocks: 0.171364%; avg_num_integers_per_block = 1.78827
	sparse chunks with 88 blocks: 0.168637%; avg_num_integers_per_block = 1.77551
	sparse chunks with 89 blocks: 0.166271%; avg_num_integers_per_block = 1.77807
	sparse chunks with 90 blocks: 0.163748%; avg_num_integers_per_block = 1.8038
	sparse chunks with 91 blocks: 0.16117%; avg_num_integers_per_block = 1.7981
	sparse chunks with 92 blocks: 0.159263%; avg_num_integers_per_block = 1.81268
	sparse chunks with 93 blocks: 0.156436%; avg_num_integers_per_block = 1.81804
	sparse chunks with 94 blocks: 0.15529%; avg_num_integers_per_block = 1.82162
	sparse chunks with 95 blocks: 0.151293%; avg_num_integers_per_block = 1.84754
	sparse chunks with 96 blocks: 0.14994%; avg_num_integers_per_block = 1.83948
	sparse chunks with 97 blocks: 0.147789%; avg_num_integers_per_block = 1.83376
	sparse chunks with 98 blocks: 0.146362%; avg_num_integers_per_block = 1.85308
	sparse chunks with 99 blocks: 0.14519%; avg_num_integers_per_block = 1.88647
	sparse chunks with 100 blocks: 0.143539%; avg_num_integers_per_block = 1.88383
	sparse chunks with 101 blocks: 0.142204%; avg_num_integers_per_block = 1.88935
	sparse chunks with 102 blocks: 0.140952%; avg_num_integers_per_block = 1.9037
	sparse chunks with 103 blocks: 0.13784%; avg_num_integers_per_block = 1.89766
	sparse chunks with 104 blocks: 0.136899%; avg_num_integers_per_block = 1.91717
	sparse chunks with 105 blocks: 0.136064%; avg_num_integers_per_block = 1.93918
	sparse chunks with 106 blocks: 0.133237%; avg_num_integers_per_block = 1.91741
	sparse chunks with 107 blocks: 0.131071%; avg_num_integers_per_block = 1.94077
	sparse chunks with 108 blocks: 0.129354%; avg_num_integers_per_block = 1.96051
	sparse chunks with 109 blocks: 0.127552%; avg_num_integers_per_block = 1.9512
	sparse chunks with 110 blocks: 0.126757%; avg_num_integers_per_block = 1.95386
	sparse chunks with 111 blocks: 0.124523%; avg_num_integers_per_block = 1.97151
	sparse chunks with 112 blocks: 0.12411%; avg_num_integers_per_block = 1.98742
	sparse chunks with 113 blocks: 0.122736%; avg_num_integers_per_block = 2.00817
	sparse chunks with 114 blocks: 0.120484%; avg_num_integers_per_block = 2.01974
	sparse chunks with 115 blocks: 0.119368%; avg_num_integers_per_block = 2.01239
	sparse chunks with 116 blocks: 0.118684%; avg_num_integers_per_block = 2.01774
	sparse chunks with 117 blocks: 0.116605%; avg_num_integers_per_block = 2.04214
	sparse chunks with 118 blocks: 0.116352%; avg_num_integers_per_block = 2.05148
	sparse chunks with 119 blocks: 0.114952%; avg_num_integers_per_block = 2.07508
	sparse chunks with 120 blocks: 0.113551%; avg_num_integers_per_block = 2.05353
	sparse chunks with 121 blocks: 0.113687%; avg_num_integers_per_block = 2.0951
	sparse chunks with 122 blocks: 0.112214%; avg_num_integers_per_block = 2.07822
	sparse chunks with 123 blocks: 0.110717%; avg_num_integers_per_block = 2.10608
	sparse chunks with 124 blocks: 0.108897%; avg_num_integers_per_block = 2.10861
	sparse chunks with 125 blocks: 0.109832%; avg_num_integers_per_block = 2.12848
	sparse chunks with 126 blocks: 0.108317%; avg_num_integers_per_block = 2.13089
	sparse chunks with 127 blocks: 0.106638%; avg_num_integers_per_block = 2.1401
	sparse chunks with 128 blocks: 0.104262%; avg_num_integers_per_block = 2.13509
	sparse chunks with 129 blocks: 0.104822%; avg_num_integers_per_block = 2.16145
	sparse chunks with 130 blocks: 0.104338%; avg_num_integers_per_block = 2.15561
	sparse chunks with 131 blocks: 0.101826%; avg_num_integers_per_block = 2.17906
	sparse chunks with 132 blocks: 0.102444%; avg_num_integers_per_block = 2.20223
	sparse chunks with 133 blocks: 0.10061%; avg_num_integers_per_block = 2.18969
	sparse chunks with 134 blocks: 0.0997488%; avg_num_integers_per_block = 2.20566
	sparse chunks with 135 blocks: 0.099811%; avg_num_integers_per_block = 2.22956
	sparse chunks with 136 blocks: 0.0982599%; avg_num_integers_per_block = 2.24726
	sparse chunks with 137 blocks: 0.0981977%; avg_num_integers_per_block = 2.25706
	sparse chunks with 138 blocks: 0.0968793%; avg_num_integers_per_block = 2.27015
	sparse chunks with 139 blocks: 0.0957575%; avg_num_integers_per_block = 2.27128
	sparse chunks with 140 blocks: 0.0952639%; avg_num_integers_per_block = 2.27609
	sparse chunks with 141 blocks: 0.0944772%; avg_num_integers_per_block = 2.29857
	sparse chunks with 142 blocks: 0.0943849%; avg_num_integers_per_block = 2.30701
	sparse chunks with 143 blocks: 0.0925889%; avg_num_integers_per_block = 2.32534
	sparse chunks with 144 blocks: 0.0928578%; avg_num_integers_per_block = 2.36337
	sparse chunks with 145 blocks: 0.0910719%; avg_num_integers_per_block = 2.3555
	sparse chunks with 146 blocks: 0.0907327%; avg_num_integers_per_block = 2.36864
	sparse chunks with 147 blocks: 0.0907026%; avg_num_integers_per_block = 2.39441
	sparse chunks with 148 blocks: 0.088999%; avg_num_integers_per_block = 2.4042
	sparse chunks with 149 blocks: 0.0882846%; avg_num_integers_per_block = 2.4049
	sparse chunks with 150 blocks: 0.0881642%; avg_num_integers_per_block = 2.44343
	sparse chunks with 151 blocks: 0.0875842%; avg_num_integers_per_block = 2.44699
	sparse chunks with 152 blocks: 0.0858605%; avg_num_integers_per_block = 2.45014
	sparse chunks with 153 blocks: 0.0860571%; avg_num_integers_per_block = 2.50263
	sparse chunks with 154 blocks: 0.0853187%; avg_num_integers_per_block = 2.49118
	sparse chunks with 155 blocks: 0.0852705%; avg_num_integers_per_block = 2.54311
	sparse chunks with 156 blocks: 0.0843334%; avg_num_integers_per_block = 2.51778
	sparse chunks with 157 blocks: 0.0846986%; avg_num_integers_per_block = 2.56229
	sparse chunks with 158 blocks: 0.0831113%; avg_num_integers_per_block = 2.5625
	sparse chunks with 159 blocks: 0.0828645%; avg_num_integers_per_block = 2.58337
	sparse chunks with 160 blocks: 0.0827621%; avg_num_integers_per_block = 2.5961
	sparse chunks with 161 blocks: 0.0824792%; avg_num_integers_per_block = 2.62516
	sparse chunks with 162 blocks: 0.0815601%; avg_num_integers_per_block = 2.66817
	sparse chunks with 163 blocks: 0.0807394%; avg_num_integers_per_block = 2.64203
	sparse chunks with 164 blocks: 0.0818812%; avg_num_integers_per_block = 2.65462
	sparse chunks with 165 blocks: 0.0805106%; avg_num_integers_per_block = 2.67697
	sparse chunks with 166 blocks: 0.0799628%; avg_num_integers_per_block = 2.72368
	sparse chunks with 167 blocks: 0.080322%; avg_num_integers_per_block = 2.70574
	sparse chunks with 168 blocks: 0.0783575%; avg_num_integers_per_block = 2.75491
	sparse chunks with 169 blocks: 0.078809%; avg_num_integers_per_block = 2.75408
	sparse chunks with 170 blocks: 0.0773421%; avg_num_integers_per_block = 2.77103
	sparse chunks with 171 blocks: 0.0781427%; avg_num_integers_per_block = 2.78935
	sparse chunks with 172 blocks: 0.0789635%; avg_num_integers_per_block = 2.84837
	sparse chunks with 173 blocks: 0.0780705%; avg_num_integers_per_block = 2.84392
	sparse chunks with 174 blocks: 0.0765595%; avg_num_integers_per_block = 2.86902
	sparse chunks with 175 blocks: 0.0782551%; avg_num_integers_per_block = 2.88528
	sparse chunks with 176 blocks: 0.0763568%; avg_num_integers_per_block = 2.90411
	sparse chunks with 177 blocks: 0.0757969%; avg_num_integers_per_block = 2.93523
	sparse chunks with 178 blocks: 0.0763427%; avg_num_integers_per_block = 2.94908
	sparse chunks with 179 blocks: 0.0754096%; avg_num_integers_per_block = 2.94598
	sparse chunks with 180 blocks: 0.0740952%; avg_num_integers_per_block = 3.00349
	sparse chunks with 181 blocks: 0.0739688%; avg_num_integers_per_block = 3.01943
	sparse chunks with 182 blocks: 0.0745869%; avg_num_integers_per_block = 3.03241
	sparse chunks with 183 blocks: 0.0736317%; avg_num_integers_per_block = 3.04728
	sparse chunks with 184 blocks: 0.0733507%; avg_num_integers_per_block = 3.07375
	sparse chunks with 185 blocks: 0.0738484%; avg_num_integers_per_block = 3.11168
	sparse chunks with 186 blocks: 0.0726524%; avg_num_integers_per_block = 3.15051
	sparse chunks with 187 blocks: 0.0736457%; avg_num_integers_per_block = 3.14308
	sparse chunks with 188 blocks: 0.0730598%; avg_num_integers_per_block = 3.21294
	sparse chunks with 189 blocks: 0.0724718%; avg_num_integers_per_block = 3.22362
	sparse chunks with 190 blocks: 0.0732926%; avg_num_integers_per_block = 3.23631
	sparse chunks with 191 blocks: 0.0729675%; avg_num_integers_per_block = 3.29176
	sparse chunks with 192 blocks: 0.0720805%; avg_num_integers_per_block = 3.287
	sparse chunks with 193 blocks: 0.0720604%; avg_num_integers_per_block = 3.34889
	sparse chunks with 194 blocks: 0.0723474%; avg_num_integers_per_block = 3.35425
	sparse chunks with 195 blocks: 0.0724798%; avg_num_integers_per_block = 3.39928
	sparse chunks with 196 blocks: 0.0721006%; avg_num_integers_per_block = 3.45567
	sparse chunks with 197 blocks: 0.0727688%; avg_num_integers_per_block = 3.50842
	sparse chunks with 198 blocks: 0.0734671%; avg_num_integers_per_block = 3.53219
	sparse chunks with 199 blocks: 0.0735113%; avg_num_integers_per_block = 3.51133
	sparse chunks with 200 blocks: 0.073116%; avg_num_integers_per_block = 3.64708
	sparse chunks with 201 blocks: 0.0733066%; avg_num_integers_per_block = 3.65843
	sparse chunks with 202 blocks: 0.0727849%; avg_num_integers_per_block = 3.63771
	sparse chunks with 203 blocks: 0.0730036%; avg_num_integers_per_block = 3.68494
	sparse chunks with 204 blocks: 0.0730257%; avg_num_integers_per_block = 3.75956
	sparse chunks with 205 blocks: 0.0732023%; avg_num_integers_per_block = 3.80686
	sparse chunks with 206 blocks: 0.0741093%; avg_num_integers_per_block = 3.84767
	sparse chunks with 207 blocks: 0.0736638%; avg_num_integers_per_block = 3.88419
	sparse chunks with 208 blocks: 0.0741755%; avg_num_integers_per_block = 3.93488
	sparse chunks with 209 blocks: 0.0742698%; avg_num_integers_per_block = 3.95262
	sparse chunks with 210 blocks: 0.0754477%; avg_num_integers_per_block = 4.05115
	sparse chunks with 211 blocks: 0.0752732%; avg_num_integers_per_block = 4.06596
	sparse chunks with 212 blocks: 0.0756504%; avg_num_integers_per_block = 4.14932
	sparse chunks with 213 blocks: 0.0753795%; avg_num_integers_per_block = 4.22715
	sparse chunks with 214 blocks: 0.0764692%; avg_num_integers_per_block = 4.33756
	sparse chunks with 215 blocks: 0.0765815%; avg_num_integers_per_block = 4.34091
	sparse chunks with 216 blocks: 0.0775307%; avg_num_integers_per_block = 4.40587
	sparse chunks with 217 blocks: 0.077322%; avg_num_integers_per_block = 4.47675
	sparse chunks with 218 blocks: 0.0785461%; avg_num_integers_per_block = 4.50094
	sparse chunks with 219 blocks: 0.0786946%; avg_num_integers_per_block = 4.62525
	sparse chunks with 220 blocks: 0.0789896%; avg_num_integers_per_block = 4.66317
	sparse chunks with 221 blocks: 0.07972%; avg_num_integers_per_block = 4.73489
	sparse chunks with 222 blocks: 0.0805488%; avg_num_integers_per_block = 4.86091
	sparse chunks with 223 blocks: 0.0810023%; avg_num_integers_per_block = 4.90105
	sparse chunks with 224 blocks: 0.0828224%; avg_num_integers_per_block = 5.04146
	sparse chunks with 225 blocks: 0.083013%; avg_num_integers_per_block = 5.15591
	sparse chunks with 226 blocks: 0.0845722%; avg_num_integers_per_block = 5.22383
	sparse chunks with 227 blocks: 0.085118%; avg_num_integers_per_block = 5.39089
	sparse chunks with 228 blocks: 0.0870244%; avg_num_integers_per_block = 5.5196
	sparse chunks with 229 blocks: 0.0875862%; avg_num_integers_per_block = 5.67595
	sparse chunks with 230 blocks: 0.0884431%; avg_num_integers_per_block = 5.74584
	sparse chunks with 231 blocks: 0.0909816%; avg_num_integers_per_block = 5.88037
	sparse chunks with 232 blocks: 0.0912986%; avg_num_integers_per_block = 6.03167
	sparse chunks with 233 blocks: 0.0931307%; avg_num_integers_per_block = 6.15711
	sparse chunks with 234 blocks: 0.0949107%; avg_num_integers_per_block = 6.35058
	sparse chunks with 235 blocks: 0.0959702%; avg_num_integers_per_block = 6.53279
	sparse chunks with 236 blocks: 0.098294%; avg_num_integers_per_block = 6.76082
	sparse chunks with 237 blocks: 0.102046%; avg_num_integers_per_block = 6.91264
	sparse chunks with 238 blocks: 0.104274%; avg_num_integers_per_block = 7.17338
	sparse chunks with 239 blocks: 0.106762%; avg_num_integers_per_block = 7.48697
	sparse chunks with 240 blocks: 0.111424%; avg_num_integers_per_block = 7.7775
	sparse chunks with 241 blocks: 0.113463%; avg_num_integers_per_block = 8.06199
	sparse chunks with 242 blocks: 0.11867%; avg_num_integers_per_block = 8.38389
	sparse chunks with 243 blocks: 0.123745%; avg_num_integers_per_block = 8.80267
	sparse chunks with 244 blocks: 0.127997%; avg_num_integers_per_block = 9.15584
	sparse chunks with 245 blocks: 0.134425%; avg_num_integers_per_block = 9.68411
	sparse chunks with 246 blocks: 0.142219%; avg_num_integers_per_block = 10.1846
	sparse chunks with 247 blocks: 0.150336%; avg_num_integers_per_block = 10.7796
	sparse chunks with 248 blocks: 0.161633%; avg_num_integers_per_block = 11.3539
	sparse chunks with 249 blocks: 0.174165%; avg_num_integers_per_block = 12.1477
	sparse chunks with 250 blocks: 0.190112%; avg_num_integers_per_block = 12.9308
	sparse chunks with 251 blocks: 0.209963%; avg_num_integers_per_block = 13.7849
	sparse chunks with 252 blocks: 0.237488%; avg_num_integers_per_block = 14.9371
	sparse chunks with 253 blocks: 0.276669%; avg_num_integers_per_block = 16.2217
	sparse chunks with 254 blocks: 0.336942%; avg_num_integers_per_block = 17.6199
	sparse chunks with 255 blocks: 0.446863%; avg_num_integers_per_block = 19.1829
	sparse chunks with 256 blocks: 0.996577%; avg_num_integers_per_block = 20.7662
	expected_value 50.1083
