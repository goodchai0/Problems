class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int i=0,j=nums.size()-1;
        //sort(nums.begin(),nums.end());
        int sum,cnt=0;
        
        unordered_map<int,int>mp;
        for(auto x:nums)
            mp[x]+=1;
        
        for(auto x:nums)
        {
            if((k-x)==x)
            {
                if(mp[x]==1)
                    continue;
                
            }
           if(mp[k-x]>0 && mp[x]>0)
           {       
               cout<<x<<" "<<k-x<<endl;
               mp[k-x]--;
               cnt++;
               mp[x]--;     
           }
           mp[i]--;
        }     
        return cnt;
    }
};