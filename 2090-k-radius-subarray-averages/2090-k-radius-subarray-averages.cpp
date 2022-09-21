class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>ans(n,-1);
        
        if(n<(2*k)+1) return ans;
        long long total=0;
        
        for(int i=0;i<2*k+1;i++)total+=nums[i];
        
        int mid=k;
        for(int i=0;i<=(n-(2*k+1));i++){
            ans[mid]=total/(2*k+1);
            
            if(mid+k+1>=n) break;
            
            total-=(long long)nums[mid-k];
            total+=(long long)nums[mid+k+1];
            mid++;
        }
        return ans;
    }
};