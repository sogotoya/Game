#include "Bar.h"
#include"Map.h"


bar::bar(const CVector2D& p, bool flip):Base(eType_bar)
{
	//画像複製
	m_img = COPY_RESOURCE("bar", CImage);
	//座標設定
	m_pos = p;
	//画像サイズ設定
	m_img.SetSize(300, 10);
	//中心位置設定
	m_img.SetCenter(150, 5);
	m_rect = CRect(-150, -5, 150, 5);
	turn = 0;
	m_vec = CVector2D(10, -10);
}

void bar::Update()
{
	

	
	if (m_pos.y < 160 * MAP_TIP_SIZE && turn == 0)
	{
		m_pos.y += 4;
	}
	if (m_pos.y > 60 * MAP_TIP_SIZE)
	{
		turn = 1;
	}
	if (m_pos.y >= -160 * MAP_TIP_SIZE && turn == 1)
	{
		m_pos.y -= 4;
	}
	if (m_pos.y < -60 * MAP_TIP_SIZE)
	{
		turn = 0;
	}
	
}

void bar::Draw()
{
	m_img.SetPos(m_pos);
	m_img.Draw();
	DrawRect();
	
			
}

void bar::Collision(Base* b)
{

}