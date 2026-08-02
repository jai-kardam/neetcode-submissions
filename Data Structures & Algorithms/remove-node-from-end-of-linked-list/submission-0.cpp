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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* temp=head;
     ListNode* dummy= new ListNode(0);
     dummy->next=head;
     int count=0;
     while(temp){
        count++;
        temp=temp->next;
     } 
     temp=dummy;
     for(int i=0;i<count-n;i++){
        temp=temp->next;
     } 
     temp->next=temp->next->next;
     return dummy->next;
    }
};
