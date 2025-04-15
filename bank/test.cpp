#include <gtest/gtest.h>
#include "pch.h"
#include <iostream>


class BankAccount {
private:
    double balance = 0.0;

public:
    double get_balance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            std::cout << "Deposited: " << amount << ", and New Balance: " << balance << std::endl;
        }
    }

    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawn: " << amount << ", New Balance: " << balance << std::endl;
            return true;
        }
        std::cout << "Withdrawal of " << amount << " failed. Insufficient balance!" << std::endl;
        return false;
    }
};

// Test
TEST(BankAccountTest, InitialBalanceIsZero) {
    BankAccount account;
    EXPECT_EQ(account.get_balance(), 0.0);
}

TEST(BankAccountTest, DepositWorks) {
    BankAccount account;
    account.deposit(100);
    EXPECT_EQ(account.get_balance(), 100);
}

TEST(BankAccountTest, WithdrawWorks) {
    BankAccount account;
    account.deposit(200);
    EXPECT_TRUE(account.withdraw(100));
    EXPECT_EQ(account.get_balance(), 100);
}

TEST(BankAccountTest, WithdrawFailsWhenInsufficient) {
    BankAccount account;
    EXPECT_FALSE(account.withdraw(50));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
