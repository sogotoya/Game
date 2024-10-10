#include "Goal.h"

Goal::Goal(const CVector2D& pos)
	:Base(eType_Goal)
{
	//画像複製
	m_img = COPY_RESOURCE("Goal", CImage);
	//中心位置設定横、縦
	m_img.SetCenter(32, 128);
	//座標設定
	m_pos = pos;
	//矩形
	m_rect = CRect(-32, -128, 32, 0);
	//画像サイズ
	m_img.SetSize(64, 128);

	m_is_goal = false;
	m_rad = 16;
}

void Goal::Draw()
{
	//位置
	m_img.SetPos(GetScreenPos(m_pos)); //GetScreenPosスクリーン対応
	//表示
	m_img.Draw();
	//当たり判定矩形の表示
	DrawRect();
	Utility::DrawCircle(GetScreenPos(m_pos), m_rad, CVector4D(1, 1, 1, 1));
}
