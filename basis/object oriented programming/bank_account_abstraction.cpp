#include <bits/stdc++.h>

#include <iostream>
#include <string>

class BankAccount
{
public:
    virtual double get_balance() = 0;             // Pure virtual function
    virtual void add_funds(double amount) = 0;    // Pure virtual function
    virtual void remove_funds(double amount) = 0; // Pure virtual function
};

class CheckingAccount : public BankAccount
{
private:
    std::string owner;
    double balance;
    static double interest_rate;

    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        balance -= amount;
    }

public:
    CheckingAccount(std::string owner, double balance) : owner(owner), balance(balance) {}
    double get_balance() override
    {
        return balance;
    }
    void add_funds(double amount) override
    {
        deposit(amount);
    }
    void remove_funds(double amount) override
    {
        withdraw(amount);
    }
    static void set_interest_rate(double rate)
    {
        interest_rate = rate;
    }
    static double get_interest_rate()
    {
        return interest_rate;
    }
};

double CheckingAccount::interest_rate = 0.01; // Initialize the static member variable

int main()
{
    CheckingAccount account("John", 1000);
    std::cout << "Balance: " << account.get_balance() << std::endl; // Prints "Balance: 1000"
    account.add_funds(500);
    std::cout << "Balance: " << account.get_balance() << std::endl; // Prints "Balance: 1500"
    account.remove_funds(250);
    std::cout << "Balance: " << account.get_balance() << std::endl;                      // Prints "Balance: 1250"
    CheckingAccount::set_interest_rate(0.03);                                            // Set the interest rate for all checking accounts to 3%
    std::cout << "Interest rate: " << CheckingAccount::get_interest_rate() << std::endl; // Prints "Interest rate: 0.03"

    return 0;
}
