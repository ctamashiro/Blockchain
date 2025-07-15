
#ifndef Blockchain_H
#define Blockchain_H
#include "Block.h"
#include "DblList.h"
#include <iostream>
#include <string>

class Blockchain {
    public: 

    //Default Constructor 
    Blockchain();

    //Default deconstructor 
    ~Blockchain();

    //List Getter
    DblList<Block>& getChain();

    //Genesis Block Constructor 
    void genesisBlock();

    //Adds a block of data using the user input
    void addBlock(std::string dataInput);

    //Validates the Chain
    bool validate();

    //Saves a file given a user created file
    std::string saveFile(std::string savedFile);

    //Loads the chain from a user generated file
    void loadFile(std::string loadedFile);

    //Displays the chain
    void display();



    private: 
    //Linked List to hold each block of data
    DblList<Block> m_chain;




};

#endif