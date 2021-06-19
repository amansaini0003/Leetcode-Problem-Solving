// Problem Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

/* 
    Apporach 1 = T.C = O(n^2) using nested while loop
                 S.C = O(1)

    Approach 2 = T.C = O(nlogn) using map 
                 S.C = O(n)

    Approach 3 = T.C = O(n)
                 S.C = O(1)
*/

// ---------------------------   Approach 3 --------------------

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        int lenA = 0, lenB = 0;
        
        ListNode *curr1 = headA, *curr2;
        while(curr1!=nullptr){
            lenA++;
            curr1 = curr1->next;
        }
        
        curr2 = headB;
        while(curr2!=nullptr){
            lenB++;
            curr2 = curr2->next;
        }
        
        int diff = abs(lenA - lenB);
        
        curr1 = headA;
        curr2 = headB;
        
        if(diff!=0){
            if(lenA > lenB){
                while(diff--)
                    curr1 = curr1->next;
            }else{
                while(diff--)
                    curr2 = curr2->next;
            }
        }
        
        while(curr1!=nullptr){
            if(curr1 == curr2)
                return curr1;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        
        return nullptr;
        
    }
};

