/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
static void removeNode(ListNode* temp, int val){
    if(temp == NULL) return;
    
    ListNode* next = temp->next;
    if(next == NULL) return;
    else if(next->val != val){
        return removeNode(next, val);
    }
    else{
        temp->next = next->next;
        free(next);
        return removeNode(temp, val);
    }
} 
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;

        ListNode* next = head->next;
        while(head->val == val){
            if(head->next == NULL) return NULL;
            else{
                next = head->next;
                free(head);
                head = next;
            }
        }
        
        next = head;
        removeNode(next, val);
        
        return head;
    }
};