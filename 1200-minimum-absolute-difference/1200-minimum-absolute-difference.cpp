class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int mi=INT_MAX;
        
        
        vector<vector<int>>ans;
        for(int i=1;i<arr.size();i++)
        {
            mi=min(mi,(arr[i]-arr[i-1]));
        }
        
        for(int i=1;i<arr.size();i++)
        {
            
            if((arr[i]-arr[i-1])==mi)
            {   vector<int>v(2);
                v[0]=(arr[i-1]);
                v[1]=(arr[i]);
                ans.push_back(v);
            }
           
        }
        return ans;
            
    }
};