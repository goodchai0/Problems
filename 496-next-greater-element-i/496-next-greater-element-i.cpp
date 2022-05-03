class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int,int>mp;
        stack<int>st;
        vector<int>ans;
        int n=nums2.size();
        
        for(int i=n-1;i>=0;i--)
        {
            int ele=nums2[i];
            // if(st.empty())
            // {
            //     st.push(ele);
            // }
            while(!st.empty() && st.top()<ele)
            {
                st.pop();
            }
            
            int res=(st.empty())?-1:st.top();
            mp.insert({ele,res});
            st.push(ele);
        }
        
        for(auto x:nums1)
            ans.push_back(mp[x]);
        
        return ans;
    }
    
};