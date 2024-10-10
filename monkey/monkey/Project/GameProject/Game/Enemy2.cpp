#include "Enemy2.h"
#include "Map.h"
#include "../Base/Base.h"


static TexAnim Enemy2Step[] = {//0

	{ 16,8 },
	{ 17,8},
	{ 18,8 },
	{ 19,8 },
	
	
	
};
static TexAnim Enemy2Attack[] = {//1
	{ 0,8 },
	{ 1,8 },
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
static TexAnim Enemy2Hit[] = {//4
	{ 32,5 },
	{33,5 },
	{ 34,5 },
	{ 35,5 },
};
TexAnimData enemy2_anim_data[] = {
	ANIMDATA(Enemy2Step),//0
	ANIMDATA(Enemy2Attack),//1
	ANIMDATA(Enemy2die),//2
	ANIMDATA(Enemy2ran),//3
	ANIMDATA(Enemy2Hit),//4
};

void Enemy2::StateIdle()//�W�����v�Ȃ�
{
	//�ړ���
	const float move_speed = 3;
	//�ړ��t���O
	bool move_flag = false;

	Base* player = Base::FindObject(eType_Player);
	if (player) {
		CVector2D v = player->m_pos - m_pos;
		if (abs(v.x) <= 510) {

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
			m_img.ChangeAnimation(e2AnimRun);
		}
		else {
			//�ҋ@�A�j���[�V����
			m_img.ChangeAnimation(e2step);
		}
	}
}

void Enemy2::StateAttack()
{
	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(e2Anim_Attack, false);
	//?�Ԗڂ̃A�j���[�V�����̎�����
	/*if (m_img.GetIndex() == ? ) {
		if (m_flip) {
			Base::Add(m_pos + CVector2D(-64, -64), m_flip, eType_Enemmy_Attack, m_attack_no);
		}
		else {
			Base::Add(m_pos + CVector2D(64, -64), m_flip, eType_Enemmy_Attack, m_attack_no);
		}
	}*/
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
		m_state = eState_Idle;
	}
}

void Enemy2::StateDamage()
{
	m_img.ChangeAnimation(e2Anim_Attack, false);
	if (m_img.CheckAnimationEnd()) {
		m_state = eState_Idle;
	}
}

void Enemy2::StateDown()
{
	m_img.ChangeAnimation(e2Animdie, false);
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
	m_img.SetSize(300, 300);
	//���S�ʒu
	m_img.SetCenter(150 ,200);
	//��`
	m_rect = CRect(-30, -98, 30, 0);
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
	//m_img.ChangeAnimation(4);
	//m_img.UpdateAnimation();
	//return;
	m_pos_old = m_pos;
	switch (m_state) {
		//�ʏ�
	case eState_Idle:
		StateIdle();
		break;
		//�U��
	case eState_Attack:
		StateAttack();
		break;
		//�_���[�W
	case eState_Damage:
		StateDamage();
		break;
		//�_�E��
	case eState_Down:
		StateDown();
		break;
	}
	//�����Ă����痎����Ԃ�
	if (m_is_ground && m_vec.y > GRAVITY * 4)
		m_is_ground = false;
	//�d�͗���
	m_vec.y += GRAVITY;
	m_pos += m_vec;

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
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
	DrawRect();

}

void Enemy2::Collision(Base* b)
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
				//�������Z�b�g
				m_vec.y = 0;
				//���n�t���OON
				m_is_ground = true;
			}
		}
		break;

	case eType_Player_Attack:
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
		
			/*if (m_damage_no != s->GetAttacNO() && Base::CollisionRect(this, s)) {
				//�����U���̘A���_���[�W�̖h�~
				m_damage_no = s->GetAttacNO();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
				Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		
		break;*/
		
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
