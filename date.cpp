class Date
{
public:
    int day, month, year;
    Date(int day=0, int month=0, int year=0)
    {
        this->day = day;
        this->month = month;
        this->year = year;
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

    void set_day(int new_day)
    {
        day = new_day;
    }
    void set_month(int new_month)
    {
        month = new_month;
    }
    void set_year(int new_year)
    {
        year = new_year;
    }

    bool operator<(const Date& second_date)
    {
        if(year < second_date.year) return true;
        else if(year == second.year && month < second_date.month) return true;
        else if(year == second.year && month == second_date.month && day < second_date.day) return true;
        else return false;
    }

    bool operator==(const Date& second_date)
    {
        return (year == second_date.year && month == second_date.month && day == second_date.day);
    }

    bool operator<=(const Date& second_date)
    {
        return ((*this) < second_date || (*this) == second_date)
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
        if(day > month_length)
        {
            if(month == 12) {year++; month = 1;}
            else month++;
        }
        day = (day + days) % month_length;
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
            if(month == 1) {year--; month = 12; days = (day - days) % 31;}
            else {--month; day = (day - days) % get_month_length(month);}
        }
    }

    Date operator-(int days)
    {
        return (*this) + (-1) * days;
    }
};
