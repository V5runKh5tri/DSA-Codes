#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
};
Node* newnode(int val){
    Node* temp=new Node;
    temp->data=val;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}
Node* insert(Node* root,int val){
    if(root==NULL)
        return (newnode(val));
    else{
        Node* temp;
        if(val<=root->data){
            temp=insert(root->left,val);
            root->left=temp;
        }
        else{
            temp=insert(root->right,val);
            root->right=temp;
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
Node* treeMin(Node *root){
    if(root==NULL)return root;
    while(root->left!=NULL)root=root->left;
    return root;
}
Node* deleteNodeBST(Node* root,int key){
    if(root==NULL)return root;
    Node *del=root, *p=NULL;
    while(del!=NULL && del->data!=key){
        if(key<del->data){
            p=del;
            del=del->left;
        }
        else{
            p=del;
            del=del->right;
        }
    }
    if(del==NULL)return root;
    else{

        //reached the node to be deleted

        //if single child
        if(del->right==NULL){
            if(p->right==del)p->right=del->left;
            else p->left=del->left;
            return root;
        }
        else if(del->left==NULL){
            if(p->right==del)p->right=del->right;
            else p->left=del->right;
            return root;
        }//if both child exists
        else if(del==root){
            treeMin(del->right)->left=del->left;
            root=del->right;
            return root;
        }
        else{
            if(p->right==del){
                p->right=del->right;
                treeMin(del->right)->left=del->left;
            }
            else{
                p->left=del->right;
                treeMin(del->right)->left=del->left;
            }
            return root;
        }
    }
    
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

    cout<<endl<< "Inorder Traversal: ";
	printInorder(deleteNodeBST(root,100));

    return 0;
}

  
