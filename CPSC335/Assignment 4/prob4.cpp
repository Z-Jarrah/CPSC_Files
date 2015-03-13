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
	
	for(int i = 0; i < 16; i++)
	{
		int k = int(words[i].at(0)) - 65;
		hashTable[k] = InsertWord(hashTable, string(words[i]));
	}

	for(int i = 0; i < 26; i++)
	{
		if(hashTable[i] != NULL)
		{
			SortHash(hashTable[i]);
		}
	}

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
		Node* tmp = h[index];
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = t;
	}
	
	return h[index];
}

void SortHash(Node*& h)
{
	//// Still needs a proper sort algorithm
	Node* curr = h;
	Node* prev;
	//Sorting
	if(curr != NULL && curr->next != NULL /*&& curr->next->info.compare(curr->info) < 0*/)
	{
		prev = curr;
		curr = curr->next;
		curr->next = prev;
		h = curr;
		prev->next = NULL;
		cout << "curr " << curr->info << "prev " << prev->info << endl;
		cout << "head is now " <<h->info << endl;
	}
	
}


