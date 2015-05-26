/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
// 2015-5-23 
// Hint#: all the values in left subtree should smaller than current node
//        all the values in right subtree should bigger than current node

static bool valid(TreeNode* node, int& min, int& max){
    min = max = node->val;
    if(node->left == NULL && node->right == NULL) return true;
    if(node->left != NULL){
        int lmin, lmax;
        if(!valid(node->left, lmin, lmax)) return false;
        if(node->val <= lmax) return false;
        min = min < lmin ? min : lmin;
        max = max > lmax ? max : lmax;
    }
    if(node->right != NULL)
    {
        int rmin, rmax;
        if(!valid(node->right, rmin, rmax)) return false;
        if(node->val >= rmin) return false;
        min = min < rmin ? min : rmin;
        max = max > rmax ? max : rmax;
    }
    return true;
} 
 
 
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        int max, min;
        return valid(root, min, max);
    }
};