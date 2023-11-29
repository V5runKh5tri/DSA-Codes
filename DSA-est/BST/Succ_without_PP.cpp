#include<bits/stdc++.h>
using namespace std;
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
Node* treeMin(Node *root){
    if(root==NULL)cout<<"empty tree";
    while(root->left!=NULL)root=root->left;
    return root;
} 
Node* treeSuccessor(Node *root,Node *node){
    if(node->right!=NULL)return treeMin(node->right);

    Node* succ=NULL;
    while(root->data!=node->data){
        if(node->data<root->data){
            succ=root;
            root=root->left;
        }
        else root=root->right;
    }
    return succ;
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
    root->left->right->right=new Node(50);
    root->left->right->left=new Node(25);
    Node *temp=root->left->right->left;
	Node* succ = treeSuccessor(root, temp);
    if (succ != NULL)
        cout << "\n Inorder Successor of "
             << temp->data << " is "<< succ->data;
    else
        cout <<"\n Inorder Successor doesn't exit";
	return 0;
}



  
