#ifndef DATE_H
#define DATA_H

#include "fstream"

// Date class definition
class Date {
private:
    int day;
    int month;
    int year;
public: 
    // constructor
    Date(int day, int month, int year) : day(day), month(month), year(year) {} 
    // function definition
    void print_date() {};
    void set_date() {};
};


#endif