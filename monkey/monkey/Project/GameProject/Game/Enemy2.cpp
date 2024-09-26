#include "Enemy2.h"
#include "AnimData.h"
#include "Field.h"
#include "Map.h"

static TexAnim Enemy2Step[] = {//0
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
	
};
static TexAnim Enemy2Attack[] = {//1
	{ 0,10 },
	{ 1,10 },
	{ 2,10 },
	{ 3,10 },
	{ 4,6 },
	{ 5,6 },
	{ 6,1 },
	{ 7,6 },
};
static TexAnim Enemy2die[] = {//2
	{ 0,10 },
	{ 1,10 },
	{ 2,10 },
	{ 3,10 },
};
static TexAnim Enemy2Hit[] = {//3
	{ 0,4 },
	{ 1,4 },
	{ 2,4 },
	{ 3,4 },
};
TexAnimData enemy2_anim_data[] = {
	ANIMDATA(Enemy2Step),//0
	ANIMDATA(Enemy2Attack),//1
	ANIMDATA(Enemy2die),//2
	ANIMDATA(Enemy2Hit),//3
};

void Enemy2::StateIdle()
{
	//移動量
	const float move_speed = 6;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		//左移動
		if (player->m_pos.x < m_pos.x - 32) { //32ドット離れていると移動
			//移動量を設定
			m_pos.x += -move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
		}
		//右移動
		if (player->m_pos.x > m_pos.x + 32) { //32ドット離れていると移動
			//移動量を設定
			m_pos.x += move_speed;
			//反転フラグ
			m_flip = false;
			move_flag = true;
		}


		//左攻撃
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 64) {
			//攻撃状態へ移行
			m_state = eState_Attack;
			m_attack_no++;  //多段ヒット対策
			m_flip = true;  //反転フラグ

		}
		//右攻撃
		if (player->m_pos.x > m_pos.x && player->m_pos.x < m_pos.x + 64) { //player->m_pos.x（プレイヤー） > m_pos.x(敵）
			//攻撃状態へ移行
			m_state = eState_Attack;
			m_attack_no++;
			m_flip = false;
		}
	}
	if (move_flag) {
		//走るアニメーション
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//待機アニメーション
		m_img.ChangeAnimation(eAnimIdle);
	}
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
	m_img.ChangeAnimation(1);
	//座標
	m_pos_old = m_pos = pos;
	//画像表示サイズ 
	m_img.SetSize(500, 500);
	//中心位置
	m_img.SetCenter(500 / 2, 500 / 2);
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
	m_img.ChangeAnimation(1);
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
	/*switch (b->m_type) {
		//攻撃オブジェクトとの判定
	case eType_Player_Attack:
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttacNO() && Base::CollisionRect(this, s)) {
				//同じ攻撃の連続ダメージの防止
				m_damage_no = s->GetAttacNO();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
		break;*/
}
