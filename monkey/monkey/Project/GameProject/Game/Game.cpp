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

Game::Game():Base(eType_Scene)
{
	//濵元
	Base::Add(new Enemy3(CVector2D(14300, 500), true));
	Base::Add(new bar2(CVector2D(9900, 200), true));
	Base::Add(new bar(CVector2D(3400, 500), true));
	Base::Add(new bar3(CVector2D(10500, 600), true));
	Base::Add(new bar4(CVector2D(14300, 1000), true));
	Base::Add(new Map);
	//Base::Add(new Bullet(CVector2D(200,200)));






	//十河
	
	Base::Add(new Enemy2(CVector2D(300, 300), true));
	

//松村
	
	Base::Add(new Player(CVector2D(400, 400), true));
	
	Base::Add(new Enemy1(CVector2D(300, 300), true));
	


}

Game::~Game()
{
}

void Game::Update()
{
	//ゴールが無ければゲームシーン終了
	//if (!Base::FindObject(eType_Goal)) {
		//すべてのオブジェクトを破壊
		//Base::KillAll();
		//タイトルシーンへ
		//Base::Add(new Title());
	//}
	//プレイヤー死亡　ボタン１でゲームシーンを終了
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//すべてのオブジェクトを破壊
		Base::KillAll();
		//タイトルシーンへ
		//Base::Add(new Title());
	}
}
