// 2015-5-23


static bool mirror(TreeNode* p, TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if((p == NULL && q != NULL) || (p != NULL && q == NULL)) return false;
    if(p->val != q->val) return false;
    
    return mirror(p->left, q->right) && mirror(p->right, q->left);
}

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        else return mirror(root->left, root->right);
    }
};