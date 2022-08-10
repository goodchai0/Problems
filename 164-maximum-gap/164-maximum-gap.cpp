class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxGap=0;
        int n=nums.size();
        if(n<2)
            return 0;
        
        int mi=INT_MAX;
        int ma=INT_MIN;
        
        for(auto i:nums){
            mi=min(mi,i);
            ma=max(ma,i);
        }
        
        int bucketSize=ceil((double)(ma-mi)/(n-1));
        
        vector<int>minOfBucket(n-1,INT_MAX);
        vector<int>maxOfBucket(n-1,INT_MIN);
        
        for(int i=0;i<n;i++){
            if(nums[i]==mi ||nums[i]==ma)
                continue;
            
            int bucketIndexForCurEle=(nums[i]-mi)/bucketSize;
            
            minOfBucket[bucketIndexForCurEle]=min(minOfBucket[bucketIndexForCurEle],nums[i]);                               maxOfBucket[bucketIndexForCurEle]=max(maxOfBucket[bucketIndexForCurEle],nums[i]);
            

        }
        
        for(int i=0;i<n-1;i++)
        {
            if(maxOfBucket[i]==INT_MIN)
                continue;
            
            maxGap=max(minOfBucket[i]-mi,maxGap);
            mi=maxOfBucket[i];
        }
        
        maxGap=max(maxGap,ma-mi);
        
        return maxGap;
    }
};