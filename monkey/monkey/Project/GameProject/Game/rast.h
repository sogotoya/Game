#pragma once
#include "../Base/Base.h"
class rast : public Base {
	//画像オブジェクト
	CImage m_img;
	//文字表示オブジェクト
	CFont m_title_text;
	int m_cnt;
public:
	rast();
	void Update();
	void Draw();
};
