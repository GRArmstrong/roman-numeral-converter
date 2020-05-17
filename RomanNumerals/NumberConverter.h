#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <vector>


// Values of individual Roman Numerals
static const std::vector<std::pair<int, char>> romanNumerals = {
    {1, 'I'},
    {5, 'V'},
    {10, 'X'},
    {50, 'L'},
    {100, 'C'},
    {500, 'D'},
    {1000, 'M'},
    {5000, 'W'},
    {10000, 'Q'}
};

// Values of Roman Numerals and valid substraction pairs
static const std::vector<std::pair<int, std::string>> romanNumeralChunks = {
    {1, "I"},
    {4, "IV"},
    {5, "V"},
    {9, "IX"},
    {10, "X"},
    {40, "XL"},
    {50, "L"},
    {90, "XC"},
    {100, "C"},
    {400, "CD"},
    {500, "D"},
    {900, "CM"},
    {1000, "M"},
    {4000, "MW"},
    {5000, "W"},
    {9000, "MQ"},
    {10000, "Q"}
};

// Exception thrown by the CharVal method if a given character isn't a valid numeral
class NumeralError : public std::exception
{
public:
    NumeralError(const char* errorMessage) : errorMsg(errorMessage) {}
    virtual const char* what() const throw()
    {
        return errorMsg;
    }

private:
    const char* errorMsg;
};

// Main class
class NumberConverter
{
public:
	static int RomanToDecimal(const std::string& roman);
	static std::string DecimalToRoman(int decimal);

private:
	static int CharVal(char numeral);
};
