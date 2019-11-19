#include <iostream>
using namespace std;

class Node
{
	public:
	int data;
	Node *left;
	Node *right;
};

Node *root = NULL;
Node *insert(Node *, int);
Node * insertNode(Node *root, int data)
{
	return insert(root,data);
}

Node * insert(Node *root, int data)
{
	if(root==NULL)
	{
		Node *n = new Node();
		n->data = data;
		n->left = n->right = NULL;
		root = n;
	}
	else if(data < root->data)
	{
		root->left = insert(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = insert(root->right, data);
	}
	return root;
}

Node * findMin(Node *root)
{
	if(root==NULL)
	{
		return root;
	}
	else if(root->left!=NULL)
	{
		return findMin(root->left);
	}
	return root;
}

Node * deleteNode(Node *root, int data)
{
	if(root==NULL)
	{
		return root;
	}
	else if(data < root->data)
	{
		root->left = deleteNode(root->left, data);
	}
	else if(data > root->data)
	{
		root->right = deleteNode(root->right, data);
	}
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			Node *temp = root;
			root = NULL;
			free(temp);
		}
		
		else if(root->left==NULL)
		{
			Node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right==NULL)
		{
			Node *temp = root;
			root = root->left;
			free(temp);
		}
		else{
			Node *temp = findMin(root->right);
			root->data = temp->data;
			root->right = deleteNode(root->right, temp->data);
		}
	}
	return root;
}

void inOrder(Node *root)
{
	if(root)
	{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void preOrder(Node *root)
{
	if(root)
	{
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(Node *root)
{
	if(root)
	{
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
	}
}


int main() {
	root = insertNode(root,3);
	root = insertNode(root,2);
	root = insertNode(root,5);
	root = insertNode(root,4);
	root = insertNode(root,6);
	inOrder(root);
	cout<<endl;
	root = deleteNode(root, 5);
	preOrder(root);
	cout<<endl;
	postOrder(root);
	return 0;
}