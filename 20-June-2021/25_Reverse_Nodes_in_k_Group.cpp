/* Problem Link: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    
    ListNode *reverseList(ListNode* curr){
        ListNode *prev = nullptr;
        while(curr!=nullptr){
            ListNode *nxtNode = curr->next;
            curr->next = prev;
            prev = curr; 
            curr = nxtNode;
        }
        return prev;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *curr = head, *remList = head, *first, *prev;
        
        ListNode *newHead = new ListNode(-1);
        ListNode *temp = newHead;
        
        while(remList!=nullptr){
            int count = k;
            while(count--){
                if(remList==nullptr)
                    break;
                prev = remList;
                remList = remList->next;
            }

            if(count>=0)break;
            
            prev->next = nullptr; 
            first = curr;
            curr = reverseList(curr);
            
            temp->next = curr;
            temp = first;          //  Alternatively   while(temp->next!=nullptr)temp = temp->next;    
            
            curr = remList;
        }
        
        temp->next = curr;
        
        curr = remList = first = prev = nullptr;
        delete curr; delete remList; delete first; delete prev;
        
        return newHead->next;
    }
};
                                
//                         p     c     r
//     head->   1-> 2   3-> 4    5 -> NULL
// newHead-> -1->2->1 ->4-> 3->NULL
//                          t

