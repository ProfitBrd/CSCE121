#include <iostream>
#include "functions.h"

using std::cout;
using std::cin;
using std::endl;



//---------------------------------------------------------------------


//---------------------------------------------------------------------

int main() {
	int firstNumber;
	int secondNumber;
	// TODO(student): print prompt for input
	do {
		cout << "Enter numbers 10 <= a <= b < 10000: ";
		cin >> firstNumber;
		cin >> secondNumber;

		if (!(is_valid_range(firstNumber, secondNumber))){
			cout << "Invalid Input" << endl; //MIGHT NEED TO ADD ANOTHER cout << endl HERE <-------------------------------------------
		}
	}
	while (!(is_valid_range(firstNumber, secondNumber)));
	//cout << firstNumber << "  " << secondNumber << endl;

	// TODO(student): validate input (and reprompt on invalid input)
	
	// TODO(student): compute and display solution
	count_valid_mv_numbers(firstNumber, secondNumber);

	return 0;

}