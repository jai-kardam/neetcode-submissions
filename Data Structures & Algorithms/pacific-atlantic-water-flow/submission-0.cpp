class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
    int n=heights.size();if(n==0)return {};
    int m =heights[0].size();if(m==0)return {};
    queue<pair<int,int>> q;
       vector<vector<int>>pacific(n,vector<int>(m,0));
       vector<vector<int>>atlantic(n,vector<int>(m,0));
       vector<vector<int>>ans;
       for(int i=0;i<m;i++){
        pacific[0][i]=1;
        q.push({0,i});}
        for(int i=0;i<n;i++){
        pacific[i][0]=1;
        q.push({i,0});}
       
       while(!q.empty()){
        auto ele=q.front();
        q.pop();
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=ele.first+row[i];
            int nc=ele.second+col[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !pacific[nr][nc] && heights[nr][nc] >=heights[ele.first][ele.second]){
                pacific[nr][nc]=1;
                q.push({nr,nc});
            }
        }
       }
       for(int i=0;i<m;i++){
        atlantic[n-1][i]=1;
        q.push({n-1,i});}
        for(int i=0;i<n;i++){
        atlantic[i][m-1]=1;
        q.push({i,m-1});}

       while(!q.empty()){
        auto ele=q.front();
        q.pop();
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=ele.first+row[i];
            int nc=ele.second+col[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !atlantic[nr][nc] && heights[nr][nc] >=heights[ele.first][ele.second]){
                atlantic[nr][nc]=1;
                q.push({nr,nc});
            }
        }
       }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(pacific[i][j] && atlantic[i][j])ans.push_back({i,j});
        }
     }  
       
    return ans;
        
    }
};
