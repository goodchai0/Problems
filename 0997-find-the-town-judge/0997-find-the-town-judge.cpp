class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp1;
        for(int i=0;i<trust.size();i++){
            mp[trust[i][0]]++;
            mp1[trust[i][1]]++;
        }
        if(trust.size()==0 && n==1)return 1;
        int ans=-1;
        int size=mp.size();
        // <<" "<<endl;
        for(int i=0;i<trust.size();i++){
            
            cout<<mp[trust[i][1]]<<" "<<mp1[trust[i][1]]<<" "<<mp.size();
            if(mp[trust[i][1]]==0 && (mp1[trust[i][1]]==n-1)){
                ans=trust[i][1];
            }
        }
        return ans;
    }
};