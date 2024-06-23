#include <string>
#include <vector>
#include <iostream>
#include "Subaccount.h" 
#include "Checking.h"
#include "Savings.h"
#include "Customer.h"
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

static unsigned int saveAccNum = 1000;
static unsigned int checkAccNum = 6000;

class bankAccount : subaccount{
public:
  bankAccount()
  {
    accNum = "BNK-9999999999";
  }
  bankAccount(unsigned int num)
  {
    accNum = "BNK" + to_string(num);
  }
  string getAccNum()
  {
    return accNum;
  }
  int getSubAccNum()
  {
    int temp = 0;
    temp += checkSubAccVec.size();
    temp += saveSubAccVec.size();
    return temp;
  }
  void createNewAcc(unsigned int num) 
  {
    customer user;
    string temp1; 
    string temp2; 
    string temp3;
    cout << BOLDMAGENTA << endl;
    //FIX CIN OF THE FIRST NAME
    cout << "\n\n   Enter the first name of the account holder: ";
    cin >> temp1;

    cout << "\n   Enter the last name of the account holder: ";
    cin >> temp2;

    cout << "\n   Enter the SSN of the account holder: ";
    cin >> temp3;

    user = customer(temp3, temp1, temp2);
    accNum = "BNK" + to_string(num);
    cust = user;
    cout << "   | A new Bank Account " << accNum << " was successfully created.\n";
  }

  void printAccInfo()
  {
    int tempAggBal = 0;
    for (int i = 0; i < saveSubAccVec.size(); ++i) 
    {
      tempAggBal += saveSubAccVec[i].getBal();
    }
    for (int i = 0; i < checkSubAccVec.size(); ++i)
    {
      tempAggBal += checkSubAccVec[i].getBal();
    }
    cout << "\n\n   | Bank Account Number: " << accNum << "\n   | Account Holder Full Name: " << cust.getFirstName() << " " << cust.getLastName() << "\n   | Account Holder SSN: " << cust.getSocial() << "\n   | Aggregated Balance: " << tempAggBal << "\n   | Consists of " << saveSubAccVec.size() + checkSubAccVec.size() << " Sub-Accounts";
    for (int i = 0; i < saveSubAccVec.size(); ++i)
    {
      saveSubAccVec[i].printSaveAccInfo();
    }
    for (int i = 0; i < checkSubAccVec.size(); ++i)
    {
      checkSubAccVec[i].printCheckAccInfo();
    }
  }

  void bankAccMenu() 
  {
    char choice = '0';
        bool invalid = false;
        bool found;
        string closeAccNum, modAccNum; 
        do
        {
            if (invalid)
            {
                cout << "Invalid input, please enter a valid input\n\n";
                invalid = false;
            }
 cout << "\nEligible services for Bank-Account " << accNum << "\n     S -- Open Saving Sub-Account\n     C -- Open Checking Sub-Acccount\n     M -- Modify a Sub-Account\n     E -- Close a Sub-Account\n     D -- Detailed Bank Account Info Sorted Based on Balances of Sub-Accounts\n     B -- Brief Bank Account Info\n     X -- Exit\n Please enter your selection here: ";
            cin >> choice;

 if (cin.fail() || ((choice != 'S') && (choice != 's') && (choice != 'E') && (choice != 'e') && (choice != 'C') && (choice != 'c') && (choice != 'M') && (choice != 'm') && (choice != 'D') && (choice != 'd') && (choice != 'B') && (choice != 'b') && (choice != 'X') && (choice != 'x')))
            {
                cin.clear();
                cout << "Invalid input, please enter a valid input:\n";
                cin >> choice;
            
            }

            if (choice == 's' || choice == 'S')
            {
                if (saveSubAccVec.size() > 0)
                {
                    tempSaveAcc.createNewSaveAcc(saveAccNum, false); 
                }
                else
                {
                    tempSaveAcc.createNewSaveAcc(saveAccNum, true);
                }
                saveAccNum += 1;
                saveSubAccVec.push_back(tempSaveAcc);
                saveSubAccVec.back().saveAccMenu();
            }
            else if (choice == 'c' || choice == 'C')
            {
                tempCheckAcc.createNewCheckAcc(checkAccNum);
                checkAccNum += 1;
                checkSubAccVec.push_back(tempCheckAcc);
                checkSubAccVec.back().checkAccMenu();
            }
            else if (choice == 'm' || choice == 'M')
            {
                found = false;
                cout << "\n   Enter the sub-account number to be modified: ";
                cin >> modAccNum;
                for (int i = 0; i < checkSubAccVec.size(); ++i)
                {
                    if (modAccNum == checkSubAccVec[i].getNum())
                    {
                        found = true;
                        checkSubAccVec[i].checkAccMenu();
                    }
                }
                for (int i = 0; i < saveSubAccVec.size(); ++i) 
                {
                    if (modAccNum == saveSubAccVec[i].getNum())
                    {
                        found = true;
                        saveSubAccVec[i].saveAccMenu();
                    }
                }
                if (!found)
                {
                    cout << "\n   | Sub-Account " << closeAccNum << " not found. Please try again. \n";
                }
            }
            else if (choice == 'e' || choice == 'E')
            {
                found = false;
                cout << "\n   Enter the sub-account number to be deleted: ";
                cin >> closeAccNum;
                for (int i = 0; i < checkSubAccVec.size(); ++i)
                {
                    if (closeAccNum == checkSubAccVec[i].getNum())
                    {
                        found = true;
                        checkSubAccVec.erase(checkSubAccVec.begin() + i); 
                    }
                }
                for (int i = 0; i < saveSubAccVec.size(); ++i)
                {
                    if (closeAccNum == saveSubAccVec[i].getNum())
                    {
                        found = true;
                        saveSubAccVec.erase(saveSubAccVec.begin() + i);
                    }
                }
                if (!found)
                {
                    cout << "\n   | Sub-Account " << closeAccNum << " not found. Please try again. \n";
                }
                else
                {
                    cout << "\n   | Sub-Account " << closeAccNum << " successfully closed.\n";
                }
            }
            else if (choice == 'd' || choice == 'D')
            {
                for (int i = 0; i < saveSubAccVec.size(); ++i)
                {
                    saveSubAccVec[i].printSaveAccInfo();
                }
                for (int i = 0; i < checkSubAccVec.size(); ++i) 
                {
                    checkSubAccVec[i].printCheckAccInfo();
                }
            }
            else if (choice == 'b' || choice == 'B')
            {
                tempAggBal = 0;
                for (int i = 0; i < saveSubAccVec.size(); ++i) 
                {
                    tempAggBal += saveSubAccVec[i].getBal();
                }
                for (int i = 0; i < checkSubAccVec.size(); ++i)
                {
                    tempAggBal += checkSubAccVec[i].getBal();
                }
                cout << "\n   | Aggregated balance of the bank account: " << accNum << " with " << saveSubAccVec.size() + checkSubAccVec.size() << " Sub-Accounts is " << tempAggBal << "\n\n";
            }
            else if (choice == 'x' || choice == 'X')
            {
                cout << "\n   | End of service for bank account" << accNum << "\n"; 
            }
        } while (!(choice == 'x' || choice == 'X'));
    }

  int getSubAccTotals()
  {
    int temp = 0;
    for (int i = 0; i < checkSubAccVec.size(); ++i)
    {
      temp += checkSubAccVec[i].getBal();
    }
    for (int i = 0; i < saveSubAccVec.size(); ++i) 
    {
      temp += saveSubAccVec[i].getBal();
    }
    return temp;
  }

  int getSaveAccNum()
  {
    return saveSubAccVec.size();
  }

  int getCheckAccNum()
  {
    return checkSubAccVec.size();
  }

  void closeAllSubAcc()
  {
    checkSubAccVec.clear();
    saveSubAccVec.clear();
  }

private:
  string accNum;
  checking tempCheckAcc;
  savings tempSaveAcc;
  vector <checking> checkSubAccVec;
  vector <savings> saveSubAccVec;
  customer cust;
  int tempAggBal;
};
