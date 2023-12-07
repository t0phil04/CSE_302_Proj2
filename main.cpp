#include "AUList.h"
#include "StackType.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

AUList csvToAUList(string file)
{
	AUList ret_SBData;
	ifstream infile(file);
	string line, curValue;
	getline(infile, line); // Remove Headers of the csv file

	while (getline(infile, line))
	{
		stringstream ss(line);
		int fieldIter = 0;
		SB_Record tempRecord;
		while (getline(ss, curValue, ','))
		{
			switch (fieldIter)
			{
			case 0: tempRecord.SB_Title = curValue; break;
			case 1: tempRecord.SB_Winner = curValue; break;
			case 2: tempRecord.winnerPts = stoi(curValue); break;
			case 3: tempRecord.SB_Loser = curValue; break;
			case 4: tempRecord.loserPts = stoi(curValue); break;
			case 5: tempRecord.MVP = curValue; break;
			}
			fieldIter++;
		}
		ret_SBData.PutItem(tempRecord);
	}
	return ret_SBData;
}

int main(int argc, char** argv) {
	AUList SB_Data = csvToAUList("superbowl.csv");

	// Winners Stack
	StackType<string> winners_stack = SB_Data.CreateStack(1);
	// Losers Stack
	StackType<string> losers_stack = SB_Data.CreateStack(2);
	// MVP Stack
	StackType<string> MVP_stack = SB_Data.CreateStack(3);

	int stack_type = -1;

	while (stack_type !=4){ // Allows for multiple entries for all Stacks available
		cout << "What type of stack do you want? " << endl;
		cout << "1. Winners\n2. Losers\n3. MVP\n4. Quit\n";
		cin >> stack_type;

		string item; // to be used as the value requested for printing
	
		switch (stack_type)
		{
		case 1:
			// Print the contents of the Winners Stack
			cout << "Stack of Winners: (From SB 1 - SB 54)" << endl;
			while (!winners_stack.IsEmpty()) {
				item = winners_stack.Pop();
				cout << "   " << item << endl;
			}
			break;
		case 2:
			// Print the contents of the Losers Stack
			cout << "Stack of Losers: (From SB 1 - SB 54)" << endl;
			while (!losers_stack.IsEmpty()) {
				item = losers_stack.Pop();
				cout << "   " << item << endl;
			}
			break;
		case 3:
			// Print the contents of the MVP Stack
			cout << "Stack of MVP Winners: (From SB 1 - SB 54)" << endl;
			while (!MVP_stack.IsEmpty()) {
				item = MVP_stack.Pop();
				cout << "   " << item << endl;
			}
			break;
		default: // When the user enters 4 for the stack_type
			char ans_;
			cout << "Would you like to see all the games and information? (Y/N)";
			cin >> ans_;
			if (ans_ == 'Y')
			{
				SB_Data.PrintList();
			}
			else
			{
				cout << "Seeya!" << endl;
			}
			break;
		}
	}
}