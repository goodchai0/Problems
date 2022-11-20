class Solution {
public:
    int calculate(string s) {
        
        stack<pair<int,int>>st;
        long long int sum=0;
        
        int sign=+1;
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(isdigit(ch))
            {
                long long int num=0;
                while(i<s.size() && isdigit(s[i]))
                {
                    num=(num*10)+s[i]-'0';
                    i++;
                }
                i--;
                sum+=(num*sign);
                sign=1;
            }
            else if(ch=='(')
            {
                st.push(make_pair(sum,sign));
                sum=0;
                sign=1;
            }
            else if(ch==')')
            {
                sum=st.top().first + (st.top().second*sum);
                st.pop();
            }
            else if(ch=='-')
            {
                sign=(-1*sign);
            }
        }
        return sum;
    }
};

// "(1+(4+5+2)-3)+(6+8)"

// when first bracket will start sum=0;
// adding sum+=1;

// when second '(' will start 
// we will store the sign and sum at that present state in the stack.
// then we will make
// sum=0;

// after adding till ')'
    
// after the ')' is encountered.

// we will add the previous sum pushed into the stack to the present sum.

    
// consider example: (1+2)-(2+1);
// the minus sign in the need to addressed.
// so we will also store the sign in the stack with the current sum.


