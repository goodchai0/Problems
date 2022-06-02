class Solution {
public:
    
    string checkBoard(vector<vector<int>>&board)
    {
        for(int j=0;j<3;j++)
        {
            int countA=0;
            int countB=0;
            for(int i=0;i<3;i++)
            {
                if(board[i][j]=='X')countA++;
                else if(board[i][j]=='O')countB++;
            }
            if(countA==3) return "A";
            if(countB==3) return "B";
        }
        for(int j=0;j<3;j++)
        {
            int countA=0;
            int countB=0;
            for(int i=0;i<3;i++)
            {
                if(board[j][i]=='X')countA++;
                else if(board[j][i]=='O')countB++;
            }
            if(countA==3) return "A";
            if(countB==3) return "B";
        }
        
        if(board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') return "A";
        if(board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') return "B";

    
        if(board[2][0] == 'X' && board[1][1] == 'X' && board[0][2] == 'X') return "A";
        if(board[2][0] == 'O' && board[1][1] == 'O' && board[0][2] == 'O') return "B";
        
        int c = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++) if(board[i][j] == 'X' || board[i][j] == 'O') c++;
        }

        if(c != 9) return "Pending";

        return "Draw";

        
    }
    string tictactoe(vector<vector<int>>& moves) {
        int n=moves.size();
        vector<vector<int>>board(3,vector<int>(3,'.'));
        for(int i=0;i<n;i++)
        {
            if(i%2==0)
            {
                board[moves[i][0]][moves[i][1]]='X';
                
            }
            else{
                board[moves[i][0]][moves[i][1]]='O';
            }
        }
        return checkBoard(board);
    }
};