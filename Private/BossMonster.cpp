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
    cout << "�� ������ ����, �밨���� ��¡ Big Balls �巡���� ��Ÿ�����ϴ�." << endl;
    Sleep(500);
    cout << "Big Balls �巡�� : �ʴ� ���� ��Ⱑ ����ϴٰ� �����ϳ�?" << endl;
    Sleep(500);
    cout << "Big Balls �巡�� : �׷�������... ���� ���� �밨���� �����ϰ� ���ϰ� �ִ�." << endl;
    Sleep(500);
    cout << "Big Balls �巡�� : �� 5�븸 �¾�����. �ڽ��� �밨���� �������ϴ� ���ο��� �� ������ ����ϴ�." << endl;
    Sleep(1000);
}

void BossMonster::ClearBoss()
{
    system("cls");
    cout << "�� ������ ����, �밨���� ��¡ Big Balls �巡�￡�� �й��Ͽ����ϴ�." << endl;
    Sleep(500);
    cout << "Big Balls �巡�� : �ʴ� ���� ��Ⱑ ����ϴٰ� �����ϳ�?" << endl;
    Sleep(500);
    cout << "Big Balls �巡�� : �׷�������... ���� ���� �밨���� �����ϰ� ���ϰ� �ִ�." << endl;
    Sleep(500);
    cout << "Big Balls �巡�� : �ڽ��� �밨���� �������ϴ� ���ο��� ��Ⱑ �ƴ� ����Ը��� ���� ���̴�." << endl;
    Sleep(1000);
}

void BossMonster::LoseBoss()
{
    system("cls");
    cout << "�� ������ ����, �밨���� ��¡ Big Balls �巡���� �����߷Ƚ��ϴ�." << endl;
    Sleep(500);
    cout << "Big Balls �巡�� : ���� �������ν� ���� �밨���� ����Ǿ���..." << endl;
    Sleep(1000);
}

BossMonster::~BossMonster()
{
    delete this;
}
