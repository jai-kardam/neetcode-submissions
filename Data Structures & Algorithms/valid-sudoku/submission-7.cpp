class Solution {
public:
    bool check(int r,int c,vector<vector<char>> &board){
        char ch=board[r][c];
        if(ch=='.')return true;
        for(int i=0;i<9;i++){
            if(board[r][i]==ch && i!=c)return false;

        }
        for(int i=0;i<9;i++){
            if(board[i][c]==ch && i!=r)return false;
        }
        int gridr = (r / 3) * 3;
        int gridc = (c / 3) * 3;
        for(int i = gridr; i < gridr + 3; i++){
            for(int j = gridc; j < gridc + 3; j++){
                if(board[i][j] == ch && (i != r || j != c)) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(!check(i,j,board))return false;
            }
        }
        return true;
        
    }
};
