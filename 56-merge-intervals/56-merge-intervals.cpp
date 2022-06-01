class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergedIntervals;
        if(intervals.size()==0)
        {
            return mergedIntervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int>tempInterval=intervals[0];
        for(auto it:intervals)
        {
            if(it[0]<=tempInterval[1])
            {
                tempInterval[1]=max(it[1],tempInterval[1]);
            }
            else
            {
                mergedIntervals.push_back(tempInterval);
                tempInterval=it;
            }
        }
        
        mergedIntervals.push_back(tempInterval);
        return mergedIntervals;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         vector<vector<int>>ans;
//         sort(intervals.begin(),intervals.end());
//         for(int i=;i<intervals.size();i++)
//         {
            
//             if(((i+1)<intervals.size()) && intervals[i][1]>=intervals[i+1][0])
//             {
//                 ans.push_back({intervals[i][0],max(intervals[i+1][1],intervals[i][1])});
//                 i++;
//             }
//             else{
//                 ans.push_back({intervals[i][0],intervals[i][1]});
//             }
                
//         }
//         return ans;
//     }
// };



