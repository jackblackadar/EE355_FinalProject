#include "person.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Person::Person(){
    // I'm already done! 
    set_person();
}

Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
    delete phone;
    delete email;
}

Person::Person(string f_name, string l_name, string b_date, string email_str, string phone_str){
    // TODO: Complete this method!
    // phone and email strings are in full version
    this->f_name = f_name;
    this->l_name = l_name;
    birthdate = new Date(b_date);

    email = new Email("Work", email_str);  // default type
    phone = new Phone("Home", phone_str);  // default type
}

Person::Person(string filename){
    set_person(filename);
}

void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    std::getline(std::cin, type);
    cout << "Email address: ";
    std::getline(std::cin, temp);
    email = new Email(type, temp);

    cout << "Type of phone number: ";
    std::getline(std::cin, type);
    cout << "Phone number: ";
    std::getline(std::cin, temp);
    phone = new Phone(type, temp);
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    string line;
    getline(file, f_name);
    getline(file, l_name);

    string bdate, email_type, email_addr, phone_type, phone_num;
    getline(file, bdate);
    birthdate = new Date(bdate);

    getline(file, email_type);
    getline(file, email_addr);
    email = new Email(email_type, email_addr);

    getline(file, phone_type);
    getline(file, phone_num);
    phone = new Phone(phone_type, phone_num);

    file.close();
}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)

    return (f_name == rhs.f_name &&
            l_name == rhs.l_name &&
            *birthdate == *(rhs.birthdate));
}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);
}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date(); // why was this function given str input when it doesnt want one? "Month D, YYYY"
    phone->print();
    email->print();
}
