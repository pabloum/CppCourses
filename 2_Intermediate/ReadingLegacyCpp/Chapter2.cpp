#include <iostream>
#include <cstring>

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

  //  warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]
  // it need to be const
  char const* myString = "Hello, this is a C-style string";
  int myStringLength = strlen(myString);

  // Bug here. No room for null character \0
  // comment all s2 if runtime error is generated
  char* s2 = new char[strlen(myString) + strlen(" Prüfung")];

  strcpy(s2, myString);
  strcat(s2, " Prüfung");

  std::cout << s2 << std::endl;

  // comment all hello if runtime error is generated
  // Bug here. No room for null character \0
  char hello[] = {' ', 'h', 'e', 'l', 'l', 'o'};
  size_t helloLength = strlen(hello);

  // THis works fine. Please avoid previous declarations
  char better[] = "Much better declaration";

  std::string s(better);
  s += " modern C++";

  char *s3 = new char[s.length() + 1]; // room for null character
  strcpy(s3, s.c_str());
  // We CAN'T use operator=, because they are POINTERS. If you try to make it equal to something, you're just changing the pointer

  std::cout << s3 << std::endl;

  delete[] s2;
  delete[] s3;

  return 0;
}
