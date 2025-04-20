#include "network.h"
#include <iostream>
using namespace std;

int main() {
	cout << "Testing Network Menu Function" << endl;
	cout << "-----------------------------" << endl;

	// make test network
	Network test;
	cout << "Network created successfully!" << endl;
	cout << "-----------------------------" << endl;


	// Then try to load the file
	test.loadDB("networkDB.txt");
	cout << "Network loaded successfully!" << endl;
	cout << "-----------------------------" << endl;


	// call functions from network
	test.showMenu();
}
