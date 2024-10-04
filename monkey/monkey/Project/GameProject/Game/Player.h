#pragma once
#include "../Base/Base.h"

class Player : public Base {
private:
	//���
	enum {
		eState_Idle,
		eState_Attack01,
		eState_Attack02,
		eState_Damage,
		eState_Down,
		eState_Crouchi,

	};
	enum {
		eAnimIdle = 0,
		eAnimRun,
		eAnimJumpUp,
		eAnimJumpDown,
		eAnimAttack01,
		eAnimCrouchi,
		eAnimAttack01End,
		eAnimAttack02,
		eAnimAttack02End,
		eAnimAttack03,
		eAnimAttack03End,
		eAnimDamage,
		eAnimDamageEnd,
		eAnimDeath,
		eAnimDown,
		eAnimDownGround,
		eAnimWakeUp,
		eAnimGuard,
		eAnimGuardEnd,
		eAnimCrash,
		eAnimCrashEnd,
		eAnimExtAttack01,
		eAnimExtAttack01End,
		eAnimExtAttack02,
		eAnimExtAttack02End,
		eAnimStep,
		
	};
	//��ԕϐ�
	int m_state;
	CImage m_img;
	bool m_flip;
	//���n�t���O
	bool m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	//�_���[�W�ԍ�
	int m_damage_no;
	//�q�b�g�|�C���g
	int m_hp;
	//�e��Ԃł̋���
	void StateIdle();
	void StateAttack01();
	void StateAttack02();
	void StateDamage();
	void StateDown();
	void StateCrouchi();
public:
	Player(const CVector2D& p, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);

};
extern TexAnimData player_anim_data[];