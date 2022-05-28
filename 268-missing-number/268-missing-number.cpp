class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=nums.size();
        int r=nums[l-1];
        if( nums[0]!=0)
            return 0;
        int ans=0;
        for(int i=1;i<l;i++)
        {
            ans=ans^nums[i];
            // cout<<nums[i]<<endl;
            // cout<<ans<<" ";
        }
        for(int i=1;i<=l;i++)
        {
            ans=ans^i;
        }
        return ans;
    }
    
};