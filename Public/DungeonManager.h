#pragma once
#include "pch.h"
class Character;
class Monster;
class MapManager;

class DungeonManager
{
public:
	DungeonManager(Character* Player, MapManager* MapManager):Player(Player), MM(MapManager),IsDungeonEnd(false), Monster(nullptr), eFightResult(FIGHTEND), IsBossMonster(false){}
	~DungeonManager(){ delete this; }

public:
	void EnterDungeon(Character* Player, MapManager* MM); // 전체 던전 클리어하면 종료
	bool IsDungeonClear();
	bool CanMove(MapManager* MM);
	void Move(MapManager* MM);
	int GetMonsterGold();
	void Fight(Character* Player, MapManager* MM); 

private:
	Monster* Monster;
	Character* Player;
	MapManager* MM;
	bool IsDungeonEnd;
	bool IsBossMonster;
	FightResult eFightResult;
};
