#include "Enemy3.h"
#include "../Base/Base.h"
#include"Map.h"
#include"bar4.h"
#include"Bullet.h"
#include"Goal.h"

Enemy3::Enemy3(const CVector2D& pos, bool flip) :Base(eType_Enemy3)
{
	//画像複製
	m_img = COPY_RESOURCE("Enemy3", CImage);
    //再生アニメーション設定
    m_img.ChangeAnimation(7);
    //座標
    m_pos_old = m_pos = pos;
    m_cnt = 0;
    //画像サイズ
    m_img.SetSize(300, 300);
    //中心位置設定
    m_img.SetCenter(150, 300);
    //矩形
    m_rect = CRect(-30, -110, 30, 0);
    //体力
	m_hp = 35;
    //反転フラグ
    m_flip = flip;
    //着地フラグ
    m_is_ground = true;
    //攻撃番号
    m_attack_no = rand();
    //ダメージ番号
    //m_damage_no = -1;
    //通常状態
   // m_state = eState_Idle;
    
   
    
}
void Enemy3::StateIdle() {
    //移動量
   // const float move_speed = 6;
    //移動フラグ
    bool move_flag = false;
    Base* player = Base::FindObject(eType_Player);
    m_img.ChangeAnimation(7);
    if (player) {
        //左移動
        /*if (player->m_pos.x < m_pos.x - 32) {
            //移動量を設定
            m_pos.x += -move_speed;
            //反転フラグ
            m_flip = true;
            move_flag = true;
        }
        //右移動
        if (player->m_pos.x > m_pos.x + 32) {
            //移動量を設定
            m_pos.x += move_speed;
            //反転フラグ
            m_flip = false;
            move_flag = true;
        }*/
        //左攻撃
        if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 1920) {
            m_cnt++;
            if (m_cnt >= 60) {
                //攻撃状態へ
                m_cnt = 0;
                m_state = eState_Attack01;
                m_attack_no++;
                m_flip = true;
                Base::Add(new Bullet (CVector2D(m_pos)));
            }
        }
    }
    //移動中なら
    /*if (move_flag) {
        //走るアニメーション
        m_img.ChangeAnimation(E3ran);
    }
    else {
        //待機アニメーション
        m_img.ChangeAnimation(E3Step);
    }*/
}
void Enemy3::StateAttack01()
{

    //攻撃アニメーションへ変更
    m_img.ChangeAnimation(E3Attack01, false);
    //3番目のパターンなら
    /*if (m_img.GetIndex() == 3) {
        if (m_flip) {
           // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
           // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }*/
    //アニメーションが終了したら
    if (m_img.CheckAnimationEnd()) {
        //通常状態へ移行
        m_state = eState_Idle;
    }

}
/*void Enemy3::StateAttack02()
{
    //攻撃アニメーションへ変更
    m_img.ChangeAnimation(E3Attack02, false);
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

}*/
void Enemy3::StateAttack03()
{
    //攻撃アニメーションへ変更
    m_img.ChangeAnimation(E3Attack03, false);
    //3番目のパターンなら
    /*if (m_img.GetIndex() == 3) {
        if (m_flip) {
            // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
            // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }*/
    //アニメーションが終了したら
    if (m_img.CheckAnimationEnd()) {
        //通常状態へ移行
        m_state = eState_Idle;
    }

}
void Enemy3::StateDamage()
{
    m_img.ChangeAnimation(E3Dmg, false);
    if (m_img.CheckAnimationEnd()) {
       m_state = eState_Idle;
    }
}
void Enemy3::StateDown()
{
    m_img.ChangeAnimation(E3Down, false);
    if (m_img.CheckAnimationEnd()) {
       Base::Add(new Goal(CVector2D(13850, 500)));
        m_kill = true;
    }
}

void Enemy3::Update()
{
    //m_img.ChangeAnimation(7);
    //m_img.UpdateAnimation();
    //return;
    m_pos_old = m_pos;
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
    /*case eState_Attack02:
        StateAttack02();
        break;*/
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
    //落ちたら落下状態へ以降
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //重力による落下
    m_vec.y += GRAVITY;
    m_pos += m_vec;
    //アニメーションの更新
    m_img.UpdateAnimation();
}

void Enemy3::Draw()
{
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.SetFlipH(m_flip);
    //描画
    m_img.Draw();
    //当たり判定矩形の表示
    DrawRect();
}

void Enemy3::Collision(Base* b)
{
    switch (b->m_type) {
    case eType_Map:
        if (Map* m = dynamic_cast<Map*> (b)) {
            int t;
            t = m->CollisionRect(CVector2D(m_pos.x, m_pos_old.y), m_rect);
            if (t != 0) {
                m_pos.x = m_pos_old.x;
            }
            t = m->CollisionRect(CVector2D(m_pos_old.x, m_pos.y), m_rect);
            if (t != 0) {
                m_pos.y = m_pos_old.y;
                //落下リセット
                m_vec.y = 0;
                //着地フラグON
                m_is_ground = true;

            }
        }
        break;
    case eType_bar4:
        if (Base::CollisionRect(this, b)) {
            if (m_pos_old.y + m_rect.m_bottom <= b->m_pos_old.y + b->m_rect.m_top) {
                m_pos.y = b->m_pos.y + b->m_rect.m_top;
                m_is_ground = true;//着地
                m_vec.y = 0;

            }

        }

            break;

        
    }

}
static TexAnim Enemy3Ran[] = {
    { 23,5 },
    { 24,5 },
    { 25,5 },
    { 26,5 },
    { 27,5 },
    { 28,5 },
    { 29,5 },
    { 30,5 },
    { 31,5 },

};
static TexAnim Enemy3Attack01[] = {
    //弓

    { 242,5 },
    { 243,5 },
    { 244,10 },
    { 245,11 },
    { 246,12 },
    { 247,13 },
    { 248,14 },
    { 249,15 },
    { 250,10 },
    { 251,9},
    { 252,7 },
    { 253,6 },
    { 254,5 },
    { 255,5 },
    { 256,5 },



};
static TexAnim Enemy3Attack02[] = {
    //近接攻撃

{220,10},
{ 221,10 },
{ 222,10 },
{ 223,8 },
{ 224,8 },
{ 225,8 },
{ 226,8 },
{ 227,8 },
{ 228,8 },
{ 229,8 },



};

static TexAnim Enemy3Attack03[] = {
    //俺はハンターだ！！..........
    { 288,10},
    { 289,10},
    { 290,10},
    { 291,10},
    { 292,20},
    { 293,20},
    { 294,20},
    { 295,10 },
    { 296,10 },
    { 297,9 },
    { 298,9 },
    { 299,8 },
    { 300,7 },
    { 301,6 },
    { 302,6 },

};
static TexAnim Enemy3Step[] = {
    { 0,6 },
    { 1,6 },
    { 2,6 },
    { 3,6 },
    { 4,6 },
    { 5,6 },
    { 6,6 },
    { 7,6},
    { 8,6},
    { 9,6},
    { 10,6},
    { 11,6},
};
static TexAnim Enemy3Dmg[] = {
    {330,9},
    {331,9},
    {332,9},
    {333,9},
    {334,9},
    {335,9},
};
static TexAnim Enemy3Down[] = {
    {352,9},
    {353,9},
    {354,9},
    {355,9},
    {356,9},
    {357,9},
    {358,9},
    {359,9},
    {360,9},
    {361,9},
    {362,9},
    {363,9},
    {364,9},
    {365,9},
    {366,9},
    {367,9},
    {368,9},
    {369,9},
    {370,9},
};
static TexAnim Enemy3taiki[] = {
    {0,5},
    {1,5},
    {2,5},
    {3,5},
    {4,5},
    {5,5},
    {6,5},
    {7,5},
    {8,5},
    {9,5},
    {10,5},
    {11,5},
};

TexAnimData enemy3_anim_data[] = {
    ANIMDATA(Enemy3Ran),
    ANIMDATA(Enemy3Attack01),
    ANIMDATA(Enemy3Attack02),
    ANIMDATA(Enemy3Attack03),
    ANIMDATA(Enemy3Step),
    ANIMDATA(Enemy3Dmg),
    ANIMDATA(Enemy3Down),
    ANIMDATA(Enemy3taiki),
};