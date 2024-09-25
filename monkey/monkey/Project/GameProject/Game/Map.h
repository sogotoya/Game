#pragma once
#include "../Base/Base.h"
//‰¡
#define MAP_WIDTH  40
//c
#define MAP_HEIGHT 22
//‘å‚«‚³
#define MAP_TIP_SIZE 128

class Map : public Base {
private:
	CImage m_img;
public:
	Map();
	void Draw();
};