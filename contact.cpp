#include "contact.h"
#include <iostream>
#include <regex>
using namespace std;

// Email constructor
Email::Email(string type, string email_addr) {
    // self ptr to set values
    this->type = type;
    this->email_addr = email_addr;
}

bool Email::is_valid_email(const string& email){
    // looks for somthing like bob@gmail.com
    std::regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return std::regex_match(email, pattern);
}

void Email::set_contact(){
    // Do not change the prompts!
    cout << "Enter the type of email address: ";
    getline(cin, this->type);
    string emailBuffer;
    while(true){
        cout << "Enter email address: ";
        getline(cin, emailBuffer);
        if(is_valid_email(emailBuffer)){
            this->email_addr = emailBuffer;
            return;
        } else{
            cout << "Invalid email, please try again\n";
        }
    }
}


string Email::get_contact(string style){
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!

    // assign type
    this->type = type;
    
    // prep phone num string
    string cleaned_num = "";
    for(char c : num) {  //iterate over each character in num string
        if(c != '-' && c != ' ') {  // only add numbers, no dash or spaces
            cleaned_num += c;
        }
    }
    
    // reformat with dashes
    if(cleaned_num.length() >= 10) {
        phone_num = cleaned_num.substr(0, 3) + "-" + cleaned_num.substr(3, 3) + "-" + cleaned_num.substr(6);
    }
    else {
        cout << "Unexpected phone number entered." << endl; // warning message
        phone_num = cleaned_num;
    }

}

bool Phone::is_valid_number(const string& number){
    // looks for something like 0123456789
    std::regex pattern("^\\D*(\\d\\D*){10}$"); // extra \ because cpp thinkis a single \ is an escapce character and not regex
    return std::regex_match(number, pattern);
}

void Phone::set_contact(){
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    getline(cin, this->type);
    string numberBuffer;
    cout << "Enter the phone number: ";
    getline(cin, numberBuffer);

    // cout << "Entered the number: " << numberBuffer <<'\n';
    // prep phone num string SAME AS CONSTRUCTOR
    string cleaned_num = "";
    for(char c : numberBuffer) {  //iterate over each character in num string
        if(c != '-' && c != ' ') {  // only add numbers, no dash or spaces
            cleaned_num += c;
        }
    }
    // reformat with dashes
    if(is_valid_number(cleaned_num)){
        this->phone_num = cleaned_num.substr(0, 3) + "-" + cleaned_num.substr(3, 3) + "-" + cleaned_num.substr(6);
    }
    else {
        cout << "Invalid number input. Enter 10 digits exactly" << endl; 
        this->set_contact();
    }
}


string Phone::get_contact(string style){
    if (style=="full")
	    return "(" + type + ") " + phone_num;
    else 
        return phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

