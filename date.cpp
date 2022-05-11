#include <iostream>

class Date
{
public:
    int day, month, year;
    Date(int day=0, int month=0, int year=0)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        this->control_inputs();
    }
    int get_day()
    {
        return day;
    }
    int get_month()
    {
        return month;
    }
    int get_year()
    {
        return year;
    }

    int get_month_length(int month)
    {
        switch(month)
        {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            {
                return 31;
                break;
            }
        case 4:
        case 6:
        case 9:
        case 11:
            {
                return 30;
                break;
            }
        case 2:
            {
                if(year % 4 == 0 && (year % 100 != 0 || year % 400 == 0)) return 29;
                else return 28;
                break;
            }
        }
    }

    void control_inputs()
    {
        if(day < 1 || day > get_month_length(month))
            throw std::out_of_range("Day out of range");
        if(month < 1 || month > 12)
            throw std::out_of_range("Month out of range");
        if(year < 1)
            throw std::out_of_range("Year cannot be negative");
    }

    void set_day(int new_day)
    {
        day = new_day;
        this->control_inputs();
    }
    void set_month(int new_month)
    {
        month = new_month;
        this->control_inputs();
    }
    void set_year(int new_year)
    {
        year = new_year;
        this->control_inputs();
    }

    bool operator<(const Date& second_date)
    {
        if(year < second_date.year) return true;
        else if(year == second_date.year && month < second_date.month) return true;
        else if(year == second_date.year && month == second_date.month && day < second_date.day) return true;
        else return false;
    }

    bool operator==(const Date& second_date)
    {
        return (year == second_date.year && month == second_date.month && day == second_date.day);
    }

    bool operator<=(const Date& second_date)
    {
        return ((*this) < second_date || (*this) == second_date);
    }

    bool operator>(const Date& second_date)
    {
        return !((*this) <= second_date);
    }

    bool operator>=(const Date& second_date)
    {
        return ((*this) > second_date || (*this) == second_date);
    }

    Date operator+=(int days)
    {
        if(day + days > get_month_length(month))
        {
            day += days;
            do
            {
                if(month == 12) {month = 1; year++;}
                else month++;
                day -= get_month_length(month);
            }
            while(day > get_month_length(month));
        }
        else day += days;
        return *this;
    }

    Date& operator++()
    {
        this->operator+=(1);
        return *this;
    }

    Date operator++(int)
    {
        Date old_date = *this;
        ++(*this);
        return old_date;
    }

    Date operator+(int days) const
    {
        Date new_date = *this;
        new_date += days;
        return new_date;
    }

    Date operator-=(int days)
    {
        if(day - days < 0)
        {
            day -= days;
            do
            {
                if(month == 1) {month = 12; year--;}
                else month--;
                day += get_month_length(month);
            }
            while(day <= 0);
        }
        else day -= days;
        return *this;
    }


    Date operator-(int days)
    {
        return (*this) + (-1) * days;
    }

    friend std::ostream& operator<<(std::ostream& os, Date& d)
    {
        if(d.day<10) os<<'0'<<d.day;
        else os<<d.day;
        os<<'.';
        if(d.month<10) os<<'0'<<d.month;
        else os<<d.month;
        os<<'.';
        if(d.year<10) os<<'0'<<d.year;
        else os<<d.year;

        return os;
    }
};

