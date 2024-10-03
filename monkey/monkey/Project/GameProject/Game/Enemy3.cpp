#include "Enemy3.h"
#include "../Base/Base.h"
#include"Map.h"


Enemy3::Enemy3(const CVector2D& pos, bool flip) :Base(eType_Enemy3)
{
	//�摜����
	m_img = COPY_RESOURCE("Enemy3", CImage);
    m_pos = pos;
	//�̗�
	m_hp = 35;
    //�ʏ���
    m_state = eState_Idle;
    //���n�t���O
    m_is_ground = true;
    //�Đ��A�j���[�V�����ݒ�
    m_img.ChangeAnimation(0);
    //���S�ʒu�ݒ�
    m_img.SetCenter(128, 224);
    m_img.SetSize(300, 300);
    
}
void Enemy3::StateIdle() {
    //�ړ���
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
        m_img.ChangeAnimation(E3ran);
    }
    else {
        //�ҋ@�A�j���[�V����
        m_img.ChangeAnimation(E3Step);
    }
}
void Enemy3::StateAttack01()
{

    //�U���A�j���[�V�����֕ύX
    m_img.ChangeAnimation(E3Attack01, false);
    //3�Ԗڂ̃p�^�[���Ȃ�
    /*if (m_img.GetIndex() == 3) {
        if (m_flip) {
           // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
           // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }*/
    //�A�j���[�V�������I��������
    if (m_img.CheckAnimationEnd()) {
        //�ʏ��Ԃֈڍs
        m_state = eState_Idle;
    }

}
void Enemy3::StateAttack02()
{
    //�U���A�j���[�V�����֕ύX
    m_img.ChangeAnimation(E3Attack02, false);
    //3�Ԗڂ̃p�^�[���Ȃ�
    /*if (m_img.GetIndex() == 3) {
        if (m_flip) {
            // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
            // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }*/
    //�A�j���[�V�������I��������
    if (m_img.CheckAnimationEnd()) {
        //�ʏ��Ԃֈڍs
        m_state = eState_Idle;
    }

}
void Enemy3::StateAttack03()
{
    //�U���A�j���[�V�����֕ύX
    m_img.ChangeAnimation(E3Attack03, false);
    //3�Ԗڂ̃p�^�[���Ȃ�
    /*if (m_img.GetIndex() == 3) {
        if (m_flip) {
            // Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
        else {
            // Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemy_Attack, m_attack_no));
        }
    }*/
    //�A�j���[�V�������I��������
    if (m_img.CheckAnimationEnd()) {
        //�ʏ��Ԃֈڍs
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
       // Base::Add(new Effect("Effect_Smoke", m_pos + CVector2D(0, 0), m_flip));
        m_kill = true;
    }
}

void Enemy3::Update()
{
    //m_img.ChangeAnimation(5);
    //m_img.UpdateAnimation();
    //return;
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
    //�������痎����Ԃֈȍ~
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
    m_pos += m_vec;
    //�A�j���[�V�����̍X�V
    m_img.UpdateAnimation();
}

void Enemy3::Draw()
{
    m_img.SetPos(m_pos);
    m_img.SetFlipH(m_flip);
    //�`��
    m_img.Draw();
    //�����蔻���`�̕\��
    //DrawRect();
}

void Enemy3::Collision(Base* b)
{
    switch (b->m_type) {
    case eType_Field:
        //Field�^�փL���X�g�A�^�ϊ��ł�����
        if (Map* f = dynamic_cast<Map*>(b)) {
            //�n�ʂ�艺�ɂ�������
            if (m_pos.y > f->GetGroundY()) {
                //�n�ʂ̍����ɖ߂�
                m_pos.y = f->GetGroundY();
                //�������x���Z�b�g
                m_vec.y = 0;
                //�ڒn�t���OON
                m_is_ground = true;
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
    //�|

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
    //�ߐڍU��

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
    //���̓n���^�[���I�I..........
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
    {133,9},
    {134,9},
    {135,9},
    {136,9},
    {137,9},
    {138,9},
};
static TexAnim Enemy3Down[] = {
    {155,9},
    {156,9},
    {157,9},
    {158,9},
    {159,9},
    {160,9},
    {161,9},
    {162,9},
    {163,9},
    {164,9},
    {165,9},
    {166,9},
    {167,9},
    {168,9},
    {169,9},
    {170,9},
    {171,9},
    {172,9},
    {173,9},
};
TexAnimData enemy3_anim_data[] = {
    ANIMDATA(Enemy3Ran),
    ANIMDATA(Enemy3Attack01),
    ANIMDATA(Enemy3Attack02),
    ANIMDATA(Enemy3Attack03),
    ANIMDATA(Enemy3Step),
    ANIMDATA(Enemy3Dmg),
    ANIMDATA(Enemy3Down),
};