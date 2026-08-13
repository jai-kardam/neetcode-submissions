class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
      queue<pair<pair<int,int>,int>> q;
      int n=grid.size();
      if(n==0)return -1;
      int m=grid[0].size();
      if(m==0)return -1;
      vector<vector<int>> visited(n,vector<int>(m,0));
      int fresh=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
            else if(grid[i][j]==1)fresh++;
        }
      }
      if(fresh==0)return 0;
      while(!q.empty()){
        auto ele=q.front();
        int r=ele.first.first;
        int c=ele.first.second;
        q.pop();
        static int row[]={0,-1,0,1};
        static int col[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc]==1){
                visited[nr][nc]=1;
                q.push({{nr,nc},ele.second+1});
                fresh-=1;
                if(fresh==0){
                    return ele.second+1;
                }
            }
        }}
      
      
    return -1;
    }
};
