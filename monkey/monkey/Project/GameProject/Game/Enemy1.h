#pragma once
#include "../Base/Base.h"

class Enemy1 : public Base {
	private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
	};
	//��ԕϐ�
	int m_state;
	CImage m_img;
	bool m_flip;
	//�̗�
	int m_hp;
    //�e��Ԃł̋���
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
	//���n�t���O
	bool m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	
	int m_damage_no;
	
public:
	Enemy1(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);

};
extern TexAnimData Enemy1_anim_data[];