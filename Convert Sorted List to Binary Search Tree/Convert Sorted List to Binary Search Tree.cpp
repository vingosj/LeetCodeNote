/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    void BuildTree(TreeNode* node, int left, int right, vector<int>& vec){
        if(left > right) return;
        if(left == right) {
            node->val = vec[left];
        }
        else {
            int mid = (left + right) / 2;
            node->val = vec[mid];
            if(left <= mid - 1){
                node->left = new TreeNode(0);
                BuildTree(node->left, left, mid-1, vec);
            }
            if(right >= mid + 1){
                node->right = new TreeNode(0);
                BuildTree(node->right, mid+1, right, vec);
            }
        }
        return;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> vec;
        while(head){
            vec.push_back(head->val);
            head = head->next;
        }
        
        int n = vec.size();
        TreeNode* root = new TreeNode(0);
        if(n <= 0) return NULL;
        BuildTree(root, 0, n-1, vec);
        
        return root;
    }
};