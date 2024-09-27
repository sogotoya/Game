#include "Enemy3.h"
#include"AnimData.h"


Enemy3::Enemy3(const CVector2D& pos, bool flip) :Base(eType_Enemy3)
{
	//画像複製
	m_img = COPY_RESOURCE("Enemy3", CImage);
    m_pos = pos;
	//体力
	m_hp = 35;
    //通常状態
    m_state = eState_Idle;
    //再生アニメーション設定
    m_img.ChangeAnimation(0);
    //中心位置設定
    m_img.SetCenter(128, 224);
    m_img.SetSize(300, 300);
    
}
void Enemy3::StateIdle() {
    /*//移動量
    const float move_speed = 6;
    //移動フラグ
    bool move_flag = false;
    Base* player = Base::FindObject(eType_Player);
    if (player) {
        //左移動
        if (player->m_pos.x < m_pos.x - 64) {
            //移動量を設定
            m_pos.x += -move_speed;
            //反転フラグ
            m_flip = true;
            move_flag = true;
        }
        //右移動
        if (player->m_pos.x > m_pos.x + 64) {
            //移動量を設定
            m_pos.x += move_speed;
            //反転フラグ
            m_flip = false;
            move_flag = true;
        }
        //左攻撃
        if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 64) {
            //攻撃状態へ
            m_state = eState_Attack01;
            m_attack_no++;
            m_flip = true;
        }
        //右攻撃
        if (player->m_pos.x > m_pos.x && player->m_pos.x < m_pos.x + 64) {
            //攻撃状態へ
            m_state = eState_Attack01;
            m_attack_no++;
            m_flip = false;
        }
    }
    //移動中なら
    if (move_flag) {
        //走るアニメーション
        m_img.ChangeAnimation(eAnimStep);
    }
    else {
        //待機アニメーション
        m_img.ChangeAnimation(eAnimIdle);
    }*/
}
void Enemy3::StateAttack01()
{
    //攻撃アニメーションへ変更
    m_img.ChangeAnimation(eAnimAttack01, false);
    //3番目のパターンなら
    if (m_img.GetIndex() == 3) {
        if (m_flip) {
           // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
           // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }
    //アニメーションが終了したら
    if (m_img.CheckAnimationEnd()) {
        //通常状態へ移行
        m_state = eState_Idle;
    }

}
void Enemy3::StateAttack02()
{
    //攻撃アニメーションへ変更
    m_img.ChangeAnimation(eAnimAttack01, false);
    //3番目のパターンなら
    if (m_img.GetIndex() == 3) {
        if (m_flip) {
            // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
            // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }
    //アニメーションが終了したら
    if (m_img.CheckAnimationEnd()) {
        //通常状態へ移行
        m_state = eState_Idle;
    }

}
void Enemy3::StateAttack03()
{
    //攻撃アニメーションへ変更
    m_img.ChangeAnimation(eAnimAttack01, false);
    //3番目のパターンなら
    if (m_img.GetIndex() == 3) {
        if (m_flip) {
            // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
            // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }
    //アニメーションが終了したら
    if (m_img.CheckAnimationEnd()) {
        //通常状態へ移行
        m_state = eState_Idle;
    }

}
void Enemy3::StateDamage()
{
    m_img.ChangeAnimation(eAnimDamage, false);
    if (m_img.CheckAnimationEnd()) {
       m_state = eState_Idle;
    }
}
void Enemy3::StateDown()
{
    m_img.ChangeAnimation(eAnimDown, false);
    if (m_img.CheckAnimationEnd()) {
       // Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
        m_kill = true;
    }
}

void Enemy3::Update()
{
    m_img.ChangeAnimation(2);
    m_img.UpdateAnimation();
    return;
    switch (m_state) {
        //通常状態
    case eState_Idle:
        StateIdle();
        break;
        //攻撃状態01
    case eState_Attack01:
        StateAttack01();
        break;
        //攻撃状態02
    case eState_Attack02:
        StateAttack02();
        break;
        //攻撃状態03
    case eState_Attack03:
        StateAttack03();
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
}

void Enemy3::Draw()
{
    m_img.SetPos(m_pos);
 
    //描画
    m_img.Draw();
    //当たり判定矩形の表示
}

void Enemy3::Collision(Base* b)
{
}
