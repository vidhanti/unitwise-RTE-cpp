#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Base class
class Account {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    // Constructor
    Account(int accNo, string name, double bal) {
        accountNumber = accNo;
        holderName = name;
        balance = bal;
    }

    // Deposit money
    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Amount deposited successfully.\n";
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdrawal
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn successfully.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    // Virtual interest calculation
    virtual double calculateInterest() {
        return 0;
    }

    // Display account details
    virtual void display() {
        cout << "\n-----------------------------------\n";
        cout << "Account Number : " << accountNumber << endl;
        cout << "Holder Name    : " << holderName << endl;
        cout << "Balance        : Rs. " << fixed << setprecision(2)
             << balance << endl;
    }

    // Virtual destructor
    virtual ~Account() {}
};


// Savings Account
class SavingsAccount : public Account {
public:
    SavingsAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {
    }

    double calculateInterest() override {
        // 4% annual interest
        return balance * 0.04;
    }

    void display() override {
        Account::display();
        cout << "Account Type   : Savings Account" << endl;
        cout << "Interest       : Rs. "
             << calculateInterest() << endl;
    }
};


// Current Account
class CurrentAccount : public Account {
public:
    CurrentAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {
    }

    double calculateInterest() override {
        // Current account has no interest
        return 0;
    }

    void withdraw(double amount) override {
        // Allow withdrawal only up to balance
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Amount withdrawn from Current Account.\n";
        } else {
            cout << "Insufficient balance or invalid amount.\n";
        }
    }

    void display() override {
        Account::display();
        cout << "Account Type   : Current Account" << endl;
        cout << "Interest       : Rs. "
             << calculateInterest() << endl;
    }
};


// Fixed Deposit Account
class FixedDepositAccount : public Account {
public:
    FixedDepositAccount(int accNo, string name, double bal)
        : Account(accNo, name, bal) {
    }

    double calculateInterest() override {
        // 7% annual interest
        return balance * 0.07;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal is not allowed from Fixed Deposit "
             << "before maturity.\n";
    }

    void display() override {
        Account::display();
        cout << "Account Type   : Fixed Deposit Account" << endl;
        cout << "Interest       : Rs. "
             << calculateInterest() << endl;
    }
};


// Main function
int main() {

    // Creating accounts
    SavingsAccount savings(101, "Swarup", 50000);
    CurrentAccount current(102, "Rahul", 75000);
    FixedDepositAccount fd(103, "Amit", 100000);

    // Base class pointers
    Account *accounts[3];

    accounts[0] = &savings;
    accounts[1] = &current;
    accounts[2] = &fd;

    int choice;
    int accountChoice;
    double amount;

    do {
        cout << "\n\n========== BANKING SYSTEM ==========\n";
        cout << "1. Display All Accounts\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. Calculate Interest\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "\n========== ACCOUNT DETAILS ==========\n";

            for (int i = 0; i < 3; i++) {
                accounts[i]->display();
            }

            break;


        case 2:
            cout << "\nSelect Account:\n";
            cout << "1. Savings Account\n";
            cout << "2. Current Account\n";
            cout << "3. Fixed Deposit Account\n";
            cout << "Enter choice: ";
            cin >> accountChoice;

            if (accountChoice >= 1 && accountChoice <= 3) {

                cout << "Enter amount to deposit: ";
                cin >> amount;

                accounts[accountChoice - 1]->deposit(amount);

            } else {
                cout << "Invalid account choice!\n";
            }

            break;


        case 3:
            cout << "\nSelect Account:\n";
            cout << "1. Savings Account\n";
            cout << "2. Current Account\n";
            cout << "3. Fixed Deposit Account\n";
            cout << "Enter choice: ";
            cin >> accountChoice;

            if (accountChoice >= 1 && accountChoice <= 3) {

                cout << "Enter amount to withdraw: ";
                cin >> amount;

                accounts[accountChoice - 1]->withdraw(amount);

            } else {
                cout << "Invalid account choice!\n";
            }

            break;


        case 4:
            cout << "\nSelect Account:\n";
            cout << "1. Savings Account\n";
            cout << "2. Current Account\n";
            cout << "3. Fixed Deposit Account\n";
            cout << "Enter choice: ";
            cin >> accountChoice;

            if (accountChoice >= 1 && accountChoice <= 3) {

                double interest =
                    accounts[accountChoice - 1]->calculateInterest();

                cout << "Calculated Interest: Rs. "
                     << fixed << setprecision(2)
                     << interest << endl;

            } else {
                cout << "Invalid account choice!\n";
            }

            break;


        case 5:
            cout << "\nThank you for using the Banking System!\n";
            break;


        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}