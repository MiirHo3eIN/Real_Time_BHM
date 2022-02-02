

#include <stdint.h>

const float eig_buff[] = {
		0.14030892,
		0.14854299,
		-0.12840097,
		-0.1503178,
		0.119967185,
		-0.18687358,
		0.10216162,
		0.1645606,
		-0.054672825999999994,
		0.1554669,
		-0.09276276,
		0.12053661,
		-0.07173237,
		0.14058897,
		0.14630355,
		-0.13070488,
		-0.14300287,
		0.12398035,
		-0.16808914,
		0.10943586400000001,
		0.1396581,
		-0.07034577,
		0.13356115,
		-0.10153084,
		0.09970146,
		-0.08163245,
		0.14078334,
		0.14328513,
		-0.13222075,
		-0.13266373,
		0.12600113,
		-0.14086117,
		0.11333632,
		0.10058371,
		-0.08558902,
		0.09178038,
		-0.101845615,
		0.05429291,
		-0.085379764,
		0.14062825,
		0.1412773,
		-0.13095912,
		-0.12570748,
		0.12108299,
		-0.12134754,
		0.10560183,
		0.07296283,
		-0.081569165,
		0.05694653,
		-0.08143701,
		0.016457215,
		-0.06412756,
		0.14036909,
		0.13833052,
		-0.12889148,
		-0.11529247,
		0.114006065,
		-0.09371628,
		0.0936704,
		0.033369523,
		-0.07434951,
		0.0068699447,
		-0.050416175,
		-0.03707473,
		-0.032691125,
		0.13976467,
		0.13385728,
		-0.12409317,
		-0.09957492,
		0.100254215,
		-0.05464915,
		0.06981258,
		-0.020054793,
		-0.053390134000000006,
		-0.060465622999999996,
		0.003381438,
		-0.10313259,
		0.022219775,
		0.13904274,
		0.12989838,
		-0.118345305,
		-0.08606230000000001,
		0.08451177,
		-0.022940533,
		0.043408602000000004,
		-0.059664222999999995,
		-0.025677587999999998,
		-0.10806931,
		0.05376351,
		-0.13984887,
		0.07134961,
		0.13829212,
		0.12659873,
		-0.11226322,
		-0.075295895,
		0.0684721,
		-0.00015330358,
		0.018139523,
		-0.08259631,
		0.0027811240000000003,
		-0.13106148,
		0.09075337,
		-0.14463247,
		0.103824444,
		0.13717106,
		0.12213392599999999,
		-0.103184745,
		-0.06123542,
		0.04611435,
		0.026633646,
		-0.016257668,
		-0.10379211599999999,
		0.04176706,
		-0.1449925,
		0.12856378,
		-0.12645647,
		0.12971555,
		0.1357609,
		0.11660596,
		-0.092061825,
		-0.044411864,
		0.020349607,
		0.055145312,
		-0.05292661,
		-0.119749404,
		0.079973266,
		-0.14448018,
		0.15000935,
		-0.0869906,
		0.13095419,
		0.13427451,
		0.110855155,
		-0.08056015,
		-0.027600434,
		-0.004749185,
		0.0803154,
		-0.08536364,
		-0.12790741,
		0.10990388,
		-0.13065710000000003,
		0.15128298,
		-0.03741843,
		0.10857716,
		0.13259944,
		0.104494534,
		-0.06809476,
		-0.009906404,
		-0.03000518,
		0.10257968,
		-0.11312605,
		-0.12719947,
		0.12936218,
		-0.102580965,
		0.12997223,
		0.018626554,
		0.064146146,
		0.13113654,
		0.09898624,
		-0.057519585,
		0.0046467367,
		-0.049919605,
		0.117530115,
		-0.1308466,
		-0.12050313,
		0.13624747,
		-0.07231855400000001,
		0.0991045,
		0.061884873,
		0.018582951,
		0.12931098,
		0.09221703,
		-0.04475735,
		0.021426609,
		-0.071298584,
		0.13035576,
		-0.14386703,
		-0.10466177,
		0.13123934,
		-0.029753497,
		0.049030565,
		0.10299721,
		-0.037779003,
		0.12746939,
		0.08541207,
		-0.032183677,
		0.037212800000000004,
		-0.08995119,
		0.13851947,
		-0.14977333,
		-0.08433454,
		0.11664756400000001,
		0.012849766,
		-0.0036636577,
		0.12939118,
		-0.084920056,
		0.12534165,
		0.07777765,
		-0.018387178,
		0.053549714000000005,
		-0.107409805,
		0.14227207,
		-0.14771639,
		-0.056744505,
		0.089773744,
		0.05759719,
		-0.06030838,
		0.13902934,
		-0.11943887,
		0.12334300000000001,
		0.07069226,
		-0.0059143845,
		0.067496784,
		-0.12064829,
		0.1414697,
		-0.13952833,
		-0.029606732,
		0.059747837000000005,
		0.09248773,
		-0.10341236,
		0.13171557,
		-0.13186115,
		0.12114554,
		0.06311515,
		0.0069698934,
		0.08088786,
		-0.13106292,
		0.13573736,
		-0.123712376,
		0.0007225125999999999,
		0.023021653,
		0.12049855,
		-0.13553873,
		0.10617412,
		-0.121253185,
		0.11844512,
		0.053977545,
		0.022026984,
		0.09508937599999999,
		-0.13943145,
		0.12434731,
		-0.09858811,
		0.035466313,
		-0.021408862999999997,
		0.14065342,
		-0.15334558,
		0.061371937,
		-0.08604036,
		0.11545475,
		0.04407135400000001,
		0.03769057,
		0.10841655,
		-0.14422357,
		0.107235335,
		-0.06571871,
		0.07015483,
		-0.066894464,
		0.14692725,
		-0.14928949,
		0.0036205271999999998,
		-0.0302904,
		0.113162264,
		0.036598925,
		0.04901154,
		0.11708022,
		-0.14472689,
		0.09157653,
		-0.038939997999999997,
		0.09188177,
		-0.09519276,
		0.14021670000000003,
		-0.13012534,
		-0.03852685,
		0.014414436999999999,
		0.110229135,
		0.027359613999999997,
		0.062298078,
		0.12548330000000002,
		-0.14136115,
		0.06914505,
		-0.0036591145,
		0.11277176400000001,
		-0.121436425,
		0.11751529,
		-0.08783452,
		-0.08543467,
		0.06741961,
		0.1069474,
		0.017282994,
		0.07607514,
		0.13235421,
		-0.13393568,
		0.042935137000000005,
		0.034104645,
		0.12763785,
		-0.13807161,
		0.081585936,
		-0.03067167,
		-0.122558765,
		0.11046601,
		0.10394945,
		0.008368806999999999,
		0.08746647,
		0.13643925,
		-0.12360675,
		0.01820117,
		0.06593183400000001,
		0.1332474,
		-0.14101018,
		0.042085264000000004,
		0.024058696,
		-0.13913937,
		0.12916331,
		0.100918606,
		-0.00038652099999999997,
		0.09784724,
		0.13838966,
		-0.11061448,
		-0.0063847825,
		0.09349023,
		0.13074155,
		-0.13204265,
		0.00013522403999999998,
		0.07379834,
		-0.13664618,
		0.12427029,
		0.098458685,
		-0.0072410433,
		0.10531282,
		0.13834834,
		-0.09792448,
		-0.02579556,
		0.111966565,
		0.123074375,
		-0.11676969400000001,
		-0.0332044,
		0.10630664,
		-0.121340215,
		0.104225285,
		0.095452875,
		-0.015381764,
		0.11338262,
		0.1361259,
		-0.08099518,
		-0.047621067999999996,
		0.12840176,
		0.106858864,
		-0.08922006,
		-0.06978591,
		0.13181510000000002,
		-0.08756877,
		0.06268381,
		0.09201582,
		-0.024302882999999997,
		0.12123980000000001,
		0.13146898,
		-0.06024901,
		-0.070073225,
		0.14014263,
		0.08265491,
		-0.051018342,
		-0.10428628,
		0.14329967,
		-0.03876086,
		0.005974066,
		0.088517025,
		-0.03303612,
		0.12800345,
		0.12478299,
		-0.038234193,
		-0.08957819,
		0.14432885,
		0.05350324,
		-0.009006773000000001,
		-0.1283682,
		0.13570337,
		0.014909678999999999,
		-0.051162597000000004,
		0.08468465,
		-0.04220981,
		0.1339582,
		0.115592204,
		-0.013777526000000002,
		-0.10740036,
		0.14151372,
		0.019310014,
		0.036841556,
		-0.14254358,
		0.110022575,
		0.069980465,
		-0.102969214,
		0.08136643,
		-0.04981364,
		0.13792334,
		0.106049545,
		0.0073976219999999995,
		-0.11885327,
		0.13213970000000003,
		-0.010956317,
		0.072500855,
		-0.14149913,
		0.07436768,
		0.10778889999999999,
		-0.12941305,
		0.07774448,
		-0.057726134000000005,
		0.14090718,
		0.09431791,
		0.029784199999999997,
		-0.12740068,
		0.11605664,
		-0.04270679,
		0.104943044,
		-0.12880512,
		0.02784087,
		0.13471639,
		-0.13661256,
		0.07423930000000001,
		-0.06505767,
		0.14259458,
		0.08165842,
		0.050244167,
		-0.13122885,
		0.09503789,
		-0.070784874,
		0.12746496,
		-0.1051578,
		-0.019947587,
		0.14353284,
		-0.1205355,
		0.07052171,
		-0.07234865,
		0.14306268,
		0.06727368,
		0.07026256,
		-0.13097098,
		0.06886473,
		-0.095620215,
		0.14049277,
		-0.07213636,
		-0.066622056,
		0.13419244,
		-0.08364382,
		0.06697682,
		-0.07896862,
		0.14243181,
		0.052686717,
		0.08750745,
		-0.12659484,
		0.04101345,
		-0.11419707,
		0.14212988,
		-0.03492058,
		-0.10319812,
		0.10966416,
		-0.035618037000000005,
		0.06299114,
		-0.085896544,
		0.14034012,
		0.03587279,
		0.10408717,
		-0.1176942,
		0.008292398000000001,
		-0.12760812,
		0.13204631,
		0.008759084,
		-0.12985986,
		0.06781301,
		0.023259519,
		0.057537105,
		-0.09486855,
		0.1358845,
		0.012593556,
		0.12272016,
		-0.10058584,
		-0.036668353,
		-0.13603285,
		0.10353323,
		0.06744774,
		-0.1439776,
		-0.0005332949,
		0.09750997,
		0.05405677,
		-0.10014106,
		0.13199046,
		-0.0024554695000000002,
		0.13205595,
		-0.08681903,
		-0.06326498,
		-0.13482791,
		0.07858501,
		0.09884791,
		-0.13766608,
		-0.043437894000000005,
		0.12986764,
		0.050178047,
		-0.10563337,
		0.1266095,
		-0.019124223,
		0.13901676,
		-0.06867816,
		-0.08992633,
		-0.12599975,
		0.04431389,
		0.12551035,
		-0.113388166,
		-0.08551972,
		0.1442473,
		0.04575346,
		-0.11134392,
		0.11932265,
		-0.037409252999999996,
		0.14326642,
		-0.046312712,
		-0.11489492,
		-0.10823982,
		0.002594981,
		0.14284898,
		-0.07167863,
		-0.120699555,
		0.13409407,
		0.04193881,
		-0.11586465,
		0.11217172,
		-0.05276527,
		0.14354503,
		-0.025347266,
		-0.13142120000000002,
		-0.08734529,
		-0.033902816,
		0.14642695,
		-0.026987165,
		-0.13669454,
		0.104430795,
		0.037313506,
		-0.12073974,
		0.10248305,
		-0.06997988,
		0.14022641,
		6.2694235e-05,
		-0.1440134,
		-0.05689815,
		-0.07376275,
		0.13605537,
		0.029308748,
		-0.13669918,
		0.049584175999999994,
		0.033444777,
		-0.124389395,
		0.09362104,
		-0.083531454,
		0.13412505,
		0.02156855,
		-0.14815372,
		-0.028525400000000003,
		-0.10188675,
		0.11662341,
		0.07357982,
		-0.12027885,
		-0.00423347,
		0.02889421,
		-0.12811069,
		0.08232563,
		-0.09773766,
		0.12368566,
		0.045333304000000005,
		-0.14509141,
		0.006255752,
		-0.12495772,
		0.082642905,
		0.114415646,
		-0.08460693,
		-0.06577575,
		0.023405642999999997,
		-0.1320039,
		0.067902036,
		-0.112828024,
		0.10723474599999999,
		0.0720513,
		-0.1323177,
		0.04785078,
		-0.14004658,
		0.03267693,
		0.14605358,
		-0.027134929,
		-0.12543514,
		0.01881083,
		-0.13470523,
		0.055244602000000004,
		-0.12366211,
		0.09077449,
		0.091689005,
		-0.11494481,
		0.079522334,
		-0.14010802,
		-0.0121459365,
		0.15285283,
		0.02377285,
		-0.15235516,
		0.014867525,
		-0.13656639,
		0.043923616,
		-0.13146499,
		0.074274704,
		0.10601652,
		-0.09484335,
		0.10258163,
		-0.12993203,
		-0.04955696,
		0.1418369,
		0.06527403,
		-0.1515931,
		0.010150264,
		-0.13816494,
		0.030075964,
		-0.13825843,
		0.05306224,
		0.118745714,
		-0.06602000000000001,
		0.12346265,
		-0.10564517,
		-0.08906792,
		0.10860915,
		0.10439484,
		-0.121899925,
		0.006032444499999999,
		-0.13912247,
		0.017757148,
		-0.14238611,
		0.0330123,
		0.12641433,
		-0.037707616,
		0.13523373,
		-0.07663327,
		-0.11603514,
		0.06757539,
		0.12677872,
		-0.07658005,
		0.0013691314000000001,
		-0.13957997,
		0.0036367142999999998,
		-0.14440644,
		0.009919651,
		0.13001163,
		-0.0040007443,
		0.13986109,
		-0.03662388,
		-0.13482594,
		0.011448502,
		0.13282950000000002,
		-0.011391813999999998,
		-0.0031673328000000004,
		-0.13957144,
		-0.010124053000000001,
		-0.14437214,
		-0.013089916000000002,
		0.12957494,
		0.029348394,
		0.13675335,
		0.0050679016999999995,
		-0.14154589,
		-0.044311974000000004,
		0.12313900000000001,
		0.054212544,
		-0.0066902624,
		-0.13906908,
		-0.020750456,
		-0.14229539,
		-0.03087122,
		0.12537031,
		0.053805675,
		0.12787056,
		0.03738797,
		-0.13629597,
		-0.08327655,
		0.10129664,
		0.09722275,
		-0.012016727,
		-0.13771982,
		-0.03658359,
		-0.136854,
		-0.05638066,
		0.11437348,
		0.088182144,
		0.10540802,
		0.08205868,
		-0.11341851,
		-0.12933233,
		0.053455744000000006,
		0.14255771,
		-0.015999988,
		-0.13620968,
		-0.048205635999999996,
		-0.1306604,
		-0.0744138,
		0.102441184,
		0.109632544,
		0.08342942,
		0.10984996,
		-0.08735743,
		-0.14974827,
		0.010580288,
		0.1545071,
		-0.01957298,
		-0.13444929,
		-0.058327492,
		-0.12343353,
		-0.0893972,
		0.08868186,
		0.124677464,
		0.059193138,
		0.12686777,
		-0.05658200000000001,
		-0.1513938,
		-0.028494428999999998,
		0.14253442,
		-0.025242696000000002,
		-0.13094477,
		-0.07361616,
		-0.109702215,
		-0.10922362,
		0.0632486,
		0.14026491,
		0.016856775,
		0.14063884,
		-0.0022101125,
		-0.13107777,
		-0.08637285,
		0.09205563,
		-0.028593017000000002,
		-0.1285618,
		-0.08226506,
		-0.10008426,
		-0.11974901,
		0.046259552,
		0.14479834,
		-0.009346284,
		0.14020692,
		0.031070612,
		-0.106227,
		-0.1119987,
		0.05018643,
		-0.033562444,
		-0.1242735,
		-0.09421489,
		-0.08408772,
		-0.13094924,
		0.019380054,
		0.14204842,
		-0.047184847,
		0.12516467,
		0.07620975,
		-0.053351055999999994,
		-0.1331167,
		-0.02370265,
		-0.038039606000000004,
		-0.11993094,
		-0.104283065,
		-0.06832225,
		-0.13820639999999998,
		-0.0057938980000000005,
		0.13315265,
		-0.07934514,
		0.100677915,
		0.11109995,
		0.0020710023000000003,
		-0.1339473,
		-0.086196505,
		-0.04195799,
		-0.115626544,
		-0.11224966,
		-0.05318345,
		-0.14099096,
		-0.027975986,
		0.11844473,
		-0.10253314,
		0.07147631,
		0.13151787,
		0.049767822,
		-0.11879021,
		-0.12734684,
		-0.04690401,
		-0.10967371599999999,
		-0.12130816,
		-0.033389416,
		-0.14096162,
		-0.05496074,
		0.09380188,
		-0.12639797,
		0.027000287999999997,
		0.14523442,
		0.10438195,
		-0.08084829,
		-0.15441403,
		-0.04939837,
		-0.10640594,
		-0.12517446,
		-0.022400236,
		-0.13842072,
		-0.068199724,
		0.07797893,
		-0.13319795,
		0.0034468477,
		0.143592,
		0.1232121,
		-0.05573517,
		-0.15230413,
		-0.05390538,
		-0.09995939,
		-0.13107717,
		-0.003046019,
		-0.130663,
		-0.08899736,
		0.045414202,
		-0.13866684,
		-0.041174196,
		0.12725775,
		0.14219615,
		0.00012460844,
		-0.11797915,
		-0.059193917,
		-0.09172119,
		-0.13656549,
		0.019947878999999998,
		-0.11706466,
		-0.10965311,
		0.003647445,
		-0.13416307,
		-0.088762425,
		0.09243185,
		0.14067902,
		0.06414413,
		-0.053003564,
		-0.06226467,
		-0.08663452,
		-0.13884217,
		0.033490583,
		-0.10666489,
		-0.11943524,
		-0.020789424,
		-0.12594958,
		-0.11209359,
		0.06599303,
		0.12670416,
		0.09714484,
		-0.0061166864,
		-0.0671878,
		-0.07781847,
		-0.14106824,
		0.054505117,
		-0.08646669,
		-0.12959255,
		-0.059725272999999995,
		-0.10256703,
		-0.13661261,
		0.014588715,
		0.08281632,
		0.13164587,
		0.06865601,
		-0.070581324,
		-0.071461074,
		-0.14157781,
		0.06860689,
		-0.070542395,
		-0.1335336,
		-0.08417896,
		-0.08205658,
		-0.14574779999999998,
		-0.021901136,
		0.04407111,
		0.14402685,
		0.11366624,
		-0.074723154,
		-0.06313574,
		-0.14067431,
		0.08485506,
		-0.04835447,
		-0.13280176,
		-0.110036135,
		-0.049856473,
		-0.1408864,
		-0.06573825,
		-0.011922776000000001,
		0.13368827,
		0.1428343,
		-0.07846974,
		-0.05529749,
		-0.13869514,
		0.09851663,
		-0.02723271,
		-0.12830846,
		-0.12850377,
		-0.018673597,
		-0.12742242,
		-0.10011941,
		-0.061071545,
		0.111251265,
		0.15024075,
		-0.081187114,
		-0.04927063,
		-0.13616492,
		0.107556485,
		-0.010125683,
		-0.12136436,
		-0.13715033,
		0.006295144,
		-0.10741957,
		-0.11877904,
		-0.09205785,
		0.07994772,
		0.13124645,
		-0.08476453,
		-0.04102937,
		-0.13178542,
		0.11786640400000001,
		0.012038084,
		-0.10838358,
		-0.14235736,
		0.037991986,
		-0.07463661,
		-0.13378355,
		-0.12242761,
		0.032340176,
		0.09019324,
		-0.08809471,
		-0.032920897000000005,
		-0.12636374,
		0.12588835,
		0.033406727000000004,
		-0.09175067,
		-0.14006934,
		0.067052394,
		-0.034610674,
		-0.13554016,
		-0.13532627,
		-0.021429647000000003,
		0.029751282,
		-0.09172715,
		-0.023801686000000002,
		-0.11931303,
		0.13286825,
		0.055821378,
		-0.07068546,
		-0.13094957,
		0.094551414,
		0.01021662,
		-0.12621357,
		-0.13391833,
		-0.07432253,
		-0.036457177,
		-0.095541485,
		-0.013765693,
		-0.11031399,
		0.13796851,
		0.07871923,
		-0.04447858,
		-0.11282515,
		0.11858545,
		0.060378596,
		-0.101367496,
		-0.11031971,
		-0.12375879,
		-0.10653611,
		-0.09858266,
		-0.0055167587,
		-0.10210666,
		0.1401821,
		0.095695116,
		-0.021950446000000002,
		-0.093165345,
		0.13104905,
		0.09441648400000001,
		-0.07380282,
		-0.0802321,
		-0.14619105,
		-0.14216806,
		-0.10172404,
		0.0033569476,
		-0.092362925,
		0.14032647,
		0.11167378,
		0.0034620827000000002,
		-0.067120105,
		0.13740906,
		0.12549943,
		-0.036296662,
		-0.03528796,
		-0.1541928,
		-0.16024885,
		-0.1046289,
		0.011796748000000001,
		-0.08235241,
		0.13837092,
		0.12396326,
		0.027357303,
		-0.039416562999999995,
		0.1349437,
		0.1425774,
		0.0011918895,
		0.009382757,
		-0.13965339999999998,
		-0.14657608,
		-0.1074674,
		0.020343008,
		-0.07146789,
		0.13428803,
		0.13378803,
		0.05128159400000001,
		-0.0090537295,
		0.12547812,
		0.15074565,
		0.040592305,
		0.056446366,
		-0.10944886,
		-0.11111178,
		-0.11009537,
		0.028413331,
		-0.060549133,
		0.12849107,
		0.13985263,
		0.07211501,
		0.01975948,
		0.109182686,
		0.14485957,
		0.072944656,
		0.091502585,
		-0.06578438,
		-0.057345394,
		-0.11299010000000001,
		0.037597906,
		-0.047418382,
		0.1199383,
		0.14340107,
		0.094012074,
		0.05242541,
		0.08440996,
		0.12772015,
		0.10537806,
		0.123501815,
		-0.007657741,
		0.013785994,
		-0.11536949,
		0.045320667,
		-0.035819046,
		0.11081425,
		0.14288431,
		0.109655954,
		0.07743944,
		0.058124114000000004,
		0.1013806,
		0.122544736,
		0.13311455,
		0.04368624,
		0.072653934,
		-0.11764453,
		0.052953112999999996,
		-0.023843331000000002,
		0.100135684,
		0.13934883,
		0.12274659,
		0.099747665,
		0.028784016000000003,
		0.068871796,
		0.13189371,
		0.13142173,
		0.09023925,
		0.121644184,
		-0.12016030400000001,
		0.06149886,
		-0.009848127,
		0.08636512,
		0.13124907,
		0.13280746,
		0.11942534,
		-0.0070063975,
		0.023615432999999998,
		0.12772088,
		0.10777092,
		0.13070838,
		0.15360452,
		-0.12204148,
		0.06811998,
		0.0013163199,
		0.07416857,
		0.12216848,
		0.13775375,
		0.13051951,
		-0.035050996,
		-0.012618161999999999,
		0.11630087,
		0.080826156,
		0.14892875,
		0.1586958,
		-0.124363974,
		0.07632717,
		0.015688945,
		0.057560243,
		0.10702535,
		0.13832945,
		0.13699941,
		-0.06879855,
		-0.05957821,
		0.088085234,
		0.030973554,
		0.15005772,
		0.13198089999999998,
		-0.12666349,
		0.08466771,
		0.030655487999999998,
		0.03917537,
		0.08816167,
		0.13411070000000003,
		0.13655567,
		-0.09967843,
		-0.10219001,
		0.051166500000000004,
		-0.022710286,
		0.13011819,
		0.080983445,
		-0.1292423,
		0.09414244,
		0.048198592,
		0.016640666999999998,
		0.062580235,
		0.12235479,
		0.12616022,
		-0.12864846,
		-0.14268036,
		-0.0010478856,
		-0.08631933,
		0.08160014,
		-0.0027795946,
		-0.13093562,
		0.10052931,
		0.060181092,
		0.00032824997000000005,
		0.042747207,
		0.11072848,
		0.11322678,
		-0.14236352,
		-0.15948017,
		-0.036794953,
		-0.11866627,
		0.03813283,
		-0.058926657,
		-0.13251536,
		0.106493436,
		0.07165004,
		-0.015902555,
		0.021559464,
		0.09488338,
		0.09406918,
		-0.14759015,
		-0.16356955,
		-0.07068252,
		-0.13855185,
		-0.011984213,
		-0.10823321,
		-0.13380489,
		0.11149546,
		0.08135409,
		-0.030268722999999997,
		0.002070638,
		0.07839084,
		0.07334233,
		-0.14518812,
		-0.15494606,
		-0.09438767,
		-0.13901706,
		-0.054014854,
		-0.13311447,
		-0.13493872,
		0.11586705,
		0.08993832,
		-0.043414562999999996,
		-0.016827635,
		0.05983265,
		0.04989236,
		-0.13508523,
		-0.13596824,
		-0.11058929,
		-0.12656583,
		-0.089248404,
		-0.13994159,
		-0.13638766,
		0.12162868,
		0.10138672,
		-0.061322477,
		-0.042719337999999996,
		0.0312329,
		0.014030028,
		-0.11174134,
		-0.095133744,
		-0.12086387,
		-0.08776678,
		-0.12424165,
		-0.11782311,
		-0.13752738,
		0.12610844,
		0.11040539999999999,
		-0.07570737,
		-0.064442165,
		0.0049904929999999995,
		-0.018173294,
		-0.08469538,
		-0.05217198,
		-0.119846955,
		-0.04484946,
		-0.13980131,
		-0.08103667,
		-0.13846311,
		0.13026129,
		0.11807929,
		-0.089651905,
		-0.08372616,
		-0.023187414,
		-0.047769766,
		-0.04962234,
		-0.005123605,
		-0.10199430599999999,
		0.003130712,
		-0.12946615,
		-0.029492962999999997,
		-0.13938852,
		0.1351076,
		0.12563019,
		-0.10653928,
		-0.10315216,
		-0.06163885,
		-0.07845373,
		0.0038948453,
		0.050147217,
		-0.06057559,
		0.052359242,
		-0.08729742,
		0.029364191,
		-0.13980608,
		0.13786055,
		0.12909134,
		-0.11624162,
		-0.113013335,
		-0.08511615,
		-0.09294095,
		0.038311355,
		0.07979756,
		-0.02761577,
		0.07575,
		-0.048882115999999996,
		0.060181107000000005,
		-0.14005925,
		0.14047296,
		0.13104135,
		-0.12553084,
		-0.11921411,
		-0.10964533,
		-0.10132332,
		0.07518378,
		0.10082116,
		0.01161573,
		0.08415083,
		-0.0021028742000000003,
		0.07417755,
		-0.14005752,
		0.14397901,
		0.13097316,
		-0.13780673,
		-0.12025134,
		-0.14176622,
		-0.10009193400000001,
		0.12275289,
		0.11125766,
		0.06800444,
		0.07312063,
		0.062523805,
		0.068012245,
		-0.13986455,
		0.14695822,
		0.12927508,
		-0.1480401,
		-0.117485754,
		-0.1691371,
		-0.092650175,
		0.16093022,
		0.10977431,
		0.11248697,
		0.052753035,
		0.10830747,
		0.050812125,
		-0.13965021,
		0.14903018,
		0.12749797,
		-0.15476121,
		-0.114371076,
		-0.18694128,
		-0.08560563,
		0.18359481,
		0.1061559,
		0.13813056,
		0.040377386,
		0.13138111,
		0.0424798,
	};