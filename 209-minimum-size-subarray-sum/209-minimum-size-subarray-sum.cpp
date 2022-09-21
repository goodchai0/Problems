class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int j=0,ans=INT_MAX,sum=0;
        //sort(nums.begin(),nums.end(),greater<int>());
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            while(sum>=target)
            {
                cout<<sum<<endl;
                ans=min(i-j+1,ans);
                sum-=nums[j];
                j++;
            }
        }
        return ans==INT_MAX?0:ans;
    }
};