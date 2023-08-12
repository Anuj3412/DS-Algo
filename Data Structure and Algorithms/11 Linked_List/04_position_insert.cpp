#include <bits/stdc++.h>
using namespace std;

// node class bana di
class node
{

public:
    int data;
    node *next;

    // constructor bana diya
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// kisi bhi position par insert kar ne ko
void insertPosition(int data, int pos, node *&head, node *&tail)
{
    // boundary condition h --> first place par add karne k liye (head insertion lagega )
    if (pos == 1 or pos == 0)
    {
        // create a new node and make it head of the list.
        node *newNode = new node(data);
        newNode->next = head;
        head = newNode;
        return;
    }

    // yaha count measure kar k --> us position tak paunchna h jaha add karna h
    int cnt = 1;
    node *temp = head;
    while (cnt < pos - 1) // ( pos - 1 ) is done because we have to stay a node before position
    {
        if (temp->next == NULL)
            break;
        temp = temp->next;
        cnt++;
    }

    // apna pointer jaha add karna h --> uske previous position par pauch gya h
    if (temp->next == NULL)
    {
        node *newNode = new node(data);
        temp->next = newNode;
        tail = newNode;
        return;
    }

    // create node and insert
    node *temp1 = new node(data);
    temp1->next = temp->next;
    temp->next = temp1;
}

// ye tail insertion h fill karne ko list ko
void insert(int data, node *&tail)
{
    node *temp = new node(data);
    tail->next = temp; // current node is attached to the new node created on tail
    tail = temp;       // tail pointer is changed to next node created for further attachment
}

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
    node *head = new node(10);
    node *tail = head; // ye pointer change hota rahega or last node ko represent karega
    insert(20, tail);
    insert(30, tail);
    insert(40, tail);
    insert(50, tail);
    insertPosition(60, 8, head, tail);
    printList(head);
    cout << endl;
    printList(tail);

    return 0;
}