#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *prev;
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void print(node *&head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// getting length of linked list
int getlength(node *&head)
{
    node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

// insert at Head
void insertAtHead(int data, node *&head)
{
    // create a new Node
    node *temp = new node(data);
    if (head == NULL)
        head = temp;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

// insert at tail
void insertAtTail(int data, node *&tail)
{
    // create a new node
    node *temp = new node(data);
    temp->prev = tail;
    tail->next = temp;
    tail = temp;
}

// insert in middle
void insertAtMid(int data, int pos, node *&head, node *&tail)
{
    // Boundary condition --> insertion at head
    if (pos == 1)
    {
        node *newNode = new node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;
    }

    // create a new pointer node
    node *temp = head;
    int count = 1;
    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }
    // to insert at end
    if (temp->next == NULL)
    {
        node *newNode = new node(data);
        newNode->prev = temp;
        temp->next = newNode;
        tail = newNode;
        return;
    }

    // create a new node
    node *newNode = new node(data);
    node *curr = temp->next;
    newNode->prev = temp;
    newNode->next = curr;
    temp->next = newNode;
    curr->prev = newNode;
}

int main()
{

    node *n1 = new node(10);
    node *head = n1;
    node *tail = n1;
    print(head);
    cout << getlength(head) << endl;
    // head insertion
    insertAtHead(20, head);
    insertAtHead(30, head);
    insertAtHead(40, head);
    insertAtHead(50, head);
    insertAtHead(60, head);
    print(head);
    cout << getlength(head) << endl;
    // tail insertion
    insertAtTail(70, tail);
    insertAtTail(80, tail);
    insertAtTail(90, tail);
    insertAtTail(100, tail);
    insertAtTail(110, tail);
    print(head);
    cout << getlength(head) << endl;
    // insertion at mid
    insertAtMid(0, 12, head, tail);
    print(head);
    cout << getlength(head) << endl;

    return 0;
}