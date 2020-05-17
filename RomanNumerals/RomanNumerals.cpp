// RomanNumerals.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "NumberConverter.h"


int main()
{
    std::string userInput;
    std::cout << "Roman Numeral to Decimal application by Graham R. Armstrong. (2020-05-17)\n\n";
    std::cout << "I've tried to avoid faff with unicode so, in this program:\n";
    std::cout << "  W =  5,000\n";
    std::cout << "  Q = 10,000\n";
    while (userInput != "q" || userInput != "Q")
    {
        std::cout << "\nHi, please employ me by selecting a mode!\n";
        std::cout << "  A: Convert Roman Numeral to decimal number\n";
        std::cout << "  B: Convert decimal number to Roman Numeral\n";
        std::cout << "What would you like to do? (A or B, Q to quit): ";
        getline(std::cin, userInput);

        if (userInput == "A" || userInput == "a")
        {
            // Mode A: Roman Numeral to Decimal
            std::cout << "Please enter a valid Roman Numeral string: ";
            getline(std::cin, userInput);
            int result = NumberConverter::RomanToDecimal(userInput);
            if (result == -1)
            {
                std::cout << "Sorry but '" << userInput << "' doesn't seem to be a valid Roman Numeral\n";
            }
            else
            {
                std::cout << "RomanToDecimal: " << result << "\n";
            }
        }
        else if (userInput == "B" || userInput == "b")
        {
            // Mode B: Decimal to Roman Numeral
            std::cout << "Please enter a valid decimal: ";
            getline(std::cin, userInput);
            unsigned int userNumber = std::stoi(userInput);
            if (userNumber > 0 && userNumber <= 10000)
            {
                std::cout << "DecimalToRoman: " << NumberConverter::DecimalToRoman(userNumber) << "\n";
            }
            else
            {
                std::cout << "Cannae dae that.\n";
            }
        }
        else if (userInput == "Q" || userInput == "q")
        {
            // Exit condition
            break;
        }
        else
        {
            // Prompt user to retry if input invalid.
            std::cout << "Honestly, this should be the easy part and you put '" << userInput << "'? Try again...\n";
        }
    }
    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
