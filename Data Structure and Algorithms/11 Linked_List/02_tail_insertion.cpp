#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insert(int data, node *&tail)
{
    node *temp = new node(data);
    tail->next = temp; //current node is attached to the new node created on tail 
    tail= temp;     // tail pointer is changed to next node created for further attachment
}

void printList(node* head){

    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    node * head = new node(10);
    node * tail = head;         // ye pointer change hota rahega or last node ko represent karega
    insert(20 , tail);
    insert(30 , tail);
    insert(40 , tail);
    insert(50 , tail);
    printList(head);

  

    return 0;
}