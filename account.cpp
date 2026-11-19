#include "account.h"

using namespace std;

// Constructor
account::account(int accNo, string name, double initialBalance)
{
    accountNumber = accNo;
    customerName = name;
    balance = initialBalance;
}

// Deposit
void account::deposit(double amount)
{
    if(amount > 0)
    {
        balance = balance + amount;
        cout << "Deposit successful." << endl;
    }
    else
    {
        cout << "Invalid amount." << endl;
    }
}

// Withdraw
void account::withdraw(double amount)
{
    if(amount <= 0)
    {
        cout << "Invalid amount." << endl;
    }
    else if(amount > balance)
    {
        cout << "Insufficient balance." << endl;
    }
    else
    {
        balance = balance - amount;
        cout << "Withdrawal successful." << endl;
    }
}

// Check balance
void account::checkBalance()
{
    cout << "Account Number: " << accountNumber << endl;
    cout << "Customer Name: " << customerName << endl;
    cout << "Current Balance: " << balance << endl;
}

// Get account number
int account::getAccountNumber()
{
    return accountNumber;
}

// Get customer name
string account::getCustomerName()
{
    return customerName;
}

// Get balance
double account::getBalance()
{
    return balance;
}

// Transfer money
void account::transfer(account &receiver,
                       double amount,
                       Transaction &transaction)
{
    if(amount <= 0)
    {
        cout << "Invalid amount." << endl;
        transaction.setStatus("Failed");
    }
    else if(amount > balance)
    {
        cout << "Insufficient balance." << endl;
        transaction.setStatus("Failed");
    }
    else
    {
        balance = balance - amount;
        receiver.balance = receiver.balance + amount;

        transaction.setStatus("Successful");

        cout << "Transfer successful." << endl;
    }
}
