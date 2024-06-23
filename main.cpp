#include <iostream>
#include <string>
#include <limits>
#include "Account.h"
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

string bank_Name;
string bank_Address;
string bank_Hours;

static unsigned int bankAccNum = 10000;

void getBankInfo()
{
  cout << BOLDRED << endl;
  cout << "Enter the name of the bank: ";
  getline(cin, bank_Name);
  cout << "Enter the address of the bank: ";
  getline(cin, bank_Address);
  cout << "Enter the working hours of the bank: ";
  getline(cin, bank_Hours);
  cout << RESET << endl;
}

char bankMenu()
{
  char input;
  //DOUBLE CHECK 
  //STACKOVERFLOW 
  const string validOptions = "asohcmdbx";
 cout << endl << BOLDBLUE << endl;
  cout << "A --- Number of Bank-Accounts" << endl;
    cout << "S --- Number of Saving-Accounts" << endl;
    cout << "H --- Number of Checking-Accounts" << endl;
    cout << "O --- Open Bank-Account" << endl;
    cout << "C --- Close Bank Account" << endl;
    cout << "M --- Modify Bank-Account" << endl;
    cout << "D --- Detailed Bank-Accounts" << endl;
    cout << "B --- Brief Bank-Accounts Info Sorted Based on Aggregated Balances" << endl  << "X --- Exit" << endl;
  cout << "Please enter your selection: ";
  cin >> input;
  input = tolower(input);
  while (validOptions.find(input) == string::npos) {
          cin.clear(); 
          cout << "\nInvalid input, please enter a valid option: ";
          cin >> input;
          input = tolower(input); 
      }

      return input;
  }


int main()
{
  getBankInfo();

  char input = '0';
  bool invalid = false;
  int aggBal;
  int numCheck;
  int numSave;
  bool found;
  string closeAccNum, modAccNum;
  vector <bankAccount> accountVec;
  bankAccount tempBankAcc;

  do {
          if (invalid) {
              cout << endl << "Invalid input, please enter a valid input" << endl << endl;
              invalid = false;
          }

          input = bankMenu();
          cin.clear();

          if (input == 'A' || input == 'a') {
              cout << endl << "   | The number of Bank Accounts is " << accountVec.size() << endl << endl;
          } else if (input == 'S' || input == 's') {
              numSave = 0;
              for (int i = 0; i < accountVec.size(); ++i) {
                  numSave += accountVec[i].getSaveAccNum();
              }
              cout << endl << "   | The number of Saving-Accounts is " << numSave << endl << endl;
          } else if (input == 'H' || input == 'h') {
              numCheck = 0;
              for (int i = 0; i < accountVec.size(); ++i) {
                  numCheck += accountVec[i].getCheckAccNum();
              }
              cout << endl << "   | The number of Checking-Accounts is " << numCheck << endl << endl;
          } else if (input == 'O' || input == 'o') {
            tempBankAcc.createNewAcc(bankAccNum);
            bankAccNum += 1;
            accountVec.push_back(tempBankAcc);
            accountVec.back().bankAccMenu();
          } else if (input == 'C' || input == 'c') {
              found = false;
             cout << endl << "   Enter the bank account number to be closed: ";
             cin >> closeAccNum;
              for (int i = 0; i < accountVec.size(); ++i)
              {
                if (closeAccNum == accountVec[i].getAccNum())
                {
                  found = true;
                 accountVec[i].closeAllSubAcc();
                 accountVec.erase(accountVec.begin() + i);
               }
              }
              if (found)
              {
               cout << endl << "   | Bank Account " << closeAccNum << " successfully closed." << endl;
             }
             else
              {
                cout << endl << "   | Bank Account " << closeAccNum << " not found. Please try again. " << endl;
             }
            } else if (input == 'M' || input == 'm') {
               found = false;
             cout << endl << "   Enter the bank account number to be modified: ";
             cin >> modAccNum;
             for (int i = 0; i < accountVec.size(); ++i)
              {
              if (modAccNum == accountVec[i].getAccNum())
              {
                found = true;
                accountVec[i].bankAccMenu();
              }
            }
            if (!found)
            {
              cout << endl << "   | Bank Account " << closeAccNum << " not found. Please try again. " << endl;
            }
          } else if (input == 'D' || input == 'd') {
            cout << endl << "   | Bank Name: " << bank_Name << endl;
            cout << endl << "   | Bank Address: " << bank_Address << endl;
              cout << endl << "   | Bank Working Address: " << bank_Hours << endl;
              cout << endl << "   | Aggregated Balance: " << aggBal << endl;
              cout << endl << "   | Consists of " << accountVec.size() << " Bank Accounts"             << endl;
            for (int i = 0; i < accountVec.size(); ++i)
            {
              accountVec[i].printAccInfo();
            }
          } else if (input == 'B' || input == 'b') {
              aggBal = 0;
              for (int i = 0; i < accountVec.size(); ++i) {
                  aggBal += accountVec[i].getSubAccTotals();
              }
              cout << endl << "   | Bank Name: " << bank_Name
                   << endl << "   | Bank Address: " << bank_Address
                   << endl << "   | Bank Working Address: " << bank_Hours
                   << endl << "   | Aggregated Balance: " << aggBal
                   << endl << "   | Consists of " << accountVec.size() << " Bank Accounts"
                   << endl;
              for (int i = 0; i < accountVec.size(); ++i) {
                  cout << endl << "   | Agggregated Balance of the bank account "
                       << accountVec[i].getAccNum() << " with "
                       << accountVec[i].getSubAccNum() << " Sub-Accounts: "
                       << accountVec[i].getSubAccTotals();
              }
          } else if (input == 'X' || input == 'x') {
              cout << endl << "   | End of service for bank " << bank_Name;
          } else {
              invalid = true;
          }

      } while (!(input == 'x' || input == 'X'));

      return 0;
  }
 