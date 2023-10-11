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

void make_circle(node *&head)
{

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
}

// Using Map
// T.C = O(n)  ----  S.C = O(n)
bool check_circle(node *head)
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

node *loop_start(node *head)
{
    if (head == NULL)
        return NULL;
    node *slow = head;
    node *fast = head;

    // with this loop we get to the position of first intersection
    while (fast->next != NULL and fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
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
    return fast;
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
        }

        else
        {
            curr = curr->next;
        }
    }
}

// Function to sort 0 1 2
// 1. keep count of 0 1 2 --- change the data of the list accordingly
// Time Complexity -- O(n) , space -- O(1)
void sort012(node *&head)
{
    if (head == NULL)
        return;

    int oneCount = 0;
    int zeroCount = 0;
    int twoCount = 0;
    node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zeroCount++;
        else if (temp->data == 1)
            oneCount++;
        else if (temp->data == 2)
            twoCount++;
        temp = temp->next;
    }

    temp = head;
    while (zeroCount)
    {
        temp->data = 0;
        temp = temp->next;
        zeroCount--;
    }

    while (oneCount)
    {
        temp->data = 1;
        temp = temp->next;
        oneCount--;
    }
    while (twoCount)
    {
        temp->data = 2;
        temp = temp->next;
        twoCount--;
    }
}

// 2. creating new list -- adding zeros -- ones -- twos
// T.C == O(n) , S.C == O(n)
void sort012_2(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head;
    node *list = new node(-1);
    node *listHead = list;
    // adding zeros
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            node *n1 = new node(0);
            list->next = n1;
            list = n1;
        }
        temp = temp->next;
    }
    // adding ones
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == 1)
        {
            node *n1 = new node(1);
            list->next = n1;
            list = n1;
        }
        temp = temp->next;
    }

    // adding twos
    temp = head;
    while (temp != NULL)
    {
        if (temp->data == 2)
        {
            node *n1 = new node(2);
            list->next = n1;
            list = n1;
        }
        temp = temp->next;
    }
    head = listHead->next;
}

// 3. creating 3 new list -- merging them
void sort012_1(node* &head){
    if(head==NULL) return;
    node* temp = head;
    node* l1 = new node(-1);
} 

int main()
{

    node *head = new node(2);
    insert(0, head);
    insert(2, head);
    insert(0, head);
    insert(1, head);
    insert(1, head);
    insert(0, head);
    print(head);
    reverse_1(head);
    print(head);
    reverse_2(head, head, NULL);
    print(head);
    cout << "mid at " << mid_1(head)->data << endl;
    cout << "mid at " << mid_2(head)->data << endl;
    // node *n1 = k_order(head, 4);
    // print(n1);
    make_circle(head);
    cout << "is circle " << circular_check(head) << endl;
    cout << "is circle " << check_circle(head) << endl;
    node *n2 = loop_start(head);
    cout << "loop starting at " << n2->data << endl;
    remove_loop(n2);
    print(head);
    cout << "is loop " << check_circle(head) << endl;
    print(head);
    cout << "after deleting duplicate " << endl;
    // delete_duplicates(head);
    // print(head);
    // delete_dup2(head);
    // cout << endl;
    print(head);
    sort012_2(head);
    print(head);

    return 0;
}