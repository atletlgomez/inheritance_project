#include "bankAccount.h"
#include <iostream>

void bankAccount::setAccountNumber(int accountNumber) {
    this->accountNumber = accountNumber;
}
int bankAccount::getAccountNumber() const {
    return this->accountNumber;
}
double bankAccount::getAccountBalance() const {
    return this->balance;
}
void bankAccount::deposit(double amount) {
    balance += amount; // balance = balance + amount
}
void bankAccount::withdraw(double amount) {
    balance -= amount;
}
void bankAccount::print() const {
    std::cout << "Account Number: " << this->accountNumber << std::endl;
    std::cout << "Balance (USD): " << this->balance << std::endl;
}
bankAccount::bankAccount() = default;

bankAccount::bankAccount(int accountNumber, double balance) :
                         accountNumber(accountNumber), balance(balance) {}
