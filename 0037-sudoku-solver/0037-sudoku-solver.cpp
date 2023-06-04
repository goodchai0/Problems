class Solution {
public:
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='.'){
                    for(int x='1';x<='9';x++){
                        if(isSafe(board,i,j,x)){
                            board[i][j]=x;
                            bool ans=solve(board);
                            if(ans==true)return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    bool isSafe(vector<vector<char>>& board,int i,int j,char x){
        for(int k=0;k<9;k++){
            if(board[i][k]==x)return false;
            if(board[k][j]==x)return false;
            if(board[3*(i/3)+k/3][3*(j/3)+k%3]==x)return false;
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};