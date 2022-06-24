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
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = new ListNode(-1);
        ListNode* curr = newHead;
        
        while(head != nullptr && head->next != nullptr){
            ListNode *node1, *node2;
            node1 = head;   head = head->next;
            node2 = head;   head = head->next;
            
            node1->next = nullptr;
            node2->next = nullptr;
            
            node2->next = node1;
            
            curr->next = node2;
            curr = curr->next->next;
        }
        if(head) {
            curr->next = head;
        }
        return newHead->next;
    }
};