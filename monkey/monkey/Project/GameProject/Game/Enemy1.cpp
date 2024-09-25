#include "Enemy1.h"
#include "AnimData.h"
#include "Field.h"

void Enemy1::StateIdle()
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
		if (player->m_pos.x < m_pos.x - 64) {//64ドット離れていると移動します
			//移動量を設定
			m_pos.x += -move_speed;
			//反転フラグ
			m_flip = true;
			move_flag = true;
		}
		//右移動
		if (player->m_pos.x > m_pos.x + 64) {
			//移動力を設定
			m_pos.x += move_speed;
			//反転フラグ
			m_flip = false;
			move_flag = true;
		}

		//左攻撃
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 64) {
			//攻撃状態へ移行
			m_state = eState_Attack;
			m_attack_no++;
			m_flip = true;
		}
		//右攻撃
		if (player->m_pos.x > m_pos.x && player->m_pos.x < m_pos.x + 64) {
			//攻撃状態へ
			m_state = eState_Attack;
			m_attack_no++;
			m_flip = false;
		}
	}
}
void Enemy1::StateAttack()
{
	//攻撃アニメーションへの変更
	//m_img.ChangeAnimation(eAnimAttack01, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}
void Enemy1::StateDamage()
{
	//m_img.ChangeAnimation(eAnimDamage, false);
}
void Enemy1::StateDown()
{
}
Enemy1::Enemy1(const CVector2D& p, bool flip) :Base(eType_Enemy) {
	//画像複製
	m_img = COPY_RESOURCE("Enemy", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	//中心位置設定
	m_img.SetCenter(128, 224);
	//当たり判定用矩形設定
	m_rect = CRect(-32, -128, 32, 0);
	//ヒットポイント
	m_hp = 5;
	//反転フラグ
	m_flip = flip;
	//着地フラグ
	m_is_ground = true;
	//攻撃番号
	m_attack_no = rand();
	//ダメージ番号
	m_damage_no = -1;

}

void Enemy1::Update()
{
}

void Enemy1::Draw()
{
}

void Enemy1::Collision(Base* b)
{
}


