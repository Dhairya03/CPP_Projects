#include "account.h"
#include "string.h"

int Account::getAccountNumber()
{
    return accountNumber;
}

std::string Account::getHolderName()
{
    return holderName;
}

long Account::getHolderContact()
{
    return holderContact;
}

std::string Account::getHolderAddress()
{
    return holderAddress;
}

double Account::getTotalBalance()
{
    return totalBalance;
}

void Account::setAccountNumber(int accountNumber)
{
    this->accountNumber = accountNumber;
}

void Account::setHolderName(const std::string &holderName)
{
    this->holderName=holderName;
}

void Account::setHolderContact(long holderContact)
{
    this->holderContact = holderContact;
}

void Account::setHolderAddress(const std::string &holderAddress)
{
    this->holderAddress = holderAddress;
}

void Account::setTotalBalance(double totalBalance)
{
    this->totalBalance += totalBalance;
}