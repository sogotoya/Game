#include "Enemy2.h"
#include "AnimData.h"
#include "Field.h"
#include "Map.h"
#include "../Base/Base.h"

static TexAnim Enemy2Step[] = {//0

	{ 16,8 },
	{ 17,8},
	{ 18,8 },
	{ 19,8 },
	
	
	
};
static TexAnim Enemy2Attack[] = {//1
	{ 0,10 },
	{ 1,10 },
	{ 2,10 },
	{ 3,10 },
	{ 4,6 },
	{ 5,6 },
	{ 6,1 },
	{ 7,6 },
};
static TexAnim Enemy2die[] = {//2
	{ 8,5 },
	{ 9,30 },
	{ 10,60 },
	{ 11,60 },
};
static TexAnim Enemy2ran[] = {//3
	{ 24,4 },
	{25,4 },
	{ 26,4 },
	{ 27,4 },
	{ 28,4 },
	{ 29,4 },
	{ 30,4 },
	{ 31,4 },

};
TexAnimData enemy2_anim_data[] = {
	ANIMDATA(Enemy2Step),//0
	ANIMDATA(Enemy2Attack),//1
	ANIMDATA(Enemy2die),//2
	ANIMDATA(Enemy2ran),//3
};

void Enemy2::StateIdle()
{
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;

	Base* player = Base::FindObject(eType_Player);
	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x - 32) { //32�h�b�g����Ă���ƈړ�
			//�ړ��ʂ�ݒ�
			m_pos.x += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//�E�ړ�
		if (player->m_pos.x > m_pos.x + 32) { //32�h�b�g����Ă���ƈړ�
			//�ړ��ʂ�ݒ�
			m_pos.x += move_speed;
			//���]�t���O
			m_flip = false;
			move_flag = true;
		}


		//���U��
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 64) {
			//�U����Ԃֈڍs
			m_state = eState_Attack;
			m_attack_no++;  //���i�q�b�g�΍�
			m_flip = true;  //���]�t���O

		}
		//�E�U��
		if (player->m_pos.x > m_pos.x && player->m_pos.x < m_pos.x + 64) { //player->m_pos.x�i�v���C���[�j > m_pos.x(�G�j
			//�U����Ԃֈڍs
			m_state = eState_Attack;
			m_attack_no++;
			m_flip = false;
		}
	}
	if (move_flag) {
		//����A�j���[�V����
		m_img.ChangeAnimation(eAnimRun);
	}
	else {
		//�ҋ@�A�j���[�V����
		m_img.ChangeAnimation(eAnimIdle);
	}
}

void Enemy2::StateAttack()
{
	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eAnimAttack01, false);
	if (m_img.GetIndex() == 3) {
		if (m_flip) {
			//Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemmy_Attack, m_attack_no));
		}
		else {
			//Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemmy_Attack, m_attack_no));
		}
	}
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
}

void Enemy2::StateDamage()
{
	m_img.ChangeAnimation(eAnimDamage, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Enemy2::StateDown()
{
	m_img.ChangeAnimation(eAnimDown, false);
	if (m_img.CheckAnimationEnd()) {
		m_kill = true;
	}
}

Enemy2::Enemy2(const CVector2D& pos, bool flip)
	:Base(eType_Enemy2)
{
	m_img = COPY_RESOURCE("Enemy2", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W
	m_pos_old = m_pos = pos;
	//�摜�\���T�C�Y 
	m_img.SetSize(500, 500);
	//���S�ʒu
	m_img.SetCenter(500 / 2, 500 / 2);
	//��`
	m_rect = CRect(-25, -100, 25, 0);
	//hp
	m_hp = 10;
	//���]�t���O
	m_flip = flip;
	//���n�t���O
	m_is_ground = true;
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -5;
}

void Enemy2::Update()
{
	//�ҋ@
	m_img.ChangeAnimation(0);//(3)
	//�X�V
	m_img.UpdateAnimation();
	//�����Ă����痎����Ԃ�
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͗���
	m_vec.y += GRAVITY;
	m_pos += m_vec;
}

void Enemy2::Draw()
{
	//�ʒu
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�\��
	//DrawRect();

}

void Enemy2::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��ł�����
		if (Field* f = dynamic_cast<Field*>(b)) {
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
