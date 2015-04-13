// Zeed Jarrah
// CPSC335

#include <iostream>
#include <iomanip>
using namespace std;

struct Node
{
	int info;
	Node* left;
	Node* right;
};

void insert(Node*& root, int data);
void print(Node* root, int spaces);
void clearTree(Node* root);


int main()
{
	Node* root = new Node;
	root = NULL;

	int data[7] = {10, 5, 1, 7, 15, 12, 20};

	for(int i = 0; i < 7; i++)
	{
		insert(root, data[i]);
	}
	int spaces = 7 * 2;
	print(root, spaces);
	
	cout << endl;
	return 0;
}

void insert(Node*& root, int data)
{
	Node* tmp = new Node;
	
	tmp->info = data;
	tmp->left = NULL;
	tmp->right = NULL;
	
	if(root == NULL)
	{
		root = tmp;
	}
	else
	{
		if(tmp->info < root->info)
		{
			insert(root->left, data);
		}
		else
		{
			insert(root->right, data);
		}
	}
}

void print(Node* root, int spaces = 0)
{
	if(root != NULL)
	{
		cout << setw(spaces) << root->info << endl;
		print(root->left, spaces - 2);
		print(root->right, spaces + 4);
	}
}
