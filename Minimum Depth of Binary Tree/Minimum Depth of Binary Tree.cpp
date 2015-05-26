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

static int path(TreeNode* node){
    if(node->left == NULL && node->right == NULL) return 1;
    else if(node->left != NULL && node->right != NULL){
        int left = path(node->left);
        int right = path(node->right);
        return left < right ? left + 1 : right + 1;
    }
    else{
        if(node->left != NULL) return path(node->left)+1;
        else return path(node->right)+1;
    }
}

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        else return path(root);
    }
};