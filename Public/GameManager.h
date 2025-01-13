#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "pch.h"
#include "Character.h"
#include "DungeonManager.h"
#include "StoreManager.h"

// 게임 진행을 총책하는 클래스
class GameManager
{
public:
	GameManager();
	void GamePlaying();
	~GameManager();
private:
	Character* _Character;
	//DungeonManager* _DungeonManager;
	StoreManager* _StoreManager;
};

#endif