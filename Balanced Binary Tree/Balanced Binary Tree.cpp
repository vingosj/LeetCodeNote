/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <stdlib.h>

static bool Balance(TreeNode* node, int& height){
    if(node == NULL){
        height = 0;
        return true;
    }
    
    int left = 0, right = 0;
    if(!Balance(node->left, left) || !Balance(node->right, right) || abs(left-right) > 1){
        return false;
    }
        
    height = left > right ? left + 1 : right + 1;
    return true;
} 
 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int height = 0;
        return Balance(root, height);
    }
};