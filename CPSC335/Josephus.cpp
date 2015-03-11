// Zeed Jarrah
// Assignment 2

#include <iostream>
#include <string>
using namespace std;

void Josephus(int n, int k);
int main()
{
	int numOfPeople;
	int k;

	cout << "People: ";
	cin >> numOfPeople;
	cout << "K = ";
	cin >> k;

	Josephus(numOfPeople, k);

	cout << endl;
	return 0;
}

void Josephus(int n, int k)
{
	if(k < 1 || n < 1)
	{
        cout << "The number of people and k can't be less than 1" << endl;
        return;
    }

    bool *table = new bool[n];
 
    for(int i = 0; i < n; i ++)
	{
        table[i] = true;
    }

    int peopleLeft = n;
    int index = 0;
    int num = 0;

    while(peopleLeft > 1)
	{
        while(table[index] != true)
		{
            index ++;
            if(index == n)
			{
                index = 0;
            }
        }

        if(num == k - 1)
		{
            table[index] = false;
            peopleLeft --;
        }
        
        num ++;
        if(num == k)
		{
            num = 0;
        }

        index ++;
        if(index == n)
		{
            index = 0;
        }
    }

    for(int i = 1; i <= n; i++)
    {
        if(table[i - 1] == true)
		{
            cout << "Person " << i << " is the last remaining.\n";
        }
    }
    delete[] table;
}
