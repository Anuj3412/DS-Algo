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

    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insert(int data, node *&tail)
{

    node *temp = new node(data);
    tail->next = temp;
    tail = temp;
}

int length(node *head)
{
    int len = 0;
    while (head != NULL)
    {
        len++;
        head = head->next;
    }
    return len;
}

// Approach - 2 ---- (considering two pointers FAST and SLOW ---- as fast reaches end slow will be at mid)
//  Time  Cmomplexity O(n)

node *getMiddle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast)
    {
        if (!fast->next or !fast->next->next)
            return slow;
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

node *reverse(node *&head, node *prev)
{

    // base condition
    if (head == NULL or head->next == NULL)
    {
        head->next = prev;
        return head;
    }

    node *nex = head->next;
    head->next = prev;
    prev = head;
    head = nex;
    reverse(head, prev);
}

void merge(node *&head1, node *&head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
   while(temp1!=NULL and temp2!=NULL){
    node* nex = temp1->next;
    temp1->next = temp2;
    node* nex2 = temp2->next;
    temp2->next = nex;
    temp1=nex;
    temp2=nex2;
   }
}

/* 

1. get the middle element
2. cut the list in two halves
3. reverse the right part 
4. merge them as per requirement

space Complexity : O(1)
Time Complexity : O()



 */
int main()
{

    node *head = new node(10);
    node *tail = head;
    insert(20, tail);
    insert(30, tail);
    insert(40, tail);
    insert(50, tail);
    insert(60, tail);
    insert(70, tail);
    insert(80, tail);
    print(head);
    node* mid = getMiddle(head);
    node * right = mid->next;
    mid->next = NULL;
    reverse(right , NULL);
    merge(head , right);
    print(head);
    return 0;
}