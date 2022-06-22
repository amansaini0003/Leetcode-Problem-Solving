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
private: 
    ListNode* mergeTwoSortedList(ListNode* l1, ListNode* l2) {
        ListNode *sorted  = new ListNode(-1);
        ListNode *curr = sorted;
        
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val){
                curr->next = l1;       
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1 == nullptr){
            curr->next = l2;
        } else {
            curr->next = l1;
        }
        
        sorted = sorted->next;
        return sorted;
    }
    
   ListNode* getMidNode(ListNode *head){
       ListNode *slow = head, *fast = head, *prev = nullptr;
       
       while(fast != nullptr && fast->next != nullptr) {
           prev = slow;
           slow = slow->next;
           fast = fast->next->next;
       }
       if(prev != nullptr)
           prev->next = nullptr;
       
       return slow;
   }
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode *first, *second;
        second = getMidNode(head);
        
        
        first = sortList(head);
        second = sortList(second);
        
        ListNode* sortedList = mergeTwoSortedList(first, second);
        
        return sortedList;
        
    }
};