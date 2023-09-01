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

// Approach - 1
// Time Complexity O(n)
node * middle(node* &head)
{
    node* mid = head;
    int len = length(head);
    int i = 0;
        while (i < len / 2)
        {
            mid = mid->next;
            i++;
        }
    
    
    
    return mid;
}

// Approach - 2 ---- (considering two pointers FAST and SLOW ---- as fast reaches end slow will be at mid)
//  Time  Cmomplexity O(n)

node *midd(node *head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* reverse(node* &head , node* prev){

    //base condition
    if(head==NULL or head->next == NULL){
        head->next = prev;
        return head;
    }

    node* nex = head->next;
    head->next = prev;
    prev = head;
    head = nex;
    reverse(head , prev);
    
}

void merge(node* &head1 , node* &head2 ){
    node*temp1 = head1;
    node*temp2 = head2;
    while(temp1->next!=NULL and temp2->next != NULL){
        node* nex1 = temp1->next;
        node* nex2 = temp2->next;
        temp1->next = temp2;
        temp2=nex1 ;
        temp1= nex1;
        temp2= nex2;
    }
}

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
    node *mid = middle(head);
    node* head2 = mid;
    cout<<head2->data<<endl;
    reverse(head2 , NULL);
    print(head);
    print(head2);
    merge(head , head2);
    print(head);


    return 0;
}