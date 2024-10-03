#pragma once
#include "../Base/Base.h"
//��
#define MAP_WIDTH  400  //250   
//�c
#define MAP_HEIGHT 400  //250
//�傫��
#define MAP_TIP_SIZE  26   //128

class Map : public Base {
private:
	CImage m_img;
	int m_state;
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


