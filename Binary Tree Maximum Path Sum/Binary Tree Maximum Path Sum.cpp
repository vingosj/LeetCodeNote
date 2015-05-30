/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <math.h> 
 
//   2015-5-29 
//   Hint#: there are totally two kind of path to check:
//          1. path not across any "root" node
//          2. path do across a "root" node (can be regard as left part and right part)

static int maxpath(TreeNode* node, int& result){
    if(node == NULL) return 0;
    
    int left = maxpath(node->left, result);
    int right = maxpath(node->right, result);
    
    // max value link with left/right node
    int maxsubpath = node->val + fmax(fmax(left, right), 0);
    
    // max value link with current node
    int max = node->val;
    if(left > 0) max += left;
    if(right > 0) max += right;
    //max = fmax(max, node->val);
    
    if(max > result) result = max;
    return maxsubpath;
}
 
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        int result = root->val;
        
        maxpath(root, result);
        
        return result;
    }
};