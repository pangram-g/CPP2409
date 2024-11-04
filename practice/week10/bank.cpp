#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
    // 잔액 외부 수정 불가하도록
private:
    double balance;
    string accountHolderName;

public:
    BankAccount(string name, double initialBalance)
    {
        accountHolderName = name;
        balance = initialBalance;
    }
    // 현재 잔액 조회 매서드
    double getBalance() const
    {
        return balance;
    }
    // 입금 매서드
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << amount << " deposited. Current balance: " << balance << endl;
        }
    }
    // 출금 매서드
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << amount << " withdrawn. Current balance:" << balance << endl;
        }
        else
        {
            cout << "Insufficient balance or invaild amount!" << endl;
        }
    }
};

int main()
{
    // 생성
    BankAccount myAccount("Alice", 1000);
    // 현 계좌 조회(public 매서드를 통해 접근)
    cout << " Initial Balance" << myAccount.getBalance() << endl;
    // 입금, 출금(public 매서드를 통해 접근)
    myAccount.deposit(500);
    myAccount.withdraw(200);
}