#include "Enemy3.h"


Enemy3::Enemy3(const CVector2D& pos, bool flip) :Base(eType_Enemy3)
{
	//画像複製
	m_img = COPY_RESOURCE("Enemy3", CImage);
	//体力
	m_hp = 35;
}

void Enemy3::Update()
{
    /*switch (m_state) {
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
    }*/
}

void Enemy3::Draw()
{
}

void Enemy3::Collision(Base* b)
{
}
