#ifndef _PCH_H_
#define _PCH_H_

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <random>
#include <cstdlib>

#define ITEM_SIZE 1

using namespace std;

typedef struct
{
	int x;
	int y;
}Pos;

enum ItemList
{
	POTION = 1
};

enum FightResult { PLAYERWIN, PLAYERLOSE, FIGHTEND };


#endif
