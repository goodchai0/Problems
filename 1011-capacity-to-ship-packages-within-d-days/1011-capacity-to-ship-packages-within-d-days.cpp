class Solution {
public:
    bool isPossible(int d,int m,vector<int>nums){
        int count=0;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            // if(nums[i]>m)
            //     return false;
            sum+=nums[i];
            if(sum>m){
                count++;
                sum=nums[i];
            }
        }
        count++;
        if(count<=d)
            return true;
        else return false;
        
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum=0,ans=0;
        int ma=INT_MIN;
        for(int i=0;i<weights.size();i++){
            ma=max(ma,weights[i]);
            sum+=weights[i];
        }
        int l=ma;
        int h=sum;
        
        while(l<=h){
            int mid=(l+h)/2;
            if(isPossible(days,mid,weights))
                ans=mid;
            if(isPossible(days,mid,weights))
                h=mid-1;
            else l=mid+1;
        }
        return ans;
    }
};