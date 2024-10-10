#include "Enemy1.h"
#include "AnimData.h"
#include "Map.h"

void Enemy1::StateIdle()
{
	//�ړ���
	const float move_speed = 5;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		CVector2D v = player->m_pos + CVector2D(0,-64) - m_pos;
		if (abs(v.x) <= 510) {


			//���ړ�
			if (v.x <-16) {//64�h�b�g����Ă���ƈړ����܂�
				//�ړ��ʂ�ݒ�
				m_pos.x += -move_speed;
				//���]�t���O
				m_flip = true;
				move_flag = true;
			}
			//�E�ړ�
			if (v.x > +16) {
				//�ړ��͂�ݒ�
				m_pos.x += move_speed;
				//���]�t���O
				m_flip = false;
				move_flag = true;
			}
			//��ړ�
			if (v.y < -16) {//64�h�b�g����Ă���ƈړ����܂�
				//�ړ��ʂ�ݒ�
				m_pos.y += -move_speed;
				move_flag = true;
			}
			//���ړ�
			if (v.y > + 16) {
				//�ړ��͂�ݒ�
				m_pos.y += move_speed;
				move_flag = true;
			}
		}
		//���U��
		if (v.Length() <  24 ) {
			//�U����Ԃֈڍs
			m_state = eState_Attack;
			m_attack_no++;  //���i�q�b�g�΍�
			//m_flip = true;  //���]�t���O

		}
		m_img.ChangeAnimation(eState_Idle, false);
	}
}
void Enemy1::StateAttack()
{
	//�U���A�j���[�V�����֕ύX
	m_img.ChangeAnimation(eState_Attack, false);
	//?�Ԗڂ̃A�j���[�V�����̎�����
	/*if (m_img.GetIndex() == ? ) {
		if (m_flip) {
			Base::Add(new Slash(m_pos + CVector2D(-64, -64), m_flip, eType_Enemmy_Attack, m_attack_no));
		}
		else {
			Base::Add(new Slash(m_pos + CVector2D(64, -64), m_flip, eType_Enemmy_Attack, m_attack_no));
		}
	}*/
	//�A�j���[�V�������I��������
	if (m_img.CheckAnimationEnd()) {
		//�ʏ��Ԃֈڍs
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
	//�摜����
	m_img = COPY_RESOURCE("Enemy1", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	
	m_img.SetSize(200, 200);
	//���S�ʒu�ݒ�
	m_img.SetCenter(100,100);
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-45, -15, 45, 15);
	
	//�q�b�g�|�C���g
	m_hp = 5;
	//���]�t���O
	m_flip = flip;
	//���n�t���O
	m_is_ground = true;
	//�U���ԍ�
	m_attack_no = rand();
	//�_���[�W�ԍ�
	m_damage_no = -1;

}

void Enemy1::Update()
{
	//m_img.ChangeAnimation(5);
	//m_img.UpdateAnimation();
	m_pos_old = m_pos;
	switch (m_state) {
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
	}
	//�����Ă����痎������Ԃֈڍs
	//if (m_is_ground && m_vec.y > GRAVITY * 4)
	//	m_is_ground = false;
	//�d�͂ɂ�闎��
	//m_vec.y += GRAVITY;
	//m_pos += m_vec;

	//�A�j���[�V�����X�V
	m_img.UpdateAnimation();
	
	
}

void Enemy1::Draw()
{
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetFlipH(m_flip);
	//�`��
	m_img.Draw();
	//�����蔻���`�\��
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
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ڒn�t���OON
				m_is_ground = true;
			}
		}
	}
	/*case eType_Map:
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
	}*/

}
static TexAnim enemy1Idle[] = {

	{ 1,6 },
	{ 2,6 },
	{ 3,6 },
	{ 4,6 },
	{ 5,6 },
	{ 6,6 },
	{ 7,6 },
	{ 8,6 },
	{ 9,6 },
};

static TexAnim enemy1Attack01[] = {
	{ 10,7 },
	{ 11,7 },
	{ 12,7 },
	{ 13,7 },
	{ 14,7 },
	{ 15,7 },
	{ 16,7 },
};
static TexAnim enemy1Damage[] = {
	{ 16,10 },
	{ 17,10 },
};
static TexAnim enemy1Down[] = {
	{ 18,18 },
	{ 19,18 },
	{ 20,18 },
	{ 21,18 },
	{ 22,18 },
	{ 23,18 },
};
TexAnimData Enemy1_anim_data[] = {
	ANIMDATA(enemy1Idle),
	ANIMDATA(enemy1Attack01),
	ANIMDATA(enemy1Damage),
	ANIMDATA(enemy1Down),
};