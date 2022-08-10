class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        vector<long long>ans;
        double x=num*1.00/3;
        cout<<x;
        if(x!=(long long)x)
            return ans;
        else{
            ans.push_back(x-1);
            ans.push_back(x);
            ans.push_back(x+1);
        }
        return ans;
    }
};