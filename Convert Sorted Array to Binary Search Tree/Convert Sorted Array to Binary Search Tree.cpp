/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void BuildTree(TreeNode* node, int left, int right, vector<int>& nums){
        if(left == right) node->val = nums[left];
        else if(left < right){
            int mid = (left + right) / 2;
            node->val = nums[mid];
            if(left <= mid - 1){
                node->left = new TreeNode(0);
                BuildTree(node->left, left, mid-1, nums);
            }
            if(right >= mid + 1){
                node->right = new TreeNode(0);
                BuildTree(node->right, mid+1, right, nums);
            }
        }
        return;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        TreeNode* root = new TreeNode(0);
        if(n <= 0) return NULL;
        BuildTree(root, 0, n-1, nums);
        return root;
    }
};