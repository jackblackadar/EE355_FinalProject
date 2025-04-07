
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
// TODO: You may need to add other libraries here!
using namespace std;


class Contact {
    // TODO: private or protected? Look at your children!	
    // USE PROTECTED SO DERIVED CLASSES CAN ACCESS IT
protected:
	string type;
public:
    // virtual functions overridden in derived classes
	virtual void print() = 0;
    virtual string get_contact(string style="full") = 0;
	virtual void set_contact() = 0;
};


class Email: public Contact{
private:
    string email_addr;
public:
    // TODO: Complete me!

    // constructor, expanded in .cpp file
    Email(string type, string email_addr) {};

    // override functions
    void set_contact() override;
    string get_contact(string style="full") override;
    void print() override;


};


class Phone: public Contact{
private:
    // TODO: modify dataType! Can int store 10 digit phone-number? 
    // NO, USE STRING INSTEAD
	string phone_num; 
public:
    // TODO: Complete me!

    // constructor, expanded in .cpp file
    Phone(string type, string phone_number) {};

    // override functions
    void set_contact() override;
    string get_contact(string style="full") override;
    void print() override;
};

#endif