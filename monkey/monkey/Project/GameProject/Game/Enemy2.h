#pragma once
#include "../Base/Base.h"

class Enemy : public Base {
private:
	//ó‘Ô
	CImage m_img;
	bool m_flip;
public:
	Enemy(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};