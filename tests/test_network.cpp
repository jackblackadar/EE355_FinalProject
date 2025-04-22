#include "network.h"
#include "person.h"
#include <iostream>


int main() {
    try {
        // Create an empty network first
        Network test;
        std::cout << "Network created successfully!" << std::endl;
        
        // Then try to load the file
        test.loadDB("networkDB.txt");
        std::cout << "Network loaded successfully!" << std::endl;
        
        // Print the network to verify contents
        test.printDB();

        test.push_front(new Person("karen", "smith", "01/01/2001", "mail@mail.com", "1112223333s"));
        test.push_back(new Person("alex", "johnson", "01/01/2001", "mail@mail.com", "1112223333s"));
        test.printDB();

        test.remove("Martin", "Van Nostrand");
        test.printDB();

        test.saveDB("updatedDB.txt");
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

       
    
    return 0;
}
