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


// Sorted List
void delete_duplicates(node *&head)
{

    if (head == NULL)
        return;

    node *curr = head;
    while (curr->next != NULL)
    {

        if (curr->data != curr->next->data)
        {
            curr = curr->next;
        }
        else
        {
            curr->next = curr->next->next;
        }
    }
}

// Unsorted List
// 1. O(n^2) time complexity -- stay on one element and delete all its duplicate
// 2. O(n) space complexity - use a hashmap, where key is the value of each element in list and mark it as visited
// 3. sort it -- then delete it
void delete_dup(node *&head) // normal nested loops
{

    node *curr = head;
    while (curr != NULL)
    {
        node *temp = curr;
        while (temp->next != NULL)
        {

            if (temp->next->data != curr->data)
            {
                temp = temp->next;
            }
            else
            {
                temp->next = temp->next->next;
            }
        }

        curr = curr->next;
    }
}

void delete_dup2(node *&head) // using map method
{
    if (head == NULL)
        return;
    map<int, bool> mp;
    node *temp = head;

    // insert in map all nodes value as false
    while (temp != NULL)
    {
        mp[temp->data] = false;
        temp = temp->next;
    }

    node *curr = head;
    mp[head->data] = true;
    while (curr != NULL)
    {
        if (curr->next != NULL and mp[curr->next->data] == false)
        {
            mp[curr->next->data] = true;
            curr = curr->next;
        }
        else if (curr->next != NULL and mp[curr->next->data] == true)
        {
            curr->next = curr->next->next;
            print(head);
        }

        else
        {
            curr = curr->next;
        }
    }
}
int main()
{

    node *head = new node(0);
    insert(0, head);
    insert(1, head);
    insert(0, head);
    insert(2, head);
    insert(2, head);
    insert(1, head);
    print(head);
    cout << "after deleting duplicate " << endl;
    delete_dup2(head);
    cout << endl;
    print(head);
    return 0;
}