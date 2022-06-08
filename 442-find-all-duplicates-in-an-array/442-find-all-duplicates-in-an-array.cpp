class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n=nums.size();
        vector<int>dup;
        for(int i=0;i<n;i++)
        {
            int ind=abs(nums[i])-1;
            
            nums[ind]=nums[ind]*(-1);
            
            if(nums[ind]>0)
                dup.push_back(ind+1);
        }
        return dup;
    }
};