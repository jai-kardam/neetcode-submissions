class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int product=1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            else{
                product*=nums[i];
            }
        }
        vector<int> ans(n,0);
        if(count>1)return ans;
        else if(count==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    ans[i]=product;
                    return ans;
                }
            }}
        else{
            for(int i=0;i<n;i++){
                ans[i]=product/nums[i];
            }
            return ans;
        }
        
    }
};
