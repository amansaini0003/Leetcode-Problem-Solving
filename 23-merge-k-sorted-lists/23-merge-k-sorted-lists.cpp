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
    ListNode* mergeTwoList(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(-1);
        ListNode *curr = l3;
        
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        
        if(l1) {
            curr->next = l1;
        } else {
            curr->next = l2;
        }
        
        return l3->next;
    } 
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0) 
            return nullptr;
        
        ListNode *sortedList = lists[0];
        
        for(int i=1; i<lists.size(); i++) {
            ListNode * currList = lists[i];
            
            sortedList = mergeTwoList(sortedList, currList);
        }
        
        return sortedList;
    }
};




