#pragma once
#include "../Base/Base.h"
class rast : public Base {
	//�摜�I�u�W�F�N�g
	CImage m_img;
	//�����\���I�u�W�F�N�g
	CFont m_title_text;
	int m_cnt;
public:
	rast();
	void Update();
	void Draw();
};
