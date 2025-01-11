#include "Monster.h"
#include "Tanker.h"

int main()
{
	Monster* mon = new Tanker("탱커", 100, 0, 5, 10);
	cout << mon->getName() << "의 공격력: " << mon->getAttack() << endl;
	delete mon;
	return 0;
}