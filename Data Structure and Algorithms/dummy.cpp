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
// Time Complexity = O(n) and S.C = O(n)
void sort012_1(node *&head)
{
    if (head == NULL)
        return;
    node *temp = head;
    node *l1 = new node(-1);
    node *l2 = new node(-1);
    node *l0 = new node(-1);
    node *l1Head = l1;
    node *l0Head = l0;
    node *l2Head = l2;

    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            node *n1 = new node(0);
            l0->next = n1;
            l0 = n1;
        }
        else if (temp->data == 1)
        {
            node *n1 = new node(1);
            l1->next = n1;
            l1 = n1;
        }
        else if (temp->data == 2)
        {
            node *n1 = new node(2);
            l2->next = n1;
            l2 = n1;
        }
        temp = temp->next;
    }
    head = l0Head->next;
    l0->next = l1Head->next;
    l1->next = l2Head->next;
}

// comparing one of the list elements
// if it can fit in between two elemnts of other list
// then we merge that element to corresponding list
// Time complexity O(m+n) , space complexity O(1)
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

// adding two numbers -- represented in form of linked list
/*
1.

-- reverse both numbers
-- covert them into integer
-- add them
-- convert it into list
-- reverse the list
-- return list
-- TC O(n+m) , SC O(max(m , n))

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
-- TC O(n+m) , SC O(max(m , n))

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

    // add the digits -- taking carry
    curr1 = head1;
    curr2 = head2;
    while (curr1 != NULL or curr2 != NULL)
    {
        int sum = 0;
        // checking for NULL case
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

        // checking for NULL case

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



*/
node* clone_random(node* head){

}

int main()
{

    node *head = new node(4);
    insert(3, head);
    insert(2, head);
    insert(1, head);
    node *head2 = new node(0);
    insert(2, head2);
    insert(4, head2);
    insert(6, head2);
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
    // sort012_1(head);
    print(head2);
    // if (palindrome_2(head))
    //     cout << "is palindorme "<<endl;
    // else
    //     cout << "is not a palindrome "<<endl;
    node *n1 = addList_2(head, head2);
    print(head);
    print(head2);
    print(n1);
    return 0;
}