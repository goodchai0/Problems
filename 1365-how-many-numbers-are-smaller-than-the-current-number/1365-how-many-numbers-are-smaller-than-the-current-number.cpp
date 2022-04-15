class Solution {
    
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int>temp(102,0);
        vector<int>count(n);
        for(int i=0;i<n;i++)
        {
            temp[nums[i]]++;
        }
        
        for(int i=1;i<102;i++)
        {
            temp[i]+=temp[i-1];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                count[i]=0;
            else
            count[i]=temp[nums[i]-1];
        }
        
        return count;
    }
};