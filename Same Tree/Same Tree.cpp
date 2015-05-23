/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

static bool Compare(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;
    
    //order(p);
    //order(q);
    if(p->val != q->val) return false;
    return Compare(p->left, q->left) && Compare(p->right, q->right);
} 
 
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return Compare(p, q);
    }
};