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
                Node* ogHead = head;
                while(ogHead!=temp->random and ogHead!=NULL){
                    dist++;
                    ogHead = ogHead->next;
                }
                Node* clHead = copyHead;
                while(dist>0){
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

// with map approach

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        map<Node* , Node*> mp;
    }
};