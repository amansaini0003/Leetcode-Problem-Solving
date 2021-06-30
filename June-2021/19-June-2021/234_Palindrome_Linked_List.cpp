/* Problem Link: https://leetcode.com/problems/palindrome-linked-list/

 Approach 1 : Clone the list then reverse it then comapre it with original list.
                T.C = O(n) + O(n) 
                S.C = O(n)

Approach 2 : split the list into two half reverse the second half
            and compare it with first half.
             T.C = O(n), S.C = O(1)

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
    
    ListNode* reverseList(ListNode *head){
        ListNode *prev = nullptr, *curr = head;
        while(curr!=nullptr){
            ListNode *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode *mid = head, *fast = head;
        while(fast->next!=nullptr && fast->next->next!=nullptr){
            mid = mid->next;
            fast = fast->next->next;
        }
        ListNode *secondHalf = mid->next;
        
        mid->next = nullptr;        
        secondHalf = reverseList(secondHalf);     // List Split into two Half.
        
        ListNode *curr1 = head, *curr2 = secondHalf;
        
        while(curr2!=nullptr){
            if(curr1->val != curr2->val){
                secondHalf = reverseList(secondHalf);  // Merge the both half.
                mid->next = secondHalf;
                return false;      
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        secondHalf = reverseList(secondHalf);  // Merge the both half.
        mid->next = secondHalf;
        
        return true;
    }
};