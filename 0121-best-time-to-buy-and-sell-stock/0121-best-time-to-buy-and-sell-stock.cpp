class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi=prices[0];
        int ans=-1;
        for(auto x:prices){
            mi=min(x,mi);
            ans=max(ans,x-mi);
        }
        return ans;
    }
};