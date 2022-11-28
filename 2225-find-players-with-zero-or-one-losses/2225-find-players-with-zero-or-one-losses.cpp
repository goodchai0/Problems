class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        vector<int> zero_lost, one_lost;
        map<int, int> mpp;
        for(int i = 0; i < matches.size(); i++) {
            mpp[matches[i][0]] += 0;
            mpp[matches[i][1]] += 1;
        }
        
        for(auto it: mpp) {
            if(it.second == 0) {
                zero_lost.push_back(it.first);
            } else if(it.second == 1) {
                one_lost.push_back(it.first);
            }
        }
        ans.push_back(zero_lost);
        ans.push_back(one_lost);
        return ans;
    }
};