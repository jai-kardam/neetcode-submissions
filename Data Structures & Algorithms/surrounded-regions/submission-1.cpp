class Solution {
public:
    void solve(vector<vector<char>>& board) {
      int n=board.size();
      int m=board[0].size(); 
      queue<pair<int,int>> q; 
      for(int i=0;i<n;i++){
        if(board[i][0]=='O'){
            q.push({i,0});
            board[i][0]='N';
            
        }
        if(board[i][m-1]=='O'){
            q.push({i,m-1});
            board[i][m-1]='N';
        }
      }
      for(int i=0;i<m;i++){
        if(board[0][i]=='O'){
            q.push({0,i});
            board[0][i]='N';
        }
        if(board[n-1][i]=='O'){
            q.push({n-1,i});
            board[n-1][i]='N';
        }

      }
      int row[]={0,-1,0,1};
      int col[]={-1,0,1,0};
      while(!q.empty()){
        auto [r,c]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nr=r+row[i];
            int nc=c+col[i];
            if(nr<0 || nc<0 || nr>=n || nc>=m || board[nr][nc]=='N' || board[nr][nc]=='X')continue;
            q.push({nr,nc});
            board[nr][nc]='N';
        }

      }
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='N'){
                board[i][j]='O';
            }
            else if(board[i][j]=='O'){
                board[i][j]='X';
            }
            
        }
      }
    }
};
