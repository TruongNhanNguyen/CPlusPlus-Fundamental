#include <bits/stdc++.h>
#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string owner;
    double balance;
    static double interest_rate;
    static int accounts_count;

    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        balance -= amount;
    }

public:
    // Constructor
    BankAccount(std::string owner, double balance) : owner(owner), balance(balance)
    {
        accounts_count++;
    }

    // Destructor
    ~BankAccount()
    {
        accounts_count--;
    }

    // Copy constructor
    BankAccount(const BankAccount &other) : owner(other.owner), balance(other.balance)
    {
        accounts_count++;
    }

    // Copy assignment operator
    BankAccount &operator=(const BankAccount &other)
    {
        owner = other.owner;
        balance = other.balance;
        return *this;
    }

    // Move constructor
    BankAccount(BankAccount &&other) noexcept : owner(std::move(other.owner)), balance(other.balance)
    {
        other.owner = "";
        other.balance = 0;
        accounts_count++;
    }

    // Move assignment operator
    BankAccount &operator=(BankAccount &&other) noexcept
    {
        owner = std::move(other.owner);
        balance = other.balance;
        other.owner = "";
        other.balance = 0;
        return *this;
    }

    std::string get_owner() const
    {
        return owner;
    }
    double get_balance() const
    {
        return balance;
    }
    void add_funds(double amount)
    {
        deposit(amount);
    }
    void remove_funds(double amount)
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
    static int get_accounts_count()
    {
        return accounts_count;
    }
};

double BankAccount::interest_rate = 0.01; // Initialize the static member variable
int BankAccount::accounts_count = 0;      // Initialize the static member variable

int main()
{
    BankAccount account1("John", 1000);
    std::cout << "Owner: " << account1.get_owner() << std::endl;     // Prints "Owner: John"
    std::cout << "Balance: " << account1.get_balance() << std::endl; // Prints "Balance: 1000"
    account1.add_funds(500);
    std::cout << "Balance: " << account1.get_balance() << std::endl; // Prints "Balance: 1500"
    account1.remove_funds(250);
    std::cout << "Balance: " << account1.get_balance() << std::endl; // Prints "Balance: 1250"

    BankAccount::set_interest_rate(0.03);                                                  // Set the interest rate for all bank accounts to 3%
    std::cout << "Interest rate: " << BankAccount::get_interest_rate() << std::endl;       // Prints "Interest rate: 0.03"
    std::cout << "Number of accounts: " << BankAccount::get_accounts_count() << std::endl; // Prints "Number of accounts: 1"

    BankAccount account2 = account1;                                 // Copy construct the account2 object from the account1 object
    std::cout << "Owner: " << account2.get_owner() << std::endl;     // Prints "Owner: John"
    std::cout << "Balance: " << account2.get_balance() << std::endl; // Prints "Balance: 1250"
    std::cout << "Number of accounts: " << BankAccount::get_accounts_count() << std::endl;
    BankAccount account3("Alice", 2000);
    account2 = account3;                                                                   // Assign the account3 object to the account2 object
    std::cout << "Owner: " << account2.get_owner() << std::endl;                           // Prints "Owner: Alice"
    std::cout << "Balance: " << account2.get_balance() << std::endl;                       // Prints "Balance: 2000"
    std::cout << "Number of accounts: " << BankAccount::get_accounts_count() << std::endl; // Prints "Number of accounts: 2"

    BankAccount account4(std::move(account2));                                             // Move construct the account4 object from the account2 object
    std::cout << "Owner: " << account4.get_owner() << std::endl;                           // Prints "Owner: Alice"
    std::cout << "Balance: " << account4.get_balance() << std::endl;                       // Prints "Balance: 2000"
    std::cout << "Number of accounts: " << BankAccount::get_accounts_count() << std::endl; // Prints "Number of accounts: 2"

    account4 = std::move(account1);                                                        // Move assign the account1 object to the account4 object
    std::cout << "Owner: " << account4.get_owner() << std::endl;                           // Prints "Owner: John"
    std::cout << "Balance: " << account4.get_balance() << std::endl;                       // Prints "Balance: 1250"
    std::cout << "Number of accounts: " << BankAccount::get_accounts_count() << std::endl; // Prints "Number of accounts: 2"

    return 0;
}
