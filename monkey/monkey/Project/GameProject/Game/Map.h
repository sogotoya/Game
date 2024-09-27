#pragma once
#include "../Base/Base.h"
//��
#define MAP_WIDTH  40
//�c
#define MAP_HEIGHT 22
//�傫��
#define MAP_TIP_SIZE 20

class Map : public Base {
private:
	CImage m_img;
public:
	Map();
	void Draw();
	//�w����W�̃`�b�v�ԍ��擾
	int GetTip(const CVector2D& pos);
	//�w���A�w��s�̃}�b�v�`�b�v���擾
	int GetTip(int col, int row);
	//�}�b�v�Ƃ̓����蔻��
	int CollisionPoint(const CVector2D& pos);
};
