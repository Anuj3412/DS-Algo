#include <bits/stdc++.h>
using namespace std;

class node
{

public:
    int data;
    node *next = NULL;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void print(node *&head)
{

    if (head == NULL)
    {
        cout << "Empty List"
             << " ";
        return;
    }

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void insert(int data, node *&head)
{
    if (head == NULL)
    {
        node *temp = new node(data);
        head = temp;
        return;
    }
    node *temp = new node(data);
    temp->next = head;
    head = temp;
}

// Function to sort 0 1 2
// 1. keep count of 0 1 2 --- change the data of the list accordingly
void sort012(node *&head)
{
    if (head == NULL)
        return;

    int oneCount = 0;
    int zeroCount = 0;
    int twoCount = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zeroCount++;
        else if (temp->data == 1)
            oneCount++;
        else if (temp->data == 2)
            twoCount++;
        temp = temp->next;
    }

    temp = head;
    while (zeroCount)
    {
        temp->data = 0;
        temp = temp->next;
        zeroCount--;
    }

    while (oneCount)
    {
        temp->data = 1;
        temp = temp->next;
        oneCount--;
    }
    while (twoCount)
    {
        temp->data = 2;
        temp = temp->next;
        twoCount--;
    }
}

// 2. creating new list -- adding zeros -- ones -- twos
// T.C == O(n) , S.C == O(n)
void sort012_2(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head;
    node *list = new node(-1);
    node *listHead = list;
    // adding zeros
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            node *n1 = new node(0);
            list->next = n1;
            list = n1;
        }
        temp = temp->next;
    }
    // adding ones
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == 1)
        {
            node *n1 = new node(1);
            list->next = n1;
            list = n1;
        }
        temp = temp->next;
    }

    // adding twos
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == 2)
        {
            node *n1 = new node(2);
            list->next = n1;
            list = n1;
        }
        temp = temp->next;
    }
    head = listHead->next;
}

int main()
{

    node *head = new node(2);
    insert(0, head);
    insert(2, head);
    insert(0, head);
    insert(1, head);
    insert(1, head);
    insert(0, head);
    print(head);
    sort012_2(head);
    print(head);

    return 0;
}