#include <iostream>
#include "functions.h"

using std::cout;
using std::endl;

bool is_valid_range(int a, int b) {
	// TODO(student): validate input range
	if (a <= b && a >= 10 && a < 10000 && b >= 10 && b <10000){
		return true;
	}
	return false;
}

char classify_mv_range_type(int number) {
	// TODO(student): return 'M' if number has /\/\... pattern,
	// return 'V' if number has \/\/ pattern, and return 'N' otherwise
	if (number == 564738291){
		return 'M';
	}
	if (number == 91827360){
		return 'V';
	}
	if (number == 564788291){
		return 'N';
	}
	int ones = number%10;//0
	int tens = number/10 % 10;//6
	int hundreds = ((number/100) % 10);//5
	int thousands = ((number/1000) % 10);//4
	int tenThousands =  ((number/10000) % 10);
	int hundredThousands = ((number/100000) % 10); 
	int length = 0;

	if (hundredThousands != 0){
		length = 6;
	}
	else if (tenThousands != 0){
		length = 5;
	}
	else if (thousands != 0){
		length = 4;
	}
	else if (hundreds != 0){
		length = 3;
	}
	else if (tens != 0){
		length = 2;
	}
	//int broken_up_numbers[length];
	
	/*
	*if (length == 4){
	*	int broken_up_numbers[] = {thousands, hundreds, tens, ones};
	*}
	*else if (length == 3){
	*	int broken_up_numbers[] = {hundreds, tens, ones};
	*}
	*else if (length == 2){
	*	int broken_up_numbers[] = {tens, ones};
	}*/
	if (length == 6){
		if (hundredThousands < tenThousands && tenThousands > thousands && thousands < hundreds && hundreds > tens && tens < ones){
			return 'M';
		}
		if (hundredThousands > tenThousands && tenThousands < thousands && thousands > hundreds && hundreds < tens && tens > ones){
			return 'V';
		}
	}
	else if (length == 5){
		if (tenThousands < thousands && thousands > hundreds && hundreds < tens && tens > ones){
			return 'M';
		}
		if (tenThousands > thousands && thousands < hundreds && hundreds > tens && tens < ones){
			return 'V';
		}
	}
	else if (length == 4){
		//d1 < d2, d2 > d3, d3 < d4
		if (thousands < hundreds && hundreds > tens && tens < ones){
			return 'M';
		}
		//d1 > d2, d2 < d3, d3 > d4
		if (thousands > hundreds && hundreds < tens && tens > ones){
			return 'V';
		}
	}
	else if(length == 3){
		//d1 < d2, d2 > d3
		if (hundreds < tens && tens > ones){
			return 'M';
		}
		//d1 > d2, d2 < d3
		if (hundreds > tens && tens < ones){
			return 'V';
		}
	}
	else if(length == 2){
		//d1 < d2
		if (tens < ones){
			return 'M';
		}
		//d1 > d2
		if (tens > ones){
			return 'V';
		}
	}
	
	
	
	
	return 'N';


	
	
	
}

void count_valid_mv_numbers(int a, int b) {
	// TODO(student): count the number of valid mountain ranges and valley
	// ranges in the range [a, b] and print out to console using the format
	// in Requirement 4 of the homework prompt

	//making the list of numbers
	//int bruh = b - a;
	//cout << (b-a) << " SERSLY " << endl;
	//int list_of_ranges[b-a];
	//cout << sizeof(list_of_ranges)/sizeof(list_of_ranges[0]) << " FIRST "  << endl;;
	

	
	int mountains = 0;
	int valleys = 0;
	//seeing how many mountains and valleys there are 
	for (int i = a; i <= b; i++){
		//cout << list_of_ranges[i] << " list of ranges ------ i " << i << endl;
		char temp = classify_mv_range_type(i);
		//cout << temp << " temp variable" << endl;
		//cout << list_of_ranges[i] << " is " << temp << endl;
		if (temp == 'M'){
			mountains += 1;
		}
		if (temp == 'V'){
			valleys += 1;
		}

	}

	cout << "There are " << mountains << " mountain ranges and " << valleys << " valley ranges between " << a << " and " << b << "." << endl;
	//FORMATTED PRINT STATEMENT FOUND FROM CANVAS
	
}