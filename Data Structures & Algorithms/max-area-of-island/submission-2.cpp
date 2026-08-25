class Solution {
public:
    int bfs(vector<vector<int>> &visited,vector<vector<int>> &grid ,int r,int c){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    q.push({r,c});
    visited[r][c]=1;
    int row[]={0,-1,0,1};
    int col[]={-1,0,1,0};
    int area=0;
    while(!q.empty()){
        auto ele=q.front();
        q.pop();
        area++;
        int r=ele.first;
        int c=ele.second;
        for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m || visited[nr][nc] || grid[nr][nc]==0)continue;
            q.push({nr,nc});
            visited[nr][nc]=1;
            
        }
    }
    return area;}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int max_area=0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    int area=bfs(visited,grid,i,j);
                    max_area=max(area,max_area);
                }
            }
        }
    return max_area;}
};
