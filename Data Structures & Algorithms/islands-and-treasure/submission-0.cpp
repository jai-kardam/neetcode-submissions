class Solution {
public:
    
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
         int n=grid.size();
         int m=grid[0].size();
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(grid[i][j]==0)
        q.push({i,j});
        
        while(!q.empty()){
        auto ele=q.front();
        q.pop();
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=ele.first+row[i];
            int nc=ele.second+col[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]!=-1 && grid[nr][nc]==INT_MAX){
                grid[nr][nc]=grid[ele.first][ele.second]+1;
                q.push({nr,nc});
            }
        }
        }
    }
};
