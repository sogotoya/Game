#include "Player.h"
#include "AnimData.h"
#include "Field.h"
#include "Bullet.h"
#include "Map.h"
Player::Player(const CVector2D& p, bool flip) :
	Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old = m_pos = p;
	//中心位置設定
	m_img.SetCenter(128, 224);
	m_img.SetSize(100, 100);
	//反転フラグ
	m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;


}
void Player::StateIdle()
{
	//移動量
	const float move_speed = 6;
	//移動フラグ
	bool move_flag = false;
	//左移動
	if (HOLD(CInput::eLeft)) {
		//移動量を設定
		m_pos.x += -move_speed;
		//反転フラグ
		m_flip = true;
		move_flag = true;
	}
	//右移動
	if (HOLD(CInput::eRight)) {
		//移動量を設定
		m_pos.x += move_speed;
		//反転フラグ
		m_flip = false;
		move_flag = true;
	}
	//攻撃
	if (PUSH(CInput::eButton1)) {
		//攻撃状態へ移行
		m_state = eState_Attack;

		//Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, 0));
	}
	//ジャンプ力
	const float jump_pow = 12;

	//ジャンプ
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}


	//ジャンプ中なら
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//上昇アニメーション
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//下降アニメーション
		m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	//地面にいるなら
	else
	{
		if (move_flag) {
			//走るアニメーション
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//待機アニメーション
			m_img.ChangeAnimation(eAnimIdle);
		}
	}


}

void Player::StateAttack()
{
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}

}
void Player::StateDamage()
{
	//m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}
void Player::StateDown()
{
	//m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}
}


void Player::Update() {
	m_img.ChangeAnimation(5);
	m_img.UpdateAnimation();
	
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack:
		StateAttack();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
	}
	//落ちていたら落下中状態へ移行
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//重力による落下
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//アニメーション更新
	m_img.UpdateAnimation();
	m_scroll.x = m_pos.x - 1280 / 2;

}
void Player::Draw() {
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
}
void Player::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		//Field型へキャスト、型変換できたら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下にいったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さに戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
		break;
	}
}

static TexAnim playerIdle[] = {
	
	{ 1,18 },
	{ 2,18 },
	{ 3,18 },

};
static TexAnim playerBattou[] = {

	{ 38,10 },
	{ 39,10 },
	{ 40,10 },
	{ 41,10 },

};
static TexAnim playerStep[] = {
	{ 8,10 },
	{ 9,10 },
	{ 10,10 },
	{ 11,10 },
	{ 12,10 },
	{ 13,10 },
	
};
static TexAnim playerAttack01[] = {
	{ 43,7 },
	{ 44,7 },
	{ 45,7 },
	{ 46,7 },
	{ 47,7 },
	{ 48,7 },
	{ 49,7 },
};
static TexAnim playerCrouchi[] = {
	{ 4,10 },
	{ 5,10 },
	{ 6,10 },
	{ 7,10 },
	
};
static TexAnim playerDown[] = {
	{ 64,18 },
	{ 65,18 },
	{ 66,18 },
	{ 67,18 },
	{ 68,18 },
	{ 69,18 },
};
TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerBattou),
	ANIMDATA(playerStep),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerCrouchi),
	ANIMDATA(playerDown),
};