class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int n=matrix.size();if(n==0)return false;
    int m=matrix[0].size();if(m==0)return false;
    int l=0;
    int r=n*m-1;
    while(l<=r){
        int mid=l+(r-l)/2;
        int row=mid/m;
        int col=mid%m;
        if(matrix[row][col]==target){
            return true;
        }
        else if(matrix[row][col]>target){
            r=mid-1;
        }
        else if(matrix[row][col]<target){
            l=mid+1;
        }
        
    }
    return false;  
    }
};
