// Also known as Floyyd Loop Detection Algorithm :

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

void make_circle(node *&head)
{

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}

// normal iteration -- T.C = O(n) -- S.C = O(n)
bool circular_check(node *head)
{
    if (head == NULL or head->next == head)
        return true;

    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next == head)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Slow -- fast pointer approach
// T.C = O(n) ----- S.C = O(1)

bool detect_loop(node *head)
{
    if (head == NULL)
        return false;
    node *slow = head;
    node *fast = head;
    while (fast->next != NULL and fast != NULL)
    {
        if (slow == fast)
            return true;

        slow = slow->next;
        fast = fast->next->next;
    }
    return false;
}
// Using Map
// T.C = O(n)  ----  S.C = O(n)
bool check_loop(node *head)
{

    map<node *, bool> mp;
    auto it = mp.begin(); // iterator for map
    node *curr = head;
    while (curr->next != NULL)
    {
        if (mp[curr] == true) // to check if  it is visited or not
            return true;
        else
        {
            mp[curr] = true; // changing the value to true after visiting
        }
        curr = curr->next;
    }

    return false;
}

/*
    -- we get the intersection point
    -- at intersection point
    --- distance of fast(at intersection point) from loop start == distance of slow(at head) from loop start
    -- now , slow is at head
    -- fast is at inersectioin point
    --- we move one step each
    -- next meeting at loop starting point
*/

node *loop_start(node *head)
{
    if (head == NULL)
        return NULL;
    node *slow = head;
    node *fast = head;

    // with this loop we get to the position of first intersection
    while (fast->next != NULL and fast != NULL)
    {
        if (slow == fast)
            break;
        slow = slow->next;
        fast = fast->next;
    }

    // to check if there is a loop or not
    if (slow != fast)
        return NULL;

    // now moving slow to head -- as slow and fast are equal distance for intersection
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}

void remove_loop(node *loop) // here we are passing loop point --- to stay in loop and not start from begining
{

    node *temp = loop;
    while (temp->next != loop)
    {
        temp = temp->next;
    }
    temp->next = NULL;
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
    make_circle(head);
    cout << circular_check(head) << endl;
    cout << check_loop(head) << endl;
    node *n2 = loop_start(head);
    cout << n2->data;

    return 0;
}