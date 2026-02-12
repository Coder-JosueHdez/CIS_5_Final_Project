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
void checkCounters(Ship shipsA[], Ship shipsE[], int countA, int countE);

int main()
{
	int countA = 3;
	int countE = 3;
	Ship shipsA[3] = { { 20, "Main Commander", "Ally" }, { 10, "Gun Ship", "Ally" }, { 15, "Tanker", "Ally" } };
	Ship shipsE[3] = { { 20, "Main Commander", "Enemy" }, { 10, "Gun Ship", "Ememy" }, { 15, "Tanker", "Ememy" } };

	string name;
	char yon;
	cout << "Name? ";
	cin >> name;
	cout << "Hello, " << name << "! Welcome aboard!" << endl;
	cout << "You're incharge of 3 ships which are in a fight with 3 enemy ships.";//quick lore drop
	do {
		cout << "You will take turns to make actions and who ever destroies the other's ships first, Wins!" << endl;//how game works
		cout << "Understood? Y / N ";
		cin >> yon;
		if (yon != 'Y' || yon != 'N')
		{
			cout << "Invalid input. Y / N" << endl;
		}
	} while (yon != 'Y' || yon != 'N');

	do {
		printShips(shipsA, shipsE, countA, countE);
		yourTurn(shipsA, shipsE);
		emenyTurn(shipsA, shipsE);
		checkCounters(shipsA, shipsE, countA, countE);
	} while (countE != 0 || countA != 0);
	if (countE == 0)
	{
		cout << "Great Job! You have defeated the enemy!" << endl;
	}
	else if (countA == 0)
	{
		cout << "You lost. Game Over" << endl;
	}

	return 0;
}

void printShips(Ship shipsA[], Ship shipsE[], int countA, int countE)//Prints ally and enemy ships
{
	cout << "Your ships: " << endl;
	for (int i = 0; i < countA; i++)
	{
		cout << i+1 << ". " << shipsA[i].team << " ship, " << shipsA[i].shipName << " has " << shipsA[i].hitPoints << " hit points." << endl;
	}

	cout << "Enemy ships: " << endl;
	for (int i = 0; i < countE; i++)
	{
		cout << i+1 << ". " << shipsE[i].team << " ship, " << shipsE[i].shipName << " has " << shipsE[i].hitPoints << " hit points." << endl;
	}
}

void yourTurn(Ship shipsA[], Ship shipsE[])//Attack or Repair
{
	int chooseShipA = 0;
	cout << "Which ship do you want to use? 0, 1, or 2." << endl;
	do {
		cin >> chooseShipA;
		cin.ignore();
		switch (chooseShipA) {
		case 0 :
			cout << shipsA[0].shipName << " was selected!" << endl;
			break;
		case 1:
			cout << shipsA[1].shipName << " was selected!" << endl;
			break;
		case 2:
			cout << shipsA[2].shipName << " was selected!" << endl;
			break;
		default :
			cout << "Invalid input. 0, 1, or 2" << endl;
		}
	} while (chooseShipA != 1 || chooseShipA != 2 || chooseShipA != 0);
	
	char action;
	int chooseShipE = 0;
	cout << "What would you like to do: Attack(a) or Repair(r)" << endl;
	do {
		cin >> action;
		cin.ignore();
		switch (action) {
		case 'a':
			cout << "Attack was selected!" << endl;

			cout << "Which ship do you want to Attack? 0, 1, or 2." << endl;
			do {
				cin >> chooseShipE;
				cin.ignore();
				switch (chooseShipE) {
				case 0:
					cout << shipsE[0].shipName << " was selected!" << endl;
					break;
				case 1:
					cout << shipsE[1].shipName << " was selected!" << endl;
					break;
				case 2:
					cout << shipsE[2].shipName << " was selected!" << endl;
					break;
				default:
					cout << "Invalid input. 0, 1, or 2" << endl;
				}
			} while (chooseShipA != 1 || chooseShipA != 2 || chooseShipA != 0);

			attackShipA(shipsA, shipsE, chooseShipA, chooseShipE);
			break;
		case 'r':
			cout << "Repair was selected!" << endl;
			repairShip(shipsA, chooseShipA);
			break;
		default:
			cout << "Invalid input. Attack(a) or Repair(r)" << endl;
		}
	} while (action != 'a' || action != 'r');
}
//Enemy Moves
void emenyTurn(Ship shipsA[], Ship shipsE[])//Enemy only attacks
{
	srand(time(nullptr));
	int randomPickA = rand() % 2;//random Enemy attacks
	int randomPickE = rand() % 2;//random Ally
	cout << shipsA[randomPickA].shipName << " is being attacked by " << shipsE[randomPickE].shipName << endl;
	attackShipE(shipsA, shipsE, randomPickA, randomPickE);
}
void attackShipE(Ship shipsA[], Ship shipsE[], int shipA, int shipE)//random damage, say how much damage was caused to which ship.
{
	srand(time(nullptr));
	int damage = rand() % 15 + 1;//can change so it may miss
	shipsA[shipA].hitPoints -= damage;
	cout << shipsE[shipE].shipName << " did " << damage << " damage to " << shipsA[shipA].shipName << endl;
	cout << shipsA[shipA].shipName << " now has " << shipsA[shipA].hitPoints << "!" << endl;
}
//Ally Moves
void attackShipA(Ship shipsA[], Ship shipsE[], int chooseShipA, int chooseShipE)//pick which ship attacks, say how much damage it causes to which ship.
{
	srand(time(nullptr));
	int damage = rand() % 15 + 1;//can change so it may miss
	shipsE[chooseShipE].hitPoints -= damage;
	cout << shipsA[chooseShipA].shipName << " did " << damage << " damage." << endl;
}
void repairShip(Ship shipsA[], int shipA)//pick which ship to ship to repair, say how much is was repaired.
{
	srand(time(nullptr));
	int repair = rand() % 10 + 1;
	shipsA[shipA].hitPoints += repair;
	cout << shipsA[shipA].shipName << " was repaired with " << repair << "hit points." << endl;
	cout << shipsA[shipA].shipName << " now has " << shipsA[shipA].hitPoints << "!" << endl;
}
void checkCounters(Ship shipsA[], Ship shipsE[], int countA, int countE)
{
	for (int i = 0; i < countA; i++)
	{
		if (shipsA[i].hitPoints = 0)
		{
			countA -= 1;
		}
	}
	for (int i = 0; i < countE; i++)
	{
		if (shipsE[i].hitPoints = 0)
		{
			countE -= 1;
		}
	}
}