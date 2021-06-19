/* Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/

    Approach : Using Floyd's Cycle Detection Algo
                T.C = O(n)
                S.C = O(1)
*/


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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        
        do{
            if(fast==nullptr || fast->next==nullptr)
                return nullptr;
            slow = slow->next;
            fast = fast->next->next;
        } while(slow!=fast);
            
        fast = head;
            
        while(slow!=fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};