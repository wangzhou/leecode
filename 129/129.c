/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#include <math.h>

int array[20];
int ind = 0;
int sum = 0;

void pre_order_tree(struct TreeNode *root)
{
        int i, tmp = 0;

        array[ind] = root->val;
        ind++;

        if (!root->left && !root->right) {
                for (i = ind - 1; i >=0; i--) {
                        tmp += array[i] * pow(10, (ind - i - 1));
                }
                
                sum += tmp;
                ind--;
        }

        if (root->left)
                pre_order_tree(root->left);
        if (root->right) {
                pre_order_tree(root->right);
                ind--;
        }
}

int sumNumbers(struct TreeNode *root)
{
        if (!root)
                return 0;

        pre_order_tree(root);

        return sum;
}
