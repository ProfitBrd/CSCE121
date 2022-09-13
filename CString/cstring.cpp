#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  //return str.size();
  int count = 0;
  char i = str[0];
  while (i != '\0'){
    i = str[count+1];
    count++;
  }
  return count;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  int index = 0;
  for (int i = 0; i < length(str); i++){
    if (str[i] == character){
      return index;
    }
    index++;
  }
  return length(str);
  
  return 0;
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  int betterLength;
  if (length(str1) < length(str2)){
    betterLength = length(str2);
  }
  else{
    betterLength = length(str1);
  }
  for (int i = 0; i < betterLength; i++){
    if (str1[i] != str2[i]){
      return false;
    }
  }
  return true;
}