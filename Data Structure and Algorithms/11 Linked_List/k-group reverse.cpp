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

void reverse_1(node *&head)
{

    if (head == NULL)
    {
        return;
    }

    node *prev = NULL;
    node *curr = head;
    while (curr != NULL)
    {
        node *nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head = prev;
}

void reverse_2(node *&head, node *curr, node *prev)
{

    // base condition
    if (curr->next == NULL)
    {
        curr->next = prev;
        head = curr;
        return;
    }
    node *nex = curr->next;
    curr->next = prev;
    prev = curr;
    reverse_2(head, nex, prev);
}

node *mid_1(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL and fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

node *mid_2(node *&head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    count = count / 2;
    temp = head;
    while (count != 0)
    {
        temp = temp->next;
        count--;
    }
    return temp;
}

node *k_order(node *head, int k)
{

    // base condition
    if (head == NULL)
        return NULL;

    // step 1 -- reverse first k nodes
    node *curr = head;
    node *prev = NULL;
    node *nex = NULL;

    int count = 0;
    while (curr != NULL and count < k)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
        count++;
    }

    // step 2 -- attach the head node to the last of the next group
    if (curr != NULL)
    {

        head->next = k_order(nex, k);
    }

    // step 3 -- return the last node
    return prev;

    /*

    1. group banaya
    2. usko reverse kiya -- uska head ab last me aayega --- group ka jo last tha vo prev par h
    3. reverse hone pare -- head last me aayega -- prev vala naya head1 ban jayega
    4. ab last me jo h (head) uska uska next -- dusre group k prev (head 1 se jodna h )

    */
}

int main()
{

    node *head = new node(50);
    insert(40, head);
    insert(30, head);
    insert(20, head);
    insert(10, head);
    insert(0, head);
    print(head);
    reverse_1(head);
    print(head);
    reverse_2(head, head, NULL);
    print(head);
    cout << mid_1(head)->data << endl;
    cout << mid_2(head)->data << endl;
    node *n1 = k_order(head, 4);
    print(n1);

    return 0;
}