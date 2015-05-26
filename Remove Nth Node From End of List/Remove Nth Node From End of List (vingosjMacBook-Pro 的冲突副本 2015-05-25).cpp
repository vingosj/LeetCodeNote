/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
static int remove(ListNode* node, int n){
    int index;
    if(node->next == NULL) index = 1;
    else{
        if((index = remove(node->next, n)) == 0) return 0;
        if(index == n){
            node->next = node->next->next;
            return 0;
        }
        index++;
    }
    return index;
} 


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL && n <= 0) return head;
        int index = remove(head, n);
        if(n == index) return head->next;
        else return head;
    }
};