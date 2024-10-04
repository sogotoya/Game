#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Enemy2.h"
#include "Enemy3.h"
Game::Game():Base(eType_Scene)
{
	
	Base::Add(new Player(CVector2D(256, 1000), false));
	Base::Add(new Enemy2(CVector2D(3 * MAP_TIP_SIZE, 5 * MAP_TIP_SIZE), true));
	Base::Add(new Enemy3(CVector2D(31 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE), true));
}

Game::~Game()
{
}

void Game::Update()
{
}
