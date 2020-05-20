#include <iostream>
#include "interval_map.h"

void print_lowest();

int main(int argc, char const *argv[]) {

  interval_map <unsigned int, char> myUintCharMap ('F');
  myUintCharMap.assign(4,5,'Q');
  myUintCharMap.assign(8,12,'P');
  myUintCharMap.assign(15,24,'Q');
  myUintCharMap.assign(18,29,'R');
  myUintCharMap.assign(8,12,'R');
  // myUintCharMap.assign(8,12,'W');
  myUintCharMap.show();

  // interval_map <int, char> myIntCharMap ('F');
  // myIntCharMap.assign(-2147483645,-2147483641,'P');
  // myIntCharMap.show();

  // print_lowest();
  return 0;
}

void print_lowest() {
  std::printf("El int más bajo: %d\n", std::numeric_limits<int>::lowest());   // -2147483648
  std::printf("El unsigned int más bajo: %d\n", std::numeric_limits<unsigned int>::lowest());
  std::printf("El float más bajo: %f\n", std::numeric_limits<float>::lowest());
  std::printf("El double más bajo: %f\n", std::numeric_limits<double>::lowest());
  std::printf("El long double más bajo: %f\n", std::numeric_limits<long double>::lowest());
  std::printf("El char más bajo: %c\n", std::numeric_limits<char>::lowest());
}
