#include "Enemy3.h"


Enemy3::Enemy3(const CVector2D& pos, bool flip) :Base(eType_Enemy3)
{
	//�摜����
	m_img = COPY_RESOURCE("Enemy3", CImage);
	//�̗�
	m_hp = 35;
}

void Enemy3::Update()
{
    /*switch (m_state) {
        //�ʏ���
    case eState_Idle:
        StateIdle();
        break;
        //�U�����
    case eState_Attack:
        StateAttack();
        break;
        //�_���[�W���
    case eState_Damage:
        StateDamage();
        break;
        //�_�E�����
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
