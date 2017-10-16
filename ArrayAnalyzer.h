// Alix Field					afield@cnm.edu				Field.P4_CPP

// ArrayAnalyzer.h

// Call std_lib_Header File
#include "std_lib_facilities.h"   

// Initialize Size of Input File
#define SIZE 1000

using namespace std;

class ArrayAnalyzer
{
	private:
		// Declare and Intialize Vector
		// vector<int>n(SIZE);
		array<int, SIZE>n;
		int total = 0;						
		string filename = "";			
		string strModes = "";				
		bool bOpen = false;					
		double average = 0;
		double median = 0;
		int high = 0;
		int low = 0;
		void Read();
		void Sort();
		void CalculateAverage();
		void CalculateMedian();
		void CalculateMode();


	public:
		ArrayAnalyzer();
		explicit ArrayAnalyzer(string fileIn);
		void SetFile(string fileIn);
		int GetTotal();
		double GetMedian();
		double GetAverage();
		string GetMode();
		void GetHighLow(int &rHigh, int &rLow);
		bool FindValue(int value, int &howMany);
		bool WriteSummary(string fileout);
};
