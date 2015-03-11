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

void InsertWord(Node* h[], string word);

int main()
{
	string words[16] = {"COW", "DOG","SEA","RUG","ROW","MOB","BOX","TEA","FOX","TAB","BAR","EAR","TAR","GIG","BIG","NOW"};
	Node* hashTable[26];
	
	//
	for(int i = 0; i < 26; i++)
	{
		hashTable[i] = NULL;
	}
	
	for(int i = 0; i < 16; i++)
	{
		InsertWord(hashTable, string(words[i]));
	}

	cout << endl;
	return 0;
}

void InsertWord(Node* h[], string word)
{
	int index = int(word.at(0)) - 65;
	cout << "index: " << index << endl;
	Node* t = new Node;
	t->info = word;
	t->next = NULL;

	if(h[index] == 0)
	{
		h[index] = t;
	}
	else
	{
		Node* p = h[index];
		Node* q;
		while(p->next != NULL)
		{
			q = p;
			p = p->next;
		}
	}
}