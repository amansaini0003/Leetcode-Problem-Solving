// Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/


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

// Approach 1 - Two Pass - T.C = O(N) + O(N), S.C = O(1)


/* 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head;
        int cnt = 0;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            cnt++;
        }
        int len=0;
        
        if(fast==nullptr)
            len = 2*cnt;
        else
            len = (2*cnt) + 1;
        
        int idx = len-n;
        
        if(idx==0)
            head = head->next;
        else
       { 
            ListNode *curr = head;
            while(--idx)
                curr = curr->next;
            
            ListNode *temp = curr->next;    
            curr->next = temp->next;
            temp->next = nullptr;      
       }
        
        return head;
    }
};

*/


// // Approach 2 - One Pass -  T.C = O(N), S.C = O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *slow = head, *fast=head;
        int cnt = 0;
        
        while(n--)
            fast = fast->next;
        
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        
        if(fast==nullptr)
            head = head->next;
        else{
            ListNode *temp = slow->next;
            slow->next = temp->next;
            temp->next = nullptr;
        }
            
        return head;
    }
};