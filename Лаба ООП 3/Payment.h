#pragma once
#include <string>
#include "Money.h"
class Payment {
    std::string* Name;
    std::string* Surname;
    std::string* Patronymic;
    Money* salary; //Оклад
    int* yearOfHiring; //Год начала работы
    double* bonusPercent; //процент надбавки
    double* incomeTaxPercent; //подоходный налог
    int* workedDays; //кол-во отработанных дней 
    int* totalWorkDays; //кол-во рабочих дней в месяце
    Money* accruedAmount; //Начисленная сумма
    Money* withheldAmount; //Удержаная сумма

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
