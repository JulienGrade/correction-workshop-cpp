#include <iostream>

class BankAccount {
private:
    double balance;

public:
    BankAccount(double balance) : balance(balance) {}

    double getBalance() {
        return balance;
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            return false;
        }

        balance += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0 || amount > balance) {
            return false;
        }

        balance -= amount;
        return true;
    }
};

class Transaction {
private:
    BankAccount* from;
    BankAccount* to;
    double amount;

public:
    Transaction(BankAccount* from, BankAccount* to, double amount)
        : from(from), to(to), amount(amount) {}

    bool execute() {
        if (!from->withdraw(amount)) {
            return false;
        }

        return to->deposit(amount);
    }
};

void testTransaction(double amount) {
    BankAccount account1{1000.0};
    BankAccount account2{500.0};
    Transaction transaction{&account1, &account2, amount};

    std::cout << "Virement de " << amount << '\n';

    if (transaction.execute()) {
        std::cout << "Transaction successful\n";
    } else {
        std::cout << "Transaction failed\n";
    }

    std::cout << "Solde emetteur : " << account1.getBalance() << '\n';
    std::cout << "Solde destinataire : " << account2.getBalance() << "\n\n";
}

int main() {
    testTransaction(500.0);
    testTransaction(5000.0);
    testTransaction(1000.0);

    return 0;
}