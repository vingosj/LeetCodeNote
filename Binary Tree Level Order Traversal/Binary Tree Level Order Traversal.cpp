/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <queue> 

//   2015-5-31 
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        vector<int> entry;
        int level = 1, nextLevel = 0;
        while(nodes.size() != 0){
            TreeNode* node = nodes.front();
            nodes.pop();
            
            if(level == 0){
                level = nextLevel;
                nextLevel = 0;
                result.push_back(entry);
                entry.clear();
            }
            level--;
            
            entry.push_back(node->val);
            
            if(node->left != NULL){
                nodes.push(node->left);
                nextLevel++;
            }
            if(node->right != NULL){
                nodes.push(node->right);
                nextLevel++;
            }
        }
        if(entry.size() != 0) result.push_back(entry);
        
        return result;
    }
};