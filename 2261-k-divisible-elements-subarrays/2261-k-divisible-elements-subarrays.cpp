class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n=nums.size();
        set<vector<int>>ans;
        
        int i,j;
        for(i=0;i<n;i++){
            vector<int>tt;
            int cnt=0;
            for(j=i;j<n;j++){
                tt.push_back(nums[j]);
                if(nums[j]%p==0)
                    cnt++;
                if(cnt>k)
                    break;
                ans.insert(tt);
            }
        }
        return ans.size();
    }
};