
#ifndef Block_H
#define Block_H
#include <iostream>
#include <string>

class Block{
    public: 

    //default constructor
    Block();

    //default deconstructor
    ~Block();

    //getters

    int getIndex(); //gets Index
    std::string getData(); //get data (user input)
    std::string getPreviousHash(); //gets the hash of the previous block
    std::string getCurrentHash(); //Gets the current hash
    std::string getTimeStamp(); //Gets Timestamp

    //setters 
    void setIndex(int indexvalue); //Sets the Index Value
    void setData(std::string datavalue); //Sets Data Value
    void setPreviousHash(std::string previousHashvalue); //Sets Previous Hash Value
    void setCurrentHash(std::string currentHashvalue); //Sets Current Hash Value
    void setTimeStamp(std::string timeStampvalue); //Sets Time Value


    //Index 
    int index();

    //Increase Index 
    int indexIncrease();

    //timestamp
    std::string generateTimeStamp();

    //ASCII conversation

    int conversation();

    //Given by Assignment

    std::string intToHexStream(int num);

    //Previous Hash

    std::string previousHash();

    //Current Hash

    std::string currentHash();

    private: 
    //Member variables 
    std::string m_data;
    int m_index = 0;
    std::string m_finalString;
    std::string m_time;
    std::string m_previousHash;
    std::string m_currentHash;
    std::string m_timeStamp;




};

#endif