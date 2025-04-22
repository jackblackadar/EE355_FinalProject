#include "person.h"
#include <iostream>

int main() {
    try {
        Person test;
        test.makeFriend(new Person("karen", "smith", "01/01/2001", "mail@mail.com", "1112223333s"));
        test.makeFriend(new Person("will", "smith", "01/01/2001", "mail@mail.com", "1112223333s"));
        test.makeFriend(new Person("alex", "smith", "01/01/2001", "mail@mail.com", "1112223333s"));
        test.print_friends();

        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    return 0;
}
