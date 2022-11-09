class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>>mp(101);
        for(auto &r: rectangles){
            mp[r[1]].push_back(r[0]);
        }
        
        for(int i=0;i<101;i++){
            sort(mp[i].begin(),mp[i].end());
        }
        
        vector<int>res;
        for(auto &p:points){
            int sum=0;
            for(int i=p[1];i<101;i++){
                auto lb=lower_bound(mp[i].begin(),mp[i].end(),p[0]);
                sum+=mp[i].end()-lb;
            }
            res.push_back(sum);
        }
        return res;
    }
};