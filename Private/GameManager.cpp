﻿#include "GameManager.h"
#include "BossMonster.h"

GameManager::GameManager()
{
	string name;
	cout << "캐릭터 이름을 입력하세요. : ";
	getline(cin, name);

	cout << "BB 던전에 입장하신 것을 환영합니다." << endl;

	_MapLevel = 1;
	_Character = new Character(name);
	_StoreManager = new StoreManager(_Character);
	_IsGameClear = false;
}

void GameManager::GamePlaying()
{
	while (1)
	{
		string choice;

		cout << "-------------------------------------------" << endl;
		_Character->PrintCharacter();
		cout << "-------------------------------------------" << endl;
		cout << endl << "아래로 내려가는 계단이 보인다." << endl;
		cout << "1. 계단을 내려간다." << endl;
		cout << "2. 상점을 이용한다." << endl;
		cout << "3. 인벤토리를 열어본다." << endl;
		cout << "4. 게임을 종료한다." << endl;
		cout << "입력 : ";
		getline(cin, choice);
		system("cls");

		if (choice == "1")
		{
			DungeonManager* _DungeonManager = new DungeonManager(_Character, _MapLevel);
			if (_Character->GetLevel() >= 11) 
			{
				EncounterBossMonster();
				break;
			}
			if (!_DungeonManager->EnterDungeon())
			{
				_MapLevel++;
			}
			else
			{
				GameOver();
				break;
			}
			continue;
		}
		if (choice == "2")
		{
			_StoreManager->VisitStore();
			continue;
		}
		if (choice == "3")
		{
			_Character->UseItem();
			continue;
		}
		if (choice == "4")
		{
			break;
		}
		if (_IsGameClear)
		{
			break;
		}
		cout << "잘못 입력하셨습니다." << endl;
	}
}

void GameManager::GameOver()
{
	cout << "전투에서 패배해 게임이 종료됩니다." << endl;
}

int GameManager::GetMapLevel() const
{
	return _MapLevel;
}

void GameManager::SetMapLevel()
{
	_MapLevel++;
}

void GameManager::EncounterBossMonster()
{
	BossMonster* Boss = new BossMonster();
	Boss->EncounterBoss();

	while (1)
	{
		_Character->PrintCharacter();
		Boss->PrintMonster();

		cout << "무엇을 하시겠습니까?\n1. 공격" << endl;
		string choice;
		getline(cin, choice);
		system("cls");

		if (choice == "1")
		{
			int CharacterAttackValue = _Character->GetAttack();
			int BossAttackValue = Boss->GetAttack();
			Boss->TakeDamage(CharacterAttackValue);

			cout << _Character->GetName() << "가 " << Boss->GetName() << "에게 " << CharacterAttackValue << "의 대미지로 공격합니다." << endl;
			cout << Boss->GetName() << "의 HP : " << Boss->GetHp() << endl;

			if (BossAttackValue == 0)
			{
				cout << 5 - Boss->GetAttackCount() << "번 남았습니다." << endl;
			}
			else
			{
				_Character->SetHP(_Character->GetHp() - BossAttackValue);
				cout << Boss->GetName() << "가 " << _Character->GetName() << "에게 " << BossAttackValue << "의 대매지로 공격합니다." << endl;
				cout << _Character->GetName() << "의 HP : " << _Character->GetHp() << endl;
			}

			if (_Character->GetHp() <= 0)
			{
				_IsGameClear = true;
				Boss->LoseBoss();
				break;
			}

			if (Boss->GetHp() <= 0)
			{
				_IsGameClear = true;
				Boss->ClearBoss();
				break;
			}
		}
	}
}

GameManager::~GameManager()
{
	delete this;
}