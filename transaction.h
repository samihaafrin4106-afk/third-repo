#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

using namespace std;

class Transaction
{
private:
    int transactionID;
    int sender;
    int receiver;
    double amount;
    string status;

public:
    Transaction();

    void setTransactionID(int id);
    void setSender(int s);
    void setReceiver(int r);
    void setAmount(double a);
    void setStatus(string st);

    int getTransactionID();
    int getSender();
    int getReceiver();
    double getAmount();
    string getStatus();
};

#endif // TRANSACTION_H
