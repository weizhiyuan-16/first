#include <iostream>
#include <ctime>
#include <queue>
using namespace std;
class Node
{
	public:
		int val;
		Node *parent;
		Node *lc;
		Node *rc;
		Node(int v)
		{
			val = v;
			parent = NULL;
			lc = NULL;
			rc = NULL;
		}
};
class Tree
{
	public:
		Node *r;
		Tree(){r = NULL;}
		void Insert(int k);
		Node *search(int k);
		Node *next(Node *root)//找到当前结点的最左结点。 
		{
			Node *p = root->rc;
			while(p->lc != NULL)
			{
				p = p->lc;
			}
			return p;
		}
		void del(int k);
};


void Tree::Insert(int k)
{
 	//空树插入。 
	 if(r == NULL)
	 {
		r = new Node(k);
		return;
	 }
	 
	Node *par = r->parent;
	Node *cur = r; 
	//找到新节点的位置。 
	while(cur != NULL)
	{
		par = cur;
		if(par->val > k)
		{
			cur = par->lc;
		}
		else if(par->val < k)
		{
			cur = par->rc;
		}
		else//该结点已存在。 
		{
			return;
		}
	}
	//将新节点插入。
	cur = new Node(k); 
	cur->parent = par;
	if(par->val > k)
	{
		par->lc = cur;
	}
	else
	{
		par->rc = cur;
	}
}


void Tree::del(int k)
{
	Node *dn = search(k);
	if(dn != NULL)
	{
		if(dn->lc == NULL && dn->rc == NULL)
		{
			if(dn == r)
			{
				r = NULL;
				return;
			}
			if(dn->parent->lc == dn)
			{
				dn->parent->lc = NULL;
			}
			else
			{
				dn->parent->rc = NULL;
			}
			return;
		}
		if(dn->lc != NULL && dn->rc == NULL)
		{
			if(dn == r)
			{
				r = dn->lc;
				return;
			}
			if(dn->parent->lc == dn)
			{
				dn->parent->lc = dn->lc;
			}
			else
			{
				dn->parent->rc = dn->lc;
			}
			dn->lc->parent = dn->parent;
			return;
		}
		if(dn->rc != NULL && dn->lc == NULL)
		{
			if(dn == r)
			{
				r = dn->rc;
				return;
			}
			if(dn->parent->lc == dn)
			{
				dn->parent->lc = dn->rc;
			}
			else
			{
				dn->parent->rc = dn->rc;
			}
			dn->rc->parent = dn->parent;
			return;
		}
		//删除结点既有左子树又有右子树，使结点的最左结点替代它。 
		Node *p = next(dn);
		dn->val = p->val;
		if(p->rc != NULL)
		{
			p->rc->parent = p->parent;
			if(p->parent->lc == p)
			{
				p->parent->lc = p->rc;
			}
			else
			{
				p->parent->rc = p->rc;
			}
		}
		else
		{
			if(p->parent->lc == p)
			{
				p->parent->lc = NULL;
			}
			else
			{
				p->parent->rc = NULL;
			}
		}
	}
}


Node* Tree::search(int k)
{
	Node *cur = r;
	while(cur != NULL)
	{
		if(cur->val == k)
		{
			return cur;
		}
		if(cur->val > k)
		{
			cur = cur->lc;
		}
		else
		{
			cur = cur->rc;
		}
	}
	return cur;
}

 
void out(Tree &t, int n)
{
	queue<Node*> q;
	Node *p;
	if(t.r == NULL)
	{
		return;
	}
	q.push(t.r);
	int count = 0;
	while(!q.empty())
	{
		p = q.front();
		q.pop();
		if(p->lc != NULL)
		{
			q.push(p->lc);
		}
		if(p->rc != NULL)
		{
			q.push(p->rc);
		}
		cout << p->val;
		count++;
		if(count < n) cout<<" ";
	}
	cout << endl;
}


int main()
{
	Tree t;
	int n = 49;
	int *num = new int[n];
	srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
		num[i] = i;
	}
	for(int i = 0; i < n; i++)
	{
		int a = rand() % n;
		int b = rand() % n;
		int t = num[a];
		num[a] = num[b];
		num[b] = t;
	}
	clock_t start1 = clock();
	for(int i = 0; i < n; i++)
	{
		t.Insert(num[i]); 
		out(t,i+1);
	}
	clock_t end1 = clock();
	srand(time(NULL));
	for(int i = 0; i < n; i++)
	{
		int a = rand() % n;
		int b = rand() % n;
		int t = num[a];
		num[a] = num[b];
		num[b] = t;
	}
	clock_t start2 = clock();
	for(int i = n - 1; i >= 0; i--)
	{
		t.del(num[i]);
	}
	clock_t end2 = clock();
	double time = (double)(end1-start1+end2-start2)/CLOCKS_PER_SEC;
	cout << time << "s" << endl;
    return 0; 
}

