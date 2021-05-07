/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
        struct ListNode* head, *cur, *a1, *a2, *tmp;
        int f = 0, v1, v2;

        if (!l1 || !l2)
                return NULL;

        head = malloc(sizeof(*head));        
        if (!head)
                return NULL;
        cur = head;
        a1 = l1;
        a2 = l2;

        while (1) {
                if (!a1)
                        v1 = 0;
                else
                        v1 = a1->val;

                if (!a2)
                        v2 = 0;
                else
                        v2 = a2->val;

                cur->val = (v1 + v2 + f) % 10;
                f = (v1 + v2 + f) / 10;

                if (a1 && !a1->next && a2 && !a2->next) {
                        if (!f) {
                                break;
                        } else {
                                tmp = malloc(sizeof(*head));
                                if (!tmp)
                                        return NULL; // leak memory here
                                tmp->val = f;                                
                                tmp->next = NULL;                                
                                cur->next = tmp;
                                break;
                        }
                }

                if (!a1 && !a2->next)
                        break;

                if (!a2 && !a1->next)
                        break;
                        
                tmp = malloc(sizeof(*head));
                if (!tmp)
                        return NULL; // leak memory here
                tmp->next = NULL;
                cur->next = tmp;
                cur = tmp;

                if (a1)
                        a1 = a1->next;
                if (a2)
                        a2 = a2->next;
        }        

        return head;
}
