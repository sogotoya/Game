#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Enemy2.h"
Game::Game():Base(eType_Scene)
{
	Base::Add(new Map());
	Base::Add(new Player(CVector2D(256, 1000), false));
	
}

Game::~Game()
{
}

void Game::Update()
{
}
