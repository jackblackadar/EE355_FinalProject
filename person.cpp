#include "person.h"
#include "misc.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Person::Person() {
    // I'm already done! 
    next = nullptr;
    prev = nullptr;
    set_person();
}

Person::~Person(){
    if (birthdate) delete birthdate;
    if (phone) delete phone;
    if (email) delete email;

    birthdate = nullptr;
    phone = nullptr;
    email = nullptr;
}

Person::Person(string f_name, string l_name, string b_date, string email_str, string phone_str){
    // phone and email strings are in full version
    this->f_name = f_name;
    this->l_name = l_name;
    birthdate = new Date(b_date);

    email = new Email("Work", email_str);  // default type
    phone = new Phone("Home", phone_str);  // default type

    next = nullptr;
    prev = nullptr;
}

Person::Person(string filename){
    next = nullptr;
    prev = nullptr;
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
    // Initialize pointers to nullptr first
    birthdate = nullptr;
    phone = nullptr;
    email = nullptr;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Failed to open file: " << filename << endl;
        return;
    }

    try {
        string line;
        if (!getline(file, f_name)) throw runtime_error("Failed to read first name");
        if (!getline(file, l_name)) throw runtime_error("Failed to read last name");

        string bdate;
        if (!getline(file, bdate)) throw runtime_error("Failed to read birthdate");
        birthdate = new Date(bdate);

        string email_type, email_addr;
        if (!getline(file, email_type)) throw runtime_error("Failed to read email type");
        if (!getline(file, email_addr)) throw runtime_error("Failed to read email address");
        email = new Email(email_type, email_addr);

        string phone_type, phone_num;
        if (!getline(file, phone_type)) throw runtime_error("Failed to read phone type");
        if (!getline(file, phone_num)) throw runtime_error("Failed to read phone number");
        phone = new Phone(phone_type, phone_num);

    } catch (const exception& e) {
        // Clean up any allocated resources
        if (birthdate) { delete birthdate; birthdate = nullptr; }
        if (email) { delete email; email = nullptr; }
        if (phone) { delete phone; phone = nullptr; }
        
        cerr << "Error reading file: " << e.what() << endl;
    }

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

    // CHANGES FOR PHASE 2 BELOW
    if (!myfriends.empty()) {  // if friends exist
        for (Person* friend_ptr : myfriends) {  // iterate over each friend
            string code = codeName(friend_ptr->f_name, friend_ptr->l_name);
            cout << code << " (" << friend_ptr->f_name << " " << friend_ptr->l_name << ")" << endl;
        }
    }
}


void Person::makeFriend(Person* newFriend) {
    // push back new friend to the end of vector
    myfriends.push_back(newFriend);

    /*
    // print all friends for debug
    for (size_t i = 0; i < friends.size(); ++i) {
        myfriends[i]->print_person();
    }
    cout << endl << endl;
    */

}
