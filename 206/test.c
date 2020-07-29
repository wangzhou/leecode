/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head)
{
        struct ListNode *ret;

        if (!head)
                return NULL;

        if (!head->next)
                return head;

        ret = reverseList(head->next);
        head->next->next = head;        
        head->next = NULL;

        return ret;
}

