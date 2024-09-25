#include"AnimData.h"

static TexAnim Enemy3Step[] = {
	{ 23,4 },
	{ 24,4 },
	{ 25,4 },
	{ 26,4 },
	{ 27,4 },
	{ 28,4 },
	{ 29,4 },
	{ 30,4 },
	{ 31,4 },
	{ 32,4 },
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
	{ 286,3 },
	{ 287,3 },
	{ 288,3 },
	{ 289,3 },
	{ 290,3 },
	{ 291,3 },
	{ 292,3 },
	{ 293,3 },
	{ 294,3 },
	{ 295,3 },
	{ 296,3 },
	{ 297,3 },
	{ 298,3 },
	{ 299,3 },
	{ 300,3 },
	{ 301,3 },
	{ 302,3 },

};
TexAnimData enemy3_anim_data[] = {
	ANIMDATA(Enemy3Step),
	ANIMDATA(Enemy3Attack01),
	ANIMDATA(Enemy3Attack02),
	ANIMDATA(Enemy3Attack03),
	
};
