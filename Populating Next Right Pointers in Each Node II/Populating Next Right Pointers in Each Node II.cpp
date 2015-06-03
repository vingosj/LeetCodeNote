/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#include <queue> 

//   2015-6-2 
 
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL) return;
        
        int level = 1, nextLevel = 0;
        queue<TreeLinkNode*> q;
        q.push(root);
        
        while(q.size() != 0){
            TreeLinkNode* node = q.front();
            q.pop();
            
            if(node->left != NULL){
                q.push(node->left);
                nextLevel++;
            }
            if(node->right != NULL){
                q.push(node->right);
                nextLevel++;
            }
            
            if(--level == 0){
                level = nextLevel;
                nextLevel = 0;
            }
            else{
                node->next = q.front();
            }
        }
        return;
    }
};