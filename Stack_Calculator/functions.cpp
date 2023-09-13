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
  if(stack.count == stack.capacity) {
    int* temp = new int[stack.capacity * 2];
    for (int i = 0; i < stack.capacity; i++) {
      temp[i] = stack.numbers[i];
    }
    delete [] stack.numbers;
    stack.numbers = temp;
    stack.capacity *= 2;
  }
  stack.numbers[stack.count] = number;
  stack.count++;

  INFO_STRUCT(stack);
  INFO(number);
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  int poppedNum = 0;
  if(stack.count == 0) {
    return INT32_MAX;
  }  
  else {
    poppedNum = stack.numbers[stack.count - 1];
    stack.count--;
  }
  INFO_STRUCT(stack);
  return poppedNum;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  int poppedNum = stack.numbers[stack.count - 1];
  INFO_STRUCT(stack);
  return poppedNum;
}
