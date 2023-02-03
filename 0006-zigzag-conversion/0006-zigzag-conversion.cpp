class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        vector<string>temp(numRows);
        int i=0,n=s.size();
        
        while(i<n){
            for(int j=0;j<numRows && i<n ;j++,i++)temp[j]+=s[i];
            for(int j=numRows-2;j>0 && i<n;j--,i++)temp[j]+=s[i];
        }
        for(int j=0;j<numRows;j++)ans+=temp[j];
        return ans;
    }
};