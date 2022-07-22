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
    ListNode* partition(ListNode* head, int x) {
        ListNode* first = new ListNode(-1);
        ListNode* second = new ListNode(-1);
        
        ListNode* firstTail = first;
        ListNode* secondTail = second;
        
        while(head) {
            ListNode* curr = head;
            head = head->next;
            curr->next = nullptr;
            
            if(curr->val < x) {
                firstTail->next = curr;
                firstTail = firstTail->next;
            } else {
                secondTail->next = curr;
                secondTail = secondTail->next;
            }
        }
        
        first = first->next;
        second = second->next;
        
        if(first == nullptr) {
            return second;
        }
        
        firstTail->next = second;
        
        return first;
    }
};