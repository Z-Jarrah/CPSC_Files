//CPSC335
//Project4
//Problem 4
#include <iostream>
#include <string>
using namespace std;

struct Node
{
	string info;
	Node* next;
};

void InsertWord(Node* h[], string word[]);
void SortHash(Node*& h);

int main()
{
	string words[16] = {"COW", "DOG","SEA","RUG","ROW","MOB","BOX","TEA","FOX","TAB","BAR","EAR","TAR","GIG","BIG","NOW"};
	Node* hashTable[26];
	//
	for(int i = 0; i < 26; i++)
	{
		hashTable[i] = NULL;
	}
		
	InsertWord(hashTable, words);

	//for(int i = 0; i < 26; i++)
	//{
	//	if(hashTable[i] != NULL)
	//	{
	//		SortHash(hashTable[i]);
	//	}
	//}

	//For debugging purposes, needs to be its own function
	int numOfwords = 0;
	for(int i = 0; i < 26; i++)
	{
		Node* tmp = hashTable[i];
		while(tmp != NULL)
		{
			cout << tmp->info << endl;
			numOfwords++;
			tmp = tmp->next;
		}
	}
	cout << numOfwords << endl;
	cout << endl;
	return 0;
}

void InsertWord(Node* h[], string word[])
{
	string tmparr[16];

	for(int k = 2; k >= 0; k--)
	{
		for(int i = 0; i < 16; i++)
		{
			int index = int(word[i].at(k)) - 65;
			cout << "letter: " << word[i].at(k) << " index: " << index << endl;
			Node* t = new Node;
			t->info = word[i];
			t->next = NULL;

			if(h[index] == 0)
			{
				h[index] = t;
			}
			else
			{
				Node* tmp = h[index];
				while(tmp->next != NULL)
				{
					tmp = tmp->next;
				}
				tmp->next = t;
			}
		}
//
//
		if(k != 0)
		{
			int l = 0;
			for(int j = 0; j < 26; j++)
			{
				Node* temp = h[j];
				while (temp != NULL)
				{
					word[l] = temp->info;
					temp = temp->next;
					l++;
				}

				delete h[j];
				h[j] = 0;
			}
		}
	}
}

void SortHash(Node*& h)
{
	//// Still needs a proper sort algorithm
	//Node* curr = h;
	//Node* prev = curr;
	//int sizeOfList = 0;

	//while(curr != NULL)
	//{
	//	curr = curr->next;
	//	sizeOfList++;
	//}

	//cout << "Size of list in index: " << sizeOfList << endl;
	//Sorting
	//if(curr != NULL && curr->next != NULL /*&& curr->next->info.compare(curr->info) < 0*/)
	//{
	//	prev = curr;
	//	curr = curr->next;
	//	curr->next = prev;
	//	h = curr;
	//	prev->next = NULL;
	//	cout << "curr " << curr->info << "prev " << prev->info << endl;
	//	cout << "head is now " <<h->info << endl;
	//}
	
}


