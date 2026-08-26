class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       queue<pair<pair<int,int>,int>> q;
       int n=grid.size();
       int m=grid[0].size();
       int time=0;
       vector<vector<int>> visited(n,vector<int>(m,0));
       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2){
                q.push({{i,j},0});
                visited[i][j]=1;
            }
        }}
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            int t=ele.second;
            int r=ele.first.first;
            int c=ele.first.second;
            time=max(t,time);
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                if(nr<0 || nr>=n || nc<0 || nc>=m || visited[nr][nc] || grid[nr][nc]!=1)continue;
                q.push({{nr,nc},t+1});
                visited[nr][nc]=1;
            }


        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]==1)return -1;
            }
        }
        return time;
       } 
    
};
