#ifndef _ITEM_H_
#define _ITEM_H_

#include <string>

using namespace std;

class Item
{
private:
	int _itemID;
	string _itemName;
public:
	Item() : _itemID(0) {}
	Item(int itemID);
	string getItemName(int itemID);
};

Item::Item(int itemID)
{
	_itemID = itemID;
	_itemName = getItemName(itemID);
}

string Item::getItemName(int itemID)
{
	if (itemID == static_cast<int>(ItemList::POTION)) return "HP Æ÷¼Ç";
}

#endif