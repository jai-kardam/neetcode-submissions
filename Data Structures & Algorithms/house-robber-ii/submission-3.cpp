class Solution {
public:
    int helper(vector<int> &nums,int idx,int s,vector<int> &dp){
        if(idx<s){
            return 0;
        }
        if(dp[idx]!=-1)return dp[idx];
    
        int pick=nums[idx]+helper(nums,idx-2,s,dp);
        int skip=helper(nums,idx-1,s,dp);
        return dp[idx]=max(skip,pick);
        
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1,-1);
        if(nums.size()==1)return nums[0];
       int one=helper(nums,nums.size()-1,1,dp);
       dp.assign(nums.size()+1,-1);
       int two=helper(nums,nums.size()-2,0,dp);
       return max(one,two);
    }
};
