/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <vector>
 
//   2015-6-2 
 
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if(root == NULL) return result;
        
        vector<TreeNode*> list;
        list.push_back(root);
        int level = 1, nextLevel = 0, i = 0;
        
        while(list.size() > 0){
            if(list[i]->left != NULL){
                list.push_back(list[i]->left);
                nextLevel++;
            }
            if(list[i]->right != NULL){
                list.push_back(list[i]->right);
                nextLevel++;
            }
            
            if(++i == level){
                result.push_back(list[i-1]->val);
                list.erase(list.begin(), list.begin() + level);
                level = nextLevel;
                nextLevel = 0;
                i = 0;
            }
        }
        
        return result;
    }
};