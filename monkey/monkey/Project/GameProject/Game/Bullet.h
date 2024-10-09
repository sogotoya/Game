#pragma once
#include "../Base/Base.h"
class Bullet : public Base {
public:
    CImage m_img;
public:
    Bullet(const CVector2D& pos);
    void Update();
    void Draw();
};

