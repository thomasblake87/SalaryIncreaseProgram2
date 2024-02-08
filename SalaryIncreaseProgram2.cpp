/*
	There only user input would be the data table. 
	The process basically is that the script will open the SalaryData.txt and SalaryOut.txt files, then it will make a loop and 
	Set each double/string in the Data table equal to either lastName, firstName, salary, or raisePercent.
	Then output it to the SalaryOut.txt file.
*/


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;

	string lastName;
	string firstName;
	double salary;
	double raisePercent;

	inFile.open("SalaryData.txt");
	outFile.open("SalaryOut.txt");

	outFile << fixed << showpoint;
	outFile << setprecision(2);

	for(;;)
	{
		inFile >> lastName >> firstName >> salary >> raisePercent;
		if (!inFile) break;
		salary = (salary + ((raisePercent / 100) * salary));
		outFile << "Name: " << firstName << " " << lastName << " New Salary:" << salary << endl;
	}

	inFile.close();
	outFile.close();
}