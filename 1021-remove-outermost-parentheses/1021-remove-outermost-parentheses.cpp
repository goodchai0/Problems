class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char>st;
        string ans;
        
        for(auto c:s)
        {
            if(c==')') st.pop();
            if(!st.empty()) ans+=c;
            if(c=='(')st.push(c);
        }
        return ans;
    }
};