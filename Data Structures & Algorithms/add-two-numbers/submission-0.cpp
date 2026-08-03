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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode* dummy=new ListNode(0);
        ListNode* prev=dummy;
     while(l1 || l2 || carry){
        int v1= l1?l1->val:0;
        int v2= l2?l2->val:0;
        int nval=v1+v2+carry;
        ListNode* nn=new ListNode(nval%10);
        carry=nval/10;
        prev->next=nn;
        prev=nn;
        if(l1)l1=l1->next;
        if(l2)l2=l2->next;
     }
    return dummy->next;   
    }
};
