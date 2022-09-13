// TODO: Implement this source file
#include <iostream>
#include "MyString.h"
using std::cout, std::endl;



MyString::MyString():stringCapacity(1), stringLength(0), dataString(){
    stringCapacity = 1;
    stringLength = 0;
    char* tempString = new char[stringCapacity];
    tempString[0] = '\0';
    dataString = tempString;
}

MyString::MyString(const MyString& string): stringCapacity(string.stringCapacity), stringLength(string.stringLength), dataString(){
    char* tempString = new char[string.stringCapacity];
    stringCapacity = string.stringCapacity;
    stringLength = string.stringLength;

    for (int i = 0; i < int(string.stringLength); i++){
        tempString[i] = string.dataString[i];
    }

    //delete[] dataString; nothing need to delete - constructor
    dataString = tempString;
    
}

MyString::MyString(const char* s): stringCapacity(1), stringLength(0), dataString(){
    //finding length

    if (s == nullptr){
        stringCapacity = 1;
        stringLength = 0;
        char* tempString = new char[1];
        tempString[0] = '\0';
        dataString = tempString;
    }

    else{
        char character = ' ';
        size_t i = 0; //capacity of the string
        while (character != '\0'){ //adds one for every character in the string (including null character)
            character = s[i];
            i++;
        }

        char* tempString = new char[i];
        stringCapacity = i;
        stringLength = i - 1; //everything except for the null character

        //deep copy
        for (int j = 0; j < int(stringLength); j++){ 
            tempString[j] = s[j];
        }
        tempString[stringLength] = '\0'; //adding the null

        //delete[] dataString;
        dataString = tempString;
    }
}

MyString::~MyString(){
    delete[] dataString;
}

size_t MyString::length() const noexcept{
    return stringLength;
}

size_t MyString::capacity() const noexcept{
    return stringCapacity;
}

size_t MyString::size() const noexcept{
    return stringLength;
}

const char* MyString::data() const noexcept{
    return dataString;
}

bool MyString::empty() const noexcept{
    return (stringLength==0);
}
//help------------------------------------------------------------------------------------------------

void MyString::resize(size_t n){
    char* tempString = new char[n];
    
    //copies over everything
    if (stringLength <= n){ //size given is greater than the length of the string
        for (int i = 0; i < int(stringLength); i++){
            tempString[i] = dataString[i];
        }
        stringCapacity = n;
        //string length stays the same
    }
    else if (n < stringLength){ //cutting off letters
        for (int i = 0; i < int(n); i++){
            tempString[i] = dataString[i];
        }
        stringCapacity = n + 1;
        stringLength = n; //Can capacity = string length????---------------------
    }

    //delete old dataString??--------------------------------------------
    delete[] dataString;
    dataString = tempString;

}

const char& MyString::front() const{ //why no work??--------------------------------
    return dataString[0];
}

const char& MyString::at(size_t pos) const{ //logic ----------------------------------------
    
    if ( (pos >= (stringLength) ) ) { //if position given is out of range (stringLength - 1) because array starts at 0
        throw std::out_of_range("The index is not in range!"); 
    }
    else{
        return dataString[pos];
    }

}

void MyString::clear() noexcept{
    
    //reset variables
    stringLength = 0;
    stringCapacity = 1;
    delete[] dataString;

    //create a new string and assign
    char* tempString = new char[1];
    tempString[0] = '\0';
    dataString = tempString;
    
}


size_t MyString::find (const MyString& str, size_t pos) const noexcept{
    
    
    size_t index = 0;
    for (int i = pos; i < int(stringLength); i++){
        
        //cout << "str " << str.dataString[i] << " THIS " << this->dataString[i] << endl;
        if (str.dataString[0] == this->dataString[i]){
            //cout << "FOUND" << endl;
            index = i;
            for(int j = i; j < int(i + str.stringLength); j++){
                if (j >= int(stringLength)){
                    //cout << "else" << endl;
                    return -1;
                }
                else if(str.dataString[j - i] != this->dataString[j]){
                    index = j;
                    break;
                }

            }
            size_t temp1 = i;
            if(index == temp1){
                return index;
            }
        }
    }
    
    return -1;
}


MyString& MyString::operator= (const MyString& str){
    char* tempString = new char[str.stringCapacity];
    for (int i = 0; i < int(str.stringLength); i++){
        tempString[i] = str.dataString[i];
    }

    delete[] this->dataString;
    this->dataString = tempString;
    this->stringCapacity = str.stringCapacity;
    this->stringLength = str.stringLength;
    
    
    return *this;
}

MyString& MyString::operator+= (const MyString& str){
    char* tempString = new char[ (str.stringCapacity + this->stringLength + 1) ];
    
    //cout << "CAPACITY " << (str.stringCapacity + this->stringLength + 1) << endl;
    
    //cout << this->stringLength << endl;
    for(int i = 0; i < int(this->stringLength); i++){
        tempString[i] = this->dataString[i];
        //cout << this->dataString[i];
    }
    
    //cout <<  "HELP " << (str.stringLength + this->stringLength) << endl;
    for (int j = this->stringLength; j < int(str.stringLength + this->stringLength); j++){
        tempString[j] = str.dataString[j - stringLength];
    }

    tempString[str.stringLength + this->stringLength + 1] = '\0';

    this->stringCapacity = str.stringCapacity + this->stringCapacity + 1;
    this->stringLength = str.stringLength + this->stringLength;
    delete[] this->dataString;
    this->dataString = tempString;
    
    //do I need to delete the other sting (str)?? ------------------------------------------------
    return *this;
}

std::ostream& operator<< (std::ostream& os, const MyString& str){
    //for loop
    for (int i = 0; i < int(str.length()); i++){
        os << str.data()[i];
    }
    return os;
    //os << str.data()[i]
}

MyString operator+ (const MyString& lhs, const MyString& rhs){
    MyString tempString;
    tempString += lhs;
    tempString += rhs;
    return tempString;
}

bool operator== (const MyString& lhs, const MyString& rhs){
    if (lhs.stringLength != rhs.stringLength){
        return false;
    }

    int temp = lhs.size();
    for (int i = 0; i < temp; i++){
        if (lhs.at(i) != rhs.at(i)){
            return false;
        }
    }
    return true;
}
