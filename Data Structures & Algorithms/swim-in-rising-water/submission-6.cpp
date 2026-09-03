class Solution {
   public:
    bool dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int r, int c, int w) {
        int n = grid.size();
        int m = grid[0].size();
        if (r == n - 1 && c == m - 1) return true;
        static int dr[] = {0, -1, 0, 1};
        static int dc[] = {-1, 0, 1, 0};
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m || visited[nr][nc] || grid[nr][nc] > w)
                continue;
            visited[nr][nc] = 1;
            if (dfs(grid, visited, nr, nc, w)) return true;
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(n==1 && m==1)return grid[0][0];
        int ma = INT_MIN;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
               
                ma = max(ma, grid[i][j]);
            }
        }
        int t=grid[0][0];
        while(t<=ma){
            int mid=t+(ma-t)/2;
            visited[0][0]=1;
            if(dfs(grid,visited,0,0,mid)){
                ma=mid-1;
            }
            else{
                t=mid+1;
            }
            for(auto &row :visited){
                fill(row.begin(),row.end(),0);
            }
        }
    return t;
        
    }
};
