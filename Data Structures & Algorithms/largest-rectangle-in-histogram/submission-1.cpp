class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
      int maxarea=0;
      stack<int> stk;
      vector<int> next(heights.size(),heights.size());
      vector<int> prev(heights.size(),-1);
      for(int i=0;i<heights.size();i++){
        while(!stk.empty() && heights[stk.top()]>=heights[i]){
            next[stk.top()]=i;
            stk.pop();
        }
        stk.push(i);
      }
      while(!stk.empty())
    stk.pop();
      for(int i=heights.size()-1;i>=0;i--){
        while(!stk.empty() && heights[stk.top()]>heights[i]){
            prev[stk.top()]=i;
            stk.pop();
        }
        stk.push(i);
      }

      for(int i=0;i<heights.size();i++){
        
        int nse=next[i];
        int pse=prev[i];
        
        int area=heights[i]*(nse-pse-1);
        maxarea=max(area,maxarea);

        
      } 
      return maxarea; 
    }
};
