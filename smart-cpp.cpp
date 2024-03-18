// smart-cpp.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class BankAccount {

private:

    int accountNumber;
    double balance;
    double interestRate;


public:
    BankAccount(int acc_num, double nachalo_balance) {
        accountNumber = acc_num;
        balance = nachalo_balance;
        interestRate = 0.0;
    }

    void deposit(double _amount) {
        if (_amount > 0)
            balance += _amount;
    }

    bool withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            return true;
        }
        else {
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

    double getInterest() const {
        return balance * interestRate * (1.0 / 12.0);
    }

    void setInterestRate(double rate) {
        interestRate = rate;
    }

    int getAccountNumber() const {
        return accountNumber;
    }

    friend bool transfer(BankAccount& _from, BankAccount& _to, double amount) {
        if (amount > 0 && _from.balance >= amount) {
            _from.balance -= amount;
            _to.balance += amount;
            return true;
        }
        else if (amount == _from.balance) {
            _from.balance -= amount;
            _to.balance += amount;
            return true;
        }
        else {
            return false;
        }
    }
};

int main() {

    setlocale(LC_ALL, "Russian");

    int acc_lol;
    int acc_tresh;

    double tekushi_balance1, tekushi_balance2;
    double transfer_summa;

    cout << "\n    >> BANK TRANSACTIONS <<";
    cout << "\nВведите номер счета 1: ";
    cin >> acc_lol;

    cout << "Введите начальный баланс первого счета: ";
    cin >> tekushi_balance1;

    cout << "Введите номер счета 2: ";
    cin >> acc_tresh;

    cout << "Введите начальный баланс второго счета: ";
    cin >> tekushi_balance2;

    while (true) {

            BankAccount acc1(acc_lol, tekushi_balance1);
            BankAccount acc2(acc_tresh, tekushi_balance2);


            cout << "\n>> BANK TRANSACTIONS <<";

            cout << "\nЧто вы хотите сделать?";
            cout << "\n1. Перевести деньги с первого счета на второй ";
            cout << "\n2. Перевести деньги со второго счета на первый ";
            cout << "\n3. Рассчитать процентную ставку ";
            cout << "\n4. Выйти из программы\n ";

            int choice;

            cin >> choice;

            switch (choice) {
            case 1: {
                cout << "\nВведите сумму для перевода с первого счета на второй: ";

                cin >> transfer_summa;

                bool isTransaction = transfer(acc1, acc2, transfer_summa);

                if (isTransaction) {

                    tekushi_balance1 = acc1.getBalance();
                    tekushi_balance2 = acc2.getBalance();

                    cout << "\nПеревод успешно выполнен" << endl;
                    cout << "\nТекущий баланс на первом счету: " << tekushi_balance1 << endl;
                    cout << "\nТекущий баланс на втором счету: " << tekushi_balance2 << endl;
                }
                else {
                    cout << "\nОшибка в переводе!" << endl;
                    break;
                }
                break;
            }

            case 2: {
                cout << "\nВведите сумму для перевода со второго счета на первый: ";

                cin >> transfer_summa;

                bool isTransaction = transfer(acc2, acc1, transfer_summa);

                if (isTransaction) {

                    tekushi_balance2 = acc2.getBalance();
                    tekushi_balance1 = acc1.getBalance();

                    cout << "\nПеревод успешно выполнен" << endl;
                    cout << "\nТекущий баланс на втором счету: " << tekushi_balance2 << endl;
                    cout << "\nТекущий баланс на первом счету: " << tekushi_balance1 << endl;
                }
                else {
                    cout << "\nОшибка в переводе!" << endl;
                    break;
                }
                break;
            }

            case 3: {
                double interestRate;

                cout << "\nВведите процентную ставку: ";
                cin >> interestRate;

                acc1.setInterestRate(interestRate);
                acc2.setInterestRate(interestRate);

                double interest1 = acc1.getInterest();
                double interest2 = acc2.getInterest();

                cout << "\nПроценты на счете 1: " << interest1 << endl;
                cout << "Проценты на счете 2: " << interest2 << endl;

                break;

            }

            case 4:
                cout << "------------------------\n";
                cout << "  Вы завершили работу!\n";
                cout << "------------------------\n";
                return 0;
                break;
            default:
                cout << "такой чиселки нет!";
                break;
            }
        }
        
    }
