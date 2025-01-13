#pragma once
#include "pch.h"
class Character;
class Monster;
class MapManager;

class DungeonManager
{
public:
	DungeonManager():IsDungeonEnd(false), Monster(nullptr), eFightResult(FIGHTEND), IsBossMonster(false){}
	~DungeonManager(){ delete this; }

public:
	void EnterDungeon(Character* Player, MapManager* MM); // 전체 던전 클리어하면 종료
	bool CanMove(MapManager* MM);
	void Move(MapManager* MM);
	int GetMonsterGold();
	void Fight(Character* Player, MapManager* MM); 
	void DeleteMonster();

private:
	Monster* Monster;
	bool IsDungeonEnd;
	bool IsBossMonster;
	FightResult eFightResult;
};
