#include "Enemy1.h"
#include "AnimData.h"
#include "Map.h"

void Enemy1::StateIdle()
{
	//移動量
	const float move_speed = 4;
	//移動フラグ
	bool move_flag = false;
	//ジャンプ力
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		CVector2D v = player->m_pos - m_pos;
		if (abs(v.x) <= 510) {


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
			//左移動
			if (player->m_pos.y < m_pos.y - 32) {//64ドット離れていると移動します
				//移動量を設定
				m_pos.y += -move_speed;
				move_flag = true;
			}
			//右移動
			if (player->m_pos.y > m_pos.y + 32) {
				//移動力を設定
				m_pos.y += move_speed;
				move_flag = true;
			}
		}
	}
}
void Enemy1::StateAttack()
{
	//攻撃アニメーションへ変更
	m_img.ChangeAnimation(eState_Attack, false);
	//?番目のアニメーションの時発動
	/*if (m_img.GetIndex() == ? ) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemmy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemmy_Attack, m_attack_no));
		}
	}*/
	//アニメーションが終了したら
	if (m_img.CheckAnimationEnd()) {
		//通常状態へ移行
		m_state = eState_Idle;
	}
}
void Enemy1::StateDamage()
{
	//m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}
void Enemy1::StateDown()
{
	//m_img.ChangeAnimation(eAnimDown, false);
}
Enemy1::Enemy1(const CVector2D& p, bool flip) :Base(eType_Enemy) {
	//画像複製
	m_img = COPY_RESOURCE("Enemy1", CImage);
	//再生アニメーション設定
	m_img.ChangeAnimation(0);
	//座標設定
	m_pos = p;
	
	m_img.SetSize(200, 200);
	//中心位置設定
	m_img.SetCenter(100,190);
	//当たり判定用矩形設定
	m_rect = CRect(-45, -115, 45, -60);
	
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
	//m_img.ChangeAnimation(5);
	//m_img.UpdateAnimation();
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
	//if (m_is_ground && m_vec.y > GRAVITY * 4)
	//	m_is_ground = false;
	//重力による落下
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;

	//アニメーション更新
	m_img.UpdateAnimation();
	
	
}

void Enemy1::Draw()
{
	//位置設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetPos(GetScreenPos(m_pos));
	//反転設定
	m_img.SetFlipH(m_flip);
	//描画
	m_img.Draw();
	//当たり判定矩形表示
	DrawRect();
}

void Enemy1::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Map:
		if (Map* m = dynamic_cast<Map*>(b)) {
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
	}
	/*case eType_Map:
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
		break;
	}*/

}
static TexAnim enemy1Idle[] = {

	{ 1,18 },
	{ 2,18 },
	{ 3,18 },
};

static TexAnim enemy1Step[] = {
	{ 8,10 },
	{ 9,10 },
	{ 10,10 },
	{ 11,10 },
	{ 12,10 },
	{ 13,10 },

};
static TexAnim enemy1Attack01[] = {
	{ 43,7 },
	{ 44,7 },
	{ 45,7 },
	{ 46,7 },
	{ 47,7 },
	{ 48,7 },
	{ 49,7 },
};
static TexAnim enemy1Crouchi[] = {
	{ 4,10 },
	{ 5,10 },
	{ 6,10 },
	{ 7,10 },

};
static TexAnim enemy1Down[] = {
	{ 64,18 },
	{ 65,18 },
	{ 66,18 },
	{ 67,18 },
	{ 68,18 },
	{ 69,18 },
};
TexAnimData Enemy1_anim_data[] = {
	ANIMDATA(enemy1Idle),
	ANIMDATA(enemy1Step),
	ANIMDATA(enemy1Attack01),
	ANIMDATA(enemy1Crouchi),
	ANIMDATA(enemy1Down),
};