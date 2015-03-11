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

Node* InsertWord(Node* h[], string word);

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
		int k = int(words[i].at(0)) - 65;
		hashTable[k] = InsertWord(hashTable, string(words[i]));
	}
	Node* tmp;
	for(int i = 0; i < 26; i++)
	{
		while(hashTable[i] != NULL)
		{
			cout <<hashTable[i]->info << endl;
		}
	}
	cout << endl;
	return 0;
}

Node* InsertWord(Node* h[], string word)
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
		h[index]->next = t;
	}
	//else
	//{
	//	Node* p = h[index];
	//	Node* q;
	//	while(p->next != NULL)
	//	{
	//		q = p;
	//		p = p->next;
	//	}
	//}
	return h[index];
}