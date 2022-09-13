/*
#include <iostream>
#include <fstream>
#include <string>

using std::cout;
using std::endl;
using std::ifstream;
using std::string;


int main(){
    ifstream infs ("easy1.txt");

    if ( infs.is_open() ){
    char one; //if = 0, bad
    char two;
    char three; //check if >= maxcol, less than 0
    char four;
    int oneButInt;
    int twoButInt;
    int threeButInt;
    int fourButInt;

    infs >> one >> two >> three >> four;
    if (one == '-' || two == '-' || three == '-' || four == '-'){
        //return nullptr
        cout << "NO" << endl;
    }
    else{
        oneButInt = one - 48;
        twoButInt = two - 48;
        threeButInt = three - 48;
        fourButInt = four - 48;
    }

    cout << oneButInt  << " " << twoButInt  << " " << threeButInt  << " " << fourButInt << endl;
    }
    else{
        cout << "help" << endl;
    }
    return 0;
}
*/