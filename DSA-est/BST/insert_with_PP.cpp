#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right ,*parent;
};
Node* newnode(int val){
    Node* temp=new Node;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    temp->parent=NULL;
    return temp;
}
Node* insert(Node* root,int val){
    if(root==NULL){
        return (newnode(val));
    }        
    else{
        Node *temp;
        if(val<=root->data){
            temp=insert(root->left,val);
            root->left=temp;
            temp->parent=root;
        }
        else{
            temp=insert(root->right,val);
            root->right=temp;
            temp->parent=root;
        }

    }
    return root;

}
void printInorder(Node* node)
{
	if (node == NULL)
		return;

	// Traverse left subtree
	printInorder(node->left);

	// Visit node
	cout << node->data << " ";

	// Traverse right subtree
	printInorder(node->right);
}
int main(){
    Node* root=NULL;
    root=insert(root,100);
    root=insert(root,20);
    root=insert(root,10);
    root=insert(root,30);
    root=insert(root,25);
    root=insert(root,50);
    root=insert(root,200);
    root=insert(root,150);
    root=insert(root,300);

    cout << "Inorder Traversal: ";
	printInorder(root);

    return 0;
}

  
