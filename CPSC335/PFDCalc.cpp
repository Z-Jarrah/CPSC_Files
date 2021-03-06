// CPSC335
// Assignment
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void CreatePFDTable(int table[], int records);

int main()
{
	ifstream inFile;
	ofstream outFile;
	int sizeOfRecords;
	int PFD[4] = {3, 1, 1, 1};	
	int tapeDrives[4][100] = {0};
	
	// Takes user input to create the PFD table that works with the given record size
	cout << "Enter number of records in file f: ";
	cin >> sizeOfRecords;
	CreatePFDTable(PFD, sizeOfRecords);
	
	// Adds dummy records to the total number of records if the value does not match a row on the PFD table 
	tapeDrives[0][0] = sizeOfRecords;
	if(sizeOfRecords != PFD[0] )
	{
		tapeDrives[0][0] = PFD[0];
		cout << "Add " << PFD[0] - sizeOfRecords << " dummy records to f to use PFD " << PFD[1]
		<< "-" << PFD[2] << "-" << PFD[3] <<endl;
	}
	cout << "Phases to sort the file using the above PFD\n";
	tapeDrives[1][1] = PFD[1];
	tapeDrives[2][1] = PFD[2];
	tapeDrives[3][1] = PFD[3];
	
	// Performs the logic of processing records from all the tape drives.
	// Subtracting by the smallest non-zero value in each column of the 
	// current row and adding by the smallest non-zero value if the current column is 0.
	// This should never encounter a situation where subtracting from a column will lead to a negative number.
	int phase = 2;
	int min = tapeDrives[0][0];
	int recordsToProcess = tapeDrives[0][0];

	while(recordsToProcess > 1)
	{
		for(int i = 0; i <= 3; i++)
		{	
			if( min > tapeDrives[i][phase - 1] && tapeDrives[i][phase - 1] != 0)
			{
				min = tapeDrives[i][phase - 1];
				tapeDrives[i][phase] = 0;
			}
		}
		for(int i = 0; i <= 3; i++)
		{
			if(tapeDrives[i][phase] >= 0)
			{
				tapeDrives[i][phase] = tapeDrives[i][phase - 1] - min;
				tapeDrives[i][phase] = abs(tapeDrives[i][phase]);
			}
		}
		recordsToProcess = tapeDrives[1][phase] + tapeDrives[2][phase] + tapeDrives[3][phase];
		phase++;
	}

	// Prints out the the number of files in each tape drive at each phase
	cout << " " << "f " << " t1" << " t2" << " t3\n";
	cout << "____________\n";
	for (int i = 0; i < phase; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << " " << tapeDrives[j][i] << " ";
		}
		cout << endl;
	}

	cout << "Phases: " << phase;
	cout << endl;
	return 0;
}

void CreatePFDTable(int table[], int records)
{
	int t1, t2, t3;
	cout << "This is the PFD table.\n";
	cout << " " << "t1 " << "t2 " << "t3" << endl;
	cout << "___________\n";
	cout << " " << table[1] << "  " << table[2] << "  " << table[3];
	while (table[0] < records)
	{
		cout << endl;
		t1 = table[1];
		t2 = table[2];
		t3 = table[3];
		table[3] = t1;
		table[2] = t1 + t3;
		table[1] = t1 + t2;
		table[0] = table[1] + table[2] + table[3];

		for (int i = 1; i < 4; i++)
		{
			cout << " " << table[i] << " ";
		}
	}
	cout << endl;
	cout << "___________" << endl << endl;
}