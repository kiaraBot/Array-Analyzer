// Alix Field				afield@cnm.edu				Field.P4_CPP
// Driver.cpp

#include "ArrayAnalyzer.h"

using namespace std;

int main()
{
	// Variable Decleration
	int rMax;
	int rMin;
	int choice = 1;
	bool findValue = false;
	int value;
	int howmany;


	//C++ Programming Class Project Header
	cout << "\nAlix Field "
		<< "\nProgram 4: Array Analyzer "
		<< "\nProgram Objectives:  Analyzing Array Number Data"
		<< "\n     *Sort Array Elements"
		<< "\n     *Average Value"
		<< "\n     *Median Value"
		<< "\n     *Mode Values"
		<< "\n     *Min & Max Values"
		<< "\n     *Search for User Defined Value Within the Array"
		<< "\n     *Open, Read, & Write Summary w/ .csv File" << endl;

	// Program Header
	cout << "\n\n                    Array Analyzer Program ";

	// Ask User for File Name
	cout << "\n\nEnter the input file name: ";
	string fileIn;
	getline(cin, fileIn);

	// Call Overloaded Constructor w/ Instantiated Object
	ArrayAnalyzer calie(fileIn);

	//---------------------------------------------------------------
	// Console Output Summary Details
	//---------------------------------------------------------------

	cout << "\n\nArray Analyzer Summary ";

	// Call GetTotal();
	int arrayTotal = calie.GetTotal();
	cout << "\nTotal: " << arrayTotal << endl;

	// Call GetAverage();
	double avg = calie.GetAverage();
	cout << "Average: " << avg << endl;

	// Call GetMedian();
	double mdn = calie.GetMedian();
	cout << "Median: " << mdn << endl;

	// Call Min /Max
	calie.GetHighLow(rMax, rMin);
	cout << "Maximum Integer: " << rMax << endl;
	cout << "Minimum Integer: " << rMin << endl;

	// Call Modes
	string cm = calie.GetMode();
	cout << cm;

	// Ask User for File Name
	cout << "\n\nEnter the output file name: ";
	string fileOut;
	getline(cin, fileOut);


	// Call WriteSummary();
	calie.WriteSummary(fileOut);




	// Exit Program User Options
	cout << "\n\nif you would like to find a specific value within a file please enter 1 : "
		<< "\nif you would like to exit the program please enter 2 : ";
	cin >> choice;
	cin.ignore();

	// If  Check: Choice 1 or Choice 2 w/ User Prompts
	if (choice == 1)
	{
		findValue = true;
		cout << "\n\nPlease enter a specific value: ";
		cin >> value;
		cin.ignore();

		//call findvalue();
		calie.FindValue(value, howmany);

		cout << "\nValue: " << value << endl;
		cout << "Appeared: " << howmany << endl;
		cout << "\n\nThank you for using my program     ~* Goodbye *~ \n\n";

	}
	else
	{
		findValue = false;
		cout << "\n\n~* Goodbye *~\n\n";
	}

	return 0;
}


