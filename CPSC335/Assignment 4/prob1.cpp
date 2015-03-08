//CPSC335
//Assignment 4
//Problem 1
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <random>
using namespace std;

std::uniform_int_distribution<int> distribution(0,25);
std::random_device rd;
std::mt19937 gen(rd());

void GenChars(int arr[], int c);
void PrintAlpha(int arr[]);
int main()
{
	int All[26] = {0};

	GenChars(All, 30);
	PrintAlpha(All);

	cout << endl;
	return 0;
}

void GenChars(int arr[], int c)
{
	int index;

	for(int i = 0; i < c; i++)
	{
		index = distribution(gen);
		arr[index]++;
	}
}

void PrintAlpha(int arr[])
{
	char alpha;
	int max = 0;
	for(int i = 0; i < 26; i++)
	{
		if(arr[i] != 0)
		{
			alpha = i + 65;
			cout << alpha << ": " << arr[i] << endl;
		}
		// Search for max frequency
		if(max < arr[i])
		{
			max = arr[i];
		}
	}
	//Print max frequency letters
	cout << "Letters: ";
	for(int i = 0; i < 26; i++)
	{
		if(arr[i] == max)
		{
			alpha = i + 65;
			cout << alpha << " ";
		}
	}
	cout << "have highest frequncy " << max << endl;
}
