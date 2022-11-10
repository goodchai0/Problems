class Solution {
public:
    string removeDuplicates(string s) {
        stack<char>st;
        for(auto x:s){
            if(!st.empty() &&x==st.top())st.pop();
            else st.push(x);
        }
        string ans="";
        while(!st.empty()){
            char x=st.top();
            st.pop();
            ans+=x;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};