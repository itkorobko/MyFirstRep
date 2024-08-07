#include "Date.h"
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;
Date::Date() //Конструктор по умолчанию. Устанавливает 0-ую дату
{
    d = 0; m = 0; y = 0;
    //Пишет                               "родился"?????
}
Date::Date(int d, int m, int y) : d(d), m(m), y(y)  //Конструктор, устанавливающий дату по параметрам
{
    if (y > 0)
    {
        if (1 <= m && m <= 12)
        {
            if (!(1 <= d && d <= day_count[m - 1] + (int)((m == 2) && IsLeapYear()))) //не факт!!!
               // throw exception("Ошибка. День введён неверно.");
                throw exception();
        }
    //   else throw exception("Ошибка.месяц должен быть в пределах[1..12].");
        else throw exception();
    }
   // else throw exception("Ошибка.Год должен быть больше нуля.");
    else throw exception();
    //
    //пишет                        родился(2)??????
}
Date::Date(const Date& rhs) //Конструктор копирования
{
    d = rhs.d; m = rhs.m; y = rhs.y; //
    // пишет                    родился(3)????
}
Date Date::operator+(int day)const
{ if (day < 0)             //                 Зачем???
        return *this - (-day);
    Date NewDate(*this);
    while(NewDate.AddYear(day));                   //Много вопросов?????????
    while (NewDate.AddMonth(day));
    while(NewDate.AddDay(day));
    return NewDate;
}
Date Date::operator-(int day) const
{
    if (day < 0)
        return *this + (-day);
    Date NewDate(*this);
    while(NewDate.SubYear(day));
    while (NewDate.SubMonth(day));
    while (NewDate.SubDay(day));
    return NewDate;

}
int Date::operator-(const Date & rhs) const
{
    return this->GetFromBegin()-rhs.GetFromBegin();
}
Date& Date::operator+=(int rhs)
{
    Date NewDate = *this +rhs;
    return NewDate;
}
Date& Date::operator-=(int rhs)
{
    Date NewDate = *this - rhs;
    return NewDate;
}
bool Date::operator!=(const Date & rhs) const
{
    return !(*this ==rhs);
}
bool Date::operator==(const Date & rhs) const
{
    return (this->d == rhs.d) && (this->m == rhs.m) && (this->y == rhs.y);
}
bool Date::operator<(const Date & rhs) const
{
    if (this->y == rhs.y)
    {
        if (this->m == rhs.m)
            return this->d < rhs.d;
        else return this->m < rhs.m;

    }
    else return this->y < rhs.y;
}
bool Date::operator<=(const Date & rhs) const
{
    return (*this == rhs) || (*this < rhs);
}
bool Date::operator>(const Date & rhs) const
{
    if (this->y == rhs.y)
    {
        if (this -> m == rhs.m)
            return this->d > rhs.d;
        else return this->m > rhs.m;
    }
    else return this->y > rhs.y;
}
bool Date::operator>=(const Date & rhs) const
{
    return (*this == rhs) || (*this > rhs);
}
Date& Date::operator=(const Date & rhs)
{
    if (this == &rhs)
        return (*this);
    this->d = rhs.d;
    this->m = rhs.m;
    this->y = rhs.y;
    return (*this);
}
Date::~Date()
{ //
    //Пишет убит???????????????7
}
int Date::GetFromBegin() const//Сколько дней прошло с начала(хороший)
{
    int days = 0;
    for (int i = 1; i < this->y; i++)
        days += 365 + int(IsLeapYear(i));
    for(int i = 1; i < this->m; i++)
        days += day_count[i - 1] + int((i == 2) && IsLeapYear());
    days += d;
    return days;
}
Date Date::LocalTime() // Очень неплохая вещь, возвращает нынешнее время
{
    time_t rawtime;
    tm* Time = new tm;
    time(&rawtime);
    localtime_s(Time, &rawtime);
    return Date(Time->tm_mday,Time->tm_mon + 1, Time->tm_year + 1900);
}
bool Date::AddDay(int& day) //Добавляет к this->дню 1 и отнимает от параметра 1
{
    if(day > 0)
    {
        day = day - 1;                       //Непонятно
        int day_cnt_in_this_mounth = day_count[m - 1] + int((m == 2) && IsLeapYear());
        d = d + 1;
        if (d > day_cnt_in_this_mounth)
            d = 1, m = m + 1;
        if (m > 12)
            m = 1, y = y + 1;
        return true;
    }
    return false;
}
bool Date::AddMonth(int& day) //Отнимает от параметра количество дней в месяце и добавлет месяц к this
{
    while (d != 1 && AddDay(day));
    int day_cnt_in_this_mounth = day_count[m - 1] + int((m == 2) && IsLeapYear());
    if(day >= day_cnt_in_this_mounth)
    {
        day = day - day_cnt_in_this_mounth;
        m = m + 1;
        if (m > 12)
            m = 1, y = y + 1;
        return true;
    }
    return false;
}
bool Date::AddYear(int& day)
{
    while (d != 1 && AddDay(day));
    while (m != 1 && AddMonth(day));
    int day_in_this_year = 365 + int(IsLeapYear());
    if (day >= day_in_this_year)
    {
        day = day-day_in_this_year;
        y = y + 1;
        return true;
    }
    return false;
}
bool Date::SubYear(int&day)
{
    while (d != day_count[m - 1] + int((m == 2) && IsLeapYear()) && SubDay(day));
    while (m != 12 && SubMonth(day));
    int day_in_this_year = 365 + int(IsLeapYear());
    if (day >= day_in_this_year)
    {
        day = day - day_in_this_year;
        y = y- 1;
        return true;
    }
    return false;
}
bool Date::SubMonth(int& day)
{
    while (d !=day_count[m - 1] + int((m == 2) && IsLeapYear()) && SubDay(day));
    int day_cnt_in_this_mounth = day_count[m - 1] + int((m == 2) && IsLeapYear());
    if (day >= day_cnt_in_this_mounth)
    {
        day = day - day_cnt_in_this_mounth;
        m = m -1;
        if (m < 1)
            m = 12, y = y - 1;
        d = day_count[m - 1] + int((m == 2) && IsLeapYear());
        return true;
    }
    return false;
}
bool Date::SubDay(int& day)
{
    if (day >0)
    {
        day = day - 1;
        d = d - 1;
        if (d < 1)
        {
            m = m - 1;
            if (m - 1 < 1)
                m = 12, y = y - 1;
            int day_cnt_in_month = day_count[m - 1] + int((m == 2) && IsLeapYear());
            d = day_cnt_in_month;
        }
        return true;
    }
    return false;
}
bool Date::IsLeapYear(int year) const
{
    if (year == -1)                      //Вообще непонятно зачем отрицательные даты?????????
        year = this->y;
    if (year % 400 == 0)
        return true;
    else if (year % 100 == 0) //Добавил else и ниже
        return false;
    else if (year % 4 == 0)
        return true;
    return false;
}
ostream& operator<<(ostream &outp__, const Date &date__)
{
    outp__ << setw(2) << setfill('0')<< date__.d << ".";
    outp__ << setw(2) << setfill('0') << date__.m << ".";
    outp__ <<setw(4) << setfill('0') << date__.y;
    return outp__;
}
//1.В субботу в 9.45 Ассемблер
//2.Лаб 2 не забыть
//3.На след. неделе переходим к изучению qt
// На след. занятии нужно уметь с помщью qt рисовать светофоры, message-box,
//
