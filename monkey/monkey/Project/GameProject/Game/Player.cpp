#include "Player.h"
#include "Bullet.h"
#include "Map.h"
#include"Bar.h"
#include"Bar2.h"
#include"Slash.h"
#include"Goal.h"
Player::Player(const CVector2D& p, bool flip) :
	Base(eType_Player) {
	//画像複製
	m_img = COPY_RESOURCE("Player", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos_old = m_pos = p;
	//中心位置設定
	m_img.SetCenter(50, 100);
	m_img.SetSize(100, 100);
	m_rect = CRect(-30,-80, 30, 0);
	//反転フラグ
	//m_flip = flip;
	//通常状態へ
	m_state = eState_Idle;
	//着地フラグ
	m_is_ground = true;
	m_hp = 100;


}
void Player::StateIdle()
{
	//移動量
	const float move_speed = 8;//8
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
		m_state = eState_Attack01;

		//Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, 0));
	}
	//しゃがみ
	if (HOLD(CInput::eDown)) {
		//しゃがみ状態へ移行
		m_state = eState_Crouchi;

	}
	//ジャンプ力
	const float jump_pow = 15;

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

void Player::StateAttack01()
{
	float move_speed = 6;

	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack01, false);
	if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add((new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no)));
		}
		else {
			Base::Add((new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no)));
		}
	}
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
	if (PUSH(CInput::eButton1)) {
		//攻撃状態へ移行
		m_state = eState_Attack02;

	if (m_is_ground == false) {
		if (m_flip == false)
			m_pos.x += move_speed;
		if (m_flip == true)
		    m_pos.x -= move_speed;
		
		}
	}

	
	

}
void Player::StateAttack02()
{
	float move_speed = 6;

	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eAnimAttack02, false);
	if (m_img.GetIndex() == 1) {
		if (m_flip) {
			Base::Add((new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Player_Attack, m_attack_no)));
		}
		else {
			Base::Add((new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, m_attack_no)));
		}
	}
	//ジャンプをして左の方向に攻撃をする
	if (m_is_ground == false) {
		if (m_flip == false)
			m_pos.x += move_speed;
		if (m_flip == true)
			m_pos.x -= move_speed;

	}
	

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
	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}
}

void Player::StateCrouchi()
{
	m_img.ChangeAnimation(eAnimCrouchi, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;

	}
}


void Player::Update() {
	//m_img.ChangeAnimation(2);
	//m_img.UpdateAnimation();
	
	m_pos_old = m_pos;
	switch (m_state) {
		//通常状態
	case eState_Idle:
		StateIdle();
		break;
		//攻撃状態
	case eState_Attack01:
		StateAttack01();
		break;
	case eState_Attack02:
		StateAttack02();
		break;
		//ダメージ状態
	case eState_Damage:
		StateDamage();
		break;
		//ダウン状態
	case eState_Down:
		StateDown();
		break;
		//しゃがみ状態
	case eState_Crouchi:
		StateCrouchi();
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
	//当たり判定矩形表示
	//DrawRect();
}
void Player::Collision(Base* b)
{

	switch (b->m_type) {
	case eType_Map:
		if (Map* m = dynamic_cast<Map*>(b)) {//
			int t;
			t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
			if (t != 0) {
				m_pos.x = m_pos_old.x;
			}
			t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
			if (t != 0) {
				m_pos.y = m_pos_old.y;
				//落下速度リセット
				m_vec.y = 0;
				//接地フラグON
				m_is_ground = true;
			}
		}
	/*case
		//Field型へキャスト、型変換できたら
		if (Map* f = dynamic_cast<Map*>(b)) {
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
		break;*/
	case eType_bar:
		if (Base::CollisionRect(this, b)) {
			if (m_pos_old.y + m_rect.m_bottom <= b->m_pos_old.y + b->m_rect.m_top) {
				m_pos.y = b->m_pos.y + b->m_rect.m_top;
				m_is_ground = true;//着地
				m_vec.y = 0;
				
			}


		}
	case eType_bar2:
		if (Base::CollisionRect(this, b)) {
			if (m_pos_old.y + m_rect.m_bottom <= b->m_pos_old.y + b->m_rect.m_top) {
				m_pos.y = b->m_pos.y + b->m_rect.m_top;
				m_is_ground = true;//着地
				m_vec.y = 0;

			}

		}
	case eType_bar3:
		if (Base::CollisionRect(this, b)) {
			if (m_pos_old.y + m_rect.m_bottom <= b->m_pos_old.y + b->m_rect.m_top) {
				m_pos.y = b->m_pos.y + b->m_rect.m_top;
				m_is_ground = true;//着地
				m_vec.y = 0;

			}

		}
		break;
	case eType_Enemy_Attack:
		//Slash型へキャスト、型変換できたら
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (Base::CollisionRect(this, s)) {
				
				
				m_hp -= 5;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				//Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
	case eType_Goal:
		if (Base::CollisionRect(this, b)) {
			
			if (Goal* g = dynamic_cast<Goal*>(b))
				g->SetGoal();
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
	{ 8,7 },
	{ 9,7 },
	{ 10,7 },
	{ 11,7 },
	{ 12,7 },
	{ 13,7 },
	
};
static TexAnim playerAttack01[] = {
	{ 43,2 },
	{ 44,2 },
	{ 45,2 },
	{ 46,2 },
	{ 47,2 },
	{ 48,2 },
	{ 49,2 },
};
static TexAnim playerAttack02[] = {
	{ 50,5 },
	{ 51,5 },
	{ 52,5 },
	
	
};
static TexAnim playerCrouchi[] = {
	{ 4,2 },
	{ 5,2 },
	{ 6,2 },
	{ 7,2 },
	
};
static TexAnim playerDown[] = {
	{ 64,18 },
	{ 65,18 },
	{ 66,18 },
	{ 67,18 },
	{ 68,18 },
	{ 69,18 },
};
static TexAnim playerJumpup[] = {
	{ 15,3 },
	{ 16,3 },
	{ 17,3 },
	{ 18,3 },
};
static TexAnim playerJumpDown[] = {
	{ 19,3 },
    { 20,3 },
    { 21,3 },
    { 22,3 },
    { 23,3 },
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerBattou),//playerStep
	ANIMDATA(playerStep),//playerJumpup
	ANIMDATA(playerAttack01),//playerJumpDown
	ANIMDATA(playerAttack02),//playerAttack01
	ANIMDATA(playerCrouchi),//playerCrouchi
	ANIMDATA(playerDown),//playerBattou
	ANIMDATA(playerJumpup),//playerAttack02
	ANIMDATA(playerJumpDown),//playerDown
};

