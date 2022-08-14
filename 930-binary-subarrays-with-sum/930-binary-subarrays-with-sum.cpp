class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int n=nums.size();
        int ans=0,sum=0,j=0;
        if(goal<0)
            return 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[j];
                j++;
            }
            ans+=(i-j+1);
        }
        return ans;
    }
    
    int numSubarraysWithSum(vector<int>& nums, int goal){
        return atMost(nums,goal)-atMost(nums,goal-1);
    }
};