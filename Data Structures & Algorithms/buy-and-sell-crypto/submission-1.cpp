class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int l=0;
      int r=l;
      int profit=0;
      while(r<prices.size()){
        if(prices[r]>prices[l]){
            profit=max(profit,prices[r]-prices[l]);
        }
        else{
            l=r;
        }
        r++;

      } return profit; 
    }
};
