#include <bits/stdc++.h>
using namespace std;


// node class bana e h 
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

// naye data ko node bana kar head se attach kiya h --> or head ki position change kar di h 
void insertAthead(int data, node *&head)
{

    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

// print kar rahe h head se (change ho gya h head)
void printList(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{

    node *n1 = new node(10);
    node *head = n1;
    insertAthead(20, head);
    insertAthead(30, head);
    insertAthead(40, head);
    printList(head);

    return 0;
}