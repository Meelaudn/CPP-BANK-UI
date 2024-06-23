#include <string>
#include <iostream>
using namespace std;

class customer
{
public:
    customer()
    {
        sSN = "000-00-0000";
        firstName = "John";
        lastName = "Doe";
    }
    customer(string ssn, string name1st, string name2nd)
    {
        sSN = ssn;
        firstName = name1st;
        lastName = name2nd;
    }

    void setFirstName(string name) { firstName = name; }
    void setLastName(string name) { lastName = name; }
    void setSocial(string ssn) { sSN = ssn; }
    string getFirstName() { return firstName; }
    string getLastName() { return lastName; }
    string getSocial() { return sSN; }

private:
    string sSN;
    string firstName;
    string lastName;
};