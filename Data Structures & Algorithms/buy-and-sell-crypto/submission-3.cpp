class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int buy=prices[0];
     int profit=0;
     for(int i=0;i<prices.size();i++){
      while(i<prices.size() &&buy<prices[i]){
        int calc=prices[i]-buy;
        profit=max(profit,calc);
        i++;
      }
      buy=prices[i];

     } 
     return profit;  
    }
};
