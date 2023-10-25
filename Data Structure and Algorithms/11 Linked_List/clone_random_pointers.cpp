// refer to Leetcode 138

#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next = NULL;
    node *random = NULL;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

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

// tail insertion
void insert(node *&tail, int data)
{

    node *n1 = new node(data);
    tail->next = n1;
    tail = n1;
}
// Clone the linked list with random pointers
// Approach - 1
/*

    -- clone normally the list
    -- now iterate through original to find the random pointers
    -- now iterate through the clone to join the randoms
    return the clone list


*/

// Approach - 2
/*

    // using map
    -- store mapping of node in original list and the node in clone list
    -- use the stored mapping to connect random pointer of clone list.
    return the clone list

    
*/

int main()
{   
    node* head = new node(1);
    node* tail = head;
    insert(tail , 2);
    insert(tail , 3);
    insert(tail , 4);
    insert(tail , 5);
    insert(tail , 6);
    insert(tail , 7);
    print(head);

    return 0;
}


