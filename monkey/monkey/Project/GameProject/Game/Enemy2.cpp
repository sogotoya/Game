#include "Enemy2.h"

Enemy2::Enemy2(const CVector2D& pos, bool flip)
	:Base(eType_Enemy2)
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
	//hp
	m_hp = 10;
	//���]�t���O
	m_flip = flip;
	//���n�t���O
	m_is_ground = true;
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -5;
}

void Enemy2::Update()
{
}

void Enemy2::Draw()
{
	//�ʒu
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�\��
	//DrawRect();

}

void Enemy2::Collision(Base* b)
{
}
