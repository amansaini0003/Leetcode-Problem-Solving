// Problem Link : https://leetcode.com/problems/add-two-numbers/

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
        ListNode *prev=nullptr, *curr = head, *nextNode;
        
        while(curr!=nullptr){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(-1);
        
        int carry = 0;
        
        while(l1!=nullptr && l2!=nullptr){
            ListNode* newNode = new ListNode();
            
            int sum = l1->val + l2->val;
            if(carry==0){
                newNode->val = sum%10;
                if(sum >= 10)
                    carry = 1;
            }
            else{
                newNode->val = (sum+carry)%10;
                if(sum+carry < 10)
                    carry = 0;
            }
            
            newNode->next = head;
            head = newNode;
            
            l1 = l1->next;
            l2 = l2->next;
        }
        
        while(l1!=nullptr){
            ListNode* newNode = new ListNode();
            int sum = l1->val;
            
            if(carry==0){
                newNode->val = sum%10;
                if(sum >= 10)
                    carry = 1;
            }else{
                newNode->val = (sum+carry)%10;
                if(sum+carry < 10)
                    carry = 0;
            }
            newNode->next = head;
            head = newNode;
            
            l1 = l1->next;
        }
        while(l2!=nullptr){
            ListNode* newNode = new ListNode();
            int sum = l2->val;
            
            if(carry==0){
                newNode->val = sum%10;
                if(sum >= 10)
                    carry = 1;
            }else{
                newNode->val = (sum+carry)%10;
                if(sum+carry < 10)
                    carry = 0;
            }
            newNode->next = head;
            head = newNode;
            
            l2 = l2->next;
        }
        
        if(carry==1){
            ListNode* newNode = new ListNode(1);
            newNode->next = head;
            head = newNode;
        }
        
        head = reverseList(head);
        
        return head->next;
    }
};