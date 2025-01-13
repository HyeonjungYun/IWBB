#ifndef _GAME_MANAGER_H_
#define _GAME_MANAGER_H_

#include "pch.h"
#include "Character.h"
#include "DungeonManager.h"
#include "StoreManager.h"
#include "MapManager.h"

// ���� ������ ��å�ϴ� Ŭ����
class GameManager
{
public:
	GameManager();
	void GamePlaying();
	~GameManager();
private:
	Character* _Character;
	DungeonManager* _DungeonManager;
	StoreManager* _StoreManager;
	MapManager* _MapManager;
};

#endif