#include "NumberConverter.h"

/**
 * @brief Convert a Roman Numeral string to a decimal number.
 * @param roman The string to convert.
 * @return Decimal value of the string.
 */
int NumberConverter::RomanToDecimal(const std::string& roman)
{
	// Running total, the value of this is returned as the result.
	int total = 0;
	try
	{
		// We iterate up to the second-to-last character to compare each pair
		// to check for where we should subtract (ie IX -> 10 - 1 = 9)
		unsigned int i;
		int previous = INT_MAX;
		int subtotal;
		for (i = 0; i < roman.size() - 1; i++)
		{
			int current = CharVal(roman[i]);
			int next = CharVal(roman[i + 1]);

			if (current < next)
			{
				// Test for valid subtraction value, it must either be 1/10th
				// or 1/5th of the next character.
				// (ie VX is invalid, IC is invalid; but IV, IX, and XL are valid)
				if ((current * 10 != next) && (current * 5 != next))
				{
					return -1;
				}
				subtotal = (next - current);
				i++;
			}
			else
			{
				subtotal = current;
			}

			// Test validity of numeral order, the chunks must be highest-to-lowest
			// from left-to-right.
			if (subtotal > previous)
			{
				return -1;
			}
			previous = subtotal;
			total += subtotal;
		}

		// If the loop ends before the last character can be used, add it here.
		if (i == roman.size() - 1)
		{
			int lastValue = CharVal(roman[roman.size() - 1]);
			// Test validity of numeral order again.
			if (lastValue > previous)
			{
				return -1;
			}
			else
			{
				total += lastValue;
			}
		}
	}
	catch (const NumeralError& e)
	{
		std::cout << e.what();
		return -1;
	}
	return total;
}

/**
 * @brief Convert a decimal numer to a Roman Numeral.
 * @param decimal Value of the Roman Numeral string to make.
 * @return Roman Numeral string.
 */
std::string NumberConverter::DecimalToRoman(int decimal)
{
	int remaining = decimal;
	std::string numerals;
	for (int i = romanNumeralChunks.size() - 1; i >= 0 && remaining > 0; i--)
	{
		int denominator = romanNumeralChunks[i].first;
		std::div_t result = std::div(remaining, denominator);
		remaining = result.rem;
		for (int j = result.quot; j > 0; j--)
		{
			numerals.append(romanNumeralChunks[i].second);
		}
	}
	return numerals;
}

/**
 * @brief Return the decimal value of a Roman Numeral.
 * @param numeral Character to return value of.
 * @throws NumeralError If character is not a valid Roman Numeral.
 * @return Decimal value of the character.
 */
int NumberConverter::CharVal(char numeral)
{
	for (const std::pair<int, char>& pair : romanNumerals)
	{
		if (pair.second == numeral)
		{
			return pair.first;
		}
	}
	throw NumeralError("Invalid character");
}
