#pragma once
#include "../Base/Base.h"

class Field :public Base {
public:
	CImage m_img;
public:
	Field(const CVector2D& pos);
	void Update();
	void Draw();
};
