#pragma once
#include "../Base/Base.h"
//‰¡
#define MAP_WIDTH  20
//c
#define MAP_HEIGHT 20
//‘å‚«‚³
#define MAP_TIP_SIZE 20

class Map : public Base {
private:
	CImage m_img;
public:
	Map();
	void Draw();
};
