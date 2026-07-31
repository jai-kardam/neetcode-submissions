class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
     unordered_map<int,int> mp;
     int n=nums.size();
     for(int i=0;i<n;i++){
        mp[nums[i]]+=1;
     }
     vector<pair<int,int>> l;
     for(auto ele:mp){
        l.push_back({ele.second,ele.first});
     }
     vector<int> ans;
     sort(l.begin(),l.end());
     for(int i=0;i<k;i++){
        ans.push_back(l.back().second);
        l.pop_back();
     }
     return ans;

    }
};
