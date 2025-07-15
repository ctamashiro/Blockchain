/*
Full Name: Cole Tamashiro 
Student ID: 2444822
Chapman email: ctamashiro@chapman.edu
Course number and section: CPSC350-02
Assignment: PA-4 Blockchain Ledger?
*/

#ifndef Interface_H
#include "Blockchain.h"
#include "Block.h"
#include <iostream>
#include <string>

class Interface {
    public:

    //Outputs the menu options 1-6
    void menu();

    //Runs the menu and all the other functions used in the program
    void run();

    private: 
    //Linked List used to store the data 
    Blockchain m_blockchain;

};
#endif