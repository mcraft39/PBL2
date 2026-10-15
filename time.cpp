#include<bits/stdc++.h>
using namespace std;

class Time {
    private:
        int milsecond;
        int second, minute, hour;
        int day, month, year;
    public:
    Time(int d = 1, int m = 1, int y = 1970) : day(d), month(m), year(y) {};

    inline int leap(int y) { return (!(y % 400) ? 1 : !(y % 100) ? 0 : !(y % 4) ? 1 : 0); }
    inline int dayCount() {
        return (month == 2 ? (28 + leap(year)) : 30 + ((month < 8 && month % 2) || (month > 7 && !(month % 2))) );
    }
    friend istream& operator >> (istream&, Time&);
    friend ostream& operator << (ostream&, const Time&);
    Time operator ++ ();
    Time operator ++ (int);
    Time operator -- ();
    Time operator -- (int);
    void set(char, int);
    int get(char);

    Time convert(int millisecond) {

        return Time();
    }
};  

istream& operator >> (istream& inp, Time& D) {
    cout << "Nhap ngay: "; inp >> D.day;
    cout << "Nhap thang: "; inp >> D.month;
    cout << "Nhap nam: "; inp >> D.year;
    return inp;
}
ostream& operator << (ostream& out, const Time& D) {
    out << D.day << '/' << D.month << '/' << D.year << '\n';
    return out;
}   
Time Time::operator ++ () {
    day++;
    if (day > dayCount()) month++, day = 1; 
    if (month > 12) year++, month = 1; 
    return *this;
}
Time Time::operator ++ (int) {
    Time D = *this;
    ++(*this);
    return D;
}

Time Time::operator -- () {
    day--;
    if (day < 1) month--; 
    if (month < 1) year--, month = 12;
    if (day < 1) day = dayCount(); 
    return *this;
}
Time Time::operator -- (int) {
    Time D = *this;
    --(*this);
    return D;
}

void Time::set(char t, int value) {
    switch (t) {
        case 'd': day = min(dayCount(), max(1, value)); break;
        case 'm': month = min(12, max(1, value));
        case 'y': year = value; break;
        default: break;
    }
}

int Time::get(char t) {
    switch (t) {
        case 'd': return day; break;
        case 'm': return month; break;
        case 'y': return year; break;
        default: return 0; break;
    }
}