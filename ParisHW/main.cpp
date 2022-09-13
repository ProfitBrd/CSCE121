/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele

Data File Information
name: data.csv
content: The csv file will contain data in the constant form of:
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/
#include <fstream>
#include <sstream>
#include <iostream>
#include "parallel_tracks.h"

const int LENGTH = 9;
using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error;

int main()
{
    // TODO: create arrays needed
	double timeArray[LENGTH];
    unsigned int numberArray[LENGTH];
    string lastNameArray[LENGTH];
    string countryArray[LENGTH];
    unsigned int rankArray[LENGTH];


    // TOTO: prep all arrays
    prep_double_array(timeArray);
    prep_unsigned_int_array(numberArray);
    prep_string_array(lastNameArray);
    prep_string_array(countryArray);
    prep_unsigned_int_array(rankArray);
    
    /*unsigned int newArray[LENGTH];
    prep_unsigned_int_array(newArray);
    get_ranking(doubleArray, newArray);
    for (int i = 0; i < LENGTH; i++){
        cout << newArray[i] << " ";
    }
    cout << endl;
    */
    
    //TESTING
    /*
    string hello = "ezZer erreraZA";
    bool h = is_valid_name(hello);
    cout << h << endl;
    */
	
    // TODO: prompt until both the file and the contained data are valid
    
	string fileName;
    do{
        try{
            cout << "Enter file name: ";
            cin >> fileName;

            //cout << is_valid_name("Payton ") << endl;
            get_runner_data(fileName, timeArray, countryArray, numberArray, lastNameArray);
            //cout << "validInfo "  << (returnValidInfo()) << endl;
        }catch(std::invalid_argument &excpt){
            cout << "Invalid File: ";
		    cout << excpt.what() << endl;
	    }catch(std::domain_error &excpt){
            cout << "Invalid File: ";
            cout << excpt.what() << endl;
        }
    }while(!returnValidInfo());
    
    if (returnValidInfo()){
        get_ranking(timeArray, rankArray);
        print_results(timeArray, countryArray, lastNameArray, rankArray);
    }

   


    /*while(true){
        try {
            break;
        }
        catch(){
            cout << "Invalid File";
        }
    }
    string fileName;
    string yeet;
    string nextLine = "";
    
    string name;
    string country;
    int number;
    double time;
    try{
    cout << "Enter File Name: " << endl;
    cin >> fileName;
    fileName = "bad_missing01.txt";
    ifstream infs(fileName);
    if (infs.is_open()){
        //infs >> time >> country >> number >> name;
        
	    getline(infs, nextLine);
	    if (nextLine.length() == 1){ //if nextline is empty
		    throw std::domain_error("File missing data");
	    }
    }
    cout << "HELP ME "  << nextLine << "HEllo1" << endl;
    
    }
    catch (...){
        cout << "Invalid_file" << endl; 
    }
    */
    //cin >> yeet;
    //get_runner_data(fileName, timeArray, countryArray, rankArray, lastNameArray);

    // TODO: determine ranking, notice the rank array receives the results

    // TODO: Output results

    return 0;
}

