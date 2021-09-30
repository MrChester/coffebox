#include <iostream>
#include <iomanip>

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

int main()
{
  double balance = 5.00;

  printBalance(balance);

  cout << "ok";
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