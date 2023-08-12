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
    tail->next = temp;
    tail = temp;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void deletion(int pos, node *&head)
{

    // if head is to be deleted
    if (pos == 1)
    {

        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // any other position
    node *temp = head;          // temporary pointer banaya jo move karega
    int cnt = 1;
    while (cnt < pos - 1)
    {
        temp = temp->next;
        cnt++;
    }

    // pointer jo delete karna h uske previous position par h

    node *curr = temp->next;
    temp->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main()
{
    node *head = new node(10);
    node *tail = head;
    insert(20, tail);
    insert(40, tail);
    insert(60, tail);
    insert(80, tail);
    insert(100, tail);
    insert(120, tail);
    print(head);
    deletion(5, head);
    print(head);

    return 0;
}