#include "Subaccount.h"
#include <iostream>
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

class checking : public subaccount 
{
public:
  checking()
  {
    balance = 0;
    accNum = "NULL";
    locked = false;
    maxCap = 0;
  }
  checking(string name, int bal, bool isLocked, int max)
  {
    balance = bal;
    accNum = name;
    locked = isLocked; 
    maxCap = max;
  }
  void printCheckAccInfo()
  { cout << BOLDYELLOW << endl;
    cout << "\n\n   | Sub-account number: " << accNum << "\n   | Balance: " << balance << "\n   | The maximum capacity is: " << maxCap;
    if (locked)
    {
      cout << "\n   | The sub-account is locked.\n"; 
    }
    else
    {
      cout << "\n   | The sub-account is not locked.\n";
    }
  }
  void createNewCheckAcc(unsigned int num) 
  {
    int temp1;
    int temp2;
    char temp3;

    cout << "\n  Enter the initial balance: ";
    cin >> temp1;

    cout << "\n  Enter the desired maximum capacity: ";
    cin >> temp2;

    cout << "\n  Define initial state (L - Locked, Otherwise - Unlocked): ";
    cin >> temp3;

    balance = temp1;
    accNum = "CHK" + to_string(num);
    maxCap = temp2;
    if (temp3 == 'l' || temp3 == 'L')
    {
      locked = true;
    }
    else
    {
      locked = false;
    }
    cout << "   | A new Checking Sub Account " << accNum << " was successfully created.\n\n";
  }
  void checkAccMenu() 
  {
char choice = '0';
    bool invalid = false;
    int input;
    do
    {
        if (invalid)
        {
            cout << "Invalid input, please enter a valid input\n\n";
            invalid = false;
        }
        cin.clear();
        cout << "Eligible services for sub-account " << accNum 
            << "\n     D -- Deposit\n     W -- Withdraw\n     C -- Max Capacity\n     L -- Lock Sub-Account\n     U -- Unlock Sub-Account\n     X -- Exit\nPlease enter your selection: ";
        cin >> choice; 
        choice = tolower(choice); // DOUBLE CHECK

        const string validOptions = "dwclux";

        if (cin.fail() || validOptions.find(choice) == string::npos)
        {
            cin.clear();
            cout << "Invalid input, please enter a valid input:\n";
            cin >> choice;
            choice = tolower(choice); //DOUBLE CHECK
            invalid = true;
            continue;
        }

      //REPLACE ALL SWITCH CASES WITH IF-ELSE STATEMENTS

        if (choice == 'd' || choice == 'D')
        {
            cout << "\n   Enter the amount to deposit: ";
            cin >> input;
            if (!locked && ((balance + input) <= maxCap))
            {
                balance += input;
      cout << "   | Deposit was successful.\n   | Current balance is " << balance << "\n\n";
            }
            else
            {
                cout << "   | Deposit failed.\n   | Current balance is " << balance << "\n\n";
            }
        }
        else if (choice == 'w' || choice == 'W')
        {
            cout << "\n   Enter the amount to withdraw: ";
            cin >> input;
            if (!locked && (input <= balance)) {
               
                balance -= input;
            cout << "  | Withdraw was successful.\n  | Current balance is " << balance << endl;
            }
            else
            {
                cout << "  | Withdraw failed.\n  | Current balance is " << balance << endl;
            }
        }
        else if (choice == 'c' || choice == 'C')
        {
            cout << "\n  Enter the new maximum capacity: ";
            cin >> input;
            if (input >= balance)
            {
                maxCap = input;
                cout << "   | Max capacity successfully changed.\n\n";
            }
            else
            {
                cout << "   | Max capacity failed to be changed.\n\n";
            }
        }
        else if (choice == 'l' || choice == 'L')
        {
            locked = true;
            cout << "   | Account Successfully Locked.\n\n";
        }
        else if (choice == 'u' || choice == 'U')
        {
            locked = false;
            cout << "   | Account Successfully Unlocked.\n\n";
        }
        else if (choice == 'x' || choice == 'X')
        {
            cout << "\n  | End Of Service For Sub-Account " << accNum << "\n";
        }
        else
        {
            invalid = true;
        }
    } while (!(choice == 'x'));
}

  private:
    bool locked; 
    int maxCap;
  };
