#include <bits/stdc++.h>
using namespace std;

// Class describing a node of tree
class Node {
public:
	int data;
	Node* left;
	Node* right;
	Node(int v)
	{
		this->data = v;
		this->left = this->right = NULL;
	}
};
//Leftmost element 
int treeMin(Node *root){
    if(root==NULL)cout<<"empty tree";
    while(root->left!=NULL)root=root->left;
    return root->data;
} 

//Rightmost element 
int treeMax(Node *root){
    if(root==NULL)cout<<"empty tree";
    while(root->right!=NULL)root=root->right;
    return root->data;
}

int main()
{
	// Build the tree
	Node* root = new Node(100);
	root->left = new Node(20);
	root->right = new Node(200);
	root->left->left = new Node(10);
	root->left->right = new Node(30);
	root->right->left = new Node(150);
	root->right->right = new Node(300);

	cout<<treeMin(root)<<endl;
    cout<<treeMax(root);
	return 0;
}

  
