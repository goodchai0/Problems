class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        set<int>s;
        unordered_map<int,int>mp;
        for(auto x:nums){
            s.insert(x);
            mp[x]++;
        }
        int x,y;
        for(int i=1;i<=nums.size();i++){
            if(s.find(i)==s.end()){
                y=i;
            }
            if(mp[i]==2){
                x=i;
            }
        }
        
        vector<int>v;
        v.push_back(x);
        v.push_back(y);
        
        return v;
    }
};