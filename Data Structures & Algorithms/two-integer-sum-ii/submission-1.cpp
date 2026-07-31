class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        int l=0;
        int r=n-1;
        while(l<r){
            int add=numbers[r]+numbers[l];
            if(add==target){
                return {l + 1, r + 1};
            }
            else if(add<target) l++;
            else r--;
        }
    }
};
