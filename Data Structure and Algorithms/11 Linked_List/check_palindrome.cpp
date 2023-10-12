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

// check palindrome
// 1. copy data in array -- check array if palindorme or not --- TC O(n) and SC O(n)
// 2. get mid -- reverse after mid part -- compare the parts
bool plaindrome_1(node *head)
{
    vector<int> nums;
    node *temp = head;
    while (temp != NULL)
    {
        nums.push_back(temp->data);
        temp = temp->next;
    }
    int s = 0;
    int n = nums.size();
    int e = n - 1;
    while (s <= e)
    {
        if (nums[s] != nums[e])
            return false;
        s++;
        e--;
    }
    return true;
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

bool palindrome_2(node *head)
{

    node *mid = mid_1(head);
    // reverse second half of linked list
    reverse_1(mid->next);
    // compare the before mid and after mid part
    node *temp = head;
    node *head2 = mid->next;
    while (head2 != NULL)
    {
        if (temp->data != head2->data)
        {
            return false;
        }
        head2 = head2->next;
        temp = temp->next;
    }

    return true;
}

int main()
{
    node *head = new node(1);
    insert(0, head);
    insert(2, head);
    insert(2, head);
    insert(0, head);
    insert(1, head);
    print(head);
    if(palindrome_2(head)) cout<<"is palindrome ";
    else cout<<"is not palindrome ";
    
    return 0;
}