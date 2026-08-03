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
     vector<pair<ListNode*,int>> arr;
     for(int i=0;i<lists.size();i++){
        while(lists[i]){
            arr.push_back({lists[i],lists[i]->val});
            lists[i]=lists[i]->next;
        }
     } 
     struct Compare {
    bool operator()(const pair< ListNode*,int>& a,
                    const pair<ListNode*,int>& b) const {
        return a.second < b.second;
    }
};
     sort(arr.begin(),arr.end(),Compare());
     ListNode* dummy= new ListNode(0);
     ListNode* temp=dummy;
     for(int i=0;i<arr.size();i++){
        auto nn=arr[i];
        temp->next=nn.first;
        temp=temp->next;
     } 
     temp->next=NULL;
     return dummy->next; 
    }
};
