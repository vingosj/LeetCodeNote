/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//   2015-5-25
 
static bool Sum(TreeNode* node, int s){
    if(node->left == NULL && node->right == NULL){
        if(s == node->val) return true;
        else return false;
    }
    bool left, right;
    if(node->left != NULL)
        if((left = Sum(node->left, s - node->val)) == true) return true;
    if(node->right != NULL)
        if((right = Sum(node->right, s - node->val)) == true) return true;
    return false;
} 

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        else return Sum(root, sum);
    }
};