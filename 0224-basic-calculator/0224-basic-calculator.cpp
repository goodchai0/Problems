class Solution {
public:
    int calculate(string s) {
        
        stack<pair<int,int>>st; //sum,sign;
        long long int sum=0;
        
        int sign=1;
        
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            
            // since its a string.
            //-111+10
            //
            if(isdigit(ch))
            {
                long long int num=0;
                while(i<s.size() && isdigit(s[i]))
                {
                    num=(num*10)+s[i]-'0';//'0' to convert it into int;
                    i++;
                }
                i--; // because of while loop;
                sum+=(num*sign);
                sign=1;
            }
            else if(ch=='(')
            {
                st.push(make_pair(sum,sign));//pushing the current sum with sign
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


// 1+11-3=9
// 14

//     9+14
//     23
    
    


// "(1+(4+5+2)-3)+(6+8)"

// when first bracket will start sum=0;
// adding sum+=1;

// sum=1;
// stack(sum);
// sum=0
    
// 4+5+2=11
// sum=9;

// stack mai jo | previous sum +=present sum;
// sum=1+11=12;


//    sign=-1;
// sum=sum+3*sign;
    


    
// when second '(' will start 
// we will store the sign and sum at that present state in the stack.
// then we will make
// sum=0;

// after adding till ')'
    
// after the ')' is encountered.

// we will add the previous sum pushed into the stack to the present sum.

    
// consider example: (1+2)-(2+1);// sign -ve present sum* sign;
// //prevuious sum + current sum*sign;
// the minus sign in the need to addressed.
// so we will also store the sign in the stack with the current sum.


