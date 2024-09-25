#include "Game.h"
#include "Map.h"

Game::Game():Base(eType_Scene)
{
	Base::Add(new Map());
}

Game::~Game()
{
}

void Game::Update()
{
}
