class Solution {
public:
    void solve(vector<vector<char>>& board) {
     queue<pair<int,int>> q;
     int n=board.size();if(n==0)return;
     int m=board[0].size();if(m==0)return;
     vector<vector<int>> visited(n,vector<int>(m,0));
     for(int i=0;i<m;i++){
        if(!visited[0][i] && board[0][i]=='O'){
        visited[0][i]=1;
        q.push({0,i});}

     }
     for(int i=0;i<n;i++){
        if(!visited[i][0] && board[i][0]=='O'){
            visited[i][0]=1;
            q.push({i,0});
        }
     }
     for(int i=0;i<m;i++){
        if(!visited[n-1][i] && board[n-1][i]=='O'){
        visited[n-1][i]=1;
        q.push({n-1,i});}

     }
     for(int i=0;i<n;i++){
        if(!visited[i][m-1] && board[i][m-1]=='O'){
            visited[i][m-1]=1;
            q.push({i,m-1});
        }
     } 
     while(!q.empty()){
        auto ele=q.front();
        q.pop();
        int row[]={0,-1,0,1};
        int col[]={-1,0,1,0};
        for(int i=0;i<4;i++){
            int nr=ele.first+row[i];
            int nc=ele.second+col[i];
            if(nr>=0 && nr<n && nc>=0 && nc<m && !visited[nr][nc] && board[nr][nc]=='O'){
                visited[nr][nc]=1;
                q.push({nr,nc});
            }

     }   
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j])board[i][j]='X';
        }
    }}
};