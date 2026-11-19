#include "savingsaccount.h"

SavingsAccount::SavingsAccount(int accNo, string name, double initialBalance)
    :public account(accNo, name, initialBalance)
{
}
