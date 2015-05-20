//
//  main.cpp
//  HW5PR3
//
//  Created by Noor Thabit on 3/8/13.
//  Copyright (c) 2013 Noor Thabit. All rights reserved.
//


#include "Chrono.h"
#include "std_lib_facilities_3.h"
namespace Chrono {
    
    // member function definitions:
    
    
    Date::Date(int yy, Month mm, int dd)
    : y(yy), m(mm), d(dd)
    {
        if (!is_date(yy,mm,dd)) throw Invalid();
    }
    
    
    
    Date& default_date()
    {
        static Date dd(2001,Date::Month::jan,1);
        return dd;
    }
    
    Date::Date()
    :y(default_date().year()),
    m(default_date().month()),
    d(default_date().day())
    {
    }
    
    void Date::add_day(int n)
    {
        
        if (n<0) error("add_day(): can't handle negative n");
        for (unsigned int i=0; i<n; i++) {
            ++d;
        }
        
    }
    
    
    void Date::add_month(int n)
    {
        
        if (n<0) error("add_month(): cannot take negative n");	
        if (m+n<=12){ m = Month(m+n); }
        if (m+n>12) {
            m= Month(((m+n)-12));
        }
        
        
    }
    
    
    void Date::add_year(int n)
    {
        if (m==feb && d==29 && !leapyear(y+n)) { // beware of leap years!
			// makes sense for both positive and negative n (n==0 should be impossible here)
			m = mar;        // use March 1 instead of February 29
			d = 1;
        }
        y+=n;
    }
    
    
    
    
    // helper functions, etc.:
    
    bool is_date(int y, Date::Month  m, int d)
    {
        // assume that y is valid
        
        if (d<=0) { return false; }          // d must be positive
        int days_in_month=31;
        
        
        switch (m) {
            case Date::feb:                        // the length of February varies
                days_in_month=(leapyear(y))?29:28;
                break;
            case Date::apr: case Date::jun: case Date::sep: case Date::nov:
                days_in_month=30;
                break;
                
        }
        if (days_in_month<d) { return false; }
        
        return true;
    }
    
    
    
    bool leapyear(int y)
    {
        
        
        if (y%4) { return false; }
        if (y%100==0 && y%400) { return false; }
        return true;
    }
    
    
    bool operator==(const Date& a, const Date& b)
    {
        return a.year()==b.year()
        && a.month()==b.month()
        && a.day()==b.day();
    }
    
    
    bool operator!=(const Date& a, const Date& b)
    {
        return !(a==b);
    }
    
    
    
    
    
    ostream& operator<<(ostream& os, const Date& d)
    {
        return os<<'('<< d.year()
        <<','<< d.month()
        <<','<<d.day()<<')';
    }
    
    
    
    
    
    
    
    istream& operator>>(istream& is, Date& dd)
    {
        int y, m, d;
        char ch1, ch2, ch3, ch4;
        is >> ch1 >> y >> ch2 >> m >> ch3 >> d >> ch4;
        if (!is) return is;
        if (ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')') { // oops: format error
            is.clear(ios_base::failbit);                    // set the fail bit
            return is;
        }
        dd = Date(y,Date::Month(m),d);     // update dd
        return is;
    }
    
    
    Date& Date::operator++()
    {
        
        ++d;
        if (!is_date(year(), month(), day())) {d=1;
            
        
        if (month()==dec) {
            m=jan;
            ++y;
           
        }
         else m= Month(m+1);
        }
        
        return *this;
    }
    
    
    
    enum Day {
        sunday=1, monday, tuesday, wednesday, thursday, friday, saturday
    };
    
    
    Day day_of_week(const Date& d)
    {
        return sunday;
    }
    
    
    Date next_Sunday(const Date& d)
    {
        return d;
    }
    
    
    Date next_weekday(const Date& d)
    {
        return d;
    }
    
} // Chrono
    