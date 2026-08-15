class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> map;
    for(int i=0;i<nums.size();i++){
        map[nums[i]]=i;
    }
    for(int i =0;i<nums.size();i++){
        int diff=target-nums[i];
        if(map.find(diff)!=map.end() && map.find(diff)->second!=i ){
            int sec=map.find(diff)->second;
            return {min(i,sec),max(i,sec)};
        }
    }
     return {};  
    }
};
