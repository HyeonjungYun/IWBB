#ifndef _STORE_MANAGER_H_
#define _STORE_MANAGER_H_

#include "pch.h"
#include "Character.h"

class StoreManager
{
public:
	StoreManager(Character *Character);
	void VisitStore();
	~StoreManager();

private:
	Character* _Character;
};

#endif