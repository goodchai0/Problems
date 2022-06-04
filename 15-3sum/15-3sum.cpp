class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        map<int,int>mp;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++)
            mp[nums[i]]=i;
        int i=0;
        int j=1;
        int k=2;
         vector<vector<int>>ans;
        int a,b,c;
        while(i < nums.size())
        {
            if(nums[i]>0)   break;
            
            while(j < nums.size())
            {
                if(mp.find(-nums[i]-nums[j])!=mp.end() && mp[-nums[i]-nums[j]] > j)
                {
                    a=nums[i];
                    b=nums[j];
                    c=(-nums[i]-nums[j]);
                    ans.push_back({a,b,c});
                }
                j=mp[nums[j]]+1;
            }
           i=mp[nums[i]]+1;
            j=i+1;
            
        }
        return ans;
        
    }
};