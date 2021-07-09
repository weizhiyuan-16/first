#include<iostream>
using namespace std;

enum RBTcolor {B, R};
class TreeNode 
{
public:
	int data;
	RBTcolor color;
	TreeNode* left, * right, * parent;
	TreeNode(int _data, RBTcolor c, TreeNode* l, TreeNode* r, TreeNode* p):data(_data), color(c), left(l), right(r), parent(p) {};
};
class RBTree 
{
	private:
		TreeNode* root;
		void PreOrderNode(TreeNode* tree)const;
		void RightRotate(TreeNode* node);
		void LeftRotate(TreeNode* node);
		void InsertNode(TreeNode* node);
		void InsertFix(TreeNode* node);
		void DeleteNode(TreeNode* node);
		void DeleteFix(TreeNode* node, TreeNode* parent);
	public:
		RBTree() { root = NULL; }
		~RBTree(){}
		void Insert(int _data);
		void Delete(int _data);
		void FindMaxMin();
		void PreOrder();
};
void RBTree::Insert(int _data) 
{
	TreeNode* newNode;
	newNode = new TreeNode(_data, B, NULL, NULL, NULL);
	InsertNode(newNode);
}
void RBTree::InsertNode(TreeNode* node) 
{
	if (root == NULL) 
	{
		root = node;
		return;
	}
	TreeNode* tmp = root, * ptmp;
	while (tmp) 
	{
		ptmp = tmp;
		if (node->data < tmp->data)
			tmp = tmp->left;
		else
			tmp = tmp->right;
	}
	if (node->data < ptmp->data)
		ptmp->left = node;
	else ptmp->right = node;
	node->parent = ptmp;
	node->color = R;
	InsertFix(node);
}
void RBTree::InsertFix(TreeNode* node) 
{
	TreeNode* parent;
	while ((parent = node->parent) && parent->color == R) 
	{
		TreeNode* gparent = node->parent->parent;
		//父节点是祖父节点的左孩子。 
		if (parent == gparent->left) 
		{
			TreeNode* uncle = gparent->right;
			//情况1：叔结点为红色。 
			if (uncle && uncle->color == R) 
			{
				uncle->color = B;
				parent->color = B;
				gparent->color = R;
				node = gparent;
				continue;
			}
            //情况2：叔结点为黑色，插入节点为父节点的右孩子。 
			if (node == parent->right) 
			{
				LeftRotate(parent);
				swap(parent, node);
			}

			parent->color = B;
			gparent->color = R;
			RightRotate(gparent);
		}
		//父节点是祖父节点的右孩子。 
		if (parent == gparent->right) 
		{
			TreeNode* uncle = gparent->left;
			if (uncle && uncle->color == R) 
			{
				uncle->color = B;
				parent->color = B;
				gparent->color = R;
				node = gparent;
				continue;
			}
			if (node == parent->left) 
			{
				RightRotate(parent);
				swap(parent, node);
			}
			parent->color = B;
			gparent->color = R;
			LeftRotate(gparent);
		}
	}
	root->color = B;
}
void RBTree::RightRotate(TreeNode* node) 
{
	TreeNode* lchild = node->left;
	node->left = lchild->right;
	if (lchild->right)
		lchild->right->parent = node;
		lchild->parent = node->parent;
		if (node->parent == NULL)
		root = lchild;
		else 
		{
			if (node == node->parent->left)node->parent->left = lchild;
			else node->parent->right = lchild;
		}
		lchild->right = node;
		node->parent = lchild;
}
void RBTree::LeftRotate(TreeNode* node) 
{
	TreeNode* rchild = node->right;
	node->right = rchild->left;
	if (rchild->left)
		rchild->left->parent = node;
	rchild->parent = node->parent;
	if (node->parent == NULL)
		root = rchild;
	else 
	{
		if (node == node->parent->left)node->parent->left = rchild;
		else node->parent->right = rchild;
	}
	rchild->left = node;
	node->parent = rchild;
}
void RBTree::PreOrderNode(TreeNode* tree)const
{
	if (tree == NULL)return;
	cout << tree->data;
	if (tree->color == B)cout << "(B) ";
	else cout << "(R) ";
	PreOrderNode(tree->left);
	PreOrderNode(tree->right);
}
void RBTree::PreOrder() 
{
	if (root == NULL)cout << "Null";
	else PreOrderNode(root);
	cout << endl;
}


void RBTree::FindMaxMin() 
{
	TreeNode* tmp1 = root;
	TreeNode* tmp2 = root;
	while (tmp1->left) tmp1 = tmp1->left;
	while (tmp2->right)tmp2 = tmp2->right;
	cout << tmp1->data << ' ' << tmp2->data << endl;
}

//找到要删除的节点。 
void RBTree::Delete(int _data) 
{
	TreeNode* tmp = root;
	while (tmp) 
	{
		if (_data < tmp->data)
			tmp = tmp->left;
		else if (_data > tmp->data)
			tmp = tmp->right;
		else break;
	}
	if (tmp == NULL)return;
	DeleteNode(tmp);
}


void RBTree::DeleteNode(TreeNode* node) 
{
	RBTcolor tcolor = B;
	if (node->left && node->right) 
	{
		TreeNode* tmp = node->right;
		while (tmp->left)tmp = tmp->left;
		node->data = tmp->data;
		if (tmp->parent == node)node->right = tmp->right;
		else tmp->parent->left = tmp->right;
		if (tmp->right)tmp->right->parent = tmp->parent;
		tcolor = tmp->color;
		if (tcolor == B)DeleteFix(tmp->right, tmp->parent);
		delete tmp;
		return;
	}
	else if (node->left) 
	{
		if (node->parent == NULL) 
		{
			root = node->left;
			node->left->parent = NULL;
		}
		else 
		{
			if (node == node->parent->left)node->parent->left = node->left;
			else node->parent->right = node->left;
			if (node->left)node->left->parent = node->parent;
			tcolor = node->color;
		}
		if (tcolor == B)DeleteFix(node->left, node->parent);
		delete node;
	}
	else 
	{
		if (node->parent == NULL) 
		{
			root = node->right;
			if (node->right)node->right->parent = NULL;
		}
		else 
		{
			if (node == node->parent->left)node->parent->left = node->right;
			else node->parent->right = node->right;
			if (node->right)node->right->parent = node->parent;
			tcolor = node->color;
		}
		if (tcolor == B)DeleteFix(node->right, node->parent);
		delete node;
	}
}
void RBTree::DeleteFix(TreeNode* node, TreeNode* parent) 
{
	TreeNode* other;
	while ((!node || node->color == B) && node != root) 
	{
		if (node == parent->left) 
		{
			other = parent->right;
			if (other->color == R) 
			{
				other->color = B;
				parent->color = R;
				LeftRotate(parent);
				other = parent->right;
			}
			if ((!other->left || other->left->color == B) && (!other->right || other->right->color == B)) 
			{
				other->color = R;
				node = parent;
				parent = node->parent;
			}
			else 
			{
				if (!other->right || other->right->color == B) 
				{
					other->left->color = B;
					other->color = R;
					RightRotate(other);
					other = parent->right;
				}
				other->color = other->parent->color;
				parent->color = B;
				other->right->color = B;
				LeftRotate(parent);
				node = root;
				break;
			}
		}
		else 
		{
			other = parent->left;
			if (other->color == R) 
			{
				other->color = B;
				parent->color = R;
				RightRotate(parent);
				other = parent->left;
			}
			if ((!other->left || other->left->color == B) && (!other->right || other->right->color == B)) 
			{
				other->color = R;
				node = parent;
				parent = node->parent;
			}
			else 
			{
				if (!other->left || other->left->color == B) 
				{
					other->right->color = B;
					other->color = R;
					LeftRotate(other);
					other = parent->left;
				}
				other->color = parent->color;
				parent->color = B;
				other->left->color = B;
				RightRotate(parent);
				node = root;
				break;
			}
		}
	}
	if (node)
		node->color = B;
}

int main() 
{
	int n, m;
	int num1, * num2;
	cin >> n;
	RBTree t;
	for (int i = 0; i < n; i++) 
	{
		cin >> num1;
		t.Insert(num1);
	}
	cin >> m;
	num2 = new int[m];
	for (int i = 0; i < m; i++) 
	{
		cin >> num2[i];
	}
	t.PreOrder();
	t.FindMaxMin();
	for(int i = 0; i < m; i++)
	{
		t.Delete(num2[i]);
	}
	t.PreOrder();
	return 0;
}
