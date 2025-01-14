#ifndef _STORE_MANAGER_H_
#define _STORE_MANAGER_H_

#include "pch.h"
#include "Character.h"

class StoreManager
{
public:
	StoreManager(Character *Character);
	void VisitStore();
	void BuyHPPotion();
	void BuyLevelUpCoupon();
	void BuyBB_Box();
	~StoreManager();

private:
	Character* _Character;
};

#endif