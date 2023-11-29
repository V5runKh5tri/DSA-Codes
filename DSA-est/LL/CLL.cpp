#include<bits/stdc++.h>
using namespace std;
class node{
    public:
    int data;
    node* next;
};
void insertAtBeg(node **head, int val){\
    node* temp=new node;
    temp->data=val;
    if(*head==nullptr){
        temp->next=temp;
        *head=temp;
        return ;
    }
    node* last=*head;
    while(last->next!=(*head)){
        last=last->next;
    }
    last->next=temp;
    temp->next=(*head);
    *head=temp;
}
void insertAtEnd(node **head,int val){
    node* temp=new node;
    temp->data=val;
    if(*head==nullptr){
        temp->next=temp;
        *head=temp;
        return ;
    }
    temp->next=*head;
    node* last=*head;
    while(last->next!=(*head)){
        last=last->next;
    }
    last->next=temp;
}
void insertAfterVal(node **head, int key, int val){
    node* temp=new node;
    temp->data=val;
    if(*head==nullptr){
        temp->next=temp;
        *head=temp;
        return ;
    }
    node* curr=*head;
    while((curr->next!=(*head))&&(curr->data!=key)){
        curr=curr->next;
    }
    if((curr->next==(*head))&&(curr->data!=key)){
        cout<<"list is empty"<<endl;
    }
    else{
        temp->next=curr->next;
        curr->next=temp;
    }
}
bool searchNode(node **head,int key){
    node* curr=*head;
    while(curr->next!=(*head)){
        if(curr->data!=key){
            return true;
        }
        curr=curr->next;
    }
    return false;
}
void deleteAtBeg(node **head){
    if((!(*head))){
        cout<<"list empty"<<endl;
        return ;
    }
    node* temp=*head;
    if(temp->next==*head)*head=nullptr;
    else{
        node *curr=*head;
        while(curr->next!=(*head))curr=curr->next;
        *head=(*head)->next;
        curr->next=*head;
    }
    delete temp;
}
void deleteAtEnd(node **head){
    if((!(*head))){
        cout<<"list empty"<<endl;
        return ;
    }
    node* temp=*head;
    if(temp->next==*head)*head=nullptr;
    else{
        node *last=*head,*prev;
        while(last->next!=(*head)){
        prev=last;
        last=last->next;
        }
        prev->next=*head;
    }
    delete temp;
}
void deleteAtVal(node **head,int key){
    if((!*head)){
        cout<<"list empty"<<endl;
        return ;
    }
    node* curr=*head,*prev;
    while((curr->next!=(*head))&&(curr->data!=key)){
        prev=curr;
        curr=curr->next;
    }
    if((curr->next==(*head))&&(curr->data!=key)){
        cout<<"key not here"<<endl;
        return ;
    }
    else if(curr==*head)deleteAtBeg(head);
    else if(curr->next==*head)deleteAtEnd(head);
    else{
        prev->next=curr->next;
    }
    delete curr;
}
void display(node** head){
    node* curr=*head;
    do{
        cout<<curr->data<<" ";
        curr=curr->next;
    }while(curr!=(*head));
    cout<<endl;
}
int main(){
    node* head=nullptr;
    insertAtBeg(&head,1);
    display(&head);
    insertAtEnd(&head,2);
    insertAtEnd(&head,3);
    display(&head);
    insertAtEnd(&head,5);
    display(&head);
    insertAfterVal(&head,3,4);
    display(&head);
    insertAtEnd(&head,6);
    cout<<searchNode(&head,3);
    cout<<endl;
    cout<<searchNode(&head,6);
    cout<<endl;
    display(&head);
    cout<<endl;
    deleteAtBeg(&head);
    display(&head);
    deleteAtEnd(&head);
    display(&head);
    deleteAtVal(&head,3);
    display(&head);
    return 0;
}

  
