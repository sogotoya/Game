#pragma once
#include"../Base/Base.h"

class Enemy3 :public Base {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack01,
		eState_Attack02,
		eState_Attack03,
		eState_Damage,
		eState_Down,
	};
	enum {
		E3ran,
		E3Attack01,
		E3Attack02,
		E3Attack03,
		E3Step,
		E3Dmg,
		E3Down,
	};
	//��ԕϐ�
	int m_state;
	CImage m_img;
	bool m_flip;
	//���n�t���O
	bool m_is_ground;
	//-�A���q�b�g����������[

	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;
	//�q�b�g�|�C���g
	int m_hp;

	//-----------------------

		//�e��Ԃł̋���
	void StateIdle();
	void StateAttack01();
	void StateAttack02();
	void StateAttack03();
	void StateDamage();
	void StateDown();
public:
	Enemy3(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};
//�G�̃A�j���[�V�����f�[�^
extern TexAnimData enemy3_anim_data[];
