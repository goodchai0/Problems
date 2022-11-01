class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& sender) {
        unordered_map<string,int>cnt;
        
        string res;
        int max_cnt=0;
        for(int i=0;i<messages.size();i++){
            int words=count(messages[i].begin(),messages[i].end(),' ')+1;
            int total=cnt[sender[i]]+=words;
            if(total>max_cnt || (total==max_cnt && sender[i]>res)){
                max_cnt=total;
                res=sender[i];
            }
        }
        return res;
    }
};