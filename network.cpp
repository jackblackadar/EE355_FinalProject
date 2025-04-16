#include "network.h"
#include <limits>
#include <fstream>
#include <iostream>
#include <sstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

Network::Network() {
    head = NULL;
    tail = NULL;
    count = 0;
}

Network::Network(string fileName) {
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
}

Network::~Network() { 
    Person* current = head;
    while (current != NULL) {
        Person* to_delete = current;
        current = current->next;
        delete to_delete;
    }
    head = NULL;
    tail = NULL;
    count = 0;
}

Person* Network::search(Person* searchEntry) {
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* current = head;
    while (current != NULL) {
        if (*current == *searchEntry) return current; // WON'T WORK bc youre comparing memmory
        current = current->next;
    }
    return NULL;
}

Person* Network::search(string fname, string lname) {
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* current = head;
    while (current != NULL) {
        if (current->f_name == fname && current->l_name == lname) return current;
        current = current->next;
    }
    return NULL;
}

void Network::loadDB(string filename) {
    // TODO: Complete this method
    ifstream file(filename);
    if (!file.is_open()) return;

    // Clear current list
    Person* current = head;
    while (current != NULL) {
        Person* to_delete = current;
        current = current->next;
        delete to_delete;
    }
    head = NULL;
    tail = NULL;
    count = 0;

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;

        string fname = line;
        string lname, bdate, email_type, email_addr, phone_type, phone_num;

        getline(file, lname);
        getline(file, bdate);
        getline(file, line); // email line
        size_t l = line.find(")");
        email_type = line.substr(1, l - 1);
        email_addr = line.substr(l + 2);

        getline(file, line); // phone line
        l = line.find(")");
        phone_type = line.substr(1, l - 1);
        phone_num = line.substr(l + 2);

        getline(file, line); // delimiter "--------------------"

        Person* p = new Person(fname, lname, bdate, email_addr, phone_num);
        p->email->set_type(email_type);
        p->phone->set_type(phone_type);

        push_back(p);
    }

    file.close();
}

void Network::saveDB(string filename) {
    // TODO: Complete this method
    ofstream file(filename);
    if (!file.is_open()) return;

    Person* current = head;
    while (current != NULL) {
        file << current->f_name << endl;
        file << current->l_name << endl;

        stringstream ss;
        ss << current->birthdate->get_month() << "/"
           << current->birthdate->get_day() << "/"
           << current->birthdate->get_year();
        file << ss.str() << endl;

        file <<  current->email->get_contact();
        file << current->phone->get_contact();
        file << "--------------------" << endl;

        current = current->next;
    }

    file.close();
}

void Network::push_back(Person* newEntry) {
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method
    newEntry->next = NULL;
    newEntry->prev = tail;

    if (tail != NULL)
        tail->next = newEntry;
    else
        head = newEntry;

    tail = newEntry;
    count++;
}

bool Network::remove(string fname, string lname) {
    // TODO: Complete this method
    Person* target = search(fname, lname);
    if (!target) return false;

    if (target->prev) target->prev->next = target->next;
    else head = target->next;

    if (target->next) target->next->prev = target->prev;
    else tail = target->prev;

    delete target;
    count--;
    return true;
}

void Network::showMenu() {
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while (1) {
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "\nSelect an option ... ";

        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }

        string fname, lname, fileName;
        cout << "\033[2J\033[1;1H";

        if (opt == 1) {
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            getline(cin, fileName);
            saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        } else if (opt == 2) {
            // TODO: Complete me!
            cout << "Loading network database \n";

            for (const auto& entry : fs::directory_iterator(".")) {
                string path = entry.path().string();
                if (path.find("networkDB") != string::npos && path.substr(path.find_last_of(".") + 1) == "txt") {
                    cout << path.substr(2) << endl; // remove "./"
                }
            }

            cout << "Enter the name of the load file: ";
            getline(cin, fileName);
            ifstream check(fileName);
            if (!check.good()) {
                cout << "File " << fileName << " does not exist!" << endl;
            } else {
                loadDB(fileName);
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
            check.close();
        } else if (opt == 3) {
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exist!
            cout << "Adding a new person \n";
            Person* newP = new Person();
            if (search(newP) == NULL) {
                push_front(newP);
            } else {
                cout << "Person already exists! \n";
                delete newP;
            }
        } else if (opt == 4) {
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            getline(cin, fname);
            cout << "Last name: ";
            getline(cin, lname);
            if (remove(fname, lname))
                cout << "Remove Successful! \n";
            else
                cout << "Person not found! \n";
        } else if (opt == 5) {
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name \n";
            cout << "Last name: ";
            getline(cin, lname);
            Person* current = head;
            bool found = false;
            while (current != NULL) {
                if (current->l_name == lname) {
                    current->print_person();
                    cout << "------------------------------" << endl;
                    found = true;
                }
                current = current->next;
            }
            if (!found) cout << "Person not found! \n";
        } else {
            cout << "Nothing matched!\n";
        }

        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline(cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
