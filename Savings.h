#include <iostream>
#include <string>
#include "Subaccount.h"
#define RESET   "\033[0m"
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
using namespace std;

class savings : public subaccount
{
public:
  savings()
  {
    balance = -777;
    accNum = "NULL"; 
    first = false;
  }
  savings(string name, int bal, bool isFirst)
  {
    balance = bal;
    accNum = name; 
    first = isFirst;
  }
  void printSaveAccInfo()
  { 
    cout << BOLDWHITE << endl;
    cout << "\n\n   | Sub-account number: " << accNum << "\n   | Balance: " << balance << "\n"; 
  }
  void createNewSaveAcc(unsigned int num, bool isFirst)
  {
    int temp1;

    cout << "\n   Enter the initial balance: ";
    cin >> temp1;
    if (isFirst)
    {
      balance = temp1 + 100;
    }
    else
    {
      balance = temp1;
    }
    // FIX ERROR HERE MAKE SAV ADD TO STRING
    accNum = "SAV" + to_string(num);
    cout << "   | A new Savings Sub Account " << accNum << " was successfully created.\n\n";
  }
  void saveAccMenu() {
    char choice = '0';
    bool invalid = false;
    int input;
    const string validOptions = "DWdwXx";

    do
    {
        if (invalid)
        {
            cout << "Invalid input, please enter a valid input\n\n";
            invalid = false;
        }
        cin.clear();
        cout << "Eligible services for sub-account " << accNum << "\n     D -- Deposit\n     W -- Withdraw\n     X -- Exit \nPlease enter your selection: ";
        cin >> choice;

        if (validOptions.find(choice) == string::npos)
        {
            cin.clear();
            invalid = true;
            continue;
        }

        if (choice == 'D' || choice == 'd')
        {
            cout << "\n   Enter the amount to deposit: ";
            cin >> input;
            balance += input;
            cout << "   | Deposit was successful.\n   | Current balance is " << balance << "\n\n";
        }
        else if (choice == 'W' || choice == 'w')
        {
            cout << "\n   Enter the amount to withdraw: ";
            cin >> input;
            if (input <= balance)
            {
                balance -= input;
                cout << "   | Withdraw was successful.\n   | Current balance is " << balance << "\n\n";
            }
            else
            {
                cout << "   | Withdraw failed.\n   | Current balance is " << balance << "\n\n";
            }
        }
        else if (choice == 'X' || choice == 'x')
        {
            cout << "\n   | End of service for sub-account " << accNum << "\n";
        }
    } while (!(choice == 'X' || choice == 'x'));
}
    
private:
  bool first;
};