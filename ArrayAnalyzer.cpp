// Alix Field			afield@cnm.edu				Field.P4_CPP

//ArrayAnalyzer.cpp

#include "ArrayAnalyzer.h"


//-------------------------------------
//Public Functions
//-------------------------------------

//Default Constructor
ArrayAnalyzer::ArrayAnalyzer()
{
	// Call Private Variables
	total;								
	filename;							
	strModes;							
	bOpen;							
	average;
	median;
	high;
	low;

	// Intialize Array
	for (int c = 0; c < SIZE; c++)
	{
		n[c] = 0;
	}

}


// Overloaded Constructor w/ Explicitly Connected to Default Constructor
ArrayAnalyzer::ArrayAnalyzer(string fileIn) : ArrayAnalyzer()
{
	filename = fileIn;

	//Call Private Methods
	Read();
	Sort();
	CalculateAverage();
	CalculateMedian();
	CalculateMode();
}

void ArrayAnalyzer::SetFile(string fileIn)
{
	filename = fileIn;

	//Call Private Methods
	Read();
	Sort();
	CalculateAverage();
	CalculateMedian();
	CalculateMode();
}


int ArrayAnalyzer::GetTotal()
{
	return total;
}

double ArrayAnalyzer::GetAverage()
{
	return average;
}

double ArrayAnalyzer::GetMedian()
{
	return median;
}

string ArrayAnalyzer::GetMode()
{
	return strModes;
}

void ArrayAnalyzer::GetHighLow(int &rHigh, int &rLow)
{

	// Min /Max with Standard Library
	for (int c = 0; c < total; c++)
	{
		rLow = min(n[c], rLow);
		rHigh = max(n[c], rHigh);
	}
	high = rHigh;
	low = rLow;
}

bool ArrayAnalyzer::FindValue(int value, int &howMany)
{
	stringstream fv;
	howMany = 0;
	for (int c = 0; c < total; c++)
	{
		// Counting the Occurences of the Found #
		if (n[c] == value)
		{
			++howMany;
		}
		else
		{
			fv << "\nThe chosen value was not within the file";
			fv << "\nThank you for using my program     ~* Goodbye *~\n\n";
		}
	}

	// Returns True or False Without IF Else Statements
	return (howMany > 0);
}

bool ArrayAnalyzer::WriteSummary(string fileout)
{
	// Open Output File ReportData.txt
	ofstream summary;
	summary.open(fileout);

	// Check: if file was opened
	if (!summary)
	{
		stringstream error;
		error << "\n\n          !!! ERROR !!!  "
			<< "\n     Cannot open " << fileout << endl;
		return false;
	}

	// Writing Output File
	summary << "\nArray Analyzer Summary"
		<< "\n\nInput File Name: " << filename
		<< "\nTotal Elements: " << total
		<< "\nInteger Maximum: " << high
		<< "\nInteger Minimum:  " << low
		<< "\nAverage: " << average
		<< "\nMedian: " << median << endl;

	// Close Output File
	summary.close();
	return true;
}


//-------------------------------
//Private Functions
//-------------------------------

void ArrayAnalyzer::Read()
{
	stringstream rf;
	ifstream file;
	file.open(filename);
	if (!file)
	{
		bOpen = false;
		rf << "\nCannot open " << filename
			<< "      ~* Goodbye *~ \n\n";
		return;
	}
	else
	{
		// File Found
		bOpen = true;
		rf << "\nFile " << filename << " opened";
	}

	// Reading and Counting Number of Elements in .txt File
	while (!file.eof())
	{
		for (int c = 0; c < SIZE; c++)
		{
			file >> n[c];
			++total = sizeof(n) / sizeof(n[0]);
		}
	}
	file.close();
}

void ArrayAnalyzer::Sort()
{
	// Standard Library Sort Method
	sort(n.begin(), n.begin() + total);
}

void ArrayAnalyzer::CalculateAverage()
{
	// Standard Library Accumlate Average
	average = accumulate(n.begin(), n.begin() + total, 0.0 / total);
}

void ArrayAnalyzer::CalculateMedian()
{
	// Finding the Median
	int middle = total / 2;

	//If: Odd Amount of Integers
	if (total % 2)
	{
		median = n[middle];
	}
	else
	{
		//Even Amount of Integers
		median = (n[middle] + n[middle + 1] / 2);
	}
}

void ArrayAnalyzer::CalculateMode()
{
	stringstream cm;
	int counter = 1;
	int max = 0;
	int mode = n[0];
	for (int pass = 0; pass < SIZE - 1; pass++)
	{
		if (n[pass] == n[pass + 1])
		{
			counter++;
			if (counter > max)
			{
				max = counter;
				mode = n[pass];
			}
		}
		else
			counter = 1; // reset counter.
	}
	cm << "Mode: " << mode << endl;
	cm << "Mode Appears: " << max << endl;
	strModes = cm.str();
}

//int count = 0;
//int maxMode = 0;
//int modeCount = 0;
//for (int c = 0; c < count;)
//{
//	while (n[c] == c)
//	{
//		count++;
//		c++;
//	}
//	if (count > maxMode)
//	{
//		maxMode = count;
//		modeCount = 1;
//	}
//	if (count == maxMode)
//	{
//		modeCount++;
//	}
//}

//for (count = 0; count < SIZE; count++)
//{
//	maxMode = n[count];
//	for (count = 0; count < SIZE; count++)
//	{
//		if (n[count] > maxMode)
//		{
//			maxMode = n[count];
//			modeCount = count;
//		}
//	}
//}
