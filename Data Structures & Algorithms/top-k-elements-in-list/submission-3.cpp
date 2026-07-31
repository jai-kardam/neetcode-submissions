class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> mp;
    int n= nums.size();
    for(int i=0;i<n;i++){
        mp[nums[i]]+=1;
    }
    vector<vector<int>> l(n+1);
    for( auto ele:mp){
        l[ele.second].push_back(ele.first);
    } vector<int>ans;
    int count=0;
    for(int i=n;i>=0;i--){
        for(auto a:l[i]){
            ans.push_back(a);
            count++;
            if(count==k)return ans;
        }
    }

    }
};
