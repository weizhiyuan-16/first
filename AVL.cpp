#include <queue>
#include <vector>
#include <iostream>
using namespace std;
typedef struct AVLNode
{
	struct AVLNode *left,*right;
	int val,height;
}*Node;
int getHeight(Node root)
{
	if(root == NULL)	return 0;
	else	return root->height;
}
Node rightrotate(Node root)
{
	Node tmp = root->left;
	root->left = tmp->right;
	tmp->right = root;
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
	tmp->height = max(getHeight(tmp->left),getHeight(tmp->right)) + 1;
	return tmp;
}
Node leftrotate(Node root)
{
	Node tmp = root->right;
	root->right = tmp->left;
	tmp->left = root;
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
	tmp->height = max(getHeight(tmp->left),getHeight(tmp->right)) + 1;
	return tmp;
}
Node rightleftrotate(Node root)
{
	root->right = rightrotate(root->right);
	return leftrotate(root);
}
Node leftrightrotate(Node root)
{
	root->left = leftrotate(root->left);
	return rightrotate(root);
}
Node insert(Node root,int key)
{
	if(root == NULL)
	{
		root = new AVLNode();
		root->val = key;
		root->left = root->right = NULL;
		root->height = 1;
		return root;
	}
	else
	{
		if(key < root->val)
		{
			root->left = insert(root->left, key);
			if(getHeight(root->left) - getHeight(root->right) == 2)
			{
				if(key < root->left->val)	root = rightrotate(root);
				else root = leftrightrotate(root);
			}
		}
		else if(key > root->val)
		{
			root->right = insert(root->right, key);
			if(getHeight(root->right) - getHeight(root->left) == 2)
			{
				if(key > root->right->val)	root = leftrotate(root);
				else root = rightleftrotate(root);
			}
		}
	}
	root->height = max(getHeight(root->left),getHeight(root->right)) + 1;
	return root;
}
void level_order_traverse(Node root)
{
	queue<Node>q;
	vector<int>ans;
	q.push(root);
	bool flag = false,flag2 = false;
	while(!q.empty())
	{
		Node p = q.front();	
		q.pop();
		ans.push_back(p->val);
		if(p->left != NULL)
		{
			q.push(p->left);
			if(flag)	flag2 = true;
		}
		else	flag = true;
 
		if(p->right != NULL)
		{
			q.push(p->right);
			if(flag)	flag2 = true;
		}
		else flag = true;
	}
	for(int i = 0; i < ans.size(); i++)
	{
		if(i == ans.size() - 1)	cout << ans[i] << endl;
		else	cout << ans[i] << ' ';
	}
	if(!flag2)	cout << "Yes" << endl;
	else cout << "No" << endl;
}
int main()
{
	int n;
    cin >> n;
	Node root = NULL;
	for(int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		root = insert(root, x);
	}
	level_order_traverse(root);
 
	return 0;
}
