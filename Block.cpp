
#include "Block.h"
#include <iostream>
#include <string> 
#include <ctime>
#include <sstream>
#include <iomanip>


//Default Constructor
Block::Block() {
}

//Default Deconstructor
Block::~Block() {
}

//Returns the value of the index
int Block::getIndex() {
    return m_index;
}

//Sets the value of the index
void Block::setIndex(int indexvalue) {
    m_index = indexvalue;
}

//Returns the user input
std::string Block::getData() {
    return m_data;
}

//Sets the value of the user input
void Block::setData(std::string datavalue){
    m_data = datavalue;
}

//Returns the value of the previous Hash
std::string Block::getPreviousHash() {
    return m_previousHash;
}

//Sets the value of the Previous Hash
void Block::setPreviousHash(std::string previousHashvalue) {
    m_previousHash = previousHashvalue;
}

//Returns the value of the Current Hash
std::string Block::getCurrentHash() {
    return m_currentHash;
}

//Sets the value of the Current Hash
void Block::setCurrentHash(std::string currentHashvalue) {
    m_currentHash = currentHashvalue;
}

//Increases the Index Value by 1
int Block::indexIncrease() {
    m_index += 1;
}

//Returns the timeStamp
std::string Block::getTimeStamp() {
    return m_timeStamp;
}

//Sets the value of the TimeStamp
void Block::setTimeStamp(std::string timeStampvalue) {
    m_timeStamp = timeStampvalue;
}

//Generates the time stamp 
std::string Block::generateTimeStamp() {
    //BEGIN CODE FROM SOURCE: https://www.w3schools.com/cpp/cpp_date.asp
    time_t rawTime;
    time(&rawTime);


    //Adjusted for California Time 
    rawTime -= 7 * 3600;  
  


    std::string result = ctime(&rawTime);

    //END OF CODE FROM SOURCE: https://www.w3schools.com/cpp/cpp_date.asp



    //Removes the extra indentation for format reasons 
    if (!result.empty() && result.back() == '\n') {
        result.pop_back();
    }


    return result;
}


//Used to turn intToHexStream provided by Problem Set Document
std::string Block::intToHexStream(int num) {
    //BEGIN CODE FROM SOURCE: https://docs.google.com/document/d/1CYbMtbwje9bkGzhi39Y5IVvNwvFIMHXkD2gUBsgrQnA/edit?tab=t.0
    std::stringstream ss;
    ss << std::hex << num;
    return ss.str();
    //BEGIN CODE FROM SOURCE: https://docs.google.com/document/d/1CYbMtbwje9bkGzhi39Y5IVvNwvFIMHXkD2gUBsgrQnA/edit?tab=t.0
}


//returns previousHash
std::string Block::previousHash() {
    return m_previousHash;
}

//returns CurrentHash
std::string Block::currentHash() {
    std::string content = std::to_string(m_index) + m_timeStamp + m_data + m_previousHash;

    int sum = 0;

    //Converts Each character in the combined string to its ASCII integer value
    for (char c : content) {
        //BEGIN CODE FROM SOURCE: https://learn.microsoft.com/en-us/cpp/cpp/static-cast-operator?view=msvc-170
        sum += static_cast<int>(c); 
        //BEGIN CODE FROM SOURCE: https://learn.microsoft.com/en-us/cpp/cpp/static-cast-operator?view=msvc-170
    }
    
    return intToHexStream(sum);
}





