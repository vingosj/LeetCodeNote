/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
//   2015-5-29
//   Hint#: go through the link List, and reverse the link direction.
//          if go back to head node, then exist a cycle
//          otherwise if go the end (NULL), then there's no cycle

 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return false;
        ListNode* node = head;
        ListNode* next = head->next;
        node->next = NULL;
        head->next = NULL;
        
        while(next != NULL){
            ListNode* nnext = next->next;
            if(next == node || next->next == head) return true;
            next->next = node;
            node = next;
            next = nnext;
        }
        
        return false;
    }
};