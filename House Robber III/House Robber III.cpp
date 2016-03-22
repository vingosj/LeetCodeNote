//   2016-3-22

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int grandson(TreeNode* node){
        int sum = 0;
        if(node->left){
            if(node->left->left) sum += node->left->left->val;
            if(node->left->right)  sum += node->left->right->val;
        }
        if(node->right){
            if(node->right->left) sum += node->right->left->val;
            if(node->right->right) sum += node->right->right->val;
        }
        return sum;
    }

    int calculate(TreeNode* node){
        if(!node->left && !node->right) return node->val;
        
        int child = 0, self = 0;
        if(node->left) child += calculate(node->left);
        if(node->right) child += calculate(node->right);
        self = node->val + grandson(node);
        node->val = self > child ? self : child;
        return node->val;
    }

    int rob(TreeNode* root) {
        if(!root) return 0;
        calculate(root);
        return root->val;
    }
};