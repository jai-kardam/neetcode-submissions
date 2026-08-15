class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int>mp;
     for(int n:nums){
        mp[n]++;
     }
     vector<vector<int>>freq(nums.size()+1);
     for(auto it:mp){
        freq[it.second].push_back(it.first);
     } 
     vector<int> ans;
     for(int i=nums.size();i>=0;i--){{
        if(freq[i].size()!=0){
        for(int n:freq[i]){
        ans.push_back(n);
        if(ans.size()==k)return ans;}}
     }

     } 
    }
};
