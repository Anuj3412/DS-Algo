#include <bits/stdc++.h>
using namespace std;

/*  Circular Linked list --- has no head and no tail --- we use a pointer named tail for traversal  */

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

// insertion at after any element
void insert(int data, int element, node *&tail)
{

    // if tail = NULL --- (empty list)
    if (tail == NULL)
    {
        node *newNode = new node(data);
        newNode->next = newNode;
        tail = newNode;
        return;
    }
    else
    {
        // after a element
        node *temp = tail;
        while (temp->data != element)
        {
            temp = temp->next;
        }
        node *newNode = new node(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// traversing a circular linked list
void print(node *&tail)
{
    if (tail == NULL)
    {
        cout << "empty List" << endl;
        return;
    }
    node *temp = tail;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
}

// deletion of a element
void deletion(int element, node *&tail)
{

    if (tail == NULL)
    {
        cout << "empty list" << endl;
        return;
    }

    node *prev = tail;
    node *curr = prev->next;
    while (curr->data != element)
    {
        prev = curr;
        curr = curr->next;
    }

    // boundary case --- if only single element is there and we delete that
    if (prev == curr)
    {
        tail = NULL;
        return;
    }

    // boundary case --- tail is at that element
    if (tail == curr)
    {
        tail = curr->next; // tail ko move kar diya kyoki vo ab delete hone vala h
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{

    node *n1 = new node(0);
    node *tail = NULL;
    insert(0, 45, tail);
    insert(1, 0, tail);
    insert(2, 1, tail);
    insert(3, 2, tail);
    insert(4, 3, tail);
    insert(5, 4, tail);
    print(tail);
    cout << endl;
    deletion(0, tail);
    print(tail);
    return 0;
}