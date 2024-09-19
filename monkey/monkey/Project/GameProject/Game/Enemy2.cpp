#include "Enemy2.h"

Enemy::Enemy(const CVector2D& pos, bool flip)
	:Base(eType_Enemy)
{
	m_img = COPY_RESOURCE("Enemy2", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標
	m_pos_old = m_pos = pos;
	//画像表示サイズ 
	m_img.SetSize(100, 100);
	//中心位置
	m_img.SetCenter(100 / 2, 100 / 2);
	//矩形
	m_rect = CRect(-25, -100, 25, 0);
}

void Enemy::Update()
{
}

void Enemy::Draw()
{
}

void Enemy::Collision(Base* b)
{
}
