//���� �3 ������ ��� 26 ����� 53
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



    cout << "������� ���,�������,��������\n�����(� ������ � ��������)\n��� ������ ������\n��������\n���-�� ������������� ����, ����� ���-�� ������� ����\n(�� ����� Enter)" << endl;
    cin >> payment;
    cout << payment;

    int x = -1;
    while (x != 0) {
        cout << "1-���������� ����������� �����, 2-���������� ���������� �����,3-����� �� ����,4-����,0-�����\n";
        cin >> x;
        switch (x)
        {
        case 1:
            payment.calculateAccruedAmount();
            cout << "����������� �����: " << payment.getAccrued() << endl;
            break;
        case 2:
            payment.calculateWithheldAmount();
            cout << "��������� �����: " << payment.getWithhel() << endl;
            break;
        case 3:

            cout << "�������� �����: " << payment.calculateMoneyInHand() << endl;
            break;
        case 4:
            cout << "����: " << payment.calculateExperience() << endl;
            break;

        default:
            break;
        }
    }

}
