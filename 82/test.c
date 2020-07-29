/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
void remove_node(struct ListNode *first, struct ListNode *second)
{
        struct ListNode *tmp = first, *remove;

        while (tmp != second->next) {
                remove = tmp;
                tmp = tmp->next;
                free(remove);
        }
}

struct ListNode* deleteDuplicates(struct ListNode* head)
{
        struct ListNode* first, *second, *pre = NULL, *tmp_head, *tmp_pre, *tmp_next;
        int find_one_rang = 0;

        pre = tmp_pre = tmp_head = first = second = head;

        /* go through the list */
        while (first && first->next) {
                /* find duplicated range */                
                while (second) {
                        if (first == second) {
                               second = second->next; 
                               tmp_pre = first;
                               continue;
                        }

                        if (tmp_pre->val == second->val) {
                                tmp_pre = second;
                                find_one_rang = 1;
                                if (second->next)
                                        second = second->next;                                
                                else
                                        break;
                        } else {
                                if (!find_one_rang) {
                                        pre = first;
                                        first = second;                                        
                                } else {
                                        second = tmp_pre;
                                        /* find one range, so break to remove it */
                                        break;
                                }

                        }
                }

                /* remove duplicated range and update pointers */                
                if (find_one_rang) {
                        if (pre == first) {
                                pre = tmp_head = tmp_next = second->next;
                                /* remove first -> second */                                
                                //remove_node(first, second);
                                first = second = tmp_next;
                        } else {
                                pre->next = tmp_next = second->next;
                                /* remove first -> second */                                
                                //remove_node(first, second);
                                first = second = tmp_next;
                        }

                        find_one_rang = 0;
                }
        }

        return tmp_head;
}
