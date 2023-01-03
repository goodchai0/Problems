class Solution {
public:
    int minDeletionSize(vector<string>& str) {
        int res=0;
        if(str.empty())return res;
        
        for(auto c=0;c<str[0].size();c++){
            for(auto r=0;r<str.size()-1;r++){
                if(str[r][c]>str[r+1][c])
                {
                    res++;
                    break;
                }
            }
        }
        return res;
    }
};