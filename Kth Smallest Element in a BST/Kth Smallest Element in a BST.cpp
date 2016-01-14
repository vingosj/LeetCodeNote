/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 2016-1-14

class Solution {
public:
    int find(TreeNode* node, int k, int& count){
        if(node == NULL) return 0;
        
        int result = find(node->left, k, count);
        if(count >= k) return result;
        else if (k == ++count) return node->val;
        else return find(node->right, k, count);
    }

    int kthSmallest(TreeNode* root, int k) {
        int count = 0;
        return find(root, k, count);
    }
};