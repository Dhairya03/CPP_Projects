#include "transaction.h"

Transaction::Transaction(int accNum, int transId, double transAmount, double netBal, std::string transType)
{
    accountNumber = accNum;
    transactionId = transId;
    transactionAmount = transAmount;
    netBalance = netBal;
    transactionType = transType;
}