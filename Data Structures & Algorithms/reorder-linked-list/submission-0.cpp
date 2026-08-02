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
    void reorderList(ListNode* head) {
      ListNode* slow=head;
      ListNode* fast=head;
      while(fast && fast->next){
         slow=slow->next;
        fast=fast->next->next;
       
      }
      ListNode* temp=slow->next;
      slow->next=NULL;
      ListNode* prev=NULL;
      while(temp){
        ListNode* next=temp->next;
        temp->next=prev;
        prev=temp;
        temp=next;
      }
      while(prev && head){
        ListNode* ahead1=head->next;
        ListNode* ahead2=prev->next;
        head->next=prev;
        prev->next=ahead1;
        prev=ahead2;
        head=ahead1;
      }

    }
};
