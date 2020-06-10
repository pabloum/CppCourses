#include <iostream>
#include <vector>
#include <string>

void explanation() {
  std::cout << "This is the explanation \n\n";
  std::string     name = "Pablo";
  std::string greeting = "Hello, " + name;

  auto stringLength = greeting.length();
  auto foundSpace   = greeting.find(" ");
  auto substr       = greeting.substr(foundSpace);

  std::cout << greeting << '\n';
  std::cout << "The length of the greeting is " << stringLength << '\n';
  std::cout << "The found space is: " << foundSpace << '\n';
  std::cout << "The found substr was: " << substr << '\n';
}

void exercise() {
  // Write a programm that asks the user for 2 words and tells them which is longer.
  std::cout << "This is the exercise \n\n";

  std::string s1, s2;

  std::cout << "Please, insert the first string: ";  getline(std::cin, s1);

  std::cout << "Please, insert the second string: "; getline(std::cin, s2);

  int length1 = s1.length();
  int length2 = s2.length();

  if (length1 > length2) {
    std::cout << "The first strign is longer \n";
  } else if (length1 < length2) {
    std::cout << "The second strign is longer \n";
  } else {
    std::cout << "Both strings have the same length \n";
  }

  // std::cout << s1 << " " << length1 << '\n';
  // std::cout << s2 << " " << length2 << '\n';

}

int main(int argc, char const *argv[]) {

  // explanation();
  exercise();

  return 0;
}
