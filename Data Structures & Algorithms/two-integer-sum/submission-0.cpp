class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      vector<pair<int,int>> arr;
      int n=nums.size();
      for(int i=0;i<n;i++){
        arr.push_back({nums[i],i});
      }
      sort(arr.begin(),arr.end());
      int l=0;
      int r=nums.size()-1;
      while(l<r){
        if(arr[l].first+arr[r].first==target){
          return {min(arr[l].second,arr[r].second),max(arr[l].second,arr[r].second)};
        }
        else if(arr[l].first+arr[r].first<target){
          l++;
        }
        else{
          r--;
        }
      }  
    }
};
