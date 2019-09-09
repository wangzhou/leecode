/*
 * change  a -> b -> c -> d to a <- b <- c <- d
 *
 * first is pointer to a, last is pointer to d
 */
void reverse(struct ListNode* first, struct ListNode* last)
{
       if (first == last) {
               return;
       } else {
                reverse(first->next, last);
                first->next->next = first;
       }
}
        
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k)
{
        struct ListNode *first_in_k, *last_in_k, *last_1, *curr, *ret = head;
        struct ListNode **pre_first;
        int i, ret_flag = 0;
                
        if (!head)
                return NULL;
        
        curr = first_in_k = head;
        pre_first = &head;
        do {
                for (i = 0; i < k - 1; i++) {
                        if (!curr->next) 
                                break;
                        else 
                                curr = curr->next;
                }
                
                if (i != k - 1) {
                        break;
                } else {
                        last_in_k = curr;
                        last_1 = curr->next;
                        
                        /* revert list begin at first_in_k and end at last_in_k */
                        *pre_first = last_in_k;
                        reverse(first_in_k, last_in_k);
                        first_in_k->next = last_1;
                        
                        if (!ret_flag) {
                                ret = last_in_k;
                                ret_flag = 1;
                        }
                                
                        pre_first = &first_in_k->next;
                        curr = first_in_k = last_1;
                }
        } while (curr);
        
        return ret;
}
