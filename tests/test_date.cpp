#include "date.h"
#include <iostream>

int main(){
    std::cout << "----Testing class Date-----\n";
    {
        Date test_date(0,0,0); 
    } 
    std::cout << "----finished-----\n"; // place a breakpoint here and check if testEmail got deallocated correctly as it goes out of scope
   
}