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
    // print in format from manual
    string str_month = monthNames[month];
    cout << str_month << " " << day << ", " << year << endl;
}

Date::Date(unsigned short month, unsigned short day,  unsigned short year)  {
    // validate the day and month of date
    if (month < 1 || month > 12) {
        cout << "Invalid month. Setting to default (1)." << endl;
        month = 1;
    }
    if (day < 1 || day > 31) {
        cout << "Invalid day. Setting to default (1)." << endl;
        day = 1;
    }
    if (year < 1) {
        cout << "Are you trying to store BCE years as negative? Setting to default (1)." << endl;
        year = 1;
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