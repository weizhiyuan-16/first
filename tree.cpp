#include<iostream>
#include<string>
#include<cmath>
using namespace std;
class node 
{
public:
	node* lChild;
	node* rChild;
	char value;
	node(char v = NULL, node* l = NULL, node* r = NULL) 
	{
		value = v;
		lChild = l;
		rChild = r;
	}
	
};
void postorder(node* Tree) 
{
	if (Tree == NULL) 
	{
		return;
	}
	else 
	{
		postorder(Tree->lChild);
		postorder(Tree->rChild);
		cout << Tree->value;
	}
}

int main() 
{
	string s;
	cin >> s;
	node* Tree = new node[s.size() + 1];//Tree[0]没有用到，从1开始。 
	int n = 1;
	int m = 1;
	//求s为满二叉树时的元素个数m。 
	while ((int)s.size() > m) 
	{
		double u = (double)n;
		m += pow(2, u);
		n++;
	}
	for (int q = 1; q <= s.size(); q++) 
	{
		if (2 * q <= (int)s.size()) Tree[q].lChild = &Tree[2 * q];
		if (2 * q + 1 <= (int)s.size()) Tree[q].rChild = &Tree[2 * q + 1];
	}
	Tree[1].value = s[0];
	for (int i = 1, j = 1; i < (int)s.size();) 
	{
		while (Tree[j].value != NULL && Tree[j].lChild != NULL && i < (int)s.size()) 
		{
			j = 2 * j;
			Tree[j].value = s[i++];

		}
		if (Tree[j / 2].rChild != NULL && Tree[j / 2].rChild->value == NULL) 
		{
			j = j + 1;
			Tree[j].value = s[i++];
		}
		else if (Tree[j / 2].rChild != NULL && Tree[j / 2].rChild->value != NULL) 
		{
			j = j / 2;
			while (j > 1 && Tree[j / 2].rChild != NULL && Tree[j / 2].rChild->value != NULL) j = j / 2;
			j = j + 1;
			Tree[j].value = s[i++];
		}
		else if (Tree[j / 2].rChild == NULL) 
		{
			j = j / 2 ;
			while (j > 1 && Tree[j / 2].rChild != NULL && Tree[j / 2].rChild->value != NULL) j = j / 2;
			j = j + 1;
			Tree[j].value = s[i++];
		}
	}
	postorder(&Tree[1]);
	delete[]Tree;
	return 0;
}

