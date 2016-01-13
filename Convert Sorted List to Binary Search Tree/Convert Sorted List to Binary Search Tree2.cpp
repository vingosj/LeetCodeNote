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
    TreeNode* BuildTree(ListNode* &head, int left, int right){
        if(left > right) return NULL;
        int mid = (left + right) / 2;
        TreeNode* leftChild = BuildTree(head, left, mid - 1);
        TreeNode* node = new TreeNode(head->val);
        head = head->next;
        TreeNode* rightChild = BuildTree(head, mid + 1, right);
        node->left = leftChild;
        node->right = rightChild;
        return node;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode* tmp = head;
        while(tmp){
            n++;
            tmp = tmp->next;
        }
        return BuildTree(head, 0, n-1);
    }
};