#include <iostream>
#include <string>
#include <sstream>
#include "CellDatabase.h"
#include "CellData.h"
#include <fstream>

using std::cout;
using std::string;
using std::fstream;
using std::ofstream;
using std::endl;

// Default constructor/destructor. Modify them if you need to.
CellDatabase::CellDatabase() {}
CellDatabase::~CellDatabase() {}

bool isNumber(const string& str){
    int count = 0;
    for (char const &c : str) {
        if (c == '.'){ 
            count++;
            continue;
        }
        if (c == '-') continue;
        if (std::isdigit(c) == 0) return false;
    }
    if (count == 0 || count == 1){
        return true;
    }
    else{
        return false;
    }
}

bool isDouble(const string& str){
    bool isDouble = false;
    int count = 0;
    for (char const &c : str) {
        if (c == '.'){
            isDouble = true;
            count++;
            continue;
        }
        if (c == '-') continue;
        if (std::isdigit(c) == 0) return false;
    }
    if(isDouble && count == 1) return true;
    else return false;
}

bool isIntNumber(const string& str){
    for (char const &c : str) {
        if (c == '-') continue;
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

void CellDatabase::loadData(const string& filename) 
{
    
    // Implement this function
    string file = filename;
    string line = "";
    int countTimes = 0;
    
    std::ofstream ofns;
    ofns.open("result.data");
    std::ifstream infs(filename);
    if (!infs.is_open()){

    }
    else{
    
        getline(infs,line);
        while(getline(infs, line))
        {
            //countTimes++;
            std::stringstream linestream(line);
            std::string value;
            int count = 0;
            string id = "";
            int fov = -100;
            double volume = 0;
            double center_x = -100;
            double center_y = -100;
            double min_x = -100;
            double max_x = -100;
            double min_y = -100;
            double max_y = -100;
            while(getline(linestream, value, ',')){
                if (count == 0){
                    if (isIntNumber(value)){
                        id = value;
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl;
                    }
                }
                else if (count == 1){
                    if (isIntNumber(value)){
                        std::stringstream tempStream(value);
                        int temp = 0;
                        tempStream >> temp;
                        fov = temp;
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl;
                    }
                }
                else if (count == 2){
                    if (isNumber(value)){
                        std::stringstream tempStream(value);
                        double temp = 0;
                        tempStream >> temp;
                        volume = temp;
                        if(!isDouble(value)){
                            cout << "Error, Invalid input: " << line << endl;
                            // ofns << "Error, Invalid input: " << line << endl;
                        }
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl;
                    }

                    if (volume < 0){ //making sure volume is positive
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl;
                    }
                }
                else if (count == 3){
                    if (isNumber(value)){
                        std::stringstream tempStream(value);
                        double temp = 0;
                        tempStream >> temp;
                        center_x = temp;
                        if(!isDouble(value)){
                            cout << "Error, Invalid input: " << line << endl;
                            // ofns << "Error, Invalid input: " << line << endl;
                        }
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl;
                    }
                }
                else if (count == 4){
                    if (isNumber(value)){
                        std::stringstream tempStream(value);
                        double temp = 0;
                        tempStream >> temp;
                        center_y = temp;
                        if(!isDouble(value)){
                            cout << "Error, Invalid input: " << line << endl;
                            // ofns << "Error, Invalid input: " << line << endl;
                        }
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl;
                    }
                }
                else if (count == 5){
                    if (isNumber(value)){
                        std::stringstream tempStream(value);
                        double temp = 0;
                        tempStream >> temp;
                        min_x = temp;
                        if(!isDouble(value)){
                            cout << "Error, Invalid input: " << line << endl;
                            // ofns << "Error, Invalid input: " << line << endl;
                        }
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl; 
                    }
                }
                else if (count == 6){
                    if (isNumber(value)){
                        std::stringstream tempStream(value);
                        double temp = 0;
                        tempStream >> temp;
                        max_x = temp;
                        if(!isDouble(value)){
                            cout << "Error, Invalid input: " << line << endl;
                            // ofns << "Error, Invalid input: " << line << endl;
                        }
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl; 
                    }
                }
                else if (count == 7){
                    if (isNumber(value)){
                        std::stringstream tempStream(value);
                        double temp = 0;
                        tempStream >> temp;
                        min_y = temp;
                        if(!isDouble(value)){
                            cout << "Error, Invalid input: " << line << endl;
                            // ofns << "Error, Invalid input: " << line << endl; 
                        }
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl; 
                    }
                }
                else if (count == 8){
                    if (isNumber(value)){
                        std::stringstream tempStream(value);
                        double temp = 0;
                        tempStream >> temp;
                        max_y = temp;
                        if(!isDouble(value)){
                            cout << "Error, Invalid input: " << line << endl;
                            // ofns << "Error, Invalid input: " << line << endl; 
                        }
                    }
                    else{
                        cout << "Error, Invalid input: " << line << endl;
                        // ofns << "Error, Invalid input: " << line << endl; 
                    }
                }
                count++;
            }
            /*
            double volume = 0;
            double center_x = 0;
            double center_y = 0;
            double min_x = 0;
            double max_x = 0;
            double min_y = 0;
            double max_y = 0;
            
            
            if (id == "" || fov == -100 || volume == 0 || center_x == -100 || center_y == -100 || min_x == -100 || max_x == -100 || min_y == -100 || max_y == -100){
                cout << "Error, Invalid input: " << line << endl;
            }
            //cout << line << endl;
            */
        if (count != 9){
            cout << "Error, Invalid input: " << line << endl;
            cout << "Error, Invalid input: " << line << endl; 
        }
            //cout << volume << "--" << center_x << "--" << center_y << "--" << min_x << "--" << max_x << "--" << min_y << "--" << max_y  << endl;
            records.insert(id, fov, volume, center_x, center_y, min_x, max_x, min_y, max_y);

        }
    //cout << records.print();
    }
    ofns.close();
    
}

// Do not modify
void CellDatabase::outputData(const string& filename) {
    ofstream dataout("sorted." + filename);

    if (!dataout.is_open()) 
    {
        cout << "Error: Unable to open " << filename << endl;
        exit(1);
    }
    dataout << records.print();
}

void CellDatabase::performQuery(const string& filename) 
{
    // Implement this function
    string file = filename;
    std::string line = "";
    /*
    cout << "HELLO" << endl;
    std::ifstream inff("result.data");
    while(getline(inff,line)){
        cout << line << endl;
    }
    inff.close();
    */
    
    std::ifstream infs(filename);
    // std::ofstream ofns;
    // ofns.open("result.data");
    std::ofstream ofns("result.data", std::ios_base::app);

    //cout <<records.print();
    while(getline(infs, line)){
        std::stringstream linestream(line);
        std::string firstWord = "";
        std::string value = "";
        int count = 0;
        int k = 0;
        int j = 0;
        int N = 0;
        
        linestream >> firstWord;
        if (firstWord != "AVG" && firstWord != "COUNT" && firstWord != "VAR" && firstWord != "OUTLIER"){
            cout << "Error, Invalid input: " << line << endl;
            ofns << "Error, Invalid input: " << line << endl;
        }

        getline(linestream, value, ' '); //taking out the blank space b/w firstWord and the rest of the input values
        while(getline(linestream, value, ' ')){
            
            if (firstWord == "AVG"){

                if (isIntNumber(value)){
                    //cout << "Value " << value << endl;
                    std::stringstream tempStream(value);
                    int temp = 0;
                    tempStream >> temp;
                    if (temp >= 0){
                        ofns << "AVG " << value << ": " << records.average(temp)<< endl;
                    }
                    else{
                        ofns << "Error, Invalid input: " << line << endl;
                    }
                    //cout << "AVG: " << value << ": " << records.average(temp)<< endl;
                }
                else{
                    ofns << "Error, Invalid input: " << line << endl;
                }
            }
            else if (firstWord == "VAR"){
                // cout << "VAR: " << value << ": " << records.variance(stoi(value))<< endl;
                if (isIntNumber(value)){
                    double temp = records.variance(stoi(value));
                    if (temp >= 0){
                        ofns << "VAR " << value << ": " << temp << endl;
                    }
                    else{
                        ofns << "Error, Invalid input: " << line << endl;
                    }
                }
                else{
                    ofns << "Error, Invalid input: " << line << endl;
                }
                //ofns << "VAR " << value << ": " << records.variance(stoi(value))<< endl;
            }
            else if (firstWord == "COUNT"){
                // cout << "RUN2" << endl;
                // cout << "COUNT " << value << ": " << records.countN(stoi(value))<< endl;
                if (isIntNumber(value)){
                    int temp = records.countN(stoi(value));
                    if(temp >= 0){
                        ofns << "COUNT " << value << ": " << temp << endl;
                    }
                    else{
                        ofns << "Error, Invalid input: " << line << endl;
                    }
                    //ofns << "COUNT " << value << ": " << records.countN(stoi(value))<< endl;
                }  
                else{
                    ofns << "Error, Invalid input: " << line << endl;
                }  
            }
            
            else if (firstWord == "OUTLIER"){
                
                if (isIntNumber(value)){ 
                    if(count == 0){k = stoi(value);}
                    if(count == 1){j = stoi(value);}
                    if(count == 2){
                        N = stoi(value);
                        if (k >= 0 && j >= 0 && N >= 0){
                            ofns << "OUTLIER " << k << " " << j << " " << N << ": " << records.outliers(k, j, N) << endl;
                        }
                        else{
                            ofns << "Error, Invalid input: " << line << endl;
                        }
                        // cout << "OUTLIER " << k << " " << j << " " << N << ": " << records.outliers(k, j, N) << endl;
                        
                    }
                }
                else{
                    ofns << "Error, Invalid input: " << line << endl;
                }
                
            }
            count++;
        }
    }
    ofns.close();
}
