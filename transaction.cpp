#include "transaction.h"

Transaction::Transaction()
{
    transactionID = 0;
    sender = 0;
    receiver = 0;
    amount = 0;
    status = "Pending";
}

void Transaction::setTransactionID(int id)
{
    transactionID = id;
}

void Transaction::setSender(int s)
{
    sender = s;
}

void Transaction::setReceiver(int r)
{
    receiver = r;
}

void Transaction::setAmount(double a)
{
    amount = a;
}

void Transaction::setStatus(string st)
{
    status = st;
}

int Transaction::getTransactionID()
{
    return transactionID;
}

int Transaction::getSender()
{
    return sender;
}

int Transaction::getReceiver()
{
    return receiver;
}

double Transaction::getAmount()
{
    return amount;
}

string Transaction::getStatus()
{
    return status;
}
