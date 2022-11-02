class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int res=0,maxi=*max_element(begin(candidates),end(candidates));
        for(auto i=1;i<=maxi;i <<= 1){
            int count=0;
            for(auto x:candidates){
                count+=(x&i)>0;
            }
            res=max(count,res);
        }
        return res;
    }
};