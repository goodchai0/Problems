class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
       unordered_map<string,int>hash;
        
        for(int row=0;row<board.size();row++)
        {
            for(int col=0;col<board[0].size();col++)
            {
                char number=board[row][col];
                if(number!='.')
                {
                    string r="row"+to_string(row)+to_string(board[row][col]);
                    // r=row05
                    string c="col"+to_string(col)+to_string(board[row][col]);
                    // c=col05
                    int b=(row/3)*3+(col/3);
                    // b=3+0 ,b=3
                    string box="box" + to_string(b)+ to_string(board[row][col]);
                    // b=box05
                    if(hash[r]!=1 && hash[c]!=1 && hash[box]!=1)
                    {
                        hash[r]+=1;
                        hash[c]+=1;
                        hash[box]+=1;
                      
                    }
                     else return false;
                }
            }
        }
        return true;
    }
};