
#include "Blockchain.h"
#include <fstream>
#include <iostream>
#include <sstream>

//Default constructor
Blockchain::Blockchain() {
}

//default deconstructor
Blockchain::~Blockchain() {
}

//Creates the GenesisBlock genereated at the beginning of every run
void Blockchain::genesisBlock() {
    //Creates a new instance of the class Block giving Genesis Block value
    Block newBlock;
    newBlock.setIndex(0);
    newBlock.setTimeStamp(newBlock.generateTimeStamp()); 
    newBlock.setData("Genesis Block");
    newBlock.setPreviousHash("0");
    newBlock.setCurrentHash(newBlock.currentHash());
    

    //Format that is shown on the terminal
    std::cout << "🧱 Genesis Block Created 🧱\n"
              << "Index: " << newBlock.getIndex() << "\n"
              << "Timestamp: " << newBlock.getTimeStamp() <<"\n"
              << "Data: " << newBlock.getData() << "\n"
              << "Previous Hash: " << newBlock.getPreviousHash() << "\n"
              << "Hash: " << newBlock.getCurrentHash() << "\n";
    std::cout << std::endl;

    //Adds the Genesis Block to the LinkedList
    m_chain.addBack(newBlock);
}


//Displays the LinkedLists filled with blocks
void Blockchain::display() {
    //Format shown in the terminal
    std::cout << "\n";
    std::cout << "🔗 Blockchain State" << std::endl;
    for(int i = 0; i < m_chain.size(); ++i) {
        Block test = m_chain.get(i);
        std::cout << "Index: " << test.getIndex() << "\n";
        std::cout << "  Timestamp: " << test.getTimeStamp() << "\n";
        std::cout << "  Data: " << test.getData() << "\n";
        std::cout << "  Previous Hash: " << test.getPreviousHash() << "\n";
        std::cout << "  Hash: " << test.getCurrentHash() << "\n";
        std::cout << "\n";
    }
    std::cout << "\n";
}


//Used to Add Blocks in the chain
void Blockchain::addBlock(std::string dataInput) {
    //Creates a new block
    Block newBlock;

    //Gives the new index value since size is +1
    int newIndex = m_chain.size();  
    Block prevBlock = m_chain.get(newIndex - 1);

    //Gives the new block it's individual values
    newBlock.setIndex(newIndex);
    newBlock.setTimeStamp(newBlock.generateTimeStamp());
    newBlock.setData(dataInput);
    newBlock.setPreviousHash(prevBlock.getCurrentHash());
    newBlock.setCurrentHash(newBlock.currentHash());  

    //Output Format
    std::cout << "\n";
    std::cout << "🧱 New Block Added 🧱\n"
              << "  Index: " << newBlock.getIndex() << "\n"
              << "  Timestamp: " << newBlock.getTimeStamp() << "\n"
              << "  Data: " << newBlock.getData() << "\n"
              << "  Previous Hash: " << newBlock.getPreviousHash() << "\n"
              << "  Hash: " << newBlock.getCurrentHash() << "\n";
    std::cout << "\n";

    //Adds the new Block to the chain and sets its Hash value
    m_chain.addBack(newBlock);
    newBlock.setCurrentHash(newBlock.currentHash());
}

//Getter for the Linked List
DblList<Block>& Blockchain::getChain() {
    return m_chain;
}

bool Blockchain::validate() {
    std::cout << "\n";
    std::cout << "Performing blockchain validation..." << std::endl;

    //Loops through the chain (linked list)
    for (int i = 0; i < m_chain.size(); ++i) {
       //Sets the current chain
        Block current = m_chain.get(i);


        std::string recomputedHash = current.currentHash();

        //Checks if the current Hash is equal to the currentHash (Checks if any values were changed and recalculates the Hash)
        if (current.getCurrentHash() != recomputedHash) {
            std::cout << "Block " << i << " has an invalid current hash!" << std::endl;
            std::cout << "Result: Blockchain is invalid!⛔️" << std::endl;
            return false;
        }

        // Check previous hash starting from block 1 (genesis block has no previous)
        if (i > 0) {
            Block previous = m_chain.get(i - 1);
            if (current.getPreviousHash() != previous.getCurrentHash()) {
                std::cout << "Block " << i << " has an invalid previous hash!" << std::endl;
                std::cout << "Result: Blockchain is invalid!⛔️" << std::endl;
                std::cout << "\n";
                return false;
            }
        }
    }

    std::cout << "Result: Blockchain is valid ✅" << std::endl;
    std::cout << "\n";
    return true;
}


std::string Blockchain::saveFile(std::string savedFile) {
    std::ofstream outFile(savedFile);
    if(outFile.is_open()) {
        //Loops through the entire chain
        for(int i = 0; i < m_chain.size(); ++i) {
    
            //Outputs each Block in the proper file format        
            Block b = m_chain.get(i);

            outFile << b.getIndex() << "|";
            outFile << b.getTimeStamp() << "|";
            outFile << b.getData() << "|";
            outFile << b.previousHash() << "|";
            outFile << b.currentHash() << "\n";

        }
        outFile.close();
        std::cout << "Blockchain saved to file: " + savedFile << std::endl;
        return "Blockchain saved to file: " + savedFile;
    } 
    //Check Statement
    else {
        std::cout << "Could not open File" << std::endl;
    }
}

//Loads the information from the file into a new list

void Blockchain::loadFile(std::string loadedFile) {
    
    //File Logic
    std::ifstream inFile(loadedFile);

    if (!inFile.is_open()) {
        std::cout << "Unable to Open File " << std::endl;
        return;
    }

    // Clear existing chain
    m_chain = DblList<Block>();

    std::string line;
    while (getline(inFile, line)) {
       // Resets the values of each Block variable
        std::string indexStr = "";
        std::string timestamp = "";
        std::string data = ""; 
        std::string prevHash = ""; 
        std::string currHash = "";
        int section = 0;

        //Loops through each character of each line
        for (int i = 0; i < line.length(); ++i) {
            //Accounts for each | seperating the data for each indvidual blockuses section as a counter to track which variables to edit
            if (line[i] == '|') {
                ++section;
                continue;
            }

            
            switch (section) {
                case 0: 
                    //String before | is the Index
                    indexStr += line[i]; 
                    break;
                case 1: 
                    //String after the first | is the timestamp
                    timestamp += line[i]; 
                    break;
                case 2: 
                    //String after the second | is the data
                    data += line[i]; 
                    break;
                case 3: 
                    //String after the third | is the prev Hash
                    prevHash += line[i]; 
                    break;
                case 4: 
                    //String after the fourth | is the currentHash
                    currHash += line[i]; 
                    break;
            }
        }

        //SOURCE FROM: 

        //BEGIN CODE FROM CHAT GPT, PROMPT ASKED: how do you convert a string value to an int
        int index = 0;
        for (char c : indexStr) {
            if (c >= '0' && c <= '9') {
                //Converts character into ASCII value and subtracts it by '0' which is equal to 48 in ACII value
                index = index * 10 + (c - '0');
            }
        }
        //END OF CODE FROM CHATGPT


        //Builds the block and adds it back to the Chain 
        Block b;
        b.setIndex(index);
        b.setTimeStamp(timestamp);
        b.setData(data);
        b.setPreviousHash(prevHash);
        b.setCurrentHash(currHash);

        m_chain.addBack(b);
    }

    //Closes the file and prints where it got the data from 
    inFile.close();
    std::cout << "Blockchain loaded from file: " << loadedFile << std::endl;
    std::cout << "\n";
}











