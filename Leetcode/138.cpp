/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// without MAP approach
// TC = O(n^2)
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (head == NULL)
            return NULL;
        Node *copy = new Node(-1);
        Node *copyHead = copy;
        Node *temp = head;
        while (temp != NULL)
        {
            Node *nodeCopy = new Node(temp->val);
            copy->next = nodeCopy;
            copy = nodeCopy;
            temp = temp->next;
        }
        copyHead = copyHead->next;
        temp = head;
        Node *temp2 = copyHead;
        while (temp != NULL)
        {
            if (temp->random == NULL)
                temp2->random = NULL;
            else
            {
                int dist = 0;
                Node *ogHead = head;
                while (ogHead != temp->random and ogHead != NULL)
                {
                    dist++;
                    ogHead = ogHead->next;
                }
                Node *clHead = copyHead;
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
};

/*
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// with map approach

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *newList = new Node(-1);
        Node *temp = head;
        Node *cloneHead = newList;
        while (temp != NULL)
        {
            Node *temp2 = new Node(temp->val);
            cloneHead->next = temp2;
            cloneHead = temp2;
            temp = temp->next;
        }

        cloneHead = newList->next;
        temp = head;
        Node *temp2 = cloneHead;
        map<Node *, Node *> mp;
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

            temp2->random = mp[curr];
            temp = temp->next;
            temp2 = temp2->next;
        }
        return cloneHead;
    }
};
/*
// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// With changing Links

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {   
        if(head== NULL) return NULL;
        // clone the  list
        Node *temp = head;
        Node *newList = new Node(-1);
        Node *cloneHead = newList;
        while (temp != NULL)
        {
            Node *temp2 = new Node(temp->val);
            cloneHead->next = temp2;
            cloneHead = temp2;
            temp = temp->next;
        }
        temp = head;
        cloneHead = newList->next;

        // change the links
        Node *temp2 = cloneHead;
        while (temp != NULL)
        {
            Node *nex1 = temp->next;
            temp->next = temp2;
            Node *nex2 = temp2->next;
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
            if (temp == NULL)
            {
                temp2->next = NULL;
                temp2 = NULL;
                break;
            }
            temp2->next = temp->next;
            temp2 = temp->next;
        }

        return cloneHead;
    }
};