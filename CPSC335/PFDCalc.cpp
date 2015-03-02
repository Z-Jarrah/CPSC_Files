// CPSC335
// Assignment
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream inFile;
	ofstream outFile;
	int sizeOfRecords;
	int t1, t2, t3;
	int PFD[4] = {3, 1, 1, 1};	
	int tapeDrives[4][100] = {0};
	
	//
	cout << "Enter number of records in file f: ";
	cin >> sizeOfRecords;
	cout << "This is the PFD table.\n";
	cout << " " << "t1 " << "t2 " << "t3" << endl;
	cout << "___________\n";
	cout << " " << PFD[1] << "  " << PFD[2] << "  " << PFD[3];  
	while(PFD[0] < sizeOfRecords)
	{
		cout << endl;
		t1 = PFD[1];
		t2 = PFD[2];
		t3 = PFD[3];
		PFD[3] = t1;
		PFD[2] = t1 + t3;
		PFD[1] = t1 + t2;
		PFD[0] = PFD[1] + PFD[2] + PFD[3];

		for (int i = 1; i < 4; i++)
		{
			cout << " " << PFD[i] << " ";
		}
	}
	cout << endl;
	cout << "___________" << endl << endl;
	//
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
	//
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
	//
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
	//
	cout << "Phases: " << phase;
	cout << endl;
	return 0;
}