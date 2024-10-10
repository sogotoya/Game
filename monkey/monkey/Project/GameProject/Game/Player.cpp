#include "Player.h"
#include "Bullet.h"
#include "Map.h"
#include"Bar.h"
#include"Bar2.h"
Player::Player(const CVector2D& p, bool flip) :
	Base(eType_Player) {
	//�摜����
	m_img = COPY_RESOURCE("Player", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos_old = m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(50, 100);
	m_img.SetSize(100, 100);
	m_rect = CRect(-30,-90, 30, 0);
	//���]�t���O
	//m_flip = flip;
	//�ʏ��Ԃ�
	m_state = eState_Idle;
	//���n�t���O
	m_is_ground = true;



}
void Player::StateIdle()
{
	//�ړ���
	const float move_speed = 8;//8
	//�ړ��t���O
	bool move_flag = false;
	//���ړ�
	if (HOLD(CInput::eLeft)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += -move_speed;
		//���]�t���O
		m_flip = true;
		move_flag = true;
	}
	//�E�ړ�
	if (HOLD(CInput::eRight)) {
		//�ړ��ʂ�ݒ�
		m_pos.x += move_speed;
		//���]�t���O
		m_flip = false;
		move_flag = true;
	}
	//�U��
	if (PUSH(CInput::eButton1)) {
		//�U����Ԃֈڍs
		m_state = eState_Attack01;

		//Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Player_Attack, 0));
	}
	//���Ⴊ��
	if (HOLD(CInput::eDown)) {
		//���Ⴊ�ݏ�Ԃֈڍs
		m_state = eState_Crouchi;

	}
	//�W�����v��
	const float jump_pow = 15;

	//�W�����v
	if (m_is_ground && PUSH(CInput::eButton2)) {
		m_vec.y = -jump_pow;
		m_is_ground = false;
	}


	//�W�����v���Ȃ�
	if (!m_is_ground) {
		if (m_vec.y < 0)
			//�㏸�A�j���[�V����
			m_img.ChangeAnimation(eAnimJumpUp, false);
		else
			//���~�A�j���[�V����
		m_img.ChangeAnimation(eAnimJumpDown, false);
	}
	//�n�ʂɂ���Ȃ�
	else
	{
		if (move_flag) {
			//����A�j���[�V����
			m_img.ChangeAnimation(eAnimRun);
		}
		else {
			//�ҋ@�A�j���[�V����
			m_img.ChangeAnimation(eAnimIdle);
		}
	}
	

}

void Player::StateAttack01()
{
	float move_speed = 6;

	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimAttack01, false);
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
	if (PUSH(CInput::eButton1)) {
		//�U����Ԃֈڍs
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

	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimAttack02, false);
	//�W�����v�����č��̕����ɍU��������
	if (m_is_ground == false) {
		if (m_flip == false)
			m_pos.x += move_speed;
		if (m_flip == true)
			m_pos.x -= move_speed;

	}


	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
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
		//�ʏ���
	case eState_Idle:
		StateIdle();
		break;
		//�U�����
	case eState_Attack01:
		StateAttack01();
		break;
	case eState_Attack02:
		StateAttack02();
		break;
		//�_���[�W���
	case eState_Damage:
		StateDamage();
		break;
		//�_�E�����
	case eState_Down:
		StateDown();
		break;
		//���Ⴊ�ݏ��
	case eState_Crouchi:
		StateCrouchi();
		break;
	}
	//�����Ă����痎������Ԃֈڍs
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͂ɂ�闎��
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
	m_scroll.x = m_pos.x - 1280 / 2;

}
void Player::Draw() {
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�\��
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
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
	/*case
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
		break;*/
	case eType_bar:
		if (Base::CollisionRect(this, b)) {
			if (m_pos_old.y + m_rect.m_bottom <= b->m_pos_old.y + b->m_rect.m_top) {
				m_pos.y = b->m_pos.y + b->m_rect.m_top;
				m_is_ground = true;//���n
				m_vec.y = 0;
				
			}


		}
	case eType_bar2:
		if (Base::CollisionRect(this, b)) {
			if (m_pos_old.y + m_rect.m_bottom <= b->m_pos_old.y + b->m_rect.m_top) {
				m_pos.y = b->m_pos.y + b->m_rect.m_top;
				m_is_ground = true;//���n
				m_vec.y = 0;

			}

		}
	case eType_bar3:
		if (Base::CollisionRect(this, b)) {
			if (m_pos_old.y + m_rect.m_bottom <= b->m_pos_old.y + b->m_rect.m_top) {
				m_pos.y = b->m_pos.y + b->m_rect.m_top;
				m_is_ground = true;//���n
				m_vec.y = 0;

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
	{19, 3 },
    { 20,3 },
    { 21,3 },
    { 22,3 },
    { 23,3 },
};

TexAnimData player_anim_data[] = {
	ANIMDATA(playerIdle),
	ANIMDATA(playerStep),
	ANIMDATA(playerJumpup),
	ANIMDATA(playerJumpDown),
	ANIMDATA(playerAttack01),
	ANIMDATA(playerCrouchi),
	ANIMDATA(playerBattou),
	ANIMDATA(playerAttack02),
	ANIMDATA(playerDown),
};

