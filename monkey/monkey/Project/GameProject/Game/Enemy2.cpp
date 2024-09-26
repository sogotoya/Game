#include "Enemy2.h"

static TexAnim Enemy2Step[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	
};
static TexAnim Enemy2Attack[] = {
	{ 0,3 },
	{ 1,3 },
	{ 2,3 },
	{ 3,3 },
	{ 4,3 },
	{ 5,3 },
	{ 6,3 },
	{ 7,3 },
};
static TexAnim Enemy2die[] = {
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
};


TexAnimData enemy2_anim_data[] = {
	ANIMDATA(Enemy2Step),
	ANIMDATA(Enemy2Attack),
	ANIMDATA(Enemy2die),
};

void Enemy2::StateIdle()
{
}

void Enemy2::StateAttack()
{
}

void Enemy2::StateDamage()
{
}

void Enemy2::StateDown()
{
}

Enemy2::Enemy2(const CVector2D& pos, bool flip)
	:Base(eType_Enemy2)
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
	//hp
	m_hp = 10;
	//反転フラグ
	m_flip = flip;
	//着地フラグ
	m_is_ground = true;
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -5;
}

void Enemy2::Update()
{
	m_img.UpdateAnimation();
}

void Enemy2::Draw()
{
	//位置
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形表示
	//DrawRect();

}

void Enemy2::Collision(Base* b)
{
}
