#ifndef __BSP_RGB_TABLE_H__
#define __BSP_RGB_TABLE_H__


///////////////////////////////////////////////
#define	STARRY_INDEX_LEN		(160)
#define	WAVE_TAB_LEN			112
#define	BREATHE_TAB_LEN			128
#define	MIXCOLOUR_TAB_LEN		144
#define	FLOW_COLOUR_TAB_LEN		224
#define	FIREWORK_INDEX_LEN		(158)
#define STARRY_DATA_LEN			96
#define	TIDE_DATA_LEN			120

/*----------------------------------------------------------------
		亮度值表格
----------------------------------------------------------------*/
const uint8_t light_value_tab[101] =
{
	0,		22,		23,		24,
	25,		26,		27,		28,		29,		30,		31,		32,
	33,		34,		36,		37,		39,		40,		42,		43,
	45,		47,		49,		51,		53,		55,		57,		59,
	61,		63,		65,		67,		69,		71,		73,		75,
	77,		79,		81,		83,		85,		87,		89,		91,
	94,		96,		99,		101,	104, 	106,	109,	111,
	114,	116,	119,	121,	124,	126,	129,	131,
	134,	137,	140,	143,	146,	149,	152,	155,
	158,	161,	164,	167,	170,	173,	176,	179,
	182,	185,	188,	191,	194,	197,	200,	203,
	206,	209,	213,	216,	220,	223,	227,	230,
	234,	237,	241,	245,	248,	251,	255,	255,
	255,
};

//----------------------------------------------------------------
// 		呼吸曲线表格
//----------------------------------------------------------------
const uint8_t breathe_data_tab[BREATHE_TAB_LEN]=
{
	0,		1,		2,		3,		4,		5,		6,		7,
	8,		9,		10,		12,		14,		16,		18,		20,
	22,		24,		27,		30,		33,		36,		39,		42,
	45,		49,		53,		57,		61,		65,		69,		73,
	77,		81,		85,		89,		94,		99,		104,	109,
	114,	119,	124,	129,	134,	140,	146,	152,
	158,	164,	170,	176,	182,	188,	194,	200,
	206,	213,	220,	227,	234,	241,	248,	255,

	255,	248,	241,	234,	227,	220,	213,	206,
	200,	194,	188,	182,	176,	170,	164,	158,
	152,	146,	140,	134,	129,	124,	119,	114,
	109,	104,	99,		94,		89,		85,		81,		77,
	73,		69,		65,		61,		57,		53,		49,		45,
	42,		39,		36,		33,		30,		27,		24,		22,
	20,		18,		16,		14,		12,		10,		9,		8,
	7,		6,		5,		4,		3,		2,		1,		0,
};


/*----------------------------------------------------------------
		波浪曲线数据
----------------------------------------------------------------*/
const uint8_t wave_data_tab[WAVE_TAB_LEN]=
{
	22,		23,		24,		25,		27,		28,		30,		31,
	33,		34,		36,		37,		39,		40,		42,		43,
	45,		47,		49,		51,		53,		55,		57,		59,
	61,		63,		65,		76,		69,		71,		73,		75,
	77,		81,		85,		89,		94,		99,		104,	109,
	114,	119,	124,	129,	134,	140,	146,	152,
	158,	164,	170,	176,	182,	188,	194,	200,
	206,	213,	220,	227,	234,	241,	248,	255,

	255,	248,	241,	234,	227,	220,	213,	206,
	200,	194,	188,	182,	176,	170,	164,	158,
	152,	146,	140,	134,	129,	124,	119,	114,
	109,	104,	99,		94,		89,		85,		81,		77,
	73,		69,		65,		61,		57,		53,		49,		45,
	42,		39,		36,		33,		30,		27,		24,		22,
};


//----------------------------------------------------------------
// 		亮度变暗表格
//----------------------------------------------------------------
const uint8_t slow_down_tab[64+1] =
{
	0,		1,		2,		3,		4,		5,		6,		7,
	8,		9,		10,		12,		14,		16,		18,		20,
	22,		24,		27,		30,		33,		36,		39,		42,
	45,		49,		53,		57,		61,		65,		69,		73,
	77,		81,		85,		89,		94,		99,		104,	109,
	114,	119,	124,	129,	134,	140,	146,	152,
	158,	164,	170,	176,	182,	188,	194,	200,
	206,	213,	220,	227,	234,	241,	248,	255,	255,
};


//----------------------------------------------------------------
//		彩虹颜色表格
//----------------------------------------------------------------
const uint8_t	flow_rainbow_colour_tab[FLOW_COLOUR_TAB_LEN][3]=
{
	{255,	8,		8},		//红
	{255,	8,		8},
	{255,	8,		8},
	{255,	8,		8},
	{255,	10,		8},
	{255,	14,		8},
	{255,	18,		8},
	{255,	22,		8},
	{255,	26,		8},
	{255,	32,		8},
	{255,	38,		8},
	{255,	44,		8},
	{255,	50,		8},
	{255,	57,		8},
	{255,	65,		8},
	{255,	73,		8},

 	{255,	81,		8},		//橙
	{255,	89,		8},
	{255,	99,		8},
	{255,	109,	8},
	{255,	119,	8},
	{255,	129,	8},
	{255,	140,	8},
	{255,	152,	8},
	{255,	164,	8},
	{255,	176,  	8},
	{255,	188,	8},
	{255,	200, 	8},
	{255,	213,	8},
	{255,	227,	8},
	{255,	241,	8},
	{255,	255,	8},

	{248,	255,	8},		//黄
	{234,	255,	8},
	{220,	255,	8},
	{206,	255,	8},
	{194,	255,	8},
	{182,	255,	8},
	{170,	255,	8},
	{158,	255,	8},
	{146,	255,	8},
	{134,	255,	8},
	{124,	255,	8},
	{114,	255,	8},
	{104,	255,	8},
	{94,	255,	8},
	{85,	255,	8},
	{77,	255,	8},

 	{69,	255,	8},		//黄绿
	{61,	255,	8},
	{53,	255,	8},
	{47,	255,	8},
	{41,	255,	8},
	{35,	255,	8},
	{29,	255,	8},
	{24,	255,	8},
	{20,	255,	8},
	{16,	255,	8},
	{12,	255,	8},
	{8,		255,	8},
	{8,		255,	8},
	{8,		255,	8},
	{8,		255,	8},
	{8,		255,	8},

	{8,		255,	8,	},	//绿
	{8,		255,	8,	},
	{8,		255,	8,	},
	{8,		255,	8,	},
	{8,		255,	10,	},
	{8,		255,	14,	},
	{8,		255,	18,	},
	{8,		255,	22,	},
	{8,		255,	26,	},
	{8,		255,	32,	},
	{8,		255,	38,	},
	{8,		255,	44,	},
	{8,		255,	50,	},
	{8,		255,	57,	},
	{8,		255,	65,	},
	{8,		255,	73,	},

 	{8,		255,	81,	},	//绿蓝
	{8,		255,	89,	},
	{8,		255,	99,	},
	{8,		255,	109,},
	{8,		255,	119,},
	{8,		255,	129,},
	{8,		255,	140	},
	{8,		255,	152	},
	{8,		255,	164,},
	{8,		255,	176, },
	{8,		255,	188,},
	{8,		255,	200,},
	{8,		255,	213,},
	{8,		255,	227,},
	{8,		255,	241,},
	{8,		255,	255,},

	{8,		248,	255,},	//青
	{8,		234,	255,},
	{8,		220,	255,},
	{8,		206,	255,},
	{8,		194,	255,},
	{8,		182,	255,},
	{8,		170,	255,},
	{8,		158,	255,},
	{8,		146,	255,},
	{8,		134,	255,},
	{8,		124,	255,},
	{8,		114,	255,},
	{8,		104,	255,},
	{8,		94,		255,},
	{8,		85,		255,},
	{8,		77,		255,},

 	{8,		69,		255,},	//蓝绿
	{8,		61,		255,},
	{8,		53,		255,},
	{8,		47,		255,},
	{8,		41,		255,},
	{8,		35,		255,},
	{8,		29,		255,},
	{8,		24,		255,},
	{8,		20,		255,},
	{8,		16,		255,},
	{8,		12,		255,},
	{8,		8,		255,},
	{8,		8,		255,},
	{8,		8,		255,},
	{8,		8,		255,},
	{8,		8,		255,},

	{8,		8,		255,},	//蓝
	{8,		8,		255,},
	{8,		8,		255,},
	{8,		8,		255,},
	{10,	8,		255,},
	{14,	8,		255,},
	{18,	8,		255,},
	{22,	8,		255,},
	{26,	8,		255,},
	{32,	8,		255,},
	{38,	8,		255,},
	{44,	8,		255,},
	{50,	8,		255,},
	{57,	8,		255,},
	{65,	8,		255,},
	{73,	8,		255,},

 	{81,	8,		255,},	//紫
	{89,	8,		255,},
	{99,	8,		255,},
	{109,	8,		255,},
	{119,	8,		255,},
	{129,	8,		255,},
	{140,	8,		255,},
	{152,	8,		255,},
	{164,	8,		255,},
	{176,  	8,		255,},
	{188,	8,		255,},
	{200, 	8,		255,},
	{213,	8,		255,},
	{227,	8,		255,},
	{241,	8,		255,},
	{255,	8,		255,},

	{255,	8,		255,},	//紫红
	{255,	8,	    255,},
	{255,	8,	    255,},
	{255,	8,	    255,},
	{255,	10,	    255,},
	{255,	14,	    255,},
	{255,	18,	    255,},
	{255,	22,	    255,},
	{255,	26,	    255,},
	{255,	32,	    255,},
	{255,	38,	    255,},
	{255,	44,	    255,},
	{255,	50,	    255,},
	{255,	57,	    255,},
	{255,	65,	    255,},
	{255,	73,	    255,},

	{255,	81,		255,}, // 紫白
	{255,	89,	    255,},
	{255,	99,	    255,},
	{255,	109,    255,},
	{255,	119,    255,},
	{255,	129,    255,},
	{255,	140,	255,},
	{255,	152,	255,},
	{255,	164,    255,},
	{255,	176,    255,},
	{255,	188,    255,},
	{255,	200,    255,},
	{255,	213,    255,},
	{255,	227,    255,},
	{255,	241,    255,},
	{255,	255,    255,},

	{255,	248,	248,},	// 白
	{255,	234,	234,},
	{255,	220,	220,},
	{255,	206,	206,},
	{255,	194,	194,},
	{255,	182,	182,},
	{255,	170,	170,},
	{255,	158,	158,},
	{255,	146,	146,},
	{255,	134,	134,},
	{255,	124,	124,},
	{255,	114,	114,},
	{255,	104,	104,},
	{255,	94,		94,	},
	{255,	85,		85,	},
	{255,	77,		77,	},
	//
 	{255,	69,		69,	},	// 红白
	{255,	61,		61,	},
	{255,	53,		53,	},
	{255,	47,		47,	},
	{255,	41,		41,	},
	{255,	35,		35,	},
	{255,	29,		29,	},
	{255,	24,		24,	},
	{255,	20,		20,	},
	{255,	16,		16,	},
	{255,	12,		12,	},
	{255,	8,		8,	},
	{255,	8,		8,	},
	{255,	8,		8,	},
	{255,	8,		8,	},
	{255,	8,		8,	},

};

//----------------------------------------------------------------
//		单色表格
//----------------------------------------------------------------
const uint8_t colour_lib[9][3] =
{
	{0xff, 0x00, 0x00},		    // 0	红
	{0xff, 0x80, 0x00},         // 1	橙
	{0xff, 0xff, 0x00},         // 2	黄
	{0x00, 0xff, 0x00},         // 3	绿
	{0x00, 0xff, 0xff},         // 4	青
	{0x00, 0x00, 0xff},         // 5	蓝
	{0x80, 0x00, 0xff},         // 6	紫
	{0xc0, 0xc0, 0xff},         // 7	白
	{0x00, 0x00, 0x00},         // 8	灭
};




#endif /*__BSP_RGB_TABLE_H__ */