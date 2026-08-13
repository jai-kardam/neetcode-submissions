class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
      vector<vector<int>> visited(n,vector<int>(m,0));
      queue<pair<int,int>>q;
      int count=0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j]==1)continue;
            if(grid[i][j]=='1' && !visited[i][j]){
            visited[i][j]=1;
            q.push({i,j});
            count++;
            }
            while(!q.empty()){
                auto ele=q.front();
                q.pop();
                int row[]={0,-1,0,1};
                int col[]={-1,0,1,0};
                for(int k=0;k<4;k++){
                    int r=ele.first+row[k];
                    int c=ele.second+col[k];
                    if( r>=0 && r<n && c>=0 && c<m && !visited[r][c] &&
                    grid[r][c]=='1'){
                        visited[r][c]=1;
                        q.push({r,c});

                    }
                }
            }
        }

      } 
      return count;
    }
};
