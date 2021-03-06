#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

int main(int argc, const char* argv[])
{
	if (argc < 2)
	{
		std::cout << "Please provide the filename of the spreadsheet. E.g. part1 spreadsheet.txt";
		return 0;
	}

	// Open the spreadsheet file
	std::fstream inputSpreadsheet;
	inputSpreadsheet.open(argv[1], std::fstream::in);
	if (!inputSpreadsheet.is_open())
	{
		std::cout << "Error opening the spreadheet!";
		return 0;
	}

	// Read the lines of numbers from the spreadsheet
	int checksum = 0;
	while (!inputSpreadsheet.eof())
	{
		// Read the line
		std::string line;
		std::getline(inputSpreadsheet, line);

		// Split the line into numbers
		std::stringstream lineStream(line);
		std::vector<int> numbers;
		while (!lineStream.eof())
		{
			int value;
			lineStream >> value;
			numbers.push_back(value);
		}
		
		if (numbers.size() > 0)
		{
			// Find the only two numbers on this row that divide evenly
			int divisonResult = 0;
			for(auto first = numbers.begin(); first != numbers.end(); ++first)
			{
				for (auto second = numbers.begin(); second != numbers.end(); ++second)
				{
					if (first == second)
					{
						continue;
					}

					if (*first > *second && *first % *second == 0)
					{
						divisonResult = *first / *second;
					}
				}
			}
			checksum += divisonResult;
		}
	}

	// Output the result
	std::cout << "Your checksum is: " << checksum;

	// Close the spreadsheet
	inputSpreadsheet.close();

    return 0;
}

