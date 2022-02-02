float X[D_DIM][N_WINDOWS] = {{-0.2095392623},
       {-0.1873585888},
       {-0.1876488138},
       {-0.2113710256},
       {-0.1928609314},
       {-0.2235739878},
       {-0.2130667891},
       {-0.2095863588},
       {-0.2256537748},
       {-0.2031181751},
       {-0.2028871358},
       {-0.2660361880},
       {-0.2458705193},
       {-0.2396782572},
       {-0.3061093221},
       {-0.3012947738},
       {-0.2993542255},
       {-0.3443247226},
       {-0.3065189727},
       {-0.2912100246},
       {-0.3282784709},
       {-0.3064363182},
       {-0.2486351320},
       {-0.2446821099},
       {-0.2150538378},
       {-0.2056475930},
       {-0.1446813957},
       {-0.1045016836},
       {-0.1047461534},
       {-0.1196242419},
       {-0.1029324027},
       {-0.0945358050},
       {-0.0532995224},
       {-0.0545962960},
       {-0.0794479218},
       {-0.1085006316},
       {-0.1158050422},
       {-0.1206369562},
       {-0.1196683988},
       {-0.1047439663},
       {-0.0861935600},
       {-0.1291702249},
       {-0.1124076218},
       {-0.0911634677},
       {-0.0699243419},
       {-0.0871721718},
       {-0.1203980569},
       {-0.1408467648},
       {-0.1481561924},
       {-0.1743049964},
       {-0.2034270546},
       {-0.2486558605},
       {-0.2836559409},
       {-0.2907939704},
       {-0.3158237861},
       {-0.2928039466},
       {-0.2983558600},
       {-0.2925034860},
       {-0.2469200046},
       {-0.2432888929},
       {-0.2124857357},
       {-0.2167374878},
       {-0.2157385575},
       {-0.1946242005},
       {-0.1798078088},
       {-0.1572668543},
       {-0.1367575862},
       {-0.1358529162},
       {-0.1155302140},
       {-0.0855393102},
       {-0.0623682681},
       {-0.0510288491},
       {-0.0694181111},
       {-0.0946387791},
       {-0.0719981698},
       {-0.1125738197},
       {-0.1308940406},
       {-0.1184443253},
       {-0.0935367345},
       {-0.0869495751},
       {-0.1098656767},
       {-0.1016763751},
       {-0.0717342607},
       {-0.0725469981},
       {-0.1002038223},
       {-0.1206043897},
       {-0.1233159438},
       {-0.1068428788},
       {-0.1164041180},
       {-0.1365668285},
       {-0.1092530076},
       {-0.1129290811},
       {-0.1009366755},
       {-0.1342123870},
       {-0.1568846777},
       {-0.1571028238},
       {-0.1248070882},
       {-0.0931571655},
       {-0.0375034847},
       {-0.0428419988}};
float Vinit[D_DIM][K_COMP] = {{-0.0447128565, 0.1224507705, 0.0403491642, 0.0593578523,
        -0.1094911846, 0.0169382433, 0.0740556451, -0.0953700602,
        -0.0266218506, 0.0032614547},
       {-0.1373117320, 0.0315159392, 0.0846160648, -0.0859515941,
        0.0350545979, -0.1312283411, -0.0038695509, -0.1615772355,
        0.1121417708, 0.0408900538},
       {-0.0024616956, -0.0775161619, 0.1273755930, 0.1967101749,
        -0.1857981864, 0.1236164030, 0.1627650753, 0.0338011697,
        -0.1199268032, 0.0863345318},
       {-0.0180920302, -0.0603920628, -0.1230058136, 0.0550537496,
        0.0792806866, -0.0623530730, 0.0520576337, -0.1144341390,
        0.0801861032, 0.0046567298},
       {-0.0186569772, -0.0101745873, 0.0868886157, 0.0750411640,
        0.0529465324, 0.0137701210, 0.0077821128, 0.0618380262,
        0.0232494559, 0.0682551407},
       {-0.0310116774, -0.2434837764, 0.1038824602, 0.2186979647,
        0.0441364444, -0.0100155233, -0.0136444744, -0.0119054188,
        0.0017409408, -0.1122018729},
       {-0.0517094458, -0.0997026828, 0.0248799161, -0.0296641152,
        0.0495211324, -0.0174703160, 0.0986335188, 0.0213533901,
        0.2190699729, -0.1896360923},
       {-0.0646916688, 0.0901486892, 0.2528325707, -0.0248634778,
        0.0043668993, -0.0226314243, 0.1331457113, -0.0287307863,
        0.0680069840, -0.0319801599},
       {-0.1272558755, 0.0313547720, 0.0503184813, 0.1293225883,
        -0.0110447026, -0.0617362064, 0.0562761097, 0.0240737092,
        0.0280665077, -0.0073112704},
       {0.1160338570, 0.0369492716, 0.1904658708, 0.1111056699,
        0.0659049796, -0.1627438341, 0.0602319280, 0.0420282204,
        0.0810951673, 0.1044442095},
       {-0.0400878192, 0.0824005618, -0.0562305431, 0.1954878075,
        -0.1331951667, -0.1760688560, -0.1650721266, -0.0890555584,
        -0.1119115399, 0.1956078904},
       {-0.0326499498, -0.1342675789, 0.1114382977, -0.0586523939,
        -0.1236853377, 0.0875838928, 0.0623362177, -0.0434956683,
        0.1407540000, 0.0129101580},
       {0.1616949599, 0.0502740882, 0.1558805541, 0.0109402696,
        -0.1219744397, 0.2449368649, -0.0545774168, -0.0198837863,
        -0.0700398505, -0.0203394449},
       {0.0242669441, 0.0201830179, 0.0661020288, 0.1792158209,
        -0.0120464572, -0.1233120735, -0.1182318127, -0.0665754518,
        -0.1674195808, 0.0825029824},
       {-0.0498213564, -0.0310984978, -0.0001891483, -0.1396620425,
        -0.0861316361, 0.0674711526, 0.0618539131, -0.0443171931,
        0.1810534914, -0.1305726923},
       {-0.0344987210, -0.0230839743, -0.2793085000, 0.1937528814,
        0.0366332015, -0.1044589382, 0.2051173443, 0.0585662000,
        0.0429526140, -0.0606998398},
       {0.0106222724, -0.1525680316, 0.0795026094, -0.0374438319,
        0.0134048197, 0.1202054862, 0.0284748111, 0.0262467445,
        0.0276499305, -0.0733271604},
       {0.0836004719, 0.1543359111, 0.0758805660, 0.0884908814,
        -0.0877281519, -0.0867787223, -0.1440876024, 0.1232253071,
        -0.0254179868, 0.1399843942},
       {-0.0781911683, -0.0437508983, 0.0095425087, 0.0921450069,
        0.0060750196, 0.0211124755, 0.0016527567, 0.0177187720,
        -0.1116470018, 0.0080927101},
       {-0.0186578994, -0.0056824481, 0.0492336556, -0.0680678141,
        -0.0084508027, -0.0297361883, 0.0417302005, 0.0784770651,
        -0.0955425262, 0.0585910431},
       {0.2065783320, -0.1471156926, -0.0830171895, -0.0880577600,
        -0.0279097722, 0.1622849086, 0.0013352676, -0.0694693595,
        0.0621803504, -0.0599804531},
       {0.1123412162, 0.0305267040, 0.1388779396, -0.0661344243,
        0.3030857112, 0.0824584625, 0.0654580153, -0.0051188448,
        -0.0725597119, -0.0867768678},
       {-0.0135977326, -0.0797269785, 0.0282675712, -0.0826097432,
        0.0621082701, 0.0956121704, -0.0705840507, 0.1192686068,
        -0.0237941936, 0.1155287886},
       {0.0438166347, 0.1122328322, -0.0997019796, -0.0106793987,
        0.1451429261, -0.0618036848, -0.2037201226, -0.1942589181,
        -0.2506440653, -0.2114163922},
       {-0.0411639163, 0.1278528083, -0.0442229280, 0.0323527354,
        -0.0109991490, 0.0008548945, -0.0168198840, -0.0174180344,
        0.0461164100, -0.1175982671},
       {0.1010127177, 0.0920017933, -0.0195057341, 0.0805393424,
        -0.0701344426, -0.0537223024, 0.0156263850, -0.0190221025,
        -0.0448738033, -0.0672448039},
       {-0.0557494722, 0.0939168744, -0.1943323406, 0.0352494364,
        -0.0236436952, 0.0727813500, 0.0515073614, -0.2782534468,
        0.0584646610, 0.0324274243},
       {0.0021862837, -0.0468673816, 0.0853281222, -0.0413029310,
        0.1834717627, 0.0564382855, 0.2137828067, -0.0785533997,
        -0.1755925640, 0.0714789597},
       {0.0852704062, 0.0035360097, -0.1538793246, -0.0447895185,
        0.0617985534, -0.0184176326, -0.0115985185, -0.0175458969,
        -0.0933914656, -0.0533020326},
       {-0.1426555421, 0.1767959948, -0.0475372875, 0.0477610182,
        -0.1021885945, 0.0794528240, -0.1873160978, 0.0920615118,
        -0.0035367925, 0.2110605054},
       {-0.1306534073, 0.0076380480, 0.0367231814, 0.1232899192,
        -0.0422856961, 0.0086464407, -0.2142466729, -0.0830168864,
        0.0451615951, 0.1104174326},
       {-0.0281736269, 0.2056355523, 0.1760249226, -0.0060652492,
        -0.2413503001, -0.1777566376, -0.0777858827, 0.1115841108,
        0.0310272288, -0.2094247816},
       {-0.0228765829, 0.1613361375, -0.0374804687, -0.0749969617,
        0.2054624103, 0.0053409537, -0.0479157099, 0.0350167159,
        0.0017164726, -0.0429142278},
       {0.1208456329, 0.1115701803, 0.0840861558, -0.0102887218,
        0.1146900376, -0.0049702579, 0.0466643267, 0.1033686868,
        0.0808844360, 0.1789754683},
       {0.0451284016, -0.1684059986, -0.1160170105, 0.1350106819,
        -0.0331283170, 0.0386539145, -0.0851455657, 0.1000881424,
        -0.0384832249, 0.1458108239},
       {-0.0532234021, 0.1118133397, 0.0674396105, -0.0722391905,
        0.1098996333, -0.0901634490, -0.0822467189, 0.0721711292,
        -0.0625342001, -0.0593843067},
       {-0.0343900709, -0.1000169190, 0.1044994410, 0.0608514698,
        -0.0069328697, -0.0108392067, 0.0450155513, 0.1765335101,
        0.0870969803, -0.0508457134},
       {0.0777419205, -0.0118771172, -0.0198998184, 0.1866471375,
        -0.0418937898, -0.0479184915, -0.1952105287, -0.1402329145,
        0.0451122939, -0.0694920901},
       {0.0515413802, -0.1114871052, -0.0767309826, 0.0674570707,
        0.1460892380, 0.0592472801, 0.1197830842, 0.1704594171,
        0.1040089153, -0.0918440038},
       {-0.0105344713, 0.0630195671, -0.0414846901, 0.0451946037,
        -0.1579156285, -0.0828627979, 0.0528879746, -0.2237086511,
        -0.1107712502, -0.0017718318},
       {-0.1719394475, 0.0057120996, -0.0799547491, -0.0291594596,
        -0.0258982853, 0.0189293198, -0.0563788735, 0.0089686407,
        -0.0601156801, 0.0556073510},
       {0.1693809113, 0.0196869779, 0.0169869255, -0.1164007971,
        0.0693366226, -0.0758067329, -0.0808847196, 0.0557439453,
        0.0181038744, 0.1107175451},
       {0.1442876928, -0.0539681562, 0.0128376990, 0.1760415184,
        0.0966539250, 0.0713049050, 0.1306206065, -0.0604602969,
        0.0636583409, 0.1409253389},
       {0.1620912286, -0.0806184817, -0.0251674208, 0.0382715174,
        -0.0288997343, -0.0391816240, 0.0684001328, -0.0353409983,
        -0.1787912891, 0.0361847316},
       {-0.0424492791, -0.0731530982, -0.1565738151, 0.1013822467,
        -0.2227112632, -0.1699333605, -0.0275846063, 0.1228955586,
        0.1309705906, -0.1154982635},
       {-0.0177632196, -0.1510456375, 0.1011207064, -0.1476562661,
        -0.0143195745, 0.1032983779, -0.0222414029, 0.1470160344,
        -0.0870008223, 0.0369190470},
       {0.0853282186, -0.0139711730, 0.1386314264, 0.0548129585,
        -0.1637449593, 0.3958602704, 0.0648643644, 0.0107343294,
        -0.1398812819, 0.0081767819},
       {-0.0459942831, 0.0644353666, 0.0371670291, 0.1853009485,
        0.0142251373, 0.0513505480, 0.0372456852, -0.0148489803,
        -0.0183400197, 0.1101000203},
       {0.0780027135, -0.0629441604, -0.1113436103, -0.0067410025,
        0.1161439982, -0.0027529386, 0.1746435089, -0.0775070287,
        0.0141640538, -0.2516303861},
       {-0.0595667881, -0.0309121319, 0.0510937774, 0.1710661839,
        0.0034943589, 0.1453917582, 0.0661681076, 0.0986352180,
        -0.0466154857, 0.1384991344},
       {-0.1072964279, 0.0495158611, -0.0952062101, -0.0518145552,
        -0.1461403605, -0.0516347909, 0.0351116897, -0.0068770463,
        -0.1347764941, 0.1470739857},
       {0.0337220938, 0.1008065433, 0.0785226920, -0.0664867767,
        -0.1945046959, -0.0915424368, 0.1225155849, -0.1053546074,
        0.0816043684, -0.0612406973},
       {0.0393109245, -0.1823919853, 0.1167075166, -0.0039668700,
        0.0885825799, 0.0189861649, 0.0798063795, -0.0101932039,
        0.0743356544, -0.1509572684},
       {-0.1080710692, 0.0725474004, -0.0039178256, -0.0228754171,
        -0.0179612295, 0.0501725109, -0.0593343754, 0.0510307597,
        -0.0915791849, -0.0407252043},
       {0.0984951672, 0.1071252428, -0.1097154360, 0.0838634747,
        -0.1039182322, 0.0733023232, -0.1898812059, -0.1117110692,
        -0.0508972278, -0.0166485955},
       {0.1423614429, 0.0903999174, 0.1575467909, 0.1206607898,
        -0.0282863552, -0.0266326884, 0.1068971622, 0.0040371431,
        -0.0156993672, -0.1335202723},
       {-0.0106460122, -0.2790996407, -0.0456117555, -0.0979890252,
        0.0692574348, -0.0478672356, -0.0329051549, 0.1347105465,
        -0.1049067745, 0.0316658895},
       {-0.1895266947, 0.0089729117, 0.0410265745, 0.0859870972,
        -0.0898683193, 0.0319656942, 0.0318154200, -0.0019231634,
        0.0150016279, 0.0463534322},
       {0.0397880425, -0.0996010889, -0.1195861510, 0.2505980285,
        0.1919792286, -0.1391693876, 0.0450217742, 0.0627437083,
        0.0751337235, 0.0140395436},
       {-0.0926871939, -0.0182420406, -0.0491125138, 0.0134373116,
        -0.0268371304, -0.0131675626, 0.1018552475, 0.1230558200,
        -0.1181103173, -0.0459930104},
       {-0.0790799954, 0.1223722212, -0.0059367903, 0.1448989404,
        -0.0477580855, 0.0025999994, -0.1348696447, 0.1302535536,
        -0.0362612088, -0.1485156451},
       {-0.0592461285, -0.2304907938, -0.0031817173, 0.0112487742,
        0.0288078167, 0.1498108184, -0.0300976154, 0.0807455917,
        0.0312238689, -0.0193321640},
       {-0.2076802022, 0.0947501167, -0.0503973949, 0.0017955892,
        -0.1270460776, 0.0282995534, 0.0108030817, 0.0029417619,
        -0.0134793129, 0.1049218291},
       {0.0966220863, 0.0725916853, 0.3321078756, -0.0600225330,
        -0.0379517516, -0.1014803691, 0.0435986196, -0.0687487393,
        -0.2698361742, -0.1213338126},
       {0.0072251899, 0.1009787335, -0.1556941558, -0.0612442128,
        -0.0139351805, -0.0728537489, 0.0531163793, 0.0004000842,
        0.0321265914, -0.0725214926},
       {0.1536536328, -0.0000375009, 0.1293549621, -0.0438997664,
        0.0590039464, -0.0679383783, -0.0950909251, -0.0704350332,
        -0.0045866686, -0.0218733459},
       {0.1539207010, -0.1148704230, -0.1090338332, 0.1700188147,
        0.0608783659, -0.1881410867, 0.0497269099, 0.0237332699,
        -0.2144444047, -0.0369562425},
       {-0.0017454952, 0.0731402517, 0.0954495667, 0.0095746771,
        0.1033450803, -0.0146273275, -0.0857496825, -0.0934181843,
        0.0542645295, -0.1958169086},
       {0.0677807571, -0.1106573067, -0.0359224096, 0.0505381903,
        0.1217940901, -0.1940680964, -0.0806178212, 0.0049061692,
        -0.0596086335, 0.0861623101},
       {-0.2086390565, 0.0361801641, 0.0425920177, 0.0049080397,
        0.1102236733, -0.1229574254, 0.1108616758, -0.0702920403,
        0.0725550518, -0.0324204219},
       {0.0814343129, 0.0780469930, -0.1464053574, -0.0154491194,
        -0.0092432319, -0.0237875265, -0.0755662765, 0.1851437895,
        0.0209096677, 0.1555015994},
       {-0.0569148654, -0.1061796761, 0.0132247779, -0.0563236604,
        0.2390145962, 0.0245422849, 0.1152599135, -0.0224235772,
        -0.0326061306, -0.0030911418},
       {0.0355717262, 0.0849586845, -0.0122154015, -0.0680851574,
        -0.1067876576, -0.0076679363, 0.0572962726, 0.0457947076,
        -0.0017817549, -0.0600138799},
       {0.0146765263, 0.0571804879, -0.0036817657, 0.0112368489,
        -0.0150504326, 0.0915499268, -0.0438200267, 0.0185535621,
        0.0394428030, 0.0725522558},
       {0.1495884766, 0.0675453809, 0.0599213235, -0.1470237089,
        0.0606403944, 0.2293717612, -0.0830010986, -0.1019519849,
        -0.0214653842, 0.1021248126},
       {0.0524750492, -0.0477124206, -0.0035990182, 0.1037038982,
        0.0672619748, 0.2428876970, 0.1005686680, 0.0353567216,
        0.0614726276, -0.0348984191},
       {-0.0977773002, 0.0171957132, 0.0490561044, -0.1395283025,
        -0.0522356465, -0.0369255902, 0.0265642403, -0.0260466059,
        0.0445096710, 0.0098112246},
       {0.1060327509, -0.1711167660, 0.1657124638, 0.1417674013,
        0.0050317086, 0.0650323214, 0.0606548400, -0.0737289628,
        0.0164665066, 0.0778174179},
       {0.0309816759, 0.1051320768, 0.0094996110, 0.0080750989,
        -0.0767803746, -0.0364538050, -0.0459717681, 0.1705483518,
        0.0240505552, -0.0999426501},
       {0.0398598388, -0.0192003697, -0.3053764380, 0.0479852371,
        -0.1552698783, 0.0578464420, -0.0961263599, -0.1458324460,
        0.0494341651, -0.1494193765},
       {-0.0446699203, 0.0204377395, 0.0612232523, 0.0744884536,
        -0.0036281289, -0.0832395348, 0.1923815426, -0.0605981321,
        0.1803588981, -0.0452524973},
       {0.1161285693, 0.1069965539, -0.1045534247, 0.0355284507,
        0.0755392029, 0.0700982122, -0.0198937450, 0.0301960045,
        -0.0394689681, -0.1171813379},
       {0.0984012237, -0.0559681422, 0.1379758192, 0.0602450901,
        -0.0892646674, -0.0161198320, -0.0286384915, -0.0870887650,
        0.0501429590, -0.0478614074},
       {0.1631691514, 0.0860891241, -0.0880189065, -0.0019000522,
        -0.0226760192, -0.1564507854, 0.0931255679, 0.0949808815,
        0.0925501215, -0.0456987858},
       {0.1068985972, -0.0209752935, 0.0935147780, 0.1812527815,
        0.0140109881, -0.1419148777, -0.0316901197, 0.0640985866,
        0.1219874379, -0.1133792035},
       {-0.0190548298, 0.0233339126, 0.0434998324, 0.0910423603,
        -0.0948439656, -0.0423478297, 0.1007966478, 0.0392334911,
        0.0448380651, 0.1125323499},
       {0.0104053390, 0.0528003422, -0.0314563862, -0.1345010020,
        -0.1295257885, 0.0074320554, -0.0199560718, -0.0654603169,
        0.0318014296, -0.0890271552},
       {0.0111337266, -0.0019522558, -0.0839988915, -0.2298205881,
        0.1456527386, 0.0316637236, -0.2664125939, -0.0426428618,
        0.0393787731, -0.0228140691},
       {0.0580330113, -0.0973267585, 0.0175167729, -0.0053483693,
        -0.0183061987, -0.0221028902, 0.0199759555, 0.0932721414,
        -0.0530119800, -0.0407240024},
       {0.0160564992, -0.0120149976, 0.0385602292, 0.0718290736,
        0.1291188903, -0.0116444148, -0.2277297997, -0.0069624539,
        0.0353870427, -0.0186955017},
       {-0.0153236162, -0.2432508513, 0.0507984337, -0.0324032329,
        -0.1511076608, -0.0871422066, -0.0864829941, 0.0608749082,
        0.0561638097, 0.1514750382},
       {0.0647924812, -0.1351649385, -0.1409209276, 0.1130725355,
        0.1566686201, -0.0237748098, 0.0558802988, -0.1504891284,
        -0.1943921758, -0.1174023677},
       {-0.0357187526, -0.0521376385, -0.0230114063, -0.0491014433,
        0.0679301145, 0.1427546951, 0.0036197463, 0.2029997487,
        -0.0634404710, -0.0525103394},
       {0.0387734663, -0.0354798762, 0.1177052256, -0.0641107815,
        0.1322693985, 0.0194175016, 0.2565452781, -0.0464114906,
        -0.0202693908, 0.0145651817},
       {-0.2181027967, 0.0602265128, 0.0480846113, 0.0109318364,
        -0.1544395781, -0.1546561040, 0.0586618519, 0.1175178688,
        0.1594464632, -0.0895441524},
       {-0.1030798028, -0.0271938800, -0.1975730142, -0.0588931176,
        0.0851789638, 0.1634602501, 0.0279155454, 0.1640553649,
        0.0410872938, 0.0191363915},
       {-0.0171441187, 0.0186937046, -0.0254852947, -0.0140910752,
        -0.0661891835, 0.0259031902, 0.0014448415, -0.1479580035,
        -0.0240700502, -0.0855671392},
       {-0.2048200459, 0.0483883649, 0.1558688255, 0.2369730189,
        0.1562419529, -0.0870801553, 0.1175244993, 0.1119899004,
        -0.1987829531, 0.0861288515},
       {0.0627177035, 0.0162808250, 0.0288616716, 0.0058307383,
        0.1631935849, -0.0401788834, -0.0199939393, 0.0007388984,
        0.0275664075, -0.1763249801},
       {0.1387973810, 0.0226199757, 0.0569124596, 0.0197315992,
        -0.0186441271, -0.0355241513, 0.0096114142, 0.0152052341,
        0.1155261755, 0.0346057746}};
