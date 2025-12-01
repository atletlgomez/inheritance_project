#include "checkingAccount.h"

#include <iomanip>
#include <iostream>

void checkingAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}
double checkingAccount::getInterestRate() const {
    return interestRate;
}
void checkingAccount::setMinBalance(double minBalance) {
    this->minBalance = minBalance;
}
double checkingAccount::getMinBalance() const {
    return minBalance;
}
void checkingAccount::setServiceCharges(double serviceCharges) {
    this->serviceCharges = serviceCharges;
}
double checkingAccount::getServiceCharges() const {
    return serviceCharges;
}
void checkingAccount::postInterest() const {
    std::cout << "Your daily interest is: " << std::fixed << std::setprecision(2)
                << "USD " << getAccountBalance() * (interestRate / 100.0 / 365.0) << std::endl;
}
bool checkingAccount::verifyBalance() const {
    if (getAccountBalance() >= minBalance) {
        std::cout << "Your balance is: " << getAccountBalance() << std::endl;
        return true;
    } else {
        std::cout << "Your balance is: " << getAccountBalance() << std::endl;
        return false;
    }
}
void checkingAccount::deposit(double amount) {
    bankAccount::deposit(amount);
}
void checkingAccount::withdraw(double amount) {
    double fee;
    if (amount > bankAccount::getAccountBalance()) {
        std::cout << "Not enough balance to withdraw: " << amount << std::endl;
        std::cout << "Your current balance is: " << bankAccount::getAccountBalance() << std::endl;
    } else if (amount > 500) {
        fee = amount * (serviceCharges/100.0);
        amount = amount + fee;
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << bankAccount::getAccountBalance();
    } else if (amount <= 500) {
        bankAccount::withdraw(amount);
        std::cout << "Your new balance is " << bankAccount::getAccountBalance();
    }

}
void checkingAccount::print() const {
    bankAccount::print();
    std::cout << "Interest Rate %: " << getInterestRate() << std::endl;
    std::cout << "Min Balance $: " << getMinBalance() << std::endl;
    std::cout << "Service Charges %: " << getServiceCharges() << std::endl;
}
checkingAccount::checkingAccount() = default;
checkingAccount::checkingAccount(int accountNumber, double balance,
                                double interestRate, double minBalance, double serviceCharges) :
                                bankAccount(accountNumber, balance), interestRate(interestRate),
                                minBalance(minBalance), serviceCharges(serviceCharges) {}

