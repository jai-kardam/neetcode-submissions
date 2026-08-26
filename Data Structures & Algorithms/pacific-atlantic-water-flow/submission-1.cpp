class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
       vector<vector<int>>pacific(n,vector<int>(m,0));
       vector<vector<int>>atlantic(n,vector<int>(m,0));
       queue<pair<int,int>> q;
       for(int i=0;i<m;i++){
        q.push({0,i});
        pacific[0][i]=1;
       }
       for(int i=0;i<n;i++){
        if(pacific[i][0])continue;
        q.push({i,0});
        pacific[i][0]=1; }
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                if(nr<0 || nc<0 || nr>=n || nc>=m || pacific[nr][nc] || heights[nr][nc]<heights[r][c])continue;
                q.push({nr,nc});
                pacific[nr][nc]=1;

            }
  
        }
        for(int i=0;i<m;i++){
        q.push({n-1,i});
        atlantic[n-1][i]=1;
       }
       for(int i=0;i<n;i++){
        if(atlantic[i][m-1])continue;
        q.push({i,m-1});
        atlantic[i][m-1]=1; }
          while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nr=row[i]+r;
                int nc=col[i]+c;
                if(nr<0 || nc<0 || nr>=n || nc>=m || atlantic[nr][nc] || heights[nr][nc]<heights[r][c])continue;
                q.push({nr,nc});
                atlantic[nr][nc]=1;

            }
  
        }
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(pacific[i][j] && atlantic[i][j])
                ans.push_back({i,j});
            }
        }
        return ans;


    }
};
