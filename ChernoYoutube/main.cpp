#include<iostream>
#include<stdio.h>

void print(int a);
void LOG(std::string msg);

int& GetValue() {
  static int value = 5;
  return value;
}

void ShowValue(int& a) {
  std::cout << "This function only admits Lvalues: ";
  print(a);
}

void ShowValue(int&& a) {
  std::cout << "This function only admits Rvalues. ";
  print(a);
}

void ShowValue(const int& a) {
  std::cout << "This function admits Lvalues and Rvalues: ";
  print(a);
}

int main(int argc, char const *argv[]) {

  LOG("The initial value: ");
  print(GetValue());
  GetValue() = 1010;

  ShowValue(GetValue());          // This is sending Lvalue
  ShowValue(GetValue() + 20);     // This is sending Rvalue
  ShowValue(10);                  // This is sending Rvalue

  LOG("The final value: ");
  print(GetValue());          // This is sending Lvalue
  return 0;
}



void LOG(std::string msg) {
  std::cout << msg;
}

void print(int a) {
  std::cout << "The sent value is: " << a << '\n';
}
