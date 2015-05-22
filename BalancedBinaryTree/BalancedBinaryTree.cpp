/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#include <stack>
#include <stdlib.h>
 
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        
        TreeNode* head = root;
        stack<TreeNode*> dfs;
        dfs.push(root);
        
        // set all notes to ZERO
        while(dfs.size() == 0){
            TreeNode* temp = dfs.top();
            temp->val = 0;
            dfs.pop();
            
            if(temp->left != NULL) dfs.push(temp->left);
            if(temp->right != NULL) dfs.push(temp->right);
        }
        
        // re-assgin value for every nodes
        dfs.push(root);
        while(dfs.size() == 0){
            TreeNode* temp = dfs.top();
            
            if(temp->left != NULL && temp->right != NULL){
                int left = temp->left->val;
                int right = temp->right->val;
            
                if(left > 0 && right > 0){
                    if(abs(left-right) > 1) return false;
                    else{
                        temp->val = left >= right ? left + 1 : right + 1;
                        dfs.pop();
                    }
                }
                else{
                    if(left == 0){
                        dfs.push(temp->left);
                    }
                    if(right == 0){
                        dfs.push(temp->right);
                    }
                }
            }
            else if(temp->left == NULL && temp->right == NULL)
            {
                temp->val = 1;
                dfs.pop();
            }
            else{
                if(temp->left == NULL && temp->right->val == 0){
                    dfs.push(temp->right);
                }else if(temp->left == NULL && temp->right->val > 0){
                    if(temp->right->val > 1) return false;
                    temp->val = temp->right->val + 1;
                    dfs.pop();
                }else if(temp->right == NULL && temp->left->val == 0){
                    dfs.push(temp->left);
                }else if(temp->right == NULL && temp->left->val > 0){
                    if(temp->left->val > 1) return false;
                    temp->val = temp->left->val + 1;
                    dfs.pop();
                }
            }
        }
        
        return true;
    }
};