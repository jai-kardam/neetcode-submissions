class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &visited,vector<vector<char>> &grid){
        int n=visited.size();
         int m=visited[0].size();
        static int row[]={0,-1,0,1};
        static int col[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]=='1' ){
                visited[nr][nc]=1;
                dfs(nr,nc,visited,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        if(n==0)return 0;
        
        int m=grid[0].size();
        if(m==0)return 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j])continue;
                if(grid[i][j]=='1'){
                    count++;
                    visited[i][j]=1;
                    dfs(i,j,visited,grid);
                }
            }
        }
    return count ;}
};
