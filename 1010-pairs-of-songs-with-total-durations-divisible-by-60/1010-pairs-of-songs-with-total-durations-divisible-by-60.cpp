class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int,int>mp;
        int count=0;
        for(int i=0;i<time.size();i++)
        {
            int curr=time[i]%60;
            if(curr==0)
                count+=mp[0];
            else if(mp.find(60-curr)!=mp.end())
                count+=mp[60-curr];
            
            mp[curr]++;
        }
        return count;
    }
};