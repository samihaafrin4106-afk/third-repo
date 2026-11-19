#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "account.h"

class SavingsAccount : public account
{
public:
    SavingsAccount(int accNo, string name, double initialBalance);
};

#endif // SAVINGSACCOUNT_H
