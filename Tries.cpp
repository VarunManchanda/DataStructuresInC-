#include<iostream>
using namespace std;

class Node{
    public:
    char word;
    Node *left;
    Node *middle;
    Node *right;
    long long int value;
};

Node * makeNode(char w){
    Node *n = new Node();
    n->word = w;
    n->left = n->middle = n->right = NULL;
    n->value = 0;

    return n;
}

Node *root = NULL;

Node * putItem(Node *, string, long long int, int);
Node * getItem(Node *, string, int);

Node * put(string key, long long int value){
    root = putItem(root, key, value, 0);
    return root;
}

Node * putItem(Node *root, string key, long long int value, int index){
    char c = key[index];

    if(root==NULL){
        root = makeNode(c);
    }
    if(c < root->word){
        root->left = putItem(root->left, key, value, index);
    }
    else if(c > root->word){
        root->right = putItem(root->right, key, value, index);
    }
    else if(index < key.length() - 1){
        root->middle = putItem(root->middle, key, value, index + 1);
    }
    else{
        root->value = value;
    }
    return root;
}

long long int get(string key){
    Node *n = getItem(root, key, 0);
    if(n==NULL){
        return -1;
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

    root = put("car", 200);
    root = put("hack", 100);
    root = put("road", 100);
    cout<<get("car")<<endl;
    return 0;
}
