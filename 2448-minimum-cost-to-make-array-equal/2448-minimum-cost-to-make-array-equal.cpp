class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long int tot=0,sum=0;
        long long int n=cost.size();
        
        vector<pair<int,int>>v;
        
        for(auto i=0;i<n;i++){
            v.push_back({nums[i],cost[i]});
        }
        
        sort(v.begin(),v.end());
        
        for(int i=0;i<n;i++)
            sum=sum+1ll*v[i].second;
        
        long long median;
        int i=0;
        while(tot<(sum+1)/2 && i<n)
        {
            tot=tot+(1ll*v[i].second);
            median=v[i].first;
            i++;
        }
        
        long long ans=0;
        
        for(int i=0;i<nums.size();i++){
            ans=ans+abs(1ll*nums[i]-median)*(1ll*cost[i]);
        }
        return ans;
    }
};