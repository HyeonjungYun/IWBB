#ifndef _DUNGEON_MANAGER_H_
#define _DUNGEON_MANAGER_H_

#include "pch.h"
#include "MapManager.h"
#include "Character.h"
#include "Monster.h"

class DungeonManager
{
public:
	DungeonManager(Character* _Character, int MapLevel) 
		: Player(_Character), MM(new MapManager(MapLevel)), IsDungeonEnd(false), DungeonMapLevel(MapLevel), eFightResult(FIGHTEND), IsBossMonster(false) {}
	~DungeonManager(){ delete this; }

public:
	bool EnterDungeon(); // 전체 던전 클리어하면 종료
	bool IsExitDungeon();
	bool CanMove(MapManager* MM);
	void Move(MapManager* MM);
	void Fight(MapManager* MM); 
	bool CanRun();

private:
	Character* Player;
	MapManager* MM;
	bool IsDungeonEnd;
	bool IsBossMonster;
	int DungeonMapLevel;
	FightResult eFightResult;
};

#endif