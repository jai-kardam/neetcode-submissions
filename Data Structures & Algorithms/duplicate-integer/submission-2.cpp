class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
    int n=nums.size();
    map<int,int> val;
    
    for(int i=0;i<n;i++){
        if(val[nums[i]]){
            return true;
        }
        else{
            val[nums[i]]+=1;
        }
    }
    return false;
    }
};