#pragma once
#include <string>
#include "Money.h"
class Payment {
    std::string* Name;
    std::string* Surname;
    std::string* Patronymic;
    Money* salary; //�����
    int* yearOfHiring; //��� ������ ������
    double* bonusPercent; //������� ��������
    double* incomeTaxPercent; //���������� �����
    int* workedDays; //���-�� ������������ ���� 
    int* totalWorkDays; //���-�� ������� ���� � ������
    Money* accruedAmount; //����������� �����
    Money* withheldAmount; //��������� �����

public:
    Payment();
    Payment(std::string name, std::string surname, std::string patronymic, Money sal, int year, double bonus, int worked, int total);

    ~Payment();
    Payment(const Payment& other);
    std::string getName();
    std::string getSurname();
    std::string getPatronymic();
    Money getSalary();
    int getYear();
    double getBonys();
    double getIncomeTax();
    int getWorked();
    int getTotal();
    Money getAccrued();
    Money getWithhel();


    void calculateWithheldAmount();
    int calculateExperience();
    void calculateAccruedAmount();
    Money calculateMoneyInHand();

    Payment& operator=(const Payment& other);
    friend std::ostream& operator<<(std::ostream& out, const Payment& payment);
    friend std::istream& operator>>(std::istream& in, Payment& payment);
};
