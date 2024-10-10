#include "Game.h"
#include "Map.h"
#include "Player.h"
#include "Enemy2.h"
#include "Enemy3.h"
#include "Enemy1.h"
//#include "Title.h"
Game::Game():Base(eType_Scene)
{
	
	Base::Add(new Player(CVector2D(256, 1000), false));
	Base::Add(new Enemy2(CVector2D(3 * MAP_TIP_SIZE, 5 * MAP_TIP_SIZE), true));
	Base::Add(new Enemy3(CVector2D(31 * MAP_TIP_SIZE, 20 * MAP_TIP_SIZE), true));
	Base::Add(new Enemy1(CVector2D(30 * MAP_TIP_SIZE, 18 * MAP_TIP_SIZE), true));
}

Game::~Game()
{
}

void Game::Update()
{
	//�S�[����������΃Q�[���V�[���I��
	if (!Base::FindObject(eType_Goal)) {
		//���ׂẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		//Base::Add(new Title());
	}
	//�v���C���[���S�@�{�^���P�ŃQ�[���V�[�����I��
	if (!Base::FindObject(eType_Player) && PUSH(CInput::eButton1)) {
		//���ׂẴI�u�W�F�N�g��j��
		Base::KillAll();
		//�^�C�g���V�[����
		//Base::Add(new Title());
	}
}
