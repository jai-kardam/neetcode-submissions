class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();if(n==0)return false;
    int m=matrix[0].size();if(m==0)return false;
    int l=0;
    int r=n-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        if(matrix[mid][0]==target){
            return true;
        }
        else if(matrix[mid][0]>target){
            r=mid-1;
        }
        else if(matrix[mid][0]<target){
            if(matrix[mid][m-1]>=target)break;
            l=mid+1;
        }
        
    }
     if (l >= n) return false;
    int arrno=l+(r-l)/2;
    l=0;
    r=m-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        int ele=matrix[arrno][mid];
        if(ele<target){
            l=mid+1;
        }
        else if(ele>target){
            r=mid-1;
        }
        else{
            return true;
        }
    } 
    return false;  
    }
};
