#include "Enemy3.h"
#include"AnimData.h"


Enemy3::Enemy3(const CVector2D& pos, bool flip) :Base(eType_Enemy3)
{
	//�摜����
	m_img = COPY_RESOURCE("Enemy3", CImage);
    m_pos = pos;
	//�̗�
	m_hp = 35;
    //�ʏ���
    m_state = eState_Idle;
    //�Đ��A�j���[�V�����ݒ�
    m_img.ChangeAnimation(0);
    //���S�ʒu�ݒ�
    m_img.SetCenter(128, 224);
    m_img.SetSize(300, 300);
    
}
void Enemy3::StateIdle() {
    /*//�ړ���
    const float move_speed = 6;
    //�ړ��t���O
    bool move_flag = false;
    Base* player = Base::FindObject(eType_Player);
    if (player) {
        //���ړ�
        if (player->m_pos.x < m_pos.x - 64) {
            //�ړ��ʂ�ݒ�
            m_pos.x += -move_speed;
            //���]�t���O
            m_flip = true;
            move_flag = true;
        }
        //�E�ړ�
        if (player->m_pos.x > m_pos.x + 64) {
            //�ړ��ʂ�ݒ�
            m_pos.x += move_speed;
            //���]�t���O
            m_flip = false;
            move_flag = true;
        }
        //���U��
        if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 64) {
            //�U����Ԃ�
            m_state = eState_Attack01;
            m_attack_no++;
            m_flip = true;
        }
        //�E�U��
        if (player->m_pos.x > m_pos.x && player->m_pos.x < m_pos.x + 64) {
            //�U����Ԃ�
            m_state = eState_Attack01;
            m_attack_no++;
            m_flip = false;
        }
    }
    //�ړ����Ȃ�
    if (move_flag) {
        //����A�j���[�V����
        m_img.ChangeAnimation(eAnimStep);
    }
    else {
        //�ҋ@�A�j���[�V����
        m_img.ChangeAnimation(eAnimIdle);
    }*/
}
void Enemy3::StateAttack01()
{
    //�U���A�j���[�V�����֕ύX
    m_img.ChangeAnimation(eAnimAttack01, false);
    //3�Ԗڂ̃p�^�[���Ȃ�
    if (m_img.GetIndex() == 3) {
        if (m_flip) {
           // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
           // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }
    //�A�j���[�V�������I��������
    if (m_img.CheckAnimationEnd()) {
        //�ʏ��Ԃֈڍs
        m_state = eState_Idle;
    }

}
void Enemy3::StateAttack02()
{
    //�U���A�j���[�V�����֕ύX
    m_img.ChangeAnimation(eAnimAttack01, false);
    //3�Ԗڂ̃p�^�[���Ȃ�
    if (m_img.GetIndex() == 3) {
        if (m_flip) {
            // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
            // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }
    //�A�j���[�V�������I��������
    if (m_img.CheckAnimationEnd()) {
        //�ʏ��Ԃֈڍs
        m_state = eState_Idle;
    }

}
void Enemy3::StateAttack03()
{
    //�U���A�j���[�V�����֕ύX
    m_img.ChangeAnimation(eAnimAttack01, false);
    //3�Ԗڂ̃p�^�[���Ȃ�
    if (m_img.GetIndex() == 3) {
        if (m_flip) {
            // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
            // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }
    //�A�j���[�V�������I��������
    if (m_img.CheckAnimationEnd()) {
        //�ʏ��Ԃֈڍs
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
        //�ʏ���
    case eState_Idle:
        StateIdle();
        break;
        //�U�����01
    case eState_Attack01:
        StateAttack01();
        break;
        //�U�����02
    case eState_Attack02:
        StateAttack02();
        break;
        //�U�����03
    case eState_Attack03:
        StateAttack03();
        break;
        //�_���[�W���
    case eState_Damage:
        StateDamage();
        break;
        //�_�E�����
    case eState_Down:
        StateDown();
        break;
    }
}

void Enemy3::Draw()
{
    m_img.SetPos(m_pos);
 
    //�`��
    m_img.Draw();
    //�����蔻���`�̕\��
}

void Enemy3::Collision(Base* b)
{
}
