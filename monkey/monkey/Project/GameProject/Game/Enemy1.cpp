#include "Enemy1.h"
#include "AnimData.h"
#include "Field.h"

void Enemy1::StateIdle()
{
	//�ړ���
	const float move_speed = 6;
	//�ړ��t���O
	bool move_flag = false;
	//�W�����v��
	const float jump_pow = 12;
	Base* player = Base::FindObject(eType_Player);
	if (player) {
		//���ړ�
		if (player->m_pos.x < m_pos.x - 64) {//64�h�b�g����Ă���ƈړ����܂�
			//�ړ��ʂ�ݒ�
			m_pos.x += -move_speed;
			//���]�t���O
			m_flip = true;
			move_flag = true;
		}
		//�E�ړ�
		if (player->m_pos.x > m_pos.x + 64) {
			//�ړ��͂�ݒ�
			m_pos.x += move_speed;
			//���]�t���O
			m_flip = false;
			move_flag = true;
		}

		//���U��
		if (player->m_pos.x < m_pos.x && player->m_pos.x > m_pos.x - 64) {
			//�U����Ԃֈڍs
			m_state = eState_Attack;
			m_attack_no++;
			m_flip = true;
		}
		//�E�U��
		if (player->m_pos.x > m_pos.x && player->m_pos.x < m_pos.x + 64) {
			//�U����Ԃ�
			m_state = eState_Attack;
			m_attack_no++;
			m_flip = false;
		}
	}
}
void Enemy1::StateAttack()
{
	//�U���A�j���[�V�����ւ̕ύX
	//m_img.ChangeAnimation(eAnimAttack01, false);
	if (m_img.CheckAnimationEnd()) {
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
	m_img = COPY_RESOURCE("Enemy", CImage);
	//�Đ��A�j���[�V�����ݒ�
	m_img.ChangeAnimation(0);
	//���W�ݒ�
	m_pos = p;
	//���S�ʒu�ݒ�
	m_img.SetCenter(128, 224);
	//�����蔻��p��`�ݒ�
	m_rect = CRect(-32, -128, 32, 0);
	m_img.SetSize(800, 800);
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
	switch (m_state) {
		//�ʏ���
	case eState_Idle:
			break;
		//�U�����
	case eState_Attack:
		StateAttack();
		break;
		//�_�E�����
	case eState_Down:
		StateDown();
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

void Enemy1::Draw()
{
	//�ʒu�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//���]�ݒ�
	m_img.SetPos(GetScreenPos(m_pos));
	//�`��
	m_img.Draw();
}

void Enemy1::Collision(Base* b)
{
	switch (b->m_type) {
	case eType_Player_Attack:
		//Slash�^�ւ̃L���X�g�A�^�ϊ��o������
		//if (Slash* s = dynamic_cast<Slash*>(b)) {
			//if (m_damage_no != s->GetAttackNo() && Base::CollisionRect(this, s)) {
				//�����U���̘A���_���[�W�h�~
			//	m_damage_no = s->GetAttackNo();
				m_hp -= 50;
				if (m_hp <= 0) {
					m_state = eState_Down;
				}
				else {
					m_state = eState_Damage;
				}
		//		Base::Add(new Effect("Effect_Blood", m_pos + CVector2D(0, -128), m_flip));
			}
		}
	//	break;
	//case eType_Field:
		//Field�^�ւ̃L���X�g�A�^�ϊ��o������
	//	if (Field* f = dynamic_cast<Field*> (b)) {
			//�n�ʂ������ɍs������
		//	if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍����ɖ߂�
			//	m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
			//	m_vec.y = 0;
				//�ڒn�t���OON
			//	m_is_ground = true;
		//	}
		//}
	//break;
//	}
//}

//SetSize