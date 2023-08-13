class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        int n=nums.size();
        vector<long long int>fp(n);
        for(auto i=0;i<n;i++){
            fp[i]=nums[i]+(s[i]=='L'?-d:d);
        }
        int mod=1e9+7;
        sort(fp.begin(),fp.end());
        long long int prefix=0;
        long long int ans=0;
        for(auto i=0;i<n;i++){
            ans=(ans+((fp[i]*i)%mod-prefix)+mod)%mod;
            prefix=(prefix+fp[i])%mod;
        }
        return ans%mod;
    }
};