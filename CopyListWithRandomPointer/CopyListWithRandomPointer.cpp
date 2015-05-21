/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
#include <map>
 
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL) return NULL;
        RandomListNode* dummy = new RandomListNode(0);
        RandomListNode* note = dummy;
        map<RandomListNode*, RandomListNode*> ref;
        
        
        while(head != NULL){
            RandomListNode* temp = new RandomListNode(head->label);
            temp->random = head->random;
            ref[head] = temp;
            
            note->next = temp;
            note = temp;
            head = head->next;
        }
        
        head = dummy -> next;
        while(head != NULL){
            if(head->random != NULL){
                head->random = ref[head->random];
            }
            head = head->next;
        }
        
        return dummy->next;
    }
};