#include "Payment.h"
#include<istream>
#include<ostream>
#include <ctime>

Payment::Payment()
    : Name(new std::string("")),
    Surname(new std::string("")),
    Patronymic(new std::string("")),
    salary(new Money(0, 0)),
    yearOfHiring(new int(0)),
    bonusPercent(new double(0.0)),
    incomeTaxPercent(new double(13.0)),
    workedDays(new int(0)),
    totalWorkDays(new int(0)),
    accruedAmount(new Money(0, 0)),
    withheldAmount(new Money(0, 0))
{}



Payment::Payment(std::string name, std::string surname, std::string patronymic, Money sal, int year, double bonus, int worked, int total)
    : Name(new std::string(name)),
    Surname(new std::string(surname)),
    Patronymic(new std::string(patronymic)),
    salary(new Money(sal)),
    yearOfHiring(new int(year)),
    bonusPercent(new double(bonus)),
    incomeTaxPercent(new double(13.0)),
    workedDays(new int(worked)),
    totalWorkDays(new int(total)),
    accruedAmount(new Money(0, 0)),
    withheldAmount(new Money(0, 0)) 
{}

Payment::~Payment()
{
    delete Name;
    delete Surname;
    delete Patronymic;
    delete salary;
    delete yearOfHiring;
    delete bonusPercent;
    delete incomeTaxPercent;
    delete workedDays;
    delete totalWorkDays;
    delete accruedAmount;
    delete withheldAmount;
}

Payment::Payment(const Payment& other) 
    : Name(new std::string(*other.Name)),
    Surname(new std::string(*other.Surname)),
    Patronymic(new std::string(*other.Patronymic)),
    salary(new Money(*other.salary)),
    yearOfHiring(new int(*other.yearOfHiring)),
    bonusPercent(new double(*other.bonusPercent)),
    incomeTaxPercent(new double(*other.incomeTaxPercent)),
    workedDays(new int(*other.workedDays)),
    totalWorkDays(new int(*other.totalWorkDays)),
    accruedAmount(new Money(*other.accruedAmount)),
    withheldAmount(new Money(*other.withheldAmount))
    {}




std::string Payment::getName()
{
    return *Name;
}

std::string Payment::getSurname()
{
    return *Surname;
}

std::string Payment::getPatronymic()
{
    return *Patronymic;
}

Money Payment::getSalary()
{
    return *salary;
}

int Payment::getYear()
{
    return *yearOfHiring;
}

double Payment::getBonys()
{
    return *bonusPercent;
}

double Payment::getIncomeTax()
{
    return *incomeTaxPercent;
}

int Payment::getWorked()
{
    return *workedDays;
}

int Payment::getTotal()
{
    return *totalWorkDays;
}

Money Payment::getAccrued()
{
    return *accruedAmount;
}

Money Payment::getWithhel()
{
    return *withheldAmount;
}




void Payment::calculateAccruedAmount() {
    double daysCoef = static_cast<double>(*workedDays) / *totalWorkDays;
    *accruedAmount = salary->multiplicate((1 + *bonusPercent / 100) * daysCoef);
}

Money Payment::calculateMoneyInHand() {
    return *accruedAmount - *withheldAmount;
}

void Payment::calculateWithheldAmount() {
    Money pensionFund = accruedAmount->multiplicate(0.01);
    Money taxPercent = (accruedAmount->multiplicate(1) - pensionFund).multiplicate(*incomeTaxPercent / 100);
    *withheldAmount = taxPercent + pensionFund;
}

int Payment::calculateExperience() {
    time_t t = time(nullptr);  
    tm currentTime;
    localtime_s(&currentTime, &t); 
    int currentYear = currentTime.tm_year + 1900; 
    return currentYear - *yearOfHiring; 
}


Payment& Payment::operator=(const Payment& other)
{
    if (this == &other) {
        return *this; 
    }

    delete Name;
    delete Surname;
    delete Patronymic;
    delete salary;
    delete yearOfHiring;
    delete bonusPercent;
    delete incomeTaxPercent;
    delete workedDays;
    delete totalWorkDays;
    delete accruedAmount;
    delete withheldAmount;

    Name = new std::string(*other.Name);
    Surname = new std::string(*other.Surname);
    Patronymic = new std::string(*other.Patronymic);
    salary = new Money(*other.salary);
    yearOfHiring = new int(*other.yearOfHiring);
    bonusPercent = new double(*other.bonusPercent);
    incomeTaxPercent = new double(*other.incomeTaxPercent);
    workedDays = new int(*other.workedDays);
    totalWorkDays = new int(*other.totalWorkDays);
    accruedAmount = new Money(*other.accruedAmount);
    withheldAmount = new Money(*other.withheldAmount);

    return *this;
}


std::ostream& operator<<(std::ostream& out, const Payment& payment) {
    out << "ФИО: " << *payment.Name << " " << *payment.Surname << " " << *payment.Patronymic << "\n"
        << "Оклад: " << *payment.salary << " Год начала работы: " << *payment.yearOfHiring << " Надбавка: " << *payment.bonusPercent << "\n"
        << "Дней проработано: " << *payment.workedDays << " Всего дней: " << *payment.totalWorkDays << "\n";
    return out;
}


std::istream& operator>>(std::istream& in, Payment& payment) {
    std::string name, surname, patronymic;
    Money salary;
    int yearOfHiring;
    double bonusPercent;
    int workedDays;
    int totalWorkDays;

    in >> name >> surname >> patronymic;
    in >> salary;
    in >> yearOfHiring >> bonusPercent >> workedDays >> totalWorkDays;

    *payment.Name = name;
    *payment.Surname = surname;
    *payment.Patronymic = patronymic;
    *payment.salary = salary;
    *payment.yearOfHiring = yearOfHiring;
    *payment.bonusPercent = bonusPercent;
    *payment.workedDays = workedDays;
    *payment.totalWorkDays = totalWorkDays;

    return in;
}
