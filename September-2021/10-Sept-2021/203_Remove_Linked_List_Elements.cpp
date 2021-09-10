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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *prev = new ListNode(0), *curr=head;
        head = prev;
        
        while(curr!=nullptr){
            if(curr->val != val){
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        prev->next = nullptr;
        return head->next;
    }
};