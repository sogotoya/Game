#include "Enemy2.h"
#include "AnimData.h"
#include "Field.h"
#include "Map.h"

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
	
}

void Enemy2::StateDamage()
{
}

void Enemy2::StateDown()
{
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
	m_img.ChangeAnimation(eAnimIdle);//(3)
	//�X�V
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
	//DrawRect();

}

void Enemy2::Collision(Base* b)
{
	/*switch (b->m_type) {
		//�U���I�u�W�F�N�g�Ƃ̔���
	case eType_Player_Attack:
		//Slash�^�փL���X�g�A�^�ϊ��ł�����
		if (Slash* s = dynamic_cast<Slash*>(b)) {
			if (m_damage_no != s->GetAttacNO() && Base::CollisionRect(this, s)) {
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
		}
		break;*/
}
