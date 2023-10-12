/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

void solve(ListNode *&head1, ListNode *&head2)
{
    ListNode *prev = head1;
    ListNode *curr = prev->next;
    ListNode *temp = head2;

    // for single element
    if (curr == NULL)
    {
        prev->next = temp;
        return;
    }

    while (curr != NULL and temp != NULL)
    {

        if (prev->val <= temp->val and temp->val < curr->val)
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
}
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {

        if (list1 == NULL)
            return list2;
        else if (list2 == NULL)
            return list1;

        else if (list1->val <= list2->val)
        {
            solve(list1, list2);
            return list1;
        }
        else
        {
            solve(list2, list1);
            return list2;
        }
    }
};