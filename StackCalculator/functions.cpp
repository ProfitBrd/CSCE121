#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  
  if (stack.capacity == stack.count){
    int* ptr = new int[stack.capacity * 2];
    for (int i = 0; i < stack.capacity; i++){
      ptr[i] = stack.numbers[i];
    }

    delete stack.numbers;
    stack.numbers=ptr;
    //ptr = nullptr;
    stack.capacity = stack.capacity * 2;
  }
  stack.numbers[stack.count] = number;
  stack.count = stack.count+ 1;
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  if (stack.count == 0){
    return INT32_MAX;
  }
  int returnV = stack.numbers[stack.count - 1];
  stack.count = stack.count - 1;
  
  
  return returnV;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  if (stack.count == 0){
    return INT32_MAX;
  }
  int returnV = stack.numbers[stack.count - 1];
  
  
  return returnV;
  return 0;
}
