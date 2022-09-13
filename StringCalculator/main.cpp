#include <iostream>
#include <string>
#include <limits>
#include <sstream>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::istringstream;


int main() {
    cout << "String Calculator" << endl;
    cout << "\"q\" or \"quit\" or ctrl+d to exit" << endl;
    cout << ">>";
    string line = "";
    string firstNumber = "";
    string operation = "";
    string secondNumber = "";
    istringstream inSS;
    // TODO(student): implement the UI
    while (true){
        getline(cin, line);
        inSS.clear(); //clear buffer each time
        inSS.str(line);

        inSS >> firstNumber;

        if (firstNumber == "q" || firstNumber == "quit"){
            cout << endl << "farvel!" << endl << endl;
            break;
        }

        else{
            inSS >> operation;
            inSS >> secondNumber;
        }
        if (operation == "+"){
            cout << endl << "ans =" << endl << endl << "    " << add(firstNumber, secondNumber) << endl << endl << ">>";
        }
        if (operation == "*"){
            cout << endl << "ans =" << endl << endl << "    " << multiply(firstNumber, secondNumber) << endl << endl << ">>";
        }
    }
    return 0;

    //cout << firstNumber << operation << secondNumber <<endl;
    //cout << trim_leading_zeros("-000889") << endl;
}

