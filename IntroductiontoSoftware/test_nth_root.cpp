#include <iostream>
#include <cmath>
#include "./nth_root.h"
#include "test_helpers.h"

int main() {
    bool pass = true;
    {   // MINIMUM REQUIREMENT (for this lab)
        // just call the function with various values of n and x
        nth_root(2, 1);
        try{
            nth_root(0,4); //A YY
        }
        catch(std::domain_error &excpt){}

        try{
            nth_root(2,-1); //B YY
        }
        catch(std::domain_error &excpt){}
        try{
            nth_root(-1, 0); //C
        }
        catch(std::domain_error &excpt){}
        nth_root(1, 8); //D
        nth_root(-1, 8); //E
        nth_root(-6, 6); //F G
        nth_root(-4, 8); //H
        nth_root(6, 3); //I
        nth_root(4, 3); //J
        nth_root(3, 0); //K
        nth_root(15, 1); //L
        nth_root(3, -3); //M
        nth_root(3, 3); //N
        nth_root(4, 4.5); //O
        std::cout << std::endl;
        
    }

    {   // TRY HARD
        // report the value
        double actual = nth_root(2, 1);
        std::cout << "nth_root(2, 1) = " << actual << std::endl;
    }

    {   // TRY HARDER
        // compare the actual value to the expected value
        double actual = nth_root(2, 1);
        double expected = 1;
        if (std::fabs(actual - expected) > 0.00005) {
            std::cout << "[FAIL] (n=2, x=1)" << std::endl;
            std::cout << "  expected nth_root(2, 1) to be " << expected << std::endl;
            std::cout << "  got " << actual << std::endl;
        } else {
            std::cout << "[PASS] (n=2, x=1)" << std::endl;
        }
    }
}
