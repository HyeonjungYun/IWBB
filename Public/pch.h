#ifndef _PCH_H_
#define _PCH_H_

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <cstdlib>
#include <unordered_map>
#include <windows.h>

#define ITEM_SIZE 1
#define POTION_GOLD 100
#define LEVEL_COUPON_GOLD 1000
#define BB_BOX_GOLD 500

using namespace std;

typedef struct
{
	int x;
	int y;
}Pos;

namespace ItemList
{
	enum Item
	{
		POTION = 1,
		LEVELUP_COUPON,
		BB_BOX
	};
}

namespace MonsterList
{
	enum Monster
	{
		ATTACKER = 1,
		HEALER,
		TANKER
	};
}

int CreateRandomValue(int first, int second)
{
	random_device rd; //랜덤 생성 클래스 선언
	mt19937 gen(rd()); // 난수
	uniform_int_distribution<> dist(first, second);

	return dist(gen);
}

enum FightResult { PLAYERWIN, PLAYERLOSE, VISITED, PLAYERRUN, FIGHTEND };

#endif
