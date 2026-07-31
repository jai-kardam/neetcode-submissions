class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int>mp;
    int n= nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]]+=1;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> heap;
    for(auto ele:mp){
        heap.push({ele.second,ele.first});
        if(heap.size()>k)heap.pop();
    }
    vector<int>ans;
    for(int i=0;i<k;i++){
        auto a=heap.top();
        ans.push_back(a.second);
        heap.pop();
    }
    return ans;
       
    }
};
