#ifndef DVBS2_CONSTANTS_16200_HPP_
#define DVBS2_CONSTANTS_16200_HPP_

#include "Tools/Code/LDPC/Standard/DVBS2/DVBS2_constants.hpp"

namespace aff3ct
{
namespace tools
{

struct dvbs2_values_16200_1800 : dvbs2_values  // r=8/9 & K = 14400
{
	dvbs2_values_16200_1800()
	{
		this->EncValues = std::vector<int>({
			4, 0, 1558, 712, 805,
			4, 1, 1450, 873, 1337,
			4, 2, 1741, 1129, 1184,
			4, 3, 294, 806, 1566,
			4, 4, 482, 605, 923,
			3, 0, 926, 1578,
			3, 1, 777, 1374,
			3, 2, 608, 151,
			3, 3, 1195, 210,
			3, 4, 1484, 692,
			3, 0, 427, 488,
			3, 1, 828, 1124,
			3, 2, 874, 1366,
			3, 3, 1500, 835,
			3, 4, 1496, 502,
			3, 0, 1006, 1701,
			3, 1, 1155, 97,
			3, 2, 657, 1403,
			3, 3, 1453, 624,
			3, 4, 429, 1495,
			3, 0, 809, 385,
			3, 1, 367, 151,
			3, 2, 1323, 202,
			3, 3, 960, 318,
			3, 4, 1451, 1039,
			3, 0, 1098, 1722,
			3, 1, 1015, 1428,
			3, 2, 1261, 1564,
			3, 3, 544, 1190,
			3, 4, 1472, 1246,
			3, 0, 508, 630,
			3, 1, 421, 1704,
			3, 2, 284, 898,
			3, 3, 392, 577,
			3, 4, 1155, 556,
			3, 0, 631, 1000,
			3, 1, 732, 1368,
			3, 2, 1328, 329,
			3, 3, 1515, 506,
			3, 4, 1104, 1172
		});

		this->N        = 16200;
		this->K        = 14400;
		this->NmK      = 1800;
		this->M        = 360;
		this->Q        = 5;
		this->N_LINES  = 40;
	}
};

struct dvbs2_values_16200_2880 : dvbs2_values  // r=5/6 & K = 13320
{
	dvbs2_values_16200_2880()
	{
		this->EncValues = std::vector<int>({
			13, 3, 2409, 499, 1481, 908, 559, 716, 1270, 333, 2508, 2264, 1702, 2805,
			3, 4, 2447, 1926,
			3, 5, 414, 1224,
			3, 6, 2114, 842,
			3, 7, 212, 573,
			3, 0, 2383, 2112,
			3, 1, 2286, 2348,
			3, 2, 545, 819,
			3, 3, 1264, 143,
			3, 4, 1701, 2258,
			3, 5, 964, 166,
			3, 6, 114, 2413,
			3, 7, 2243, 81,
			3, 0, 1245, 1581,
			3, 1, 775, 169,
			3, 2, 1696, 1104,
			3, 3, 1914, 2831,
			3, 4, 532, 1450,
			3, 5, 91, 974,
			3, 6, 497, 2228,
			3, 7, 2326, 1579,
			3, 0, 2482, 256,
			3, 1, 1117, 1261,
			3, 2, 1257, 1658,
			3, 3, 1478, 1225,
			3, 4, 2511, 980,
			3, 5, 2320, 2675,
			3, 6, 435, 1278,
			3, 7, 228, 503,
			3, 0, 1885, 2369,
			3, 1, 57, 483,
			3, 2, 838, 1050,
			3, 3, 1231, 1990,
			3, 4, 1738, 68,
			3, 5, 2392, 951,
			3, 6, 163, 645,
			3, 7, 2644, 1704
		});

		this->N        = 16200;
		this->K        = 13320;
		this->NmK      = 2880;
		this->M        = 360;
		this->Q        = 8;
		this->N_LINES  = 37;
	}
};

struct dvbs2_values_16200_3600 : dvbs2_values  // r=4/5 & K = 12600
{
	dvbs2_values_16200_3600()
	{
		this->EncValues = std::vector<int>({
			3, 5, 896, 1565,
			3, 6, 2493, 184,
			3, 7, 212, 3210,
			3, 8, 727, 1339,
			3, 9, 3428, 612,
			3, 0, 2663, 1947,
			3, 1, 230, 2695,
			3, 2, 2025, 2794,
			3, 3, 3039, 283,
			3, 4, 862, 2889,
			3, 5, 376, 2110,
			3, 6, 2034, 2286,
			3, 7, 951, 2068,
			3, 8, 3108, 3542,
			3, 9, 307, 1421,
			3, 0, 2272, 1197,
			3, 1, 1800, 3280,
			3, 2, 331, 2308,
			3, 3, 465, 2552,
			3, 4, 1038, 2479,
			3, 5, 1383, 343,
			3, 6, 94, 236,
			3, 7, 2619, 121,
			3, 8, 1497, 2774,
			3, 9, 2116, 1855,
			3, 0, 722, 1584,
			3, 1, 2767, 1881,
			3, 2, 2701, 1610,
			3, 3, 3283, 1732,
			3, 4, 168, 1099,
			3, 5, 3074, 243,
			3, 6, 3460, 945,
			3, 7, 2049, 1746,
			3, 8, 566, 1427,
			3, 9, 3545, 1168
		});

		this->N        = 16200;
		this->K        = 12600;
		this->NmK      = 3600;
		this->M        = 360;
		this->Q        = 10;
		this->N_LINES  = 35;
	}
};

struct dvbs2_values_16200_4320 : dvbs2_values  // r=3/4 & K = 11880
{
	dvbs2_values_16200_4320()
	{
		this->EncValues = std::vector<int>({
			12, 3, 3198, 478, 4207, 1481, 1009, 2616, 1924, 3437, 554, 683, 1801,
			3, 4, 2681, 2135,
			3, 5, 3107, 4027,
			3, 6, 2637, 3373,
			3, 7, 3830, 3449,
			3, 8, 4129, 2060,
			3, 9, 4184, 2742,
			3, 10, 3946, 1070,
			3, 11, 2239, 984,
			3, 0, 1458, 3031,
			3, 1, 3003, 1328,
			3, 2, 1137, 1716,
			3, 3, 132, 3725,
			3, 4, 1817, 638,
			3, 5, 1774, 3447,
			3, 6, 3632, 1257,
			3, 7, 542, 3694,
			3, 8, 1015, 1945,
			3, 9, 1948, 412,
			3, 10, 995, 2238,
			3, 11, 4141, 1907,
			3, 0, 2480, 3079,
			3, 1, 3021, 1088,
			3, 2, 713, 1379,
			3, 3, 997, 3903,
			3, 4, 2323, 3361,
			3, 5, 1110, 986,
			3, 6, 2532, 142,
			3, 7, 1690, 2405,
			3, 8, 1298, 1881,
			3, 9, 615, 174,
			3, 10, 1648, 3112,
			3, 11, 1415, 2808
		});

		this->N        = 16200;
		this->K        = 11880;
		this->NmK      = 4320;
		this->M        = 360;
		this->Q        = 12;
		this->N_LINES  = 33;
	}
};

struct dvbs2_values_16200_5400 : dvbs2_values  // r=2/3 & K = 10800
{
	dvbs2_values_16200_5400()
	{
		this->EncValues = std::vector<int>({
			13, 0, 2084, 1613, 1548, 1286, 1460, 3196, 4297, 2481, 3369, 3451, 4620, 2622,
			13, 1, 122, 1516, 3448, 2880, 1407, 1847, 3799, 3529, 373, 971, 4358, 3108,
			13, 2, 259, 3399, 929, 2650, 864, 3996, 3833, 107, 5287, 164, 3125, 2350,
			3, 3, 342, 3529,
			3, 4, 4198, 2147,
			3, 5, 1880, 4836,
			3, 6, 3864, 4910,
			3, 7, 243, 1542,
			3, 8, 3011, 1436,
			3, 9, 2167, 2512,
			3, 10, 4606, 1003,
			3, 11, 2835, 705,
			3, 12, 3426, 2365,
			3, 13, 3848, 2474,
			3, 14, 1360, 1743,
			3, 0, 163, 2536,
			3, 1, 2583, 1180,
			3, 2, 1542, 509,
			3, 3, 4418, 1005,
			3, 4, 5212, 5117,
			3, 5, 2155, 2922,
			3, 6, 347, 2696,
			3, 7, 226, 4296,
			3, 8, 1560, 487,
			3, 9, 3926, 1640,
			3, 10, 149, 2928,
			3, 11, 2364, 563,
			3, 12, 635, 688,
			3, 13, 231, 1684,
			3, 14, 1129, 3894
		});

		this->N        = 16200;
		this->K        = 10800;
		this->NmK      = 5400;
		this->M        = 360;
		this->Q        = 15;
		this->N_LINES  = 30;
	}
};

struct dvbs2_values_16200_6480 : dvbs2_values  // r=3/5 & K = 9720
{
	dvbs2_values_16200_6480()
	{
		this->EncValues = std::vector<int>({
			12, 2765, 5713, 6426, 3596, 1374, 4811, 2182, 544, 3394, 2840, 4310, 771,
			12, 4951, 211, 2208, 723, 1246, 2928, 398, 5739, 265, 5601, 5993, 2615,
			12, 210, 4730, 5777, 3096, 4282, 6238, 4939, 1119, 6463, 5298, 6320, 4016,
			12, 4167, 2063, 4757, 3157, 5664, 3956, 6045, 563, 4284, 2441, 3412, 6334,
			12, 4201, 2428, 4474, 59, 1721, 736, 2997, 428, 3807, 1513, 4732, 6195,
			12, 2670, 3081, 5139, 3736, 1999, 5889, 4362, 3806, 4534, 5409, 6384, 5809,
			12, 5516, 1622, 2906, 3285, 1257, 5797, 3816, 817, 875, 2311, 3543, 1205,
			12, 4244, 2184, 5415, 1705, 5642, 4886, 2333, 287, 1848, 1121, 3595, 6022,
			12, 2142, 2830, 4069, 5654, 1295, 2951, 3919, 1356, 884, 1786, 396, 4738,
			3, 0, 2161, 2653,
			3, 1, 1380, 1461,
			3, 2, 2502, 3707,
			3, 3, 3971, 1057,
			3, 4, 5985, 6062,
			3, 5, 1733, 6028,
			3, 6, 3786, 1936,
			3, 7, 4292, 956,
			3, 8, 5692, 3417,
			3, 9, 266, 4878,
			3, 10, 4913, 3247,
			3, 11, 4763, 3937,
			3, 12, 3590, 2903,
			3, 13, 2566, 4215,
			3, 14, 5208, 4707,
			3, 15, 3940, 3388,
			3, 16, 5109, 4556,
			3, 17, 4908, 4177
		});

		this->N        = 16200;
		this->K        = 9720;
		this->NmK      = 6480;
		this->M        = 360;
		this->Q        = 18;
		this->N_LINES  = 27;
	}
};

struct dvbs2_values_16200_9000 : dvbs2_values  // r=1/2 & K =7200
{
	dvbs2_values_16200_9000()
	{
		this->EncValues = std::vector<int>({
			8, 20, 712, 2386, 6354, 4061, 1062, 5045, 5158,
			8, 21, 2543, 5748, 4822, 2348, 3089, 6328, 5876,
			8, 22, 926, 5701, 269, 3693, 2438, 3190, 3507,
			8, 23, 2802, 4520, 3577, 5324, 1091, 4667, 4449,
			8, 24, 5140, 2003, 1263, 4742, 6497, 1185, 6202,
			3, 0, 4046, 6934,
			3, 1, 2855, 66,
			3, 2, 6694, 212,
			3, 3, 3439, 1158,
			3, 4, 3850, 4422,
			3, 5, 5924, 290,
			3, 6, 1467, 4049,
			3, 7, 7820, 2242,
			3, 8, 4606, 3080,
			3, 9, 4633, 7877,
			3, 10, 3884, 6868,
			3, 11, 8935, 4996,
			3, 12, 3028, 764,
			3, 13, 5988, 1057,
			3, 14, 7411, 3450
		});

		this->N        = 16200;
		this->K        = 7200;
		this->NmK      = 9000;
		this->M        = 360;
		this->Q        = 25;
		this->N_LINES  = 20;
	}
};

struct dvbs2_values_16200_9720 : dvbs2_values  // r=2/5 & K = 6480
{
	dvbs2_values_16200_9720()
	{
		this->EncValues = std::vector<int>({
			12, 5650, 4143, 8750, 583, 6720, 8071, 635, 1767, 1344, 6922, 738, 6658,
			12, 5696, 1685, 3207, 415, 7019, 5023, 5608, 2605, 857, 6915, 1770, 8016,
			12, 3992, 771, 2190, 7258, 8970, 7792, 1802, 1866, 6137, 8841, 886, 1931,
			12, 4108, 3781, 7577, 6810, 9322, 8226, 5396, 5867, 4428, 8827, 7766, 2254,
			12, 4247, 888, 4367, 8821, 9660, 324, 5864, 4774, 227, 7889, 6405, 8963,
			12, 9693, 500, 2520, 2227, 1811, 9330, 1928, 5140, 4030, 4824, 806, 3134,
			3, 1652, 8171, 1435,
			3, 3366, 6543, 3745,
			3, 9286, 8509, 4645,
			3, 7397, 5790, 8972,
			3, 6597, 4422, 1799,
			3, 9276, 4041, 3847,
			3, 8683, 7378, 4946,
			3, 5348, 1993, 9186,
			3, 6724, 9015, 5646,
			3, 4502, 4439, 8474,
			3, 5107, 7342, 9442,
			3, 1387, 8910, 2660
		});

		this->N        = 16200;
		this->K        = 6480;
		this->NmK      = 9720;
		this->M        = 360;
		this->Q        = 27;
		this->N_LINES  = 18;
	}
};

struct dvbs2_values_16200_10800 : dvbs2_values  // r=1/3 & K =5400
{
	dvbs2_values_16200_10800()
	{
		this->EncValues = std::vector<int>({
			12, 416, 8909, 4156, 3216, 3112, 2560, 2912, 6405, 8593, 4969, 6723, 6912,
			12, 8978, 3011, 4339, 9312, 6396, 2957, 7288, 5485, 6031, 10218, 2226, 3575,
			12, 3383, 10059, 1114, 10008, 10147, 9384, 4290, 434, 5139, 3536, 1965, 2291,
			12, 2797, 3693, 7615, 7077, 743, 1941, 8716, 6215, 3840, 5140, 4582, 5420,
			12, 6110, 8551, 1515, 7404, 4879, 4946, 5383, 1831, 3441, 9569, 10472, 4306,
			3, 1505, 5682, 7778,
			3, 7172, 6830, 6623,
			3, 7281, 3941, 3505,
			3, 10270, 8669, 914,
			3, 3622, 7563, 9388,
			3, 9930, 5058, 4554,
			3, 4844, 9609, 2707,
			3, 6883, 3237, 1714,
			3, 4768, 3878, 10017,
			3, 10127, 3334, 8267
		});

		this->N        = 16200;
		this->K        = 5400;
		this->NmK      = 10800;
		this->M        = 360;
		this->Q        = 30;
		this->N_LINES  = 15;
	}
};


struct dvbs2_values_16200_12960 : dvbs2_values  // r=1/4 & K = 3240
{
	dvbs2_values_16200_12960()
	{
		this->EncValues = std::vector<int>({
			12, 6295, 9626, 304, 7695, 4839, 4936, 1660, 144, 11203, 5567, 6347, 12557,
			12, 10691, 4988, 3859, 3734, 3071, 3494, 7687, 10313, 5964, 8069, 8296, 11090,
			12, 10774, 3613, 5208, 11177, 7676, 3549, 8746, 6583, 7239, 12265, 2674, 4292,
			12, 11869, 3708, 5981, 8718, 4908, 10650, 6805, 3334, 2627, 10461, 9285, 11120,
			3, 7844, 3079, 10773,
			3, 3385, 10854, 5747,
			3, 1360, 12010, 12202,
			3, 6189, 4241, 2343,
			3, 9840, 12726, 4977
		});

		this->N        = 16200;
		this->K        = 3240;
		this->NmK      = 12960;
		this->M        = 360;
		this->Q        = 36;
		this->N_LINES  = 9;
	}
};


}
}
#endif /* DVBS2_CONSTANTS_16200_HPP_ */
