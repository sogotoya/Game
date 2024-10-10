#include "Bullet.h"

Bullet::Bullet(const CVector2D& pos,bool flip):Base(eType_Bullet)
{
	//�摜����
	m_img.Load("Image/arrow_.png");
	//���W�ݒ�
	m_pos = pos;
	//�摜�T�C�Y�ݒ�
	m_img.SetSize(500, 500);
	//���S�ʒu�ݒ�
	m_img.SetCenter(250, 250);
	m_rect = CRect(-65, -25, 65, 25);//���C�����A�E�A������
	m_flip = flip;
}

void Bullet::Update()
{
	const int move_speed = 6;//�e�̑���
	m_pos.x -= move_speed;//�e�̕���
m_rad = 15;
m_pos_old = m_pos;
}
void Bullet::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
	m_img.SetFlipH(m_flip);
}
