// Time Complexity : O(NLogN)
// Space Complexity : O(n) / O(logN)


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

// Function to merge the sorted list

node *merge(node *head1, node *head2)
{
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    // for single element
    if (head1->next == NULL)
    {
        head1->next = head2;
        return head1;
    }

    // merging
    node *prev = head1;
    node *curr = prev->next;
    node *temp = head2;
    while (curr != NULL and temp != NULL)
    {
        if (prev->data <= temp->data and curr->data >= temp->data)
        {
            prev->next = temp;
            prev = temp;
            temp = temp->next;
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

// Merge Sort in Linked List
node *mergeSort(node *head)
{
    // base case
    if (head == NULL or head->next == NULL)
    {
        return head;
    }

    // break the list in two parts
    node *fast = head;
    node *slow = head;
    node *mid = NULL;
    while (fast->next != NULL and fast->next->next != NULL)
    {
      
        fast = fast->next->next;
        slow = slow->next;
    }
    mid = slow;
    


    // seprate it into two parts
    node *left = head;
    node *right = mid->next;
    mid->next = NULL;

    // recursive call
    left = mergeSort(left);
    right = mergeSort(right);

    // merge these sorted list
    node *ans = NULL;
    if (left->data <= right->data)
    {
        ans = merge(left, right);
    }
    else
    {
        ans = merge(right, left);
    }
    return ans;
}

int main()
{

    node *head = new node(2);
    insert(0, head);
    insert(5, head);
    insert(6, head);
    insert(7, head);
    insert(8, head);
    insert(9, head);
    print(head);
    node *ans = mergeSort(head);
    print(ans);

    return 0;
}