/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
        struct ListNode *first, *second, *pre = NULL, *tmp;
        int gap, i;

        first = second = head;
        gap = n - 1;

        for (i = 0; i < gap; i++) {
                second = second->next;
        }

        while (second->next) {
                pre = first;
                first = first->next;
                second = second->next;
        }

        /* remove first node and return */
        if (first == head) {
                tmp = first->next;
                free(first);
                return tmp;
        } else {
                pre->next = first->next;
                free(first);
                return head;
        }
} 
