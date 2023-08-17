class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int f, int x) {
        int n=nums.size();
        vector<int>bucket(101,0);
        vector<int>ans;
        int i=0;
        int j=0;
        while(j<n){
            bucket[nums[j]+50]++;
            if(j-i+1==f){
                int y=x;
                int k;
                for(k=0;k<101;k++){
                    // cout<<bucket[k]<<" ";
                    if(bucket[k]!=0 && y!=0){
                        // cout<<k<<endl;
                        y-=bucket[k];
                        if(y<=0)break;
                        // if(bucket[k]!=0){
                        //     k--;continue;
                        // }
                            
                    }
                }
                // cout<<endl;
                int temp=(k-50<0)?k-50:0;
                ans.push_back(temp);
                bucket[nums[i]+50]--;
                i++;
            }
            j++;
        }
        return ans;
    }
};