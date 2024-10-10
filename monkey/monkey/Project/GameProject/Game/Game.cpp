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
	//ūM³
	Base::Add(new Enemy3(CVector2D(14300, 500), true));
	Base::Add(new bar2(CVector2D(10000, 200), true));
	Base::Add(new bar(CVector2D(3400, 500), true));
	Base::Add(new bar3(CVector2D(10700, 600), true));
	Base::Add(new bar4(CVector2D(14300, 1000), true));
	Base::Add(new Map);
	//Base::Add(new Bullet(CVector2D(200,200)));






	//\Ķ
	
	Base::Add(new Enemy2(CVector2D(300, 300), true));
	

//¼ŗ
	
	Base::Add(new Player(CVector2D(400, 400), true));
	
	Base::Add(new Enemy1(CVector2D(300, 300), true));
	


}

Game::~Game()
{
}

void Game::Update()
{
	//S[Ŗ³ÆźĪQ[V[I¹
	//if (!Base::FindObject(eType_Goal)) {
		//·×ÄĢIuWFNgšjó
		//Base::KillAll();
		//^CgV[Ö
		//Base::Add(new Title());
	//}
	//vC[S@{^PÅQ[V[šI¹
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//·×ÄĢIuWFNgšjó
		Base::KillAll();
		//^CgV[Ö
		//Base::Add(new Title());
	}
}
