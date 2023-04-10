class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        
        for(auto i:s){
            if(i=='('|| i=='{' || i=='[')
                st.push(i);
            
            else {

                if(st.empty()==true)
                    {
                        return false;
                    }
                else
                {
                    char temp=st.top();
                    if(i=='}')
                    {
                        if(temp!='{')
                            return false;
                    }
                    if(i==')')
                    {
                        if(temp!='(')
                            return false;
                    }
                    if(i==']')
                    {
                        if(temp!='[')
                            return false;
                    }
                }
                st.pop();
            }
        }
            if(st.empty()==true)
                return true;
            return false;
        
    }
};