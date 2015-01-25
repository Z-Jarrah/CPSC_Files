#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int binaryNumber;

	cout << "Enter a positive integer: ";
	cin >> binaryNumber;

	for(int i = 15; i >= 0; i--)
	{
		if(i == 11 || i == 7 || i == 3)
		{
			cout << " ";
		}

		if((binaryNumber / pow(2, i)) < 1)
		{
			cout << "0";
		}
		else
		{
			cout << "1";
			binaryNumber = binaryNumber - pow(2,i);
		}
	}

	cout << endl;
	return 0;
}