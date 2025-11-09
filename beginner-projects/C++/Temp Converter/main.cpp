#include <iostream>

int main(){

    double temp;
    char unit;

    std::cout << "*****Temperature conversion program*****\n";
    std::cout << "F is farenheit\n";
    std::cout << "C is celsius\n";

    std::cout << "What unit would you like to convert to? ";
    std::cin >> unit;
    if (unit == 'F'|| unit == 'f')
    {
        std::cout << "Enter the tempertaure in celsius: ";
        std:: cin >> temp;

        temp = (1.8 * temp) + 32.0;
        std::cout << "Tempertaure in farenheit is: " << temp<<'\n';
    }
    else if (unit == 'C' || unit == 'c')
    {
        std::cout << "Enter the tempertaure in farenheit: ";
        std:: cin >> temp;

        temp = (temp - 32)/1.8; 
        std::cout << "Tempertaure in celsius is: " << temp<<'\n';
    }
    else{
        std::cout << "Please enter only C or F";
    }


    std::cout << "****************************************";

    return 0;
}
