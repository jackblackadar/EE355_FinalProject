#ifndef DATE_H
#define DATE_H

#include "fstream"

// Date class definition
class Date {
private:
    int day;
    int month;
    int year;
public: 
    // constructor
    Date(unsigned short month, unsigned short day, unsigned short year);
    // function definition
    void print_date();
    void set_date();
    void set_type(); // NOT IMPL
    void set_type(string input);  // NOT IMPL
};


#endif