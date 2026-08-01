class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
      unordered_set<int> s;
      s.insert(nums.begin(),nums.end());
      int longest=0;
      for(int a:s){
        if(s.find(a-1)==s.end()){
            int len=1;
            int cur=a;
            while(s.find(cur+1)!=s.end()){
                len++;
                cur++;
            }
            longest=max(longest,len);
        }
      }return longest;  
    }
};
