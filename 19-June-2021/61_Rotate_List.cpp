/*  Problem Link: https://leetcode.com/problems/rotate-list/

    T.C = O(n) + O(n);
    S.C = O(1)
*/

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
    
    ListNode* rotateRight(ListNode* head, int k) {
        int len = 0;
        ListNode *curr = head;
        
        while(curr!=nullptr){
            len++;
            curr = curr->next;
        }
         if(len==0)return head;
        
        k -= len*(k/len);
        
        if(k==0)return head;
        
        ListNode *slow = head, *fast = head, *newHead;
        
        while(k--)
            fast = fast->next;
        
        while(fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        newHead = slow->next;
        slow->next = nullptr;
        fast->next = head;
        
        head = newHead;
        
        slow = nullptr, fast=nullptr, newHead=nullptr;
        delete slow; delete fast; delete newHead;
        
        
        return head;
    }
};