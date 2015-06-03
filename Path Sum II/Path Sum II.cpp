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
 
void findpath(
        vector<int> entry, 
        int sum, 
        TreeNode* node, 
        vector<vector<int>>& result, 
        int target)
{
    entry.push_back(node->val);
    sum += node->val;
    if(node->left == NULL && node->right == NULL){
        if(sum == target){
            result.push_back(entry);
        }
    }
    else
    {
        if(node->left != NULL){
            findpath(entry, sum, node->left, result, target);
        }
        if(node->right != NULL){
            findpath(entry, sum, node->right, result, target);
        }
    }
    return;
}
 
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(root == NULL) return result;
        
        vector<int> entry;
        findpath(entry, 0, root, result, sum);
        return result;
    }
};