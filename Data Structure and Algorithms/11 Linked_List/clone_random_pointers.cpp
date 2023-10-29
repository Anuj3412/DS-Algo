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

    T.C = O(n^2)

*/

node *copyRandomList(node *head)
{
    if (head == NULL)
        return NULL;
    node *copy = new node(-1);
    node *copyHead = copy;
    node *temp = head;
    while (temp != NULL)
    {
        node *nodeCopy = new node(temp->data);
        copy->next = nodeCopy;
        copy = nodeCopy;
        temp = temp->next;
    }
    copyHead = copyHead->next;
    temp = head;
    node *temp2 = copyHead;
    while (temp != NULL)
    {
        if (temp->random == NULL)
            temp2->random = NULL;
        else
        {
            int dist = 0;
            node *ogHead = head;
            while (ogHead != temp->random and ogHead != NULL)
            {
                dist++;
                ogHead = ogHead->next;
            }
            node *clHead = copyHead;
            while (dist > 0)
            {
                clHead = clHead->next;
                dist--;
            }
            temp2->random = clHead;
        }
        temp2 = temp2->next;
        temp = temp->next;
    }
    return copyHead;
}

// using MAP Method 
// Approach - 2
/*

    // using map
    -- store mapping of node in original list and the node in clone list
    -- use the stored mapping to connect random pointer of clone list.
    return the clone list

    T.C = O(n)
    S.C = O(n)

*/

node *copyRandomList2(node *head)
{
    node *newList = new node(-1);
    node *temp = head;
    node *cloneHead = newList;
    while (temp != NULL)
    {
        node *temp2 = new node(temp->data);
        cloneHead->next = temp2;
        cloneHead = temp2;
        temp = temp->next;
    }

    cloneHead = newList->next;
    temp = head;
    node *temp2 = cloneHead;
    map<node *, node *> mp;
    while (temp != NULL)
    {
        mp[temp] = temp2;
        temp = temp->next;
        temp2 = temp2->next;
    }

    temp = head;
    temp2 = cloneHead;
    while (temp != NULL)
    {

        temp2->random = mp[temp->random];
        temp = temp->next;
        temp2 = temp2->next;
    }
    return cloneHead;
}

// changing links
// Approach - 3
/*

    -- clone normally the list
    -- now add the clone nodes in between the original node : 1 1 2 2 3 3 4 4  in this way
    -- iterate through the new list
    -- since the random of the original are previous of the clone random nodes
    -- change links in that way
    -- revert the changes in the list made earlier
    -- return the clone list
    return the clone list

    T.C = O(n)
    S.C = O(1)


*/

node *change_link(node *head)
{   
    if(head==NULL) return NULL;
    // clone the  list
    node *temp = head;
    node *newList = new node(-1);
    node *cloneHead = newList;
    while (temp != NULL)
    {
        node *temp2 = new node(temp->data);
        cloneHead->next = temp2;
        cloneHead = temp2;
        temp = temp->next;
    }
    temp = head;
    cloneHead = newList->next;

    // change the links
    node *temp2 = cloneHead;
    while (temp != NULL)
    {
        node *nex1 = temp->next;
        temp->next = temp2;
        node *nex2 = temp2->next;
        temp2->next = nex1;
        temp2 = nex2;
        temp = nex1;
    }

    temp = head;
    temp2 = cloneHead;
    // connect the random pointers
    while (temp != NULL)
    {
        if (temp->random == NULL)
            temp->next->random = NULL;
        else
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    temp = head;
    temp2 = head->next;
    // revert the changes in the original list
    while (temp != NULL)
    {
        temp->next = temp2->next;
        temp = temp2->next;
        if(temp==NULL){
            temp2->next = NULL;
            temp2 = NULL;
            break;
        }
        temp2->next= temp->next;
        temp2=temp->next;
    }

    return cloneHead;
}

int main()
{
    node *head = new node(1);
    node *tail = head;
    insert(tail, 2);
    insert(tail, 3);
    insert(tail, 4);
    insert(tail, 5);
    insert(tail, 6);
    insert(tail, 7);
    print(head);

    return 0;
}
