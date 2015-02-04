#include <iostream>
using namespace std;
void DisplayBits(unsigned int number); 
int main()
{
	unsigned int value;

	cout << "Enter a positive integer: ";
	cin >> value; 
	DisplayBits(value);

	cout << endl;
	return 0;
}
 
void DisplayBits(unsigned int number)
{
	unsigned int mask = 1 << 15;
	cout << number << " at base 2 is ";
	for(int i = 1; i <= 16; ++i)
	{
		if((number & mask) == 0)
			cout << '0';
		else
			cout << '1';

		number <<= 1;
		if(i % 4 == 0)
			cout << ' ';
	}
}