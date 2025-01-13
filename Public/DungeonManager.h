#pragma once
#include "pch.h"
class Character;
class Monster;
class MapManager;

class DungeonManager
{
public:
	DungeonManager():isDungeonEnd(false), monster(nullptr), eFightResult(FIGHTEND){}
	~DungeonManager(){ delete this; }

public:
	void EnterDungeon(Character* Player, MapManager* MM); // 전체 던전 클리어하면 종료
	FightResult Fight(Character* Player, MapManager* MM);
private:
	Monster* monster;
	bool isDungeonEnd;
	FightResult eFightResult;
};
