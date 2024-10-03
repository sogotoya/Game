#pragma once
#include "../Base/Base.h"

class Field :public Base {
private:
    //画像オブジェクト（前景）
    CImage m_forMap_Tip;
    //画像オブジェクト（遠景）
    CImage m_town;
    //画像オブジェクト（最遠景）
    CImage m_sky;
    //地面の高さ
    float m_Map_Tip;


public:
	CImage m_img;
	Field(const CVector2D& pos);
	void Update();
	void Draw();
};

