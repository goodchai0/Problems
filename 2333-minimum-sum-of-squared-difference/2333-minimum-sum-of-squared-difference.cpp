class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        unordered_map<int,int>mp;
        
        for(int i=0;i<nums1.size();i++){
            mp[abs(nums1[i]-nums2[i])]++;
        }
        int k=k1+k2;
        int curr=0;
        int value=0;
        
        for(int i=(int)1e5;i>=0;i--){
            curr=mp[i];
            if(curr<k){
                if(i<=1)
                    return 0;
                
                mp[i-1]+=mp[i];
                mp[i]=0;
                k-=curr;
            }
            else{
                if(i==0)
                    return 0;
                mp[i]-=k;
                mp[i-1]+=k;
                break;
            }
        }
        long long ans=0;
        
        for(int i=1;i<=1e5;i++){
            ans+=(long long)mp[i]*((long long)i*i);
        }
        
        return ans;
    }
};