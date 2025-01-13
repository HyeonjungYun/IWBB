#pragma once
#include "pch.h"
class Character;
class Monster;
class MapManager;

class DungeonManager
{
public:
	DungeonManager():IsDungeonEnd(false), Monster(nullptr), eFightResult(FIGHTEND){}
	~DungeonManager(){ delete this; }

public:
	void EnterDungeon(Character* Player, MapManager* MM); // 전체 던전 클리어하면 종료
	void Move(MapManager* MM);
	void SamePosition(MapManager* MM);
	void VisitCheck(vector<Pos>& visited, Character* Player, MapManager* MM);
	void Result(vector<Pos>& visited, MapManager* MM);
	void EnterBoss(MapManager* MM);
	int GetMonsterGold();
	FightResult Fight(Character* Player, MapManager* MM);


private:
	Monster* Monster;
	bool IsDungeonEnd;
	FightResult eFightResult;
};
