/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//   2015-6-4 
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return l1;
        
        bool carry = false;
        ListNode* root = new ListNode(0);
        ListNode* head = root;
        while(l1 != NULL || l2 != NULL){
            int s = 0;
            if(l1 != NULL){
                s += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                s+= l2->val;
                l2 = l2->next;
            }
            
            if(carry){
                s++;
                carry = false;
            }
            
            if(s > 9){
                carry = true;
                s %= 10;
            }
            
            ListNode* node = new ListNode(s);
            head->next = node;
            head = node;
        }
        
        if(carry){
            ListNode* node = new ListNode(1);
            head->next = node;
        }
        
        return root->next;
    }
};