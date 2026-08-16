class Solution {
public:
    int trap(vector<int>& height) {
     int leftmax=0;
   
     int l=0;
     int r=height.size()-1;
      int rightmax=0;
     int water=0;
     while(l<r){
      if(height[l]>height[r]){
        if(rightmax<height[r])rightmax=height[r];
        else
        water+=(rightmax-height[r]);
        r--;
      }
      else if(height[r]>=height[l]){
        if(leftmax<height[l])leftmax=height[l];
        else
        water+=leftmax-height[l];
        l++;
      }

      
     }  
     return water; 
    }
};
