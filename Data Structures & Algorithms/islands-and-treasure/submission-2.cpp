class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<int>> matrix=grid;
        queue<pair<pair<int,int>,int>> q;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    q.push({{i,j},0});
                    visited[i][j]=1;
                }
            }
        }
        
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        while(!q.empty()){
            auto ele=q.front();
            q.pop();
            int r=ele.first.first;
            int c=ele.first.second;
            int dis=ele.second;
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                if(nr<0 || nc<0 || nr>=n || nc>=m || matrix[nr][nc]==-1 || visited[nr][nc])continue;
                matrix[nr][nc]=dis+1;
                visited[nr][nc]=1;
                q.push({{nr,nc},dis+1});

            }
        }
        grid=matrix;

    }
};
