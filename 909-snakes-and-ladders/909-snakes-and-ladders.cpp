class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int r=board.size();
        int steps=0;
        
        queue<int>q;
        q.push(1);
        
        while(!q.empty())
        {
            int n=q.size();
            for(int i=0;i<n;i++)
            {
                int t=q.front();
                q.pop();
                if(t==r*r)return steps;
                for(int i=1;i<=6;i++)
                {
                    int next_step=t+i;
                    if(next_step>r*r)break;
                    
                    auto pos=findCoordinates(r,next_step);
                    int row=pos[0];
                    int col=pos[1];
                    
                    if(board[row][col]!=-1)
                        next_step=board[row][col];
                    if(board[row][col]!=r*r+1)
                    {
                        q.push(next_step);
                        board[row][col]=r*r+1;
                    }
                }
            }
            steps++;
        }
        return -1;
        
    }
    
    vector<int> findCoordinates(int row,int next_step)
    {
        int x=(next_step-1)/row;
        int y=(next_step-1)%row;
        if(x%2==1)y=row-1-y;
        x=row-1-x;
        return {x,y};
    }
};

//compare this two solution for the explaination
//https://github.com/luckykumardev/leetcode-solution/blob/master/snakes%20and%20ladders.java
//https://leetcode.com/problems/snakes-and-ladders/discuss/627444/C%2B%2B-solution-with-detailed-explanation