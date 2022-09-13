// Class file for Database class

#include "Database.h"

using std::string, std::vector;

// Constructor
// Constructor for Database class
// TODO(student): implement constructor using member initializer list
Database :: Database() : stateParkList({}), camperList({}) {}
// Mandatory
// Getter function for data member camperName
// Destructor
// DO NOT CHANGE, ALREADY IMPLEMENTED
Database::~Database() {
	for (unsigned int i = 0; i < stateParkList.size(); ++i) {
		delete stateParkList.at(i);
	}
	
	for (unsigned int i = 0; i < camperList.size(); ++i) {
		delete camperList.at(i);
	}
}

// Mandatory
// Dynamically creates a new state park and adds it to stateParkList
void Database::addStatePark(string parkName, double entranceFee, double trailMiles) {
	INFO(parkName)
	INFO(entranceFee)
	INFO(trailMiles)
	// TODO(student): implement function
	StatePark* newPark = new StatePark(parkName, entranceFee, trailMiles);
	stateParkList.push_back(newPark);
	//delete newPark;
	//return;
}

// Mandatory
// Dynamically creates a new passport and adds it to camperList
void Database::addPassport(string camperName, bool isJuniorPassport) {
	INFO(camperName)
	INFO(isJuniorPassport)
	// TODO(student): implement function
	Passport* newPass = new Passport(camperName, isJuniorPassport);
	camperList.push_back(newPass);
	//return;
}

// Mandatory
// Searches for a passport and state park whose name matches the given parameters and
// adds the park to the passport
void Database::addParkToPassport(string camperName, string parkName) {
	INFO(camperName)
	INFO(parkName)
	// TODO(student): implement function
	int shouldAdd = 0;
	int temp1 = 0;
	int temp2 = 0;

	int fixBCMimir = stateParkList.size();
	for(int i = 0; i < fixBCMimir; i++){
		if (stateParkList[i]->getParkName() == parkName){
			shouldAdd++;
			temp1 = i;
			//break;
		}
	}

	int fixBCMimir2 = camperList.size();
	for(int i = 0; i < fixBCMimir2; i++){
		if (camperList[i]->getCamperName() == camperName){
			shouldAdd++;
			temp2 = i;
			//break;
		}
	}

	if (shouldAdd == 2){
		camperList[temp2]->addParkVisited(stateParkList[temp1]);
	}
	//return;
}

// Option A
// Returns a vector of the names of all the parks whose revenue is between the parameters
// given (including the boundaries)
vector<string> Database::getParksInRevenueRange(double lowerBound, double upperBound) {
	INFO(lowerBound)
	INFO(upperBound)
	// TODO(student): implement function
	return {};
}
// Option B
// Returns a vector of the names of all the campers who have reached at least the hiking
// level given by the parameter
vector<string> Database::getHikersAtLeastLevel(int level) {
	INFO(level)
	// TODO(student): implement function
	return {};
}