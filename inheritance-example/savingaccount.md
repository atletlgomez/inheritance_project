The main.cpp with a option to choose between saving and chcking account

```c++
#include <iostream>
#include "checkingAccount.h"
#include "savingsAccount.h"

int main() {

    /*Added this to change what kind of account they would like */

    int accountType;
    std::cout << "Account Type?:\n" << std::endl;
    std::cout << "Enter 1 for Checking Account\n" << std::endl;
    std::cout << "Enter 2 for Savings Account\n" << std::endl;
    std::cin >> accountType;


    /* this is the orignal option of a checking account */
    if (accountType == 1) {
    int accountNumber, input;
    double amount, interestRate, minBalance, serviceCharges;
    std::cout << "Enter account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter balance (in USD): ";
    std::cin >> amount;
    std::cout << "Enter interest rate (%): ";
    std::cin >> interestRate;
    std::cout << "Enter min balance (in USD): ";
    std::cin >> minBalance;
    std::cout << "Enter service charges (%): ";
    std::cin >> serviceCharges;
    checkingAccount account(accountNumber, amount, interestRate, minBalance, serviceCharges);
    do {
        std::cout << std::endl;
        std::cout << "Which service do you want to use?" << std::endl;
        std::cout << "1<--Deposit: " << std::endl;
        std::cout << "2<--Withdraw: " << std::endl;
        std::cout << "3<--Print balance: " << std::endl;
        std::cout << "4<--Print account details: " << std::endl;
        std::cout << "5<--Print daily interest" << std::endl;
        std::cout << "0<--Exit" << std::endl;
        std::cin >> input;
        switch (input) {
            case 0:
                std::cout << "Thank you. Good bye" << std::endl;
                break;
            case 1:
                std::cout << "Deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Service charge of " << account.getServiceCharges() <<
                "% applies if the withdrawal amount is more than $500 from the checking account" << std::endl;
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                if (account.verifyBalance()) {
                    std::cout << "Your account balance is positive" << std::endl;
                } else {
                    std::cout << "Your account balance is lower than the min balance" << std::endl;
                }
                break;
            case 4:
                account.print();
                break;
            case 5:
                account.postInterest();
                break;
            default:
                std::cout << "Invalid input." << std::endl;
        }
    } while (input != 0);


    /*this is the exact as the first but as a saving account with inherited functions */
} else if (accountType == 2) {
    int accountNumber, input;
    double amount, interestRate;
    std::cout << "Enter Saving account number: ";
    std::cin >> accountNumber;
    std::cout << "Enter Saving balance (in USD): ";
    std::cin >> amount;
    std::cout << "Enter Saving interest rate (%): ";
    std::cin >> interestRate;
    savingsAccount account(accountNumber, amount, interestRate);
    do {
        std::cout << std::endl;
        std::cout << "Which service do you want to use?" << std::endl;
        std::cout << "1<--Deposit: " << std::endl;
        std::cout << "2<--Withdraw: " << std::endl;
        std::cout << "3<--Print balance: " << std::endl;
        std::cout << "4<--Print account details: " << std::endl;
        std::cout << "5<--Print daily interest" << std::endl;
        std::cout << "0<--Exit" << std::endl;
        std::cin >> input;
        switch (input) {
            case 0:
                std::cout << "Thank you. Good bye" << std::endl;
                break;
            case 1:
                std::cout << "Deposit amount: ";
                std::cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                std::cout << "Enter withdrawal amount: ";
                std::cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                std::cout << "Current Balance: " << account.getAccountBalance() << std::endl;
                break;
            case 4:
                account.print();
                break;
            case 5:
                account.postInterest();
                break;
            default:
                std::cout << "Invalid input." << std::endl;
        }
    } while (input != 0);

}else {
    std::cout << "Enter 1 or 2 Please\n";
}
    return 0;
}

```

Header File for the saving account extending from the bank account header file
```c++

#pragma once
#include "bankAccount.h"

/* This is the header for the savings Account C++ */
/* extends from bank account to saving account*/

class savingsAccount : public bankAccount {
    /*once set cannot be changed*/
private:
    double interestRate = 0.0;
public:
    void setInterestRate(double interestRate);
    double getInterestRate() const;
    void postInterest();
    void withdraw(double amount);
    void print() const;
    savingsAccount();
    savingsAccount(int accountNumber, double balance, double interestRate);
};

```

Saving Account C++ File Defining all the extened functions from bank account 
```c++
#include <iostream>
/*to include the stated functons from header file*/
#include "savingsAccount.h"
#include <iomanip>


/*setter entered interest will now be the  saving interest rate*/
void savingsAccount::setInterestRate(double interestRate) {
    this->interestRate = interestRate;
}

/* getter */
double savingsAccount::getInterestRate() const {
    return this->interestRate;
}

/*outputting new saving account prompt*/
void savingsAccount::postInterest() {
    double interest = getAccountBalance() * (interestRate / 100.0 / 365.0);
    std::cout << "Saving Interest: " << std::fixed << std::setprecision(2) << interest << std::endl;

    bankAccount::deposit(interest);
}

/*Modified to the saving account prompt*/
void savingsAccount::withdraw(double amount) {
    if (amount > getAccountBalance()) {
        std::cout << "No Saving funds for withdrawal of  " << amount << std::endl;
        std::cout << "Current Saving Account Balance: " << getAccountBalance() << std::endl;
    } else {
        bankAccount::withdraw(amount);
    }
}


/*Modified to saving interest*/
void savingsAccount::print() const {
    bankAccount::print();
    std::cout << "Saving Interest Rate: " << this->interestRate << std::endl;
}


savingsAccount::savingsAccount() {};

/*intitlizes values once it begins the parameters are entered */
savingsAccount::savingsAccount(int accountNumber, double balance, double interestRate) :
    bankAccount(accountNumber, balance), interestRate(interestRate) {}
```
