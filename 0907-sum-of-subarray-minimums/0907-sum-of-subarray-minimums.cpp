class Solution {
public:
    long long int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        
        
        ///Left
        vector<int> left(n,0), right(n,n);
        stack<int> st;
        
        for(int i=0; i<n; i++)
        {
            while(st.size() && arr[i] < arr[st.top()]) st.pop();
            if(st.size()) left[i] = i - st.top();
            else left[i] = i+1;
            st.push(i);
            // cout<<left[i]<<" ";
        }
        while(st.size()) st.pop();
        
        
        
        // Right
        for(int i=n-1; i>=0; i--)
        {
            while(st.size() && arr[i] <= arr[st.top()]) st.pop();
            if(st.size()) right[i] = st.top() - i;
            else right[i] = n - i;
            st.push(i);
            cout<<right[i]<<" ";
        }
        
        
        int res = 0;
        for(int i=0; i<n; i++)
        {
            long long prod = (left[i]*right[i])%MOD;
            prod = (prod*arr[i])%MOD;
            res = (res + prod)%MOD;
        }
        
        return res%MOD;
    }
};