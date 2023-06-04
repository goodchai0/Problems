class Solution {
public:
    class Trie{
        public:
            Trie *child[26];
            bool isEnd=false;
    };
    
    void insert(string &word,Trie* root){
        Trie* curr=root;
        for(auto ch:word){
            if(!curr->child[ch-'a'])curr->child[ch-'a']=new Trie();
            curr=curr->child[ch-'a'];
        }
        curr->isEnd=true;
        
    }
    
    bool search(string &word,Trie* root){
        
        Trie* curr=root;
        for(auto ch:word){
            if(!curr->child[ch-'a'])return false;
            curr=curr->child[ch-'a'];
        }
        return curr->isEnd;
      
    }
    
    int dp[305];
    
    bool solve(string &s, Trie *root,int n,int start){
        if(start==n)return true;
        if(dp[start]!=-1)return dp[start];
        for(int i=start;i<n;i++){
            string str=s.substr(start,i-start+1);
            if(search(str,root)){
                if(solve(s,root,n,i+1))return dp[start]=true;
            }
        }
        return dp[start]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie* root=new Trie();
        for(auto &word:wordDict)insert(word,root);
        
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        return solve(s,root,n,0);
    }
};