class Solution {
public:
    class Trie{
        public:
            Trie *child[26];
            bool isEnd=false;
    };
    
    void insert(string &word,Trie* root){
        Trie *curr=root;
        for(auto &ch:word){
            if(!curr->child[ch-'a'])curr->child[ch-'a']=new Trie();
            curr=curr->child[ch-'a'];
        }
        curr->isEnd=true;
    }
    
    bool search(string &word,Trie* root){
        Trie* curr=root;
        for(auto &ch:word){
            if(!curr->child[ch-'a'])return false;
            curr=curr->child[ch-'a'];
        }
        return curr->isEnd;
    }
    
    int dp[305][305];
        vector<string> ans;//Store all valid sentences

    void solve(const string &s, Trie* root, string st,int pos){
        if(pos==s.size()){
            ans.push_back(st);
            return;
        }
        st+=" ";
        for(int i=pos;i<s.size();i++){
            string str=s.substr(pos,i-pos+1);
            if(search(str,root))
                solve(s,root,st+s.substr(pos,i+1-pos),i+1);
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        Trie* root=new Trie();
        for(auto word: wordDict)
            insert(word,root);
        
        for(int i=0;i<s.size();i++){
            string str=s.substr(0,i+1);
            if(search(str,root))
                solve(s,root,s.substr(0,i+1),i+1);
        }
        return ans;
    }
};