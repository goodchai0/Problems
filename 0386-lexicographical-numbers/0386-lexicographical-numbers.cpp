class TrieNode{
public:
    vector<TrieNode*>next;
    bool isWord;
    int data;
    TrieNode(){
        next.resize(10,NULL);
        isWord=false;
        data=-1;
    }
};



class Solution {
public:
    TrieNode *root=new TrieNode();
    vector<int>ans;
    
    void printAll(TrieNode* root){
        if(root->isWord){
            ans.push_back(root->data);
        }
        
        for(int i=0;i<10;i++){
            if(root->next[i])
                printAll(root->next[i]);
        }
    }
    
    void insert(int num){
        string s=to_string(num);
        TrieNode* p=root;
        
        for(int i=0;i<s.size();i++){
            if(p->next[s[i]-'0']==NULL)
                p->next[s[i]-'0']=new TrieNode();
            p=p->next[s[i]-'0'];
        }
        p->data=num;
        p->isWord=true;
    }
    
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=n;i++){
            insert(i);
        }
        printAll(root);
        return ans;
    }
};