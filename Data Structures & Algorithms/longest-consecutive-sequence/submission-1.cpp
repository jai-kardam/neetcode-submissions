class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
      sort(nums.begin(),nums.end());
      int i=0;
      int longest=0;
      int curr=nums[i];
      int len=0;
      while(i<n){
        if(curr!=nums[i]){
            curr=nums[i];
            len=0;}
            while(i<n && nums[i]==curr){
                i++;
            }
            len++;
            curr++;
            longest=max(longest,len);
        }

        
    return longest;}
};
