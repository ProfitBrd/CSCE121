#include <iostream>
#include <string>
#include "./string_calculator.h"

using std::cout;
using std::endl;
using std::string;

unsigned int digit_to_decimal(char digit) {
    if (static_cast<int>(digit) >= 48 && static_cast<int>(digit) <= 57){
        return static_cast<int>(digit) - 48; //RETURNS ASCII VALUES, but they start at 48
    }
    throw std::invalid_argument("NOT 0-9");
}

char decimal_to_digit(unsigned int decimal) {
    if (!(decimal / 10)){
        return static_cast<char>(decimal+48);
    }
    throw std::invalid_argument("More than one digit");
    
}

string trim_leading_zeros(string num) {

    int count = 0;
    int temp = num.length();
    string answer = "";
    if (num.at(0) == '-'){  //checking for negative
        count++;
        answer += '-';
    }
    while(num.at(count) == '0'){ //skipping over zeros
        if ((count == temp - 1) && (num.at(count == '0'))){
            return ("0");
        }
        count++;
    }
    while(count < temp){ //making new characters after leading zeros
        answer += num.at(count);
        count++;
    }
    return answer;
}

string add(string lhs, string rhs) {
    const int ARRAYLENGTH = 500;
    int returnValue[ARRAYLENGTH];
    for(int i = 0; i < ARRAYLENGTH; i++){ //sets all of array = 0
        returnValue[i] = 0;
    }

    int addingTensOrNot = 0;
    int countRight = rhs.length() - 1; //see when array accessing needs to stop
    int countLeft = lhs.length() - 1; //see when array accessing needs to stop
    bool bothNegative = false;

    //adding
    if ((lhs.at(0) == '-' && rhs.at(0) != '-') || (lhs.at(0) != '-' && rhs.at(0) == '-')){ //edge case where one is negative but the other isn't
        return "";
    }

    if(lhs.at(0) == '-' && rhs.at(0) == '-'){ //both negative, replace value with 0 and save for later
        lhs.replace(0, 1, "0");
        rhs.replace(0,1,"0");
        bothNegative = true;
    }

    for (int i = ARRAYLENGTH-1; i >= 0; i--){
        
        if (countLeft >= 0 && countRight >= 0){
            int preAddingNumber = addingTensOrNot + (digit_to_decimal(lhs.at(countLeft)) + digit_to_decimal(rhs.at(countRight)));
            //cout << addingTensOrNot + digit_to_decimal(lhs.at(countLeft)) + digit_to_decimal(rhs.at(countRight)) << endl;
            int addingNumber = preAddingNumber % 10;
            returnValue[i] = addingNumber;
            if ((preAddingNumber/10) >= 1){
                addingTensOrNot = 1;
            }
            else{
                addingTensOrNot = 0;
            }
        }

        else if (countLeft >= 0){
            if (addingTensOrNot + digit_to_decimal(lhs.at(countLeft)) >= 10){
                returnValue[i] += (addingTensOrNot + digit_to_decimal(lhs.at(countLeft)))%10;
                returnValue[i-1] += 1;
            }
            else{
                returnValue[i] += addingTensOrNot + digit_to_decimal(lhs.at(countLeft));
            }
            addingTensOrNot = 0;
        }

        else if (countRight >= 0){
            if (addingTensOrNot + digit_to_decimal(rhs.at(countRight)) >= 10){
                returnValue[i] += (addingTensOrNot + digit_to_decimal(rhs.at(countRight)))%10;
                returnValue[i-1] += 1;
            }
            else{
                returnValue[i] += addingTensOrNot + digit_to_decimal(rhs.at(countRight));
            }
            addingTensOrNot = 0;
        }

        //we can't add tens to a number, so if they both equal zero and you need to add ten
        if (addingTensOrNot == 1 && countLeft == 0 && countRight == 0){
            returnValue[i-1] += 1;
        }
        countRight--;
        countLeft--;
        
    }
     
    //PRINTING
    string answer = "";
    if (bothNegative == true){
        answer += '-';
    }
    for (int i = 0; i < ARRAYLENGTH; i++){
        answer += (decimal_to_digit(returnValue[i]));
    }
    
    return trim_leading_zeros(answer);
}

string multiply(string lhs, string rhs) {
    const int ARRAYLENGTH = 1000;
    int returnValue[ARRAYLENGTH];
    for(int i = 0; i < ARRAYLENGTH; i++){ //sets all of array = 0
        returnValue[i] = 0;
    }

    int countLeft = lhs.length() - 1; //see when array accessing needs to stop
    bool oneNegative = false;

    
    //checking if one or both are negative
    if(lhs.at(0) == '-' && rhs.at(0) == '-'){
        lhs.replace(0, 1, "0");
        rhs.replace(0,1,"0");
    }
    else if(lhs.at(0) == '-'){ 
        lhs.replace(0, 1, "0");
        oneNegative = true;
    }
    else if (rhs.at(0) == '-'){
        rhs.replace(0, 1,"0");
        oneNegative = true;
    }


    //multiplying
    for (int i = ARRAYLENGTH - 1; i >= ARRAYLENGTH/2; i--){
        int countRight = rhs.length() - 1; //see when array accessing needs to stop
        for (int j = ARRAYLENGTH - 1; j >= ARRAYLENGTH/2; j--){
            
            if (countRight < 0){
                break;
            }
            returnValue[i + j - 999] += (digit_to_decimal(rhs.at(countRight)) * digit_to_decimal(lhs.at(countLeft))); //getting the value of multipliction   
            if (returnValue[i + j - 999] >= 10) { //rechecking to see if there is a double digit number
                returnValue[i + j - 1000] += returnValue[i + j - 999] /10; //adding the tens place
                returnValue[i + j - 999] = returnValue[i + j - 999] %10; //adding the ones place
            }
            countRight--; //subtracting one from the top to get multiplied by the one number on the bottom
        }
        countLeft--;
        if (countLeft < 0){
            break;
        }
         //subtracting one from the bottom to multiply by everything on the top again
    }
     
    //PRINTING
    string answer = "";
    if (oneNegative == true){
        answer += '-';
    }
    for (int i = 0; i < ARRAYLENGTH; i++){
        answer += (decimal_to_digit(returnValue[i]));
    }
    //cout << "ANSWER " << answer << endl;
    /*for (int i = 0; i < ARRAYLENGTH; i++){
        cout << returnValue[i] << endl;
    }*/
    
    return trim_leading_zeros( answer);
}
