#include "TP.h"

Tp::Tp(const CVector2D& pos, const CVector2D& next)
	:Base(eType_Tp)
{
	m_img = COPY_RESOURCE("Tp",CImage);
	//中央位置
	m_img.SetCenter(32, 64);
	//画像表示サイズ
	m_img.SetSize(64, 64);
	//座標
	m_pos = pos;
	m_next_pos = next;
	m_rect = CRect(-32, -64, 32, 0);
}

void Tp::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
}
