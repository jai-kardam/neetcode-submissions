class Solution {
public:
    int climbStairs(int n) {
      int curr=1;
      int prev=0;
      for(int i=1;i<=n;i++){
        int temp=curr;
        curr=prev+curr;
        prev=temp;
      }
      return curr;
    }
};
