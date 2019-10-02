#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

class node{
    public:
    int val;
    node *left;
    node *right;
    int ht;
};


node *root = NULL;
//functions declarations
node * insertNode(node *, int);

int height(node *node){
    if(node==NULL){
        return -1;
    }
    return node->ht;
}


int balance(node *node){
    if(node==NULL){
        return 0;
    }
    return height(node->left) - height(node->right);
}

node * findMin(node *root){
	while(root->left!=NULL){
		root = root->left;
	}
	return root;
}


node *rightRotate(node *c){
    cout<<"Rotating to the right on node "<<c->val<<endl;
    node *b = c->left;
    node *T3 = b->right;
    b->right = c;
    c->left = T3;
    c->ht = max(height(c->left), height(c->right)) + 1;
    b->ht = max(height(b->left), height(b->right)) + 1;

    return b;
}

node *leftRotate(node *c){
    cout<<"Rotating to the left on node "<<c->val<<endl;
    node *b = c->right;
    node *T2 = b->left;
    b->left = c;
    c->right = T2;
    c->ht = max(height(c->left), height(c->right)) + 1;
    b->ht = max(height(b->left), height(b->right)) + 1;

    return b;
}


node * insert(node * root,int data)
{
    if(root==NULL){
        node *n = new node();
        n->val = data;
        n->left = n->right = NULL;
        n->ht = 0;
        root = n;
    }
        if(data > root->val) {
            root->right = insert(root->right, data);
        } 
        else if (data < root->val) {
            root->left = insert(root->left, data);
        }

    root->ht = max(height(root->left), height(root->right)) + 1;
    int bf = balance(root);

    //LL Case
    if(bf > 1 && data < root->left->val){
        cout<<"Left left heavy situation..."<<endl;
        return rightRotate(root);
    }

    //RR Case
    if(bf < -1 && data > root->right->val){
        cout<<"Right right heavy situation..."<<endl;
        return leftRotate(root);
    }

    //LR Case
    if(bf > 1 && data > root->left->val){
        cout<<"Left right heavy situation..."<<endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //RL Case
    if(bf < -1 && data < root->right->val){
        cout<<"Right left heavy situation..."<<endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }


    return root;
  
}


node* deleteNode(node* root, int key)  
{  
       
    if (root == NULL){
        return root;  
    }   
    if (key < root->val){
        root->left = deleteNode(root->left, key);  
    }    
    else if(key > root->val){
        root->right = deleteNode(root->right, key); 
    }  
    else
    {  
		//case 1: 0 children
		if(root->left==NULL && root->right==NULL){
			free(root);
			cout<<"Removing a leaf node..."<<endl;
			root = NULL;
		}
		//case 2: 1 child
		else if(root->left==NULL){
			node *temp = root;
			root = root->right;
			cout<<"Removing a node with right child..."<<endl;
			free(temp);
		}
		else if(root->right==NULL){
			node *temp = root;
			root = root->left;
			cout<<"Removing a node with left child..."<<endl;
			free(temp);
		}
		//case 3: 2 children
		else{
            cout<<"Removing a node with two children..."<<endl;
			node *temp = findMin(root->right);
			root->val = temp->val;
			root->right = deleteNode(root->right, temp->val);
		}
    }  
    //this is for if no node is left so simply return NULL
    if (root == NULL){
        return root;  
    }
    root->ht = max(height(root->left),height(root->right)) + 1;  
    int bf = balance(root);  

   //LL Case
    if(bf > 1 && key < root->left->val){
        cout<<"Left left heavy situation..."<<endl;
        return rightRotate(root);
    }

    //RR Case
    if(bf < -1 && key > root->right->val){
        cout<<"Right right heavy situation..."<<endl;
        return leftRotate(root);
    }

    //LR Case
    if(bf > 1 && key > root->left->val){
        cout<<"Left right heavy situation..."<<endl;
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    //RL Case
    if(bf < -1 && key < root->right->val){
        cout<<"Right left heavy situation..."<<endl;
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

  
    return root;  
} 

void preOrder(node *root){
    if(root){
        cout<<root->val<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void displayLevel(node *root){
    vector<node *> queue;
    queue.push_back(root);
    while(queue.size()!=0){
        node *n = queue.front();
        queue.erase(queue.begin());
        cout<<n->val<<" ";
        if(n->left!=NULL){
            queue.push_back(n->left);
        }
        if(n->right!=NULL){
            queue.push_back(n->right);
        }
    }
}

void inOrder(node *node){
    if(node){
        inOrder(node->left);
        cout<<node->val<<endl;
        inOrder(node->right);
    }
}


int main(){
    root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 5); 
	root = insert(root, 6);
	root = insert(root, 15);
    displayLevel(root);
    cout<<endl;
    root = deleteNode(root, 15);
    root = deleteNode(root, 20);
    inOrder(root);
    return 0;
}