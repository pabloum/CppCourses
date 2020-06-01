#include <iostream>

int main(int argc, char const *argv[]) {

  const int sizeArrays = 5;

  int myArray[] = {1,2,3,4,5};

  int mArray2[sizeArrays];
  mArray2[0] = 1;
  mArray2[1] = 2;
  mArray2[2] = 3;
  mArray2[3] = 4;
  mArray2[4] = 5;

  *(myArray + 1) = 99; // myArray[1] = 99;

  int* dynamicNumbers = new int[sizeArrays];
  dynamicNumbers[0] = 1;
  dynamicNumbers[1] = 2;
  dynamicNumbers[2] = 3;
  dynamicNumbers[3] = 4;
  dynamicNumbers[4] = 5;

  // only works on trivial code.
  int localSize = sizeof(dynamicNumbers) / sizeof(dynamicNumbers[0]); // works on the stack
  int freeSize = sizeof(dynamicNumbers) / sizeof(dynamicNumbers[0]); // doesnt work on the heap

  delete[] dynamicNumbers;

  int myArray[] = {1,2,3,4,5};
  char* myString;

  return 0;
}
