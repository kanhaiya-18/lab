#include <iostream>
#include <cmath>
using namespace std;

class Bank
{
    float balance;
    float rate_of_interest;

public:
    Bank(float initial_balance, float roi)
    {
        balance = initial_balance;
        rate_of_interest = roi;
    }

    void deposit(float amount)
    {
        if (amount <= 0)
        {
            cout << "Deposit amount must be positive!" << endl;
            return;
        }
        balance += amount;
        cout << "After depositing, total balance is: " << balance << endl;
    }

    void withdraw(float amount)
    {
        if (amount <= 0)
        {
            cout << "Withdrawal amount must be positive!" << endl;
            return;
        }
        if (balance - amount < 0)
        {
            cout << "Insufficient balance for this withdrawal!" << endl;
            return;
        }
        balance -= amount;
        cout << "After withdrawal, remaining balance is: " << balance << endl;
    }

    void calculateCompoundInterest(float time)
    {
        if (time <= 0)
        {
            cout << "Time period must be positive!" << endl;
            return;
        }
        float new_balance = balance * pow((1 + rate_of_interest / 100), time);
        cout << "Balance after " << time << " years with compound interest: " << new_balance << endl;
    }

    void displayBalance()
    {
        cout << "Current balance: " << balance << endl;
    }

    void setInterestRate(float new_rate)
    {
        if (new_rate <= 0)
        {
            cout << "Interest rate must be positive!" << endl;
            return;
        }
        rate_of_interest = new_rate;
        cout << "Interest rate updated to: " << rate_of_interest << "%" << endl;
    }

    ~Bank() {}
};

int main()
{
    float initial_balance, roi;
    cout << "Enter initial balance and rate of interest: ";
    cin >> initial_balance >> roi;

    Bank bank_account(initial_balance, roi);

    int choice;
    do
    {
        cout << "\nBanking Operations Menu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Calculate Compound Interest\n";
        cout << "4. Display Current Balance\n";
        cout << "5. Set Interest Rate\n";
        cout << "6. Reset Balance\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            float amount;
            cout << "Enter amount to deposit: ";
            cin >> amount;
            bank_account.deposit(amount);
            break;
        }
        case 2:
        {
            float amount;
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            bank_account.withdraw(amount);
            break;
        }
        case 3:
        {
            float time;
            cout << "Enter time (in years) to calculate compound interest: ";
            cin >> time;
            bank_account.calculateCompoundInterest(time);
            break;
        }
        case 4:
            bank_account.displayBalance();
            break;
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

