#pragma once
#include"../Base/Base.h"

class Enemy3 :public Base {
private:
	//状態
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
	//状態変数
	int m_state;
	CImage m_img;
	bool m_flip;
	//着地フラグ
	bool m_is_ground;
	//-連続ヒットを解決するー

	//攻撃番号
	int m_attack_no;
	//ダメージ番号
	int m_damage_no;
	//ヒットポイント
	int m_hp;

	//-----------------------

		//各状態での挙動
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
//敵のアニメーションデータ
extern TexAnimData enemy3_anim_data[];
