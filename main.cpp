# include <iostream>
# include <iomanip>
# include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;

struct Ship {
	int hitPoints;
	string shipName;
	string team;

	Ship(int h, const string s, const string t)
		: hitPoints(h), shipName(s), team(t) {
	}
};

int main()
{
	int countA = 3;
	int countE = 3;
	Ship shipsA[3] = { { 20, "Main Commander", "Ally" }, { 10, "Gun Ship", "Ally" }, { 15, "Tanker", "Ally" } };
	Ship shipsE[3] = { { 20, "Main Commander", "Enemy" }, { 10, "Gun Ship", "Ememy" }, { 15, "Tanker", "Ememy" } };

	string name;
	string choice;
	string chooseShip;
	string action;
	string yon;
	cout << "Name? ";
	cin >> name;
	cout << "Hello, " << name << "! Welcome aboard!" << endl;
	cout << "You are incharge of 3 ships which are in a fight with 3 enemy ships.";//quick lore drop
	cout << "You will take turns to make actions and who ever destroies the other's ships first, Wins!" << endl;//how game works
	cout << "Understood? Y/N";
	cin >> yon;

/*	if (yon = 'N')
	{
		cout << "You will take turns to make actions. Who's ever destroies the other's ships first, Wins!" << endl;//how game works
		cout << "Understood? Y/N" << endl;
		cin >> yon;
	}
	else if (yon = 'Y')
	{
		cout << "Great then, let's begin!" << endl;
	}
	else
	{
		cout << "Invalid input" << endl;
	}*/


	printShips(shipsA, shipsE, countA, countE);
	cout << "Which ship do you want to use?" << endl;
	cin >> chooseShip;
	cout << "What would you like to do: Attack(a) or Repaire(r)" << endl;
	cin >> action;

	turn(ships, action);

	return 0;
}

void printShips(Ship shipsA[], Ship shipsE[], int countA, int countE)
{
	cout << "Your ships: " << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << shipsA[i].team << " ship, " << shipsA[i].shipName << " has " << shipsA[i].hitPoints << " hit points." << endl;
	}

	cout << "Enemy ships: " << endl;

	for (int i = 0; i < countE; i++)
	{
		cout << shipsE[i].team << " ship, " << shipsE[i].shipName << " has " << shipsE[i].hitPoints << " hit points." << endl;
	}
}
void turn(Ship ships[], string action)//Attack or Repair
{


}

void attackShip(Ship shipsA[])//pick which ship attacks, say how much damage it causes to which ship.
{
	srand(time(nullptr));
	int damage = rand() % 15;
	string attckingShip;
	cout << shipsA[].shipName << " did " << damage << "damage!" << endl;
}

void repairShip(Ship shipsA[])//pick which ship to ship to repair, say how much is was repaired.
{
	srand(time(nullptr));
	int repair = rand() % 20 + 1;

	cout << shipsA[].shipName << " was repaired with " << repair << "hit points." << endl;

}