class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        vector<int>arr(nums.size()+1,-1);
        reverse(nums.begin(),nums.end());
        // set<int>s;
        int step=0;
        int flag2=-1,flag=0;
        for(auto x:nums){
            step++;
            if(x<=k){
                arr[x]=1;
                cout<<x;
            }
            if(x==k){
                flag=1;
            }
            if(flag==1){
                flag2=1;
                for(int i=1;i<=k;i++){
                    if(arr[i]!=1){
                        flag2=0;
                    }

                }
            }
            if(flag2==1){
                return step;
            }
        }
        return step;
    }
};