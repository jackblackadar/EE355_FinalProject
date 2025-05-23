#ifndef DATE_H
#define DATE_H

#include "fstream"
#include <string>

// Date class definition
class Date {
private:
    int day;
    int month;
    int year;
public: 
    // constructor
    Date(unsigned short month, unsigned short day, unsigned short year);
    Date(std::string input);
    // function definition
    void print_date();
    void set_date();
    int get_month() const;
    int get_day() const;
    int get_year() const;
    bool operator==(const Date& date);
};


#endif