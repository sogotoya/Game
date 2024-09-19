#pragma once
#include "../Base/Base.h"

class Enemy : public Base {
private:
	enum {
		eState_Idle,
		eState_Attack,
		eState_Damage,
		eState_Down,
	};
	//状態変数
	int m_state;
	CImage m_img;
	bool m_flip;
	//体力
	int m_hp;
	//各状態での挙動
	void StateIdle();
	void StateAttack();
	void StateDamage();
	void StateDown();
	//着地フラグ
	bool m_is_ground;
	//攻撃番号
	int m_attack_no;



public:
	Enemy(const CVector2D& pos, bool flip);
	void Update();
	void Draw();
	void Collision(Base* b);
};