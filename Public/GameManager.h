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
	int GetMapLevel() const;
	void SetMapLevel();
	~GameManager();
private:
	Character* _Character;
	StoreManager* _StoreManager;
	int _MapLevel;
};

#endif