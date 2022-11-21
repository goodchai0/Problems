class Solution {
public:
    int n,m;
    bool isBorder(int i,int j){
        return (i==0 || i==m-1 || j==0 || j==n-1);
    }
    
    bool valid(int r,int c){
        return (r>=0 && c>=0 && r<m && n>c);
    }
    
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0} ; // (0,0)->(0,1),(0,-1),(1,0),(-1,0);
    
    

    
    int nearestExit(vector<vector<char>>& maze, vector<int>& e) {
        
        m=maze.size(),n=maze[0].size();
        int ans=0;
        if(isBorder(e[0],e[1]))
            maze[e[0]][e[1]]='+';
        queue<pair<int,int>>q;
        q.push({e[0],e[1]});
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                auto top=q.front();
                q.pop();
                int x=top.first,y=top.second;
                if( maze[x][y]!='+' && isBorder(x,y))
                    return ans;
                
                for(int j=0;j<4;j++){
                    int r=x+dx[j];
                    int c=y+dy[j];
                    
                    if(valid(r,c) && maze[r][c]=='.'){
                        q.push({r,c});
                        maze[r][c]='*';
                    }
                }
                    
            }
            ans++;
        }
        return -1;
    }
};