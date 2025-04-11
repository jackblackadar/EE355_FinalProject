#include "contact.h"

int main(){
    std::cout << "----Testing class Email-----\n";
    {
        Email testEmail("school email", "kmkrtchy@usc.edu");
        testEmail.set_contact();
        /* 
        input in 
        "personal email"
        "bob.com" // should prompt to try again
        "personal email"
        "bob@com" // should prompt to try again
        "personal email"
        "bob@mail.com" // will work
        */
        testEmail.get_contact("full");
        testEmail.get_contact();
        testEmail.print();     
    } 
    std::cout << "----Testing class Phone-----\n"; // place a breakpoint here and check if testEmail got deallocated correctly as it goes out of scope
    {
        Phone testPhone("phone", "7472703131");
        testPhone.set_contact();
        /* 
        input in 
        "number"
        "abc" // should prompt to try again
        "number"
        "123456789012" // should prompt to try again
        "number"
        "747-270-3131" // will work
        */
        testPhone.get_contact("full");
        testPhone.get_contact();
        testPhone.print();    
    }
}