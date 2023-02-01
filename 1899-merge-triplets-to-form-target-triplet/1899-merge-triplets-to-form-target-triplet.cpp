class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>res(3);
        for(auto &x:triplets){
            if(x[0]<=target[0] && x[1]<=target[1] && x[2]<=target[2])
                res={max(x[0],res[0]),max(x[1],res[1]),max(x[2],res[2])};
        }
        for(auto x:res){
            cout<<x;
        }
        return res==target;
    }
};