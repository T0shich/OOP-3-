//Лаба №3 Лаптев стр 26 номер 53
#include<iostream>
#include <windows.h>
#include "Payment.h"
#include "Money.h"


using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Payment payment;



    cout << "Введите Имя,фамилию,отчество\nОклад(в рубляи и копейках)\nГод начала работы\nНадбавку\nКол-во проработанных дней, общее кол-во рабочих дней\n(всё через Enter)" << endl;
    cin >> payment;
    cout << payment;

    int x = -1;
    while (x != 0) {
        cout << "1-Вычисление начисленной суммы, 2-Вычисление удержанной суммы,3-Сумма на руки,4-Стаж,0-Выход\n";
        cin >> x;
        switch (x)
        {
        case 1:
            payment.calculateAccruedAmount();
            cout << "Начисленная сумма: " << payment.getAccrued() << endl;
            break;
        case 2:
            payment.calculateWithheldAmount();
            cout << "Удержаная сумма: " << payment.getWithhel() << endl;
            break;
        case 3:

            cout << "Итоговая сумма: " << payment.calculateMoneyInHand() << endl;
            break;
        case 4:
            cout << "Стаж: " << payment.calculateExperience() << endl;
            break;

        default:
            break;
        }
    }

}
