#include "Slash.h"
Slash::Slash(const CVector2D& pos, bool flip, int type, int attack_no) : Base(type)
{
	//���]�t���O
	m_flip = flip;
	//�摜����
	m_img = COPY_RESOURCE("Effect_Slash", CImage);
	//���W�ݒ�
	m_pos = pos;
	//�\���T�C�Y�̐ݒ�
	m_img.SetCenter(128, 128);
	//���S�ʒu�ݒ�
	m_img.SetCenter(64, 64);
	//�����蔻��p��`
	m_rect = CRect(-64, -64, 64, 64);
	//�Đ��A�j���[�V�����ݒ�(�񃋁[�v�j
	m_img.ChangeAnimation(0, false);
	//�U���ԍ�
	m_attack_no = attack_no;
}

void Slash::Update()
{
	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
	//�A�j���[�V�����I���`�F�b�N
	if (m_img.CheckAnimationEnd()) {
		//�G�t�F�N�g������
		SetKill();
	}
}

void Slash::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
	//DrawRect();

}
