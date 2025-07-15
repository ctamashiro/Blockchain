/*
Full Name: Cole Tamashiro 
Student ID: 2444822
Chapman email: ctamashiro@chapman.edu
Course number and section: CPSC350-02
Assignment: PA-4 Blockchain Ledger?
*/

#include "Interface.h"
#include <iostream>
#include <string> 
#include <ctime>
#include <sstream>
#include <iomanip>

//Menu so the user can navigate through the program
void Interface::menu() {
    std::cout << "Welcome to your Panther Blockchain Ledger:" << "\n" 
    << "1. Add a New Block" << "\n" 
    << "2. Display the Blockchain" << "\n" 
    << "3. Validate the Blockchain" << "\n" 
    << "4. Save Blockchain to File" << "\n" 
    << "5. Load Blockchain from File" << "\n" 
    << "6. Exit" << "\n"
    << "Enter your choice: ";
}


//Used to Run through the whole program 
void Interface::run() {
    //Creates a genesis block and the choice variable
    m_blockchain.genesisBlock();
    std::string choice;

    //Will run forever until the user quits 
    while(choice != "7") {
    menu();
    std::getline(std::cin, choice);

    //User Chooses to add a block
    if(choice == "1") {
        std::cout << "Enter block data: ";
        std::string dataInput;
        std::getline(std::cin, dataInput);  
        m_blockchain.addBlock(dataInput);
    } else if (choice == "2") { //User chooses to display the chain
        m_blockchain.display();
    } else if (choice == "3") { //User chooses to validate the blocks
        if(m_blockchain.validate() == false) {
            break; //Breaks if the blocks are not valid 
        }
    } else if (choice == "4") { //User chooses to save the chain they created in a file
        std::cout << "Enter filename to save the blockchain: ";
        std::string savedFile;
        std::getline(std::cin, savedFile); 
        m_blockchain.saveFile(savedFile);
        break;
    } else if (choice == "5") { //User chooses to load the information from a file and make it into a chain
        std::cout << "Enter filename to load the blockchain: ";
        std::string fileName;
        std::getline(std::cin, fileName);  
        m_blockchain.loadFile(fileName);
    } else if (choice == "6") { //User chooses to exit the program
        std::cout << "Exiting Program" << std::endl;
        break;
    } else { //Input check to make sure the user entered a valid number
        std::cout << "The number you entered was not an integer 1-6" << std::endl;
    }

}

}
