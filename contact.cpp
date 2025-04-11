
#include "contact.h"
// TODO: Add needed libraries! 
#include <iostream>
using namespace std;

// Email constructor
Email::Email(string type, string email_addr) {
    // self ptr to set values
    this->type = type;
    this->email_addr = email_addr;
}


void Email::set_contact(){
    // Do not change the prompts!
    cout << "Enter the type of email address: ";
    getline(cin, this->type);
    while(true){
        cout << "Enter email address: ";
        getline(cin, this->email_addr);
        return; // REGEX goes here for validation
    }
    

    /* error handling for answer to improve robustness???? */
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


void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
    getline(cin, this->type);
	cout << "Enter the phone number: ";
    getline(cin, this->phone_num);
 
    // prep phone num string SAME AS CONSTRUCTOR
    string cleaned_num = "";
    for(char c : this->phone_num) {  //iterate over each character in num string
        if(c != '-' && c != ' ') {  // only add numbers, no dash or spaces
            cleaned_num += c;
        }
    }
    // reformat with dashes
    if(cleaned_num.length() >= 10) {
        this->phone_num = cleaned_num.substr(0, 3) + "-" + cleaned_num.substr(3, 3) + "-" + cleaned_num.substr(6);
    }
    else {
        cout << "Unexpected phone number entered." << endl; // warning message
        this->phone_num = cleaned_num;
    }

    // error handling for robustness???
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email 
    if (style=="full")
	    return "(" + type + ") " + phone_num;
    else 
        return phone_num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}

