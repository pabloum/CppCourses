#include <iostream>

int main(int argc, char const *argv[]) {

  int numberToGuess = 7;
  bool keepgoing = true;

  while (keepgoing) {
    int numberGuessed;

    std::cout << "Enter your guess: ";
    std::cin >> numberGuessed;

    if (numberGuessed < numberToGuess) {
      std::cout << "You missed, your guess was below the given number, keep trying" << '\n';
    }
    else if (numberGuessed > numberToGuess) {
      std::cout << "You missed, your guess was above the given number, keep trying" << '\n';
    }
    else {
      std::cout << "Yesss!!!! your guessed. Game ended" << '\n';
      keepgoing = false;
    }
  }

  return 0;
}
