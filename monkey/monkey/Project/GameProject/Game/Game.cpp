#include "Base/Base.h" 
#include"Game/Enemy1.h"
#include"Game/Field.h"
#include"Game/AnimData.h"
#include"Game/Map.h"
#include"Game/Player.h"
#include"Game/Enemy3.h"
#include"Game/Enemy2.h"
#include"Game/Game.h"
#include"Game/TP.h"
#include"Game/Bar.h"
#include"Game/Bar2.h"
#include"Game/Bar3.h"
#include"Game/Bar4.h"
#include"Game/Bullet.h"
#include"Title/Title.h"
#include"Game/Goal.h"
#include"Game/rast.h"

Game::Game():Base(eType_Scene)
{
	//濵元
	Base::Add(new Enemy3(CVector2D(14300, 500), true));
	Base::Add(new bar2(CVector2D(10000, 200), true));
	Base::Add(new bar(CVector2D(3400, 500), true));
	Base::Add(new bar3(CVector2D(10700, 600), true));
	Base::Add(new bar4(CVector2D(14300, 1000), true));
	Base::Add(new Map);
	
	//Base::Add(new Bullet(CVector2D(200,200)));
	





	//十河
	
	Base::Add(new Enemy2(CVector2D(2000, 300), true));
	Base::Add(new Enemy2(CVector2D(5000, 300), true));
	Base::Add(new Enemy2(CVector2D(6000, 300), true));
	
	

//松村
	
	Base::Add(new Player(CVector2D(13000, 400), true));
	
	Base::Add(new Enemy1(CVector2D(3000, 300), true));
	Base::Add(new Enemy1(CVector2D(8000, 500), true));
	

	m_gamestate = 0;
}

Game::~Game()
{
}

void Game::Update()
{
	switch (m_gamestate) {
		case 0:
			if (!Base::FindObject(eType_Enemy3)) {
				m_gamestate++;
				Base::Add(new Goal(CVector2D(13850, 500)));
			}
			break;
		case 1:
			//ゴールが無ければゲームシーン終了
			if (!Base::FindObject(eType_Goal)) {
				Base::Add(new rast);
				m_gamestate++;
		}
			break;
		case 2:
			if (PUSH(CInput::eButton1)) {
				//すべてのオブジェクトを破壊
				Base::KillAll();
				//タイトルシーンへ
				Base::Add(new Title());
			}
			break;
	}
	
	//プレイヤー死亡　ボタン１でゲームシーンを終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//すべてのオブジェクトを破壊
		Base::KillAll();
		//タイトルシーンへ
		//Base::Add(new Title());
	}
}
