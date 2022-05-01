class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        string ans="";
        
        for(auto x:s)
        {
            if(st.empty())
                st.push(x);
            else if(x==st.top())
            {
                    st.pop();
            }
            else 
                 st.push(x);
                
        }
        while(!st.empty())
        {
            char a=st.top();
            ans+=a;
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};