class Solution {
    void bfs(vector<vector<int>> &visited,vector<vector<char>> &grid ,int r,int c){
    int n=grid.size();
    int m=grid[0].size();
    queue<pair<int,int>> q;
    q.push({r,c});
    int row[]={0,-1,0,1};
    int col[]={-1,0,1,0};
    while(!q.empty()){
        auto ele=q.front();
        q.pop();
        int r=ele.first;
        int c=ele.second;
        if(visited[r][c])continue;
        visited[r][c]=1;
        for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr<0 || nr>=n || nc<0 || nc>=m || visited[nr][nc] || grid[nr][nc]=='0')continue;
            q.push({nr,nc});
        }
    }}
public:
    int numIslands(vector<vector<char>>& grid) {
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>> visited (n,vector<int>(m,0));
    
  
   int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && grid[i][j]=='1'){
                bfs(visited,grid,i,j);
                ans++;
            }
        }
    }
    return ans;
    

    }
};
