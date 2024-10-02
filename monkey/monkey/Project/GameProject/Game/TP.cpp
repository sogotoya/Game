#include "TP.h"

Tp::Tp(const CVector2D& pos, const CVector2D& next)
	:Base(eType_Tp)
{
	m_img = COPY_RESOURCE("Tp",CImage);
	//�����ʒu
	m_img.SetCenter(32, 64);
	//�摜�\���T�C�Y
	m_img.SetSize(64, 64);
	//���W
	m_pos = pos;
	m_next_pos = next;
	m_rect = CRect(-32, -64, 32, 0);
}

void Tp::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
