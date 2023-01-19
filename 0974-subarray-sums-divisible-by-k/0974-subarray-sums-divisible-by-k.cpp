class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int curr=0;
        map<int,int>mp;
        mp[0]=1;
        int ans=0;
        int rem;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            rem=(curr%k+k)%k;
            
            if(mp[rem]){
                ans+=mp[rem];
            }
            mp[rem]++;
        }
        return ans;
    }
};