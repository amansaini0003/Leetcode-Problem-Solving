/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
  
        ListNode *slow = head, *fast=head;
        
        while(n-- && fast!=NULL)
            fast = fast->next;
        
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }
        if(fast==NULL)
            return head->next;
        
        ListNode *removeNode = slow->next;
        slow->next = removeNode->next;

        removeNode->next = NULL;
        
        return head;
    }
};