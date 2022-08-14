class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long int n=nums.size();
        long long int count=0,sum=0,j=0;
        for(long long int  i=0;i<n;i++)
        {   
            sum=sum+nums[i];
            while((sum*((i-j)+1))>=k){
                sum-=nums[j];
                j++;
            }
            count+=(i-j+1);
        }
        
        cout<<count;
        return count;
    }
};