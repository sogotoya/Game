#include "Enemy2.h"

Enemy::Enemy(const CVector2D& pos, bool flip)
	:Base(eType_Enemy)
{
	//m_img = COPY_RESOURCE("", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}

void Enemy::Collision(Base* b)
{
}
