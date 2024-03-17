#include "transaction.h"


int Transaction::getTransactionId()
{
    return transactionId;
}

double Transaction::getTransactionAmount()
{
    return transactionAmount;
}

double Transaction::getNetBalance()
{
    return netBalance;
}

std::string Transaction::getTransactionType()
{
    return transactionType;
}

void Transaction::setTransactionId(int transactionId)
{
    this->transactionId = transactionId;
}

void Transaction::setTransactionAmount(double transactionAmount)
{
    this->transactionAmount = transactionAmount;
}

void Transaction::setNetBalance(double netBalance)
{
    this->netBalance = netBalance;
}

void Transaction::setTransactionType(std::string transactionType)
{
    this->transactionType = transactionType;
}