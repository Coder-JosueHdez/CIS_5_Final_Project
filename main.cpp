#include <iostream>
#include <cstdlib>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Ship {
	int hitPoints;
	string shipName;
	string team;

	Ship(int h, const string s, const string t)
		: hitPoints(h), shipName(s), team(t) {
	}
};

void printShips(Ship shipsA[], Ship shipsE[], int countA, int countE);//Prints ally and enemy ships
void yourTurn(Ship shipsA[], Ship shipsE[]);//Attack or Repair
void emenyTurn(Ship shipsA[], Ship shipsE[]);//Enemy only attacks
void attackShipE(Ship shipsA[], Ship shipsE[], int shipA, int shipE);//random damage, say how much damage was caused to which ship.
void attackShipA(Ship shipsA[], Ship shipsE[], int chooseShipA, int chooseShipE);//pick which ship attacks, say how much damage it causes to which ship.
void repairShip(Ship shipsA[], int shipA);//pick which ship to ship to repair, say how much is was repaired.
//void checkCounters(Ship shipsA[], Ship shipsE[], int countA, int countE);//checks for who wins/loses

int main()
{
	int countA = 3;
	int countE = 3;
	Ship shipsA[3] = { { 15, "Main Commander", "Ally" }, { 10, "Gun Ship", "Ally" }, { 20, "Tanker", "Ally" } };
	Ship shipsE[3] = { { 15, "Main Commander", "Enemy" }, { 10, "Gun Ship", "Ememy" }, { 20, "Tanker", "Ememy" } };

	int counterA = 3;
	int counterE = 3;

	string name;
	string yon = "No";
	cout << "Name? ";
	cin >> name;
	cout << "Hello, " << name << "! Welcome aboard!" << endl;
	cout << "You're incharge of 3 ships which are in a fight with 3 enemy ships.";//quick lore drop
	do {
		cout << "You will take turns to make actions and who ever destroies the other's ships first, Wins!" << endl;//how game works
		cout << "Understood? Yes / No ";
		cin >> yon;
		if (yon == "Yes")//checking for understanding, will repeat til user inputs "Yes"
		{
			cout << "Great! Let's begin!" << endl;
			break;
		}
		else if (yon != "No")
		{
			cout << "Invalid input." << endl;
			yon = "No";//resets to No
		}
	} while (yon == "No");

	int r = 1;//rounds
	do {
		cout << "=============================" << endl;
		cout << "========== Round " << r++ << " ==========" << endl;
		cout << "=============================" << endl;
		printShips(shipsA, shipsE, countA, countE);
		cout << endl;
		emenyTurn(shipsA, shipsE);
		yourTurn(shipsA, shipsE);
		//checkCounters(shipsA, shipsE, counterA, counterE);
		for (int i = 0; i < 3; i++)
		{
			if (shipsA[i].hitPoints <= 0)//looks for destroied ships
			{
				counterA -= 1;//-1 from counter
			}
			if (shipsE[i].hitPoints <= 0)//looks for destroied ships
			{
				counterE -= 1;//-1 from counter
			}
		}
		if (counterA <= 0)//if count = 0 Game Over
		{
			cout << "You lost. Game Over" << endl;
			break;
		}
		else if (counterE <= 0)
		{
			cout << "Great Job " << name << "! You have defeated the enemy!" << endl;
			break;
		}
		else
		{
			counterA = 3;//Otherwise counters are rest to 3 for next time
			counterE = 3;
		}
	} while (r < 51);
	if (r == 50)
	{
		cout << "============== [DRAW] ==============";
	}

	return 0;
}

void printShips(Ship shipsA[], Ship shipsE[], int countA, int countE)//Prints ally and enemy ships
{
	cout << "Your ships: " << endl;
	for (int i = 0; i < countA; i++)
	{
		if (shipsA[i].hitPoints > 0)//checks for any destroied ships to label as [DESTROIED]
		{
			cout << i << ". " << shipsA[i].team << " ship, " << shipsA[i].shipName << " has " << shipsA[i].hitPoints << " hit points." << endl;
		}
		else
		{
			cout << i << ". " << shipsA[i].team << " ship, " << shipsA[i].shipName << " is [DESTROIED]" << endl;
		}
	}

	cout << "Enemy ships: " << endl;
	for (int i = 0; i < countE; i++)
	{
		if (shipsE[i].hitPoints > 0)//checks for any destroied ships to label as [DESTROIED]
		{
			cout << i << ". " << shipsE[i].team << " ship, " << shipsE[i].shipName << " has " << shipsE[i].hitPoints << " hit points." << endl;
		}
		else
		{
			cout << i << ". " << shipsE[i].team << " ship, " << shipsE[i].shipName << " is [DESTROIED]" << endl;
		}
	}
}

void yourTurn(Ship shipsA[], Ship shipsE[])//Attack or Repair
{
	cout << "***Your Turn***\n";
	int chooseShipA = 3;
		cout << "Which ship do you want to use? 0, 1, or 2." << endl;
		do {
			cin >> chooseShipA;
			cin.ignore();
			switch (chooseShipA) {
			case 0:
				cout << "--  " << shipsA[0].shipName << " was selected! --" << endl;
				break;
			case 1:
				cout << "--  " << shipsA[1].shipName << " was selected! --" << endl;
				break;
			case 2:
				cout << "--  " << shipsA[2].shipName << " was selected! --" << endl;
				break;
			default:
				cout << "Invalid input. 0, 1, or 2" << endl;
				chooseShipA = 3;//resets to 3
			}
		} while (chooseShipA == 3);
		
		int action = 0;
		int chooseShipE = 3;
		cout << "What would you like to do: Attack(1) or Repair(2)" << endl;
		do {
			cin >> action;
			cin.ignore();
			switch (action) {
			case 1:
				cout << "-- Attack was selected! --" << endl;

				cout << "Which ship do you want to Attack? 0, 1, or 2." << endl;
				do {
					cin >> chooseShipE;
					cin.ignore();
					switch (chooseShipE) {
					case 0:
						cout << "--  " << shipsE[0].shipName << " was selected! --" << endl;
						break;
					case 1:
						cout << "--  " << shipsE[1].shipName << " was selected! --" << endl;
						break;
					case 2:
						cout << "--  " << shipsE[2].shipName << " was selected! --" << endl;
						break;
					default:
						cout << "Invalid input. 0, 1, or 2" << endl;
						chooseShipE = 3;//resets to 3
					}
				} while (chooseShipE == 3);

				attackShipA(shipsA, shipsE, chooseShipA, chooseShipE);
				break;
			case 2:
				repairShip(shipsA, chooseShipA);
				break;
			default:
				cout << "Invalid input. Attack(1) or Repair(2)" << endl;
				action = 0;//resets to 0
			}
		} while (action == 0);
	return;
}
//Enemy Moves
void emenyTurn(Ship shipsA[], Ship shipsE[])//Enemy only attacks
{
	cout << "***Enemy Turn***\n";
	srand(time(nullptr));
	int randomPickA = rand() % 3;//random Ally is attacked
	int randomPickE = rand() % 3;//random Enemy
	cout << "Ally " << shipsA[randomPickA].shipName << " is being attacked by Enemy " << shipsE[randomPickE].shipName << endl;
	attackShipE(shipsA, shipsE, randomPickA, randomPickE);
	return;
}
void attackShipE(Ship shipsA[], Ship shipsE[], int shipA, int shipE)//random damage, say how much damage was caused to which ship.
{
	srand(time(nullptr));
	int damage = rand() % 15 + 1;//can change so it may miss
	if (shipsA[shipA].hitPoints <= 0)//checks to see if selected ship is destroied
	{
		cout << "Ally ship is already destroied!" << endl;
	}
	else if (shipsE[shipE].hitPoints <= 0)//checks to see if selected ship is destroied
	{
		cout << "Enemy ship is destroied! It can not attack." << endl;
	}
	else
	{
		shipsA[shipA].hitPoints -= damage;
		cout << "Enemy " << shipsE[shipE].shipName << " did " << damage << " damage to Ally " << shipsA[shipA].shipName << endl;
		cout << "Ally " << shipsA[shipA].shipName << " now has " << shipsA[shipA].hitPoints << " hit points!" << endl;
	}
	return;
}
//Ally Moves
void attackShipA(Ship shipsA[], Ship shipsE[], int chooseShipA, int chooseShipE)//pick which ship attacks, say how much damage it causes to which ship.
{
	srand(time(nullptr));
	int damage = rand() % 15 + 1;//can change so it may miss
	if (shipsA[chooseShipA].hitPoints <= 0)//checks to see if selected ship is destroied
	{
		cout << "Ally ship is destroied! It can not attack." << endl;
	}
	else if (shipsE[chooseShipE].hitPoints <= 0)//checks to see if selected ship is destroied
	{
		cout << "Enemy ship is already destroied!" << endl;
	}
	else
	{
		shipsE[chooseShipE].hitPoints -= damage;
		cout << "Ally " << shipsA[chooseShipA].shipName << " did " << damage << " damage to enemy " << shipsE[chooseShipE].shipName << endl;
		cout << "Enemy " << shipsE[chooseShipE].shipName << " now has " << shipsE[chooseShipE].hitPoints << " hit points!" << endl;
	}
	return;
}
void repairShip(Ship shipsA[], int shipA)//pick which ship to ship to repair, say how much is was repaired.
{
	cout << "-- Repair was selected! --" << endl;
	srand(time(nullptr));
	int repair = rand() % 10 + 1;
	if (shipsA[shipA].hitPoints <= 0)//checks to see if selected ship is destroied
	{
		cout << "Ally " << shipsA[shipA].shipName << " is destroied! Can not be repaired." << endl;
	}
	else
	{
		shipsA[shipA].hitPoints += repair;
		cout << "Ally " << shipsA[shipA].shipName << " was repaired with " << repair << " hit points." << endl;
		cout << "Ally " << shipsA[shipA].shipName << " now has " << shipsA[shipA].hitPoints << " hit points!\n";
	}
	return;
}
/*void checkCounters(Ship shipsA[], Ship shipsE[], int counterA, int counterE)//checks for who wins/loses
{
	for (int i = 0; i < 3; i++)
	{
		if (shipsA[i].hitPoints <= 0)
		{
			counterA -= 1;
			if (counterA <= 0)
			{
				cout << "You lost. Game Over" << endl;
				return;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		if (shipsE[i].hitPoints <= 0)
		{
			counterE -= 1;
			if (counterE <= 0)
			{
				cout << "Great Job! You have defeated the enemy!" << endl;
				return;
			}
		}
	}
	cout << "You have " << counterA << " ships left." << " Emeny has " << counterE << " ships left." << endl;
	return;
}*/