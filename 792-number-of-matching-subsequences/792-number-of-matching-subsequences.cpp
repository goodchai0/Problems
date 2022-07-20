class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>>m;
        int i=0;
        for(auto x:s)
            m[x].push_back(i++);
        
        bool flag=1;
        int count=0;
        for(int i=0;i<words.size();i++)
        {
            int latest=-1;
            
            string curr=words[i];
            for(int j=0;j<words[i].size();j++)
            {
                auto it=upper_bound(m[curr[j]].begin(),m[curr[j]].end(),latest);
                if(it==m[curr[j]].end())break;
                latest=*it;
                if(j==curr.size()-1)count++;
            }
        }
            
        return count;
    }
};