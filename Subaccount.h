#pragma once
#include <string>
using namespace std;

    class subaccount {
        public:
            subaccount()
        {
         balance = 0;
          accNum = "NULL";
        }
     subaccount(string name, int bal) {
        balance = bal;
        accNum = name;
      }
       void setNum(string name) {
        accNum = name;
        }
        void setBal(int bal) {
         balance = bal;
        }
     string getNum() {
        return accNum;
     }
     int getBal() {
        return balance;
      }

protected:
    int balance;
    string accNum;
};
