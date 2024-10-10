#include "Goal.h"

Goal::Goal(const CVector2D& pos)
	:Base(eType_Goal)
{
	//�摜����
	m_img = COPY_RESOURCE("Goal", CImage);
	//���S�ʒu�ݒ艡�A�c
	m_img.SetCenter(48, 128);
	//���W�ݒ�
	m_pos = pos;
	//��`
	m_rect = CRect(-48, -128, 48, 0);
	//�摜�T�C�Y
	m_img.SetSize(96, 128);

	m_is_goal = false;
	m_rad = 16;
}

void Goal::Draw()
{
	//�ʒu
	m_img.SetPos(GetScreenPos(m_pos)); //GetScreenPos�X�N���[���Ή�
	//�\��
	m_img.Draw();
	//�����蔻���`�̕\��
	DrawRect();
	//Utility::DrawCircle(GetScreenPos(m_pos), m_rad, CVector4D(1, 1, 1, 1));
}
