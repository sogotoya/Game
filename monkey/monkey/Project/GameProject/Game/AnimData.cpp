#include"AnimData.h"

static TexAnim Enemy3Step[] = {
	{ 23,5 },
	{ 24,5 },
	{ 25,5 },
	{ 26,5 },
	{ 27,5 },
	{ 28,5 },
	{ 29,5 },
	{ 30,5 },
	{ 31,5 },
	
};
static TexAnim Enemy3Attack01[] = {
	{ 48,2 },
	{ 49,2 },
	{ 50,2 },
	{ 51,2 },
	{ 52,2 },
};
static TexAnim Enemy3Attack02[] = {
	{ 0,0 },
};

static TexAnim Enemy3Attack03[] = {
	//俺はハンターだ！！
	{ 286,10 },
	{ 287,10 },
	{ 288,10},
	{ 289,10},
	{ 290,10},
	{ 291,10},
	{ 292,20},
	{ 293,20},
	{ 294,20},
	{ 295,10 },
	{ 296,10 },
	{ 297,9 },
	{ 298,9 },
	{ 299,8 },
	{ 300,7 },
	{ 301,6 },
	{ 302,6 },

};
TexAnimData enemy3_anim_data[] = {
	ANIMDATA(Enemy3Step),
	ANIMDATA(Enemy3Attack01),
	ANIMDATA(Enemy3Attack02),
	ANIMDATA(Enemy3Attack03),
	
};
