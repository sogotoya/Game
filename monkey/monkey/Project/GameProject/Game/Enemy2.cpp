#include "Enemy2.h"

Enemy::Enemy(const CVector2D& pos, bool flip)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy2", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W
	m_pos_old = m_pos = pos;
	//�摜�\���T�C�Y 
	m_img.SetSize(100, 100);
	//���S�ʒu
	m_img.SetCenter(100 / 2, 100 / 2);
	//��`
	m_rect = CRect(-25, -100, 25, 0);
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
