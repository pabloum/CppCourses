#include <iostream>
#include <vector>
#include <algorithm>

// Macros
#define SQ(a) (a)*(a)
#define ARRAY_SIZE 5

// typedef
typedef std::vector<int> VectorOfInt;

// Function pointer

int addition(int a, int b) { return a+b; }
int substraction(int a, int b) { return a-b; }
typedef int (*operation)(int a, int b);

// ---

int main(int argc, char const *argv[]) {

  int myArray[ARRAY_SIZE]  = {1,2,3,4,5};
  VectorOfInt vector = {6,7,8,9,10};

  for (auto &vble : myArray) {
    std::cout << "The square is: " << SQ(vble) << '\n';
  }

  std::for_each(vector.begin(), vector.end(), [](const int& position) {
    std::cout << "My VectorOfInt position: " << position << '\n';
  });


  operation op = addition;
  int resultAddition = 0;
  for (int i = 0; i < ARRAY_SIZE; i++)
    resultAddition = op(myArray[i],resultAddition);

  int resultSubstraction = 0;
  op = substraction;
  for (int i = 0; i < ARRAY_SIZE; i++)
    resultSubstraction = op(myArray[i],resultSubstraction);

  std::cout << "The result of the addition was: " << resultAddition << '\n';
  std::cout << "The result of the substraction was: " << resultSubstraction << '\n';

  op = addition;

  return 0;
}

/*
OUTPUT:

The square is: 1
The square is: 4
The square is: 9
The square is: 16
The square is: 25
*/
