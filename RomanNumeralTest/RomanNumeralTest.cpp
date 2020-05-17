#include "pch.h"
#include "CppUnitTest.h"
#include "../RomanNumerals/NumberConverter.h"
#include "TestData.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace RomanNumeralTest
{
	TEST_CLASS(NumberConverterTest)
	{
	public:
		
		TEST_METHOD(RomanToDecimalTest)
		{
			// Iterate valid values and ensure the strings correspond to the correct decimals
			for (unsigned int i = 0; i < td_validValues.size(); i++)
			{
				std::pair<int, std::string> testItem = td_validValues[i];
				std::string testValue = testItem.second;
				int expectedValue = testItem.first;
				int actualValue = NumberConverter::RomanToDecimal(testValue);
				Assert::AreEqual(expectedValue, actualValue);
			}
		}

		TEST_METHOD(DecimalToRomanTest)
		{
			// Iterate valid values and ensure the decimals correspond to the correct string
			for (unsigned int i = 0; i < td_validValues.size(); i++)
			{
				std::pair<int, std::string> testItem = td_validValues[i];
				int testValue = testItem.first;
				std::string expectedValue = testItem.second;
				std::string actualValue = NumberConverter::DecimalToRoman(testValue);
				Assert::AreEqual(expectedValue, actualValue);
			}
		}

		TEST_METHOD(InvalidRomanToDecimalTest)
		{
			// Iterate invalid values and ensure the RomanToDecimal method returns -1 for bad input
			for (unsigned int i = 0; i < td_invalidRomanNumerals.size(); i++)
			{
				std::string testValue = td_invalidRomanNumerals[i];
				int expectedValue = -1;
				int actualValue = NumberConverter::RomanToDecimal(testValue);
				Assert::AreEqual(expectedValue, actualValue);
			}
		}
	};
}
