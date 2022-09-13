#include <iostream>
#include <iomanip>
#include <string>
#include "parallel_tracks.h"
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

using std::string;
using std::cin; using std::cout; using std::endl;
using std::string; using std::getline; using std::ifstream;
using std::invalid_argument; using std::domain_error;
const int LENGTH = 9;
bool validInfo;

bool is_valid_number(const std::string& str){
	string numberList = "1234567890";
	bool itsValid = false;
	//checks every value in the string 
	for (int i = 0; i < str.length(); i++){
		for (int j = 0; j < numberList.length(); j++){
			if (str[i] == numberList[j]){
				itsValid = true;
			}
		}
		if (itsValid == false){
			return false;
		}
		itsValid = false; //resetting variable
	}
	return true;
}


bool is_valid_time(const std::string& str){
	int count = 0;
	int wholeNumberCount = 0;
	int decimalCount = 0;
	//if its negative, its not a valid number
	if (str.at(0) == '-'){
		return false;
		count++;
	}
	for (int i = count; i < str.length(); i++){
		string temp = "";
		temp += str[i]; //appending char to a temporary string so we can check it with is_valid_number, which only accepts a string
		if (str[i] == '.'){ //if it has a decimal
			decimalCount++;
		}
		else if(is_valid_number(temp)){ //if it is a real number
			wholeNumberCount++;
		}
		else{
			return false;
		}
	}
	if (wholeNumberCount <= 0 || decimalCount > 1){
		return false;
	}
	return true;

}

bool is_valid_country(const std::string& str){
	if (str.length() != 3){
		return false;
	}
	for (int i = 0; i < 3; i++){
		int temp = str.at(i);
		if ( !( temp <= 90 && temp >= 65 )  ){ //ASCII Values 65 -> 90 for 'A' -> 'Z' ----- Saying if the variable is not in the ASCII variable range return false
			return false;
		}
	}
	return true;
}

bool is_valid_name(const std::string& str){
	if(str.length() <= 1){
		return false;
	}
	for (int i = 0; i < str.length(); i++){
		int temp = str.at(i);
		//cout << temp << endl;
		if ( !( (temp <= 90 && temp >= 65) || (temp <= 122 && temp >= 97) || (temp == 32)  )  ){ //ASCII Values 65 -> 90 for 'A' -> 'Z' || 97 -> 122 for 'a' -> 'z' || space (" ") -> 32  ----- Saying if the variable is not in the ASCII variable range return false
			return false;
		}
	}
	return true;
}


//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays , and a legit filename is pass
// PostCondition: all arrays contain data from the csv file given
//---------------------------------------------------------
void get_runner_data( const std::string& file, double timeArray[], std::string countryArray[], 
		unsigned int numberArray[], std::string lastnameArray[]) 
{
	//validInfo = true;
	string fileName = file;
	
	ifstream infs (fileName );
	validInfo = true;
	
	//checking if valid file name
	//cout << infs.is_open() << endl;
	try{
		if (!infs.is_open()){
			throw std::invalid_argument("Invalid File: Cannot Open File");
		}
	}
	catch(std::invalid_argument &excpt){
		cout << excpt.what() << endl;
		validInfo = false;
	}
	
	
	//-----------------------------------------
	
	string line = "";
	double time = 0;
	string strTime = "";
	string country = "";
	int number = 0;
	string strNumber = "";
	string name = "";

	int i = 0;
	bool priorValidInfo = true; //both true until given a reason not to be
	bool anotherValidInfo = true;
	/*
	if (infs.is_open()){
		infs >> time >> country >> number >> name;
	}
	cout << time << country << number << name;
	*/
	if (infs.is_open()){
		try{
			while (getline(infs, line)){
				//cout << line.length() << endl;
				if (line.length() == 1){ //if nextline empty
					throw std::domain_error("Invalid File: File missing data");
				}
			}
		}catch(std::domain_error &excpt){
				cout << excpt.what() << endl;
				validInfo = false;
				priorValidInfo = false;
		}
	}
	
	//resets the file to be read again
	infs.clear();
	infs.seekg(0, infs.beg);

	//rest of the error cases
	if (infs.is_open()){
		while (i < 9){
			infs >> strTime >> country >> strNumber >> name;

			//cout << "TIME: " << strTime << "  " << "COUNTRY: " << country <<"NUMBER: " << number << "NAME: " << name << endl;
			try{
				
				if (!is_valid_time(strTime)){
					throw std::domain_error("Invalid File: File contains invalid data (time)");
				}
				time = std::stod(strTime); // assignes double time with the double value of string strTime
				if (!is_valid_country(country)){
					throw std::domain_error("Invalid File: File contains invalid data (country)");
				}
				else if (!is_valid_number(strNumber)){
					throw std::domain_error("Invalid File: File contains invalid data (number)");
				}
				number = std::stoi(strNumber); //assignes int number with the int value of string strNumber
				if(!is_valid_name(name)){
					throw std::domain_error("Invalid File: File contains invalid data (name)");
				}

			}catch(std::domain_error &excpt){
				cout << excpt.what() << endl;
				anotherValidInfo = false;
			}
			

			//cout << "PRIOR " << priorValidInfo << " ANOTHER " << anotherValidInfo << endl;
			if (priorValidInfo && anotherValidInfo){ //if above function says the file is valid and none of the functions throw errors
				validInfo = true;
			}
			else{ //above function says file is invalid
				validInfo = false;
			}
			


			//appending the values to strings
			timeArray[i] = time;
			countryArray[i] = country;
			numberArray[i] = number;
			lastnameArray[i] = name;
			
			i++; //increment to move to the next line of values
		}
	
	}

	//resets file to be read again
	infs.clear();
	infs.seekg(0, infs.beg);
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
	
  	for (int i = 0; i < LENGTH; i++){
	  	ary[i] = 0.0;
  	}
}

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  a double arrays is pass in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
	for (int i = 0; i < LENGTH; i++){
		ary[i] = 0;
	}
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  a string arrays is pass in
// PostCondition: data in the array is "N/A" out to determine if
// a value has changed
//---------------------------------------------------------
void prep_string_array(std::string ary[])
// making sure all values within the array are set to "N/A";
{
	for (int i = 0; i < LENGTH; i++){
		ary[i] = "N/A";
	}
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	
	for (int i = 0; i < LENGTH; i++){
		int placing = 1;
		for (int j = 0; j < LENGTH; j++){
			if (timeArray[j] < timeArray[i]){
				placing++;
			}
		}
		rankArray[i] = placing;
	}
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  almost all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays then along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const std::string countryArray[],
		const std::string lastnameArray[], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}

std::string trim(const std::string word) {
	string ret = word;

	// remove whitespace from the beginning
	while (!ret.empty() && isspace(ret.at(0))) {
			ret.erase(0, 1);
		}

	// remove whitespace from the end
	//  Note: last index is (.size() - 1) due to 0 based indexing
	while (!ret.empty() && isspace(ret.at(ret.size()-1))) {
		ret.erase(ret.size()-1, 1);
	}
	
	return ret;
}

bool returnValidInfo(){
	return validInfo;
}