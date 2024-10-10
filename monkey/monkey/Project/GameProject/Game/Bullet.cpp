#include "Bullet.h"

Bullet::Bullet(const CVector2D& pos):Base(eType_Bullet)
{
	//画像複製
	m_img.Load("Image/arrow_.png");
	//座標設定
	m_pos = pos;
	//画像サイズ設定
	m_img.SetSize(500, 500);
	//中心位置設定
	m_img.SetCenter(75, 25);
	m_rect = CRect(-65, -25, 65, 0);//左，うえ、右、したた
	
}

void Bullet::Update()
{
	const int move_speed = 6;//弾の速さ
	m_pos.x -= move_speed;//弾の方向
m_rad = 15;
m_pos_old = m_pos;
}
void Bullet::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	// Utility::DrawCircle(m_pos, m_rad, CVector4D(1, 0, 0, 0.5));


}
