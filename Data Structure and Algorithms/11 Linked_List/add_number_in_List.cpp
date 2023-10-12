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
// adding two numbers -- represented in form of linked list
/*
1.

-- reverse both numbers
-- covert them into integer
-- add them
-- convert it into list
-- reverse the list
-- return list
-- TC O(n) , SC O(n)

*/

node *addList(node *head1, node *head2)
{
    int sum1 = 0;
    int sum2 = 0;
    node *temp1 = head1;
    node *prev = NULL;
    node *temp2 = head2;
    while (temp1 != NULL)
    {
        node *nex = temp1->next;
        temp1->next = prev;
        prev = temp1;
        temp1 = nex;
    }
    head1 = prev;
    prev = NULL;
    while (temp2 != NULL)
    {
        node *nex = temp2->next;
        temp2->next = prev;
        prev = temp2;
        temp2 = nex;
    }
    head2 = prev;
    temp1 = head1;
    temp2 = head2;
    int p = 1;
    while (temp1 != NULL)
    {
        sum1 = sum1 + temp1->data * p;
        p = p * 10;
        temp1 = temp1->next;
    }
    p = 1;
    while (temp2 != NULL)
    {
        sum2 = sum2 + temp2->data * p;
        p = p * 10;
        temp2 = temp2->next;
    }

    int totalSum = sum1 + sum2;
    node *ans = new node(-1);
    node *temp = ans;
    while (totalSum)
    {
        node *n1 = new node(totalSum % 10);
        temp->next = n1;
        temp = n1;
        totalSum = totalSum / 10;
    }

    prev = NULL;
    node *temp3 = ans->next;
    while (temp3 != NULL)
    {
        node *nex = temp3->next;
        temp3->next = prev;
        prev = temp3;
        temp3 = nex;
    }
    ans->next = prev;

    return ans->next;
}

/*

2.

-- reverse the list numbers
-- add them with taking carry
-- reverse the final list
-- return the list
-- TC O(n) , SC O(n)

*/

node *addList_2(node *head1, node *head2)
{
    node *ans = new node(-1);
    node *ansHead = ans;
    int carry = 0;
    // reverse these list
    node *curr1 = head1;
    node *curr2 = head2;
    node *prev = NULL;
    while (curr1 != NULL)
    {
        node *next = curr1->next;
        curr1->next = prev;
        prev = curr1;
        curr1 = next;
    }
    head1 = prev;
    prev = NULL;
    while (curr2 != NULL)
    {
        node *next = curr2->next;
        curr2->next = prev;
        prev = curr2;
        curr2 = next;
    }
    head2 = prev;
    curr1 = head1;
    curr2 = head2;
    while (curr1 != NULL or curr2 != NULL)
    {
        int sum = 0;
        if (curr1 == NULL)
            sum = carry + curr2->data;
        else if (curr2 == NULL)
            sum = carry + curr1->data;
        else
            sum = carry + curr1->data + curr2->data;
        int digit = sum % 10;
        node *n1 = new node(digit);
        carry = sum / 10;
        ans->next = n1;
        ans = n1;
        if (curr1 == NULL)
            curr2 = curr2->next;
        else if (curr2 == NULL)
            curr1 = curr1->next;
        else
        {
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
    }
    ansHead = ansHead->next;
    reverse_1(ansHead);

    return ansHead;
}
int main()
{

    node *head = new node(4);
    insert(3, head);
    insert(2, head);
    insert(1, head);
    node *head2 = new node(0);
    insert(7, head2);
    insert(1, head2);
    insert(2, head2);
    cout<<"List 1: ";
    print(head);
    cout<<"List 2: ";
    print(head2);
    node *n1 = addList_2(head, head2);
    // print(head);
    // print(head2);
    print(n1);

    return 0;
}