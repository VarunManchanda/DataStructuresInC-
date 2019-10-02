#include<iostream>
using namespace std;

class Node{
    public:
    char word;
    Node *left;
    Node *middle;
    Node *right;
    int value;
};

Node * makeNode(char w){
    Node *n = new Node();
    n->word = w;
    n->left = n->middle = n->right = NULL;
    n->value = 0;

    return n;
}

Node *root = NULL;

Node * putItem(Node *, string, int);
Node * getItem(Node *, string, int);

Node * put(string key){
    root = putItem(root, key, 0);
    return root;
}

Node * putItem(Node *root, string key,int index){
    char c = key[index];

    if(root==NULL){
        root = makeNode(c);
    }
    if(c < root->word){
        root->left = putItem(root->left, key, index);
    }
    else if(c > root->word){
        root->right = putItem(root->right, key, index);
    }
    else if(index < key.length() - 1){
        root->value += 1;
        root->middle = putItem(root->middle, key, index + 1);
    }
    else{
        root->value += 1 ;
    }
    return root;
}

int get(string key){
    Node *n = getItem(root, key, 0);
    if(n==NULL){
        return 0;
    }
    return n->value;
}

Node * getItem(Node *root, string key, int index){
    char c = key[index];

    if(root==NULL){
        return root;
    }
    else if(c < root->word){
        return getItem(root->left, key, index);
    }
    else if(c > root->word){
        return getItem(root->right, key, index);
    }
    else if(index < key.length() - 1){
        return getItem(root->middle, key, index + 1);
    }
    else{
        return root;
    }

}

int main(){

    root = put("aab");
    root = put("abcde");
    root = put("aabcd");
    cout<<get("ab");
    




    return 0;
}