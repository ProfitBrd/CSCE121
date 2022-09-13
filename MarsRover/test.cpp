#include <iostream>
#include "MyString.h"
using namespace std;

int main(){
    char* test1 = new char[7]{'c', 'h', 'e', 'r', 'r', 'y', '\0'};
    char* test2 = new char[4]{'y', 'r', 'r', '\0'};
    char* test3 = new char[2]{'g', '\0'};

    MyString bruh1(test1);
    MyString bruh2(test2);
    MyString bruh3(test3);
    


    cout << bruh1 << endl;
    size_t x = bruh1.find(bruh2, 0);
    cout << x << endl;
    /*
    bruh1 += bruh2;

    cout << "SIZE: " << bruh1.size() << endl;
    cout << "CAPACITY: " << bruh1.capacity() << endl;
    for (int i = 0; i < bruh1.length(); i++){
        cout << i << " " << bruh1.data()[i] << " ";
    }
    cout << "--------------" << endl;
    */

}