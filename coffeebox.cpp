#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

#define ESPRESSO_PRICE 1.8
#define CAPUCCINO_PRICE 2.3
#define LATTE_PRICE 1.8
#define ESPRESSO_MENU_NUMBER 2
#define CAPUCCINO_MENU_NUMBER 3
#define LATTE_MENU_NUMBER 4
#define PROGRESS_BAR_WIDTH 20
#define PROGRESS_BAR_STEP 0.10
#define PROGRESS_BAR_MAX_VALUE 100.0

void printBalance(double balance);
void printUserMenu();
void printCoinMenu();
void runCoffeeBox(int addCups, int emptyCups, double balance);
double addCoin();
bool orderCoffee(double price, int menuNumber, int emptyCups, double balance);
void runProgressBar();
void clearConsole();
void sleep(int milliseconds);

int main()
{
	int addCups = 0;
	int emptyCups = 7;
  double balance = 0.00;

	runCoffeeBox(addCups, emptyCups, balance);

  return 0;
}

void printBalance(double balance)
{
	cout << " -------------------------------------- " << endl;
	cout << "|      Coffeebox :: Balance            |" << endl;
	cout << " -------------------------------------- " << endl;
	cout << "|\t     "<< fixed << setprecision(2) << balance << "  BYN                 |" << endl;
	cout << " -------------------------------------- " << endl;
}

void printUserMenu()
{
	cout << " -------------------------------------- " << endl;
	cout << "| 1 - Add coin                         |" << endl;
	cout << "| 2 - Order Espresso (1.80)            |" << endl;
	cout << "| 3 - Order Capuccino (2.30)           |" << endl;
	cout << "| 4 - Order Latte (1.8)                |" << endl;
	cout << "| 5 - Service menu                     |" << endl;
	cout << "| 6 - Log out                          |" << endl;
	cout << " -------------------------------------- " << endl;
}

void printCoinMenu()
{
	cout << " -------------------------------------- " << endl;
	cout << "|      Available :: Denomination       |" << endl;
	cout << " -------------------------------------- " << endl;
	cout << "|       1 - 1BYN   2 - 2BYN            |" << endl;
	cout << "|      50 - 0.5BYN    20 - 0.2BYN      |" << endl;
	cout << "|             10 - 0.1BYN              |" << endl;
	cout << " -------------------------------------- " << endl;
}

void runCoffeeBox(int addCups, int emptyCups, double balance)
{
	double proceeds = 0.00;
	int menuItemNumber = 0;
	bool flag = true;
	bool isCoffeeDone = false;

	while(flag)
	{
		printBalance(balance);
		printUserMenu();
		
		cout << " Please, select menu item: ";
	 	cin >> menuItemNumber;
		
		switch (menuItemNumber){
			case 1:
				proceeds += addCoin();
				balance = proceeds;
				sleep(1000);
				clearConsole();
				break;
			case 2:
				isCoffeeDone = orderCoffee(ESPRESSO_PRICE, ESPRESSO_MENU_NUMBER, emptyCups, balance);
				if (isCoffeeDone)
				{
				balance -= ESPRESSO_PRICE;
				emptyCups--;
				sleep(2000);
				clearConsole();
				}
				else{
					clearConsole();
				}
				break;
			case 3:
				isCoffeeDone = orderCoffee(CAPUCCINO_PRICE, CAPUCCINO_MENU_NUMBER, emptyCups, balance);
				if (isCoffeeDone)
				{
					balance -= CAPUCCINO_PRICE;
					emptyCups--;
					sleep(2000);
					clearConsole();
				}
				else{
					clearConsole();
				}
				break;
			case 4:
				isCoffeeDone = orderCoffee(LATTE_PRICE, LATTE_MENU_NUMBER, emptyCups, balance);
				if (isCoffeeDone){
					balance -= LATTE_PRICE;
					emptyCups--;
				  sleep(2000);
				  clearConsole();
				}else {
					clearConsole();
				}
				break;
			case 5:
				clearConsole();
				flag = false;
				break;
			case 6:{
				flag = false;
				cout << "Attention! Shutdown in progress.\n";
				sleep(500);
				runProgressBar();
				clearConsole();
				cout.flush();
				cout << "Coffee box not working." << endl;
				break;
			}
			default:
				cout << "Error! Wrong menu number. Please type number again [1..6]!";
				sleep(2000);
				clearConsole();
				break;
		}
	}	
}

double addCoin()
{
	double coin = 0;

	printCoinMenu();

	cout << "Deposite coin: ";
	cin >> coin;

	if (coin == 10 || coin == 20 || coin == 50){
		return coin / 100;
	}
	else if (coin == 1 || coin == 2){
		return coin;
	}
	else{
		cout << "Error! Invalid coin denomination! Please deposite coins according to the menu";
		sleep(2000);
		return 0;
	}
}

bool orderCoffee(double price, int menuNumber, int emptyCups, double balance)
{
	if(emptyCups < 1){
		cout << "Error! Sorry, not enough cups in the CoffeeBox";
		sleep(2000);
		clearConsole();
		printBalance(balance);
		printUserMenu();
		return false;
	}
	else if (balance < price){
		cout << "You have't deposited enough coins. Please add more coins!";
		sleep(2000);
		clearConsole();
		printBalance(balance);
		printUserMenu();
		return false;
	}
	else{
		switch (menuNumber){
		case 2:
			runProgressBar();
			cout << "Your Espresso is done." << endl;
			break;
		case 3:
			runProgressBar();
			cout << "Your Capuccino is done." << endl;
			break;
		case 4:
			runProgressBar();
			cout << "Your Latte is done." << endl;
			break;
		default:
			cout << "Error! You input wrong menu number. Please try again!";
			break;
		}
		cout << "Have a nice day!" << endl;
		return true;
	}

}

void runProgressBar()
{
	double progress = 0.0;
	
    while (progress <= 1.0) {
      int pos = PROGRESS_BAR_WIDTH * progress;

			for (int i = 0; i < PROGRESS_BAR_WIDTH; ++i) {
					if (i < pos)
						cout << ".";	
					else
			cout << " ";
			}
    	sleep(50);
			cout << progress * PROGRESS_BAR_MAX_VALUE << " %\r";
			cout.flush();
			progress += PROGRESS_BAR_STEP;
    }
    cout << endl;
}

void clearConsole()
{
	cout.flush();
	system("cls");
}

void sleep(int milliseconds)
{
	this_thread::sleep_for(chrono::milliseconds(milliseconds));
}