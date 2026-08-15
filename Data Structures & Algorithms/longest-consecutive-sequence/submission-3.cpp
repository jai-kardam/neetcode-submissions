class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
     unordered_set<int>st(nums.begin(),nums.end());
     int longest=0;
     for(int i=0;i<nums.size();i++){
        if(st.count(nums[i]-1))continue;
        else{
            int start=nums[i];
            int count =1;
            while(st.count(start+1)){
                start++;
                count++;
                
            }
            longest=max(longest,count);
        }
     } 
     return longest;  
    }
};
