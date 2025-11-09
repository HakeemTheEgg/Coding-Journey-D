#include <iostream>


int main() { 
    int num;
    int guess;
    int attempts = 0;

    srand(time( NULL));
    num = rand() % 100 + 1;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    do
    {
        std::cout << "Enter your guess (1-100): ";
        std::cin >> guess;
        attempts++;

        if (guess < num) {
            std::cout << "Too low! Try again" << std::endl;
        } else if (guess > num) {
            std::cout << "Too high! Try again" << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the number " << num << " in " << attempts << " attempts" << std::endl;
        }
    } while (guess != num);
    
    return 0;
}
