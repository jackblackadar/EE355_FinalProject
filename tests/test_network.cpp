#include "network.h"
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
        test.showMenu();

        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }

       
    
    return 0;
}
