#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>
#include "transaction.h"

using namespace std;

class account
{
private:
    int accountNumber;
    string customerName;
    double balance;

public:
    account(int accNo, string name, double initialBalance);

    void deposit(double amount);
    void withdraw(double amount);
    void checkBalance();

    int getAccountNumber();
    string getCustomerName();
    double getBalance();

    void transfer(account &receiver, double amount,
                  Transaction &transaction);
};

#endif // ACCOUNT_H
