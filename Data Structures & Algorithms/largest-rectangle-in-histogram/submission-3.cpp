class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
     stack<int> stk;
     int maxarea=0;
     for(int i=0;i<heights.size();i++){
        while(!stk.empty() && heights[i]< heights[stk.top()]){
           int val=heights[stk.top()];
           stk.pop();
           int area=val*(i-(stk.empty()?-1:stk.top())-1);
           maxarea=max(area,maxarea);
        }
        stk.push(i);

     }
     while(!stk.empty()){
        int val=heights[stk.top()];
        stk.pop();
        int area=val*(heights.size()-(stk.empty()?-1:stk.top())-1);
        maxarea=max(area,maxarea);
     } 
     return maxarea;  
    }
};
