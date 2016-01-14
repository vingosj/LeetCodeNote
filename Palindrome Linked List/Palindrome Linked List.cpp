/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 2016-1-14
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == NULL) return true;
        
        // find mid point
        ListNode *oneStep = head, *twoStep = head;
        ListNode *mid, *next, *tmp;
        while(twoStep != NULL && twoStep->next != NULL && twoStep->next->next != NULL){
            oneStep = oneStep->next;
            twoStep = twoStep->next->next;
        }
        mid = oneStep;
        next = oneStep->next;
        oneStep->next = NULL;
        
        // reverse right half
        while(next != NULL){
            tmp = next->next;
            next->next = oneStep;
            oneStep = next;
            next = tmp;
        }
        
        while(head != NULL){
            if(head->val != oneStep->val) return false;
            head = head->next;
            oneStep = oneStep->next;
        }
        
        return true;
    }
};