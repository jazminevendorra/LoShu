// This program will ask for number input and display it as a
// Lo Shu Square game. It will determine whether it is or isnt a 
// Lo Shu Square.

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	const int rows = 3;
	const int collumns = 3;
	double grid[rows][collumns];
	int lrows, lcollumns;
	int number = 0;
	double total;
	string choice;

	do
	{
		// Intro
		cout << "Creating Lo Shu Square ...\n";
		cout << "Enter Nine Numbers (1-9)\n";

		// Ask for numbers
		for (lcollumns = 0; lcollumns < collumns; lcollumns++)
		{
			for (lrows = 0; lrows < rows; lrows++)
			{

				do
				{
					// Save numbers into a 2-d Array
					number += 1;
					cout << "\tNumber " << number << ": ";
					cin >> grid[lrows][lcollumns];

					// Validation
					if (grid[lrows][lcollumns] < 1 and grid[lrows][lcollumns] > 9)
						cout << "Error ... Invalid number. Try again\n";

				} while (grid[lrows][lcollumns] < 1 && grid[lrows][lcollumns] > 9);

			}

		}


		// Display grid
		cout << "\n-------------\n";

		for (lcollumns = 0; lcollumns < collumns; lcollumns++)
		{

			for (lrows = 0; lrows < rows; lrows++)
			{
				cout << "| " << grid[lrows][lcollumns] << " ";

			}
			cout << "|\n";
			cout << "-------------\n";
		}


		// Calculate if numbers create lo shu square
		for (int row = 0; row < lrows; row++)
		{
			// Set the accumulator.
			total = 0;
			// Sum a row
			for (int col = 0; col < lcollumns; col++)
			{
				total += grid[row][col];

			}

		}
		if (total == 15)
		{
			for (int col = 0; col < lcollumns; col++)
			{
				total = 0;

				for (int row = 0; row < lrows; row++)
					total += grid[row][col];
			}
			if (total == 15)
				cout << "\nThis is a Lo Shu Magic Square!!!";
			else
				cout << "\nSorry ... this is not a Lo Shu Magic Square";
		}
		else
			cout << "\nSorry ... this is not a Lo Shu Magic Square";

		
		// End of program?
		cout << "\n\nWould you like to try again (y\/n) ? ";
		cin >> choice;
		if (choice != "n")
			break;
	} while (choice != "n");
	
}