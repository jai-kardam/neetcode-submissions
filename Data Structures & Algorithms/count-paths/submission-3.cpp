class Solution {
public:
    int helper(int m,int n ,int r,int c,vector<vector<int>> &dp){
        if(r==m-1 && c==n-1){
            return 1;
        }
        if( r>=m || c>=n){
            return 0;
        }
        if(dp[r][c]!=-1)return dp[r][c];
        int ans=0;
        ans+=helper(m,n,r,c+1,dp);
        ans+=helper(m,n,r+1,c,dp);
        return dp[r][c]= ans;
        
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        dp[m-1][n-1]=1;
        for(int i=0;i<n-1;i++){
            dp[m-1][i]=1;
        }
        for(int i=0;i<m-1;i++){
            dp[i][n-1]=1;
        }
        for(int r=m-2;r>=0;r--){
            for(int c=n-2;c>=0;c--){
                dp[r][c]=dp[r][c+1]+dp[r+1][c];
            }
        }
        return dp[0][0];
    }
};
