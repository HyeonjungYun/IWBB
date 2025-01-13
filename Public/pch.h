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

#endif
