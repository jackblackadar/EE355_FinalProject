#include "date.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// allows for index of month to access string name
static const string monthNames[] = {"", "January", "February", "March", "April", 
    "May", "June", "July", "August", 
    "September", "October", "November", "December"};



void Date::print_date() {
    // Validate month before using it as an index
    if (month < 1 || month > 12) {
        cout << "Invalid month value: " << month << ". Cannot print date." << endl;
        return;
    }
    
    string str_month = monthNames[month];
    cout << str_month << " " << day << ", " << year << endl;
}

Date::Date(unsigned short month, unsigned short day,  unsigned short year)  {
    // validate the day and month of date
    if (month < 1 || month > 12) {
        month = 1;
    }
    if (day < 1 || day > 31) {
        day = 1;
    }
    if (year < 1) {
        year = 1;
    }

    this->day = day;
    this->month = month;
    this->year = year;
} 

Date::Date(string input)  {
    // Initialize with default values first
    this->month = 1;
    this->day = 1;
    this->year = 2000;
    
    try {
        std::stringstream ss(input);
        std::string token;
        
        // Get month
        std::getline(ss, token, '/');
        int m = std::stoi(token);
        
        // Get day
        std::getline(ss, token, '/');
        int d = std::stoi(token);
        
        // Get year
        std::getline(ss, token);
        int y = std::stoi(token);
        
        // Validate and assign
        if (m >= 1 && m <= 12) this->month = m;
        if (d >= 1 && d <= 31) this->day = d;
        if (y >= 1) this->year = y;
    } 
    catch (const std::exception& e) {
        std::cout << "Error parsing date: " << input << ". Using default values." << std::endl;
        // Keep default values
    }
} 

void Date::set_date() {
    // get user info
    string temp;
    cout << "Enter date (M/D/YYYY): ";
    getline(cin, temp);
    
    // parse date data
    stringstream ss(temp);
    string monthStr, dayStr, yearStr;
    
    // extract values using '/' as delimiter
    getline(ss, monthStr, '/');
    getline(ss, dayStr, '/');
    getline(ss, yearStr, '/');
    
    // convert strings to integers
    try {
        month = stoi(monthStr);
        day = stoi(dayStr);
        year = stoi(yearStr);
    } catch (const exception& e) {
        cout << "Error parsing date. Using default values." << endl;
        // set to default values if conversion fails
        month = 1;
        day = 1;
        year = 2000;    
    }
    
    // validate the day and month of date
    if (month < 1 || month > 12) {
        cout << "Invalid month. Setting to default." << endl;
        month = 1;
    }
        if (day < 1 || day > 31) {
        cout << "Invalid day. Setting to default." << endl;
        day = 1;
    }
}

int  Date::get_month() const {
    return month;
}
 int Date::get_day() const{
    return day;
}
int  Date::get_year() const{
    return year;
}

bool Date::operator==(const Date& other_date){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)

    return (day == other_date.get_day() &&
            month == other_date.get_month() &&
            year == other_date.get_year());
}