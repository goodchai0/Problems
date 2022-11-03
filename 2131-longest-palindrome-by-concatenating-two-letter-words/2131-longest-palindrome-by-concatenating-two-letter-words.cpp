class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>m;
        int res=0,center=0;
        for (auto &w : words)
            ++m[w];
        for(auto &[w,cnt]:m){
            string reversed=string(rbegin(w), rend(w));
            if(w==reversed)
            {
                res+=2*(cnt/2);
                center|=cnt%2;
                // cout<<center<<" ";
            }
            else{
                auto it=m.find(reversed);
                if(it!=m.end())
                    res+=min(cnt,it->second);
                    
            }
        }
        // cout<<endl;
        return 2*res+(center?2:0);
    }
};