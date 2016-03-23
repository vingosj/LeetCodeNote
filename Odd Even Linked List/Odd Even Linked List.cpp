/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !(head->next)) return head;
        ListNode* even = head->next;
        ListNode* pre = head;
        ListNode* cur = head->next;
        ListNode* next = cur->next;
        ListNode* tail = head;
        bool odd = true;

        while(next != NULL){
            pre->next = next;
            if(odd) tail = next;
            odd = !odd;
            cur->next = NULL;
            
            pre = cur;
            cur = next;
            next = next->next;
        }
        tail->next = even;
        
        return head;
    }
};