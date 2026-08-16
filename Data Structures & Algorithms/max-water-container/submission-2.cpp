class Solution {
public:
    int maxArea(vector<int>& heights) {
      int water=0;
      int l=0;
      int r=heights.size()-1;
      while(l<r){
        int calc=min(heights[l],heights[r])*(r-l);
        water=max(water,calc);
        if(heights[l]>heights[r])r--;
        else if(heights[l]<=heights[r])l++;

      } 
      return water; 
    }
};
