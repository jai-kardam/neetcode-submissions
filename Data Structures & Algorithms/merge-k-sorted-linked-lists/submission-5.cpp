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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)return NULL;
        struct Compare{
        bool operator()(const pair<int,ListNode*> &a,const pair<int,ListNode*> &b)const{return a.first>b.first;}
       };
       priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,Compare> pq;
       
       for(int i=0;i<n;i++){
        if(lists[i])
        pq.push({lists[i]->val,lists[i]});
       }
       ListNode* dummy= new ListNode(0);
       ListNode* temp=dummy;
       while(!pq.empty()){
        auto node=pq.top();
        temp->next=node.second;
        pq.pop();
        if(node.second->next)pq.push({node.second->next->val,node.second->next});
        temp=temp->next;


       }
       temp->next=NULL;
       return dummy->next;

    }
};
