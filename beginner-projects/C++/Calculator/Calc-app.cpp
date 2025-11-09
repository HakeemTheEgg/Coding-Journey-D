#include <iostream>

int main() {

    char op;
    double num1;
    double num2;

    std::cout << "******Calculator App*******\n\n";

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Enter the operator (+ - * /): ";
    std::cin >> op;

    switch (op) {
        case '+':
            std::cout << "result of " << num1 << " + " << num2 << " equals: " << num1 + num2;
            break;
        case '-':
            std::cout << "result of " << num1 << " - " << num2 << " equals: " << num1 - num2;
            break;
        case '*':
            std::cout << "result of " << num1 << " * " << num2 << " equals: " << num1 * num2;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Error: division by zero is not allowed";
            } else {
                std::cout << "result of " << num1 << " / " << num2 << " equals: " << num1 / num2;
            }
            break;
        default:
            std::cout << "invalid operator. Enter one of + - * /.";
            break;
    }

    std::cout << "\n****************************************";
    return 0;
}
