#pragma once
#include "../Base/Base.h"
//��
#define MAP_WIDTH  150  //250   
//�c
#define MAP_HEIGHT 150  //250
//�傫��
#define MAP_TIP_SIZE  100  //128

class Map : public Base {
private:
	CImage m_background;
	CImage m_img;
	int m_state;
public:
	Map();
	void Draw();
	//�w����W�̃`�b�v�ԍ��擾
	int GetTip(const CVector2D& pos, int* tx = nullptr, int* ty = nullptr);
	//�w���A�w��s�̃}�b�v�`�b�v���擾
	int GetTip(int x, int y);
	//�}�b�v�Ƃ̓����蔻��
	int CollisionPoint(const CVector2D& pos);
	int stage[MAP_HEIGHT][MAP_WIDTH];
};


