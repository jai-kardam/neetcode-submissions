class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       for(int i=0;i<9;i++){
            unordered_map<char,int> mp;
        for(int j=0;j<9;j++){
            if(isdigit(board[i][j]) && !mp.count(board[i][j])){
                mp[board[i][j]]+=1;
            }
            else if(isdigit(board[i][j]))return false;
            
        }
       }
       for(int i=0;i<9;i++){
        unordered_map<char,int> mp;
        for(int j=0;j<9;j++){
           if(isdigit(board[j][i]) && !mp.count(board[j][i])){
                mp[board[j][i]]+=1;
            }
            else if(isdigit(board[j][i]))return false;
        }}
        for(int sq=0;sq<9;sq++){
            unordered_map<char,int> mp;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    int r=(sq/3)*3+i;
                    int c=(sq%3)*3+j;
                    if(isdigit(board[r][c]) && !mp.count(board[r][c]))
                    mp[board[r][c]]+=1;
                    else if(isdigit(board[r][c])) return false;
                }
            }
        }
       

        
      return true; } 
    };
