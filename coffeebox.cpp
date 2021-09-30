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
void runProgressBar();

int main()
{
  double balance = 0.00;

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

void sleep(int milliseconds)
{
	this_thread::sleep_for(chrono::milliseconds(milliseconds));
}