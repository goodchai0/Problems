class Solution {
public:
    bool isVaild(int x,int y,vector<vector<int>>&board)
    {
        return (x>=0 && x<board.size() && y>=0 && y<board[0].size());
    }
    
    
    void gameOfLife(vector<vector<int>>& board) {
        vector<int>dx={0,0,1,1,1,-1,-1,-1};
        vector<int>dy={1,-1,1,-1,0,0,1,-1};
        
        for(int i=0;i<board.size();i++)
        {
            for(int j=0; j<board[0].size();j++)
            {
                int count=0;
                
                for(int k=0;k<8;k++)
                {
                    int curr_i=i+dx[k],curr_j=j+dy[k];
                    if(isVaild(curr_i,curr_j,board) && abs(board[curr_i][curr_j])==1)
                        count++;
                }
                if(board[i][j]==1 && (count>3 || count <2))
                    board[i][j]=-1;
                if(board[i][j]==0 && count==3)
                    board[i][j]=2;
            }
        }
        
         for(int i=0;i<board.size();i++)
            for(int j=0; j<board[0].size();j++)
            {
                if(board[i][j]>=1)
                    board[i][j]=1;
                else
                    board[i][j]=0;
            }
    }
    
};