#include<bits/stdc++.h>
using namespace std;

class node{

    public:
    int data ;
    node* next = NULL;

    node(int data){
        this->data = data;
        this->next = NULL;
    }

};

void At_head(node* &head , int data){
    node* temp = new node(data);
    if(head == NULL){
        temp = head;
    }
    else{
        temp->next = head;
        head = temp;
    }
}

void print(node* head){
    node* temp = head;
    if(head==NULL) {
    cout<<"Empty List";
    return;
    }
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}


int main(){

    node* n1 = new node(50);
    node* head = n1;
    At_head(head , 40);
    At_head(head , 30);
    At_head(head , 20);
    At_head(head , 10);
    At_head(head , 0);
    print(head);
    


    return 0;
}