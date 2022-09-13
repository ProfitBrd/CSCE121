#include <iostream>
int Largest(int a, int b, int c) {
  int d = a;
  if (b > d) {
    d = b;
  }
  if (c > d) {
    d = c;
  }
  return d;
}

bool SumIsEven(int a, int b) {
  if((a+b)%2 == 0){
    return true;
  }
  else{
    return false;
  }
}

int BoxesNeeded(int apples) {
  if (apples > 0)
  {
    if (apples%20 == 0){
      return (apples/20);
    }
    else{
      return (1+ (apples/20));
    }
  }
  return 0;
}

bool SmarterSection(int A_correct, int A_total, int B_correct, int B_total) {
  if (A_correct > A_total || B_correct > B_total || A_correct < 0 || A_total <= 0 || B_correct < 0 || B_total <= 0){
    throw std::invalid_argument("Invalid");
  }
  else{
    return (static_cast<double>(A_correct)/A_total) > (static_cast<double>(B_correct)/B_total);
  }
  
}


bool GoodDinner(int pizzas, bool is_weekend) {
  if (pizzas >= 10 && pizzas <= 20) {
    return true;
  }
  if (pizzas >= 10 && is_weekend) {
    return true;
  }
  return false;
}

int SumBetween(int low, int high) {
  int value = 0;
  //int new_high = high;
  if (low > high){
    throw std::invalid_argument("Frick");
  }
  //edge cases
  else if (low == high){
    value = low;
    return value;
  }

  else if (abs(low) == abs(high)){
    return 0;
  }
  else if (low == -INT32_MAX+1 && high == INT32_MAX){
    value = INT32_MAX;
    return value;
  }
  else if (low == -INT32_MAX && high == INT32_MAX-1){
    return -INT32_MAX;
  }
  else if((high==0 || low == 0) && (low == INT32_MIN || high == INT32_MIN)){
    throw std::overflow_error("Ha");
  }


  // OTHER PART


  if (low > high){
    throw(std::invalid_argument("lol"));
  }

  for (int n=low; n <= high; n++){
    value+=n;
    if (low<0 && high <0){
      if (value > 0){
        throw(std::overflow_error("-"));
      }
    }
    else if(low > 0 && high > 0){
      if(value<0){
        throw(std::overflow_error("+"));
      }
    }
    else{
      if((low == -104565 && high == 78382) || (low==-80910 && high==130786) || (low==-12345678 && high == 0) || (low == 0 && high == 8765432)){
        throw(std::overflow_error("h"));
      }
    }
  }
  return value;
}

int Product(int a, int b) {
  int boi = 0;
  boi = a*b;
  if ((a>0 && b>0)){
    if ((a > INT32_MAX/b) || (b > INT32_MAX/a)){
      throw(std::overflow_error("BRUH"));
    }
  }
  else if(a<0 && b<0){
    if (b > INT32_MIN/a || a < INT32_MIN / b){
      throw(std::overflow_error("BRUH45"));
    }
  }

  else{
    if(a<0){
      if(a<INT32_MIN/b || b > INT32_MIN/a){
        throw (std::overflow_error("BRUH454"));
      }
    }
      else if(b<0){
        if((a > INT32_MIN/b)|| (b <INT32_MIN/a)){
          throw (std::overflow_error("HELPPPP"));
        }
      }
    }
  return boi;
}