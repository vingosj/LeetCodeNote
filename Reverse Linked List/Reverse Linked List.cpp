/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
static ListNode* recursive(ListNode* former, ListNode* later){
    if(later->next == NULL)
    {
        later->next = former;
        return later;
    }
    else
    {
        ListNode* nextLater = later->next;
        later->next = former;
        return recursive(later, nextLater);
    }
}
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;
        else{
            ListNode* later = head->next;
            head->next = NULL;
            return recursive(head, later);
        }
    }
};