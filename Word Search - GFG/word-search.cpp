//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
bool check(vector<vector<char>>& board,int x,int y, string& word,int i){
        if(i==word.size())return true;
        if(x<0 || x>=board.size() || y<0 || y>=board[0].size() || board[x][y]=='.' || board[x][y]!=word[i])
            return false;
        
        char ch=board[x][y];
        board[x][y]='.';
        bool res=(check(board,x+1,y,word,i+1) || check(board,x,y+1,word,i+1)
                 || check(board,x-1,y,word,i+1) ||check(board,x,y-1,word,i+1));
        board[x][y]=ch;
        return res;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(word[0]==board[i][j]){
                    if(check(board,i,j,word,0))return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends