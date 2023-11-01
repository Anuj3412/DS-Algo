
/* Node structure  used in the program

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};
*/

/*  Function which returns the  root of
    the flattened linked list. */

Node *merge(Node *head1, Node *head2)
{
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    Node *newList = new Node(-1);
    Node *a = head1;
    Node *b = head2;
    Node *c = newList;

    while (a != NULL and b != NULL)
    {
        if (a->data <= b->data)
        {
            Node *temp = new Node(a->data);
            c->bottom = temp;
            c = c->bottom;
            a = a->bottom;
        }
        else if (a->data > b->data)
        {
            Node *temp = new Node(b->data);
            c->bottom = temp;
            c = c->bottom;
            b = b->bottom;
        }
    }

    if (a == NULL and b != NULL)
    {
        c->bottom = b;
    }
    else if (a != NULL and b == NULL)
    {
        c->bottom = a;
    }

    newList = newList->bottom;

    return newList;
}

Node *flatten(Node *root)
{
    // Your code here
    Node *head = root;
    // base condition
    if (root == NULL)
        return root;

    // recursive call
    head->next = flatten(head->next);

    // merge the two list
    head = merge(head, head->next);

    return head;
}


/*

-- using recursion for flattning
-- untill we reach last node
-- then merge them in sorted order

*/