#include "Bar.h"
#include"Map.h"


bar::bar(const CVector2D& p, bool flip):Base(eType_bar)
{
	//画像複製
	m_img = COPY_RESOURCE("bar", CImage);
	//座標設定
	m_pos = p;
	//画像サイズ設定
	m_img.SetSize(150, 50);
	//中心位置設定
	m_img.SetCenter(75, 25);
	m_rect = CRect(-75, -25, 75,25 );//左，うえ、右、したた
	turn = 0;
	m_img.ChangeAnimation(0);
	
}

void bar::Update()
{
	
	m_img.ChangeAnimation(0);
	m_img.UpdateAnimation();
	
	if (turn == 0)
	{
		m_pos.y += 4;
	}
	if (m_pos.y > 4 * MAP_TIP_SIZE)
	{
		turn = 1;
	}
	if ( turn == 1)
	{
		m_pos.y -= 4;
	}
	if (m_pos.y < 1 * MAP_TIP_SIZE)
	{
		turn = 0;
	}
	
}

void bar::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	DrawRect();
	
			
}

void bar::Collision(Base* b)
{

}
static TexAnim barfuuu[] = {
	{0,5},
	{1,5},
	{2,5},
	{3,5},
	
};
TexAnimData bar_anim_data[] = {
	ANIMDATA(barfuuu),
};