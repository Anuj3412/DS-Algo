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


// Time Complexity = O(n) -- Space complexity == O(1)
void delete_duplicates(node *&head)
{

    if (head == NULL)
        return;

    node *curr = head;
    while (curr->next != NULL)
    {

        if (curr->data != curr->next->data) // jab tak equal nahi h adjacent --- move karte jao
        {
            curr = curr->next;
        }
        else    // duplicate ko delete kar diya -- age move nahi kiye check karne se phle
        {
            curr->next = curr->next->next;
        }
    }
}
int main()
{

    node *head = new node(60);
    insert(50, head);
    insert(50, head);
    insert(50, head);
    insert(20, head);
    insert(10, head);
    insert(0, head);
    print(head);
    cout << "after deleting duplicate " << endl;
    delete_duplicates(head);
    print(head);
    return 0;
}