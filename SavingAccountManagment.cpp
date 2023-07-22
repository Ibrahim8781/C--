
#include<iostream>
#include<cstring>

using namespace std;

class SavingAccount
{

private:
    char* name;
    float annualIntrestRate;
    double savingBalance;
    const char accountNum[4];
public:

    float calculateMonthlyInterest() const {
        return this->savingBalance * this->annualIntrestRate / 12;
    }

    void modifyInterestRate(float newValue) {
        this->annualIntrestRate = newValue;
    }

    const char* getAccountNum() const {
        return accountNum;
    }

    double getSavingBalance() const {
        return savingBalance;
    }

    void setSavingBalance(double balance) {
        savingBalance = balance;
    }


};

