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

// Time complexity O(m+n) , space complexity O(1)
/*

-- iterate one list with two pointers -- prev and curr
-- another with one -- keep checking to put it in between prev and curr
-- change the prev to prev->next -- check if more can be inserted in between

*/
node *merge_sorted(node *&head1, node *&head2)
{
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    node *prev = head1;
    node *curr = prev->next;
    node *temp = head2;

    // for single element
    if (curr == NULL)
    {
        prev->next = temp;
        return head1;
    }
    while (curr != NULL and temp != NULL)
    {
        if (temp->data <= curr->data and prev->data <= temp->data)
        {
            prev->next = temp;
            temp = temp->next;
            prev = prev->next;
            prev->next = curr;
        }
        else
        {
            prev = curr;
            if (curr->next == NULL and temp != NULL)
            {
                curr->next = temp;
                break;
            }
            else
            {
                curr = curr->next;
            }
        }
    }

    return head1;
}


int main()
{

    node *head1 = new node(17);
    insert(13, head1);
    insert(9, head1);
    insert(5, head1);
    insert(2, head1);
    insert(1, head1);
    node *head2 = new node(12);
    insert(10, head2);
    insert(8, head2);
    insert(6, head2);
    insert(4, head2);
    insert(2, head2);
    print(head1);
    print(head2);
    // this is done to check -- which list we have to start with
    if (head1->data <= head2->data)
    {
        head1 = merge_sorted(head1, head2);
        print(head1);
    }
    else if (head1->data > head2->data)
    {
        head2 = merge_sorted(head2, head1);
        print(head2);
    }

    return 0;
}