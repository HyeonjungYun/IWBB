#include "BossMonster.h"

BossMonster::BossMonster() : Monster(1, MonsterList::BOSS)
{
    _AttackCount = 0;
}

int BossMonster::GetBossHP() const
{
    return _MonsterHP;
}

int BossMonster::GetBossMaxHP() const
{
    return _MonsterMaxHP;
}

int BossMonster::GetAttackCount() const
{
    return _AttackCount;
}

int BossMonster::AttackBoss()
{
    if (_AttackCount >= 5)
        return _MonsterAttack;

    _AttackCount++;
    return 0;
}

void BossMonster::TakeDamage(int damage)
{
    _MonsterHP -= damage;

    if (_MonsterHP <= 0) { _MonsterHP = 0; return; }
}

void BossMonster::MonsterAction()
{
    return;
}

void BossMonster::EncounterBoss()
{
    system("cls");
    cout << "이 던전의 주인, 용감함의 상징 Big Balls 드래곤이 나타났습니다." << endl;
    Sleep(500);
    cout << "Big Balls 드래곤 : 너는 너의 용기가 충분하다고 생각하나?" << endl;
    Sleep(500);
    cout << "Big Balls 드래곤 : 그럴리없지... 나는 너의 용감함을 적절하게 평가하고 있다." << endl;
    Sleep(500);
    cout << "Big Balls 드래곤 : 딱 5대만 맞아주지. 자신의 용감함을 과대평가하는 범부에겐 이 정도면 충분하다." << endl;
    Sleep(1000);
}

void BossMonster::ClearBoss()
{
    system("cls");
    cout << "이 던전의 주인, 용감함의 상징 Big Balls 드래곤에게 패배하였습니다." << endl;
    Sleep(500);
    cout << "Big Balls 드래곤 : 너는 너의 용기가 충분하다고 생각하나?" << endl;
    Sleep(500);
    cout << "Big Balls 드래곤 : 그럴리없지... 나는 너의 용감함을 적절하게 평가하고 있다." << endl;
    Sleep(500);
    cout << "Big Balls 드래곤 : 자신의 용감함을 과대평가하는 범부에겐 용기가 아닌 우매함만이 있을 뿐이다." << endl;
    Sleep(1000);
}

void BossMonster::LoseBoss()
{
    system("cls");
    cout << "이 던전의 주인, 용감함의 상징 Big Balls 드래곤을 쓰러뜨렸습니다." << endl;
    Sleep(500);
    cout << "Big Balls 드래곤 : 나의 죽음으로써 나의 용감함은 증명되었다..." << endl;
    Sleep(1000);
}

BossMonster::~BossMonster()
{
    delete this;
}
