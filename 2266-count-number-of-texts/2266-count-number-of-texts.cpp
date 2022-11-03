class Solution {
public:
    int countTexts(string pressed) {
        
        int MOD = 1000000007;
        int pl = pressed.length();
        
        // base case combinations for 2-9 digits of length 0 to 4
        vector<vector<int>>preDP = {{0,1,2,4},{0,1,2,4,8}};
            
        // store max freq of each digit and freq chunks
        int maxFreq[10] = {};
        vector<int>freq[10];
        
        int curr = -1;
        int count = 0;
        
        for(int i=0;i<pl;i++)
        {
            if(pressed[i]-'0' == curr)
            {
                count++;
                maxFreq[curr] = max(maxFreq[curr],count);
                freq[curr].back()++;
            }
            else
            {
                curr = pressed[i]-'0';
                count = 1;
                maxFreq[curr] = max(maxFreq[curr],count);
                freq[curr].push_back(count);
            }
        }
        
        vector<long long>dp(pl+1);
        unsigned long long totalCount = 1L;
        int type;
        for(int i=0;i<10;i++)
        {
            if(maxFreq[i]==0)continue;
            
            // get digit type
            type = (i==7 || i==9) ? 1 : 0;
            
            // store the base case combinations for length 0 to 4
            for(int j=0;j<=maxFreq[i] && j<=3+type;j++)
                dp[j] = preDP[type][j];
            
            // store combinations for length 5 to max freq of current digit 
            for(int j=4+type;j<=maxFreq[i];j++)
                dp[j] = (dp[j-1]  + dp[j-2] + dp[j-3] + (type ? dp[j-4] : 0) + MOD)%MOD;
            
            // get the digit freq chunk multiplications as they are independent
            for(int j=0;j<freq[i].size();j++)
                totalCount = (totalCount%MOD * dp[freq[i][j]]%MOD) %MOD ;  
        }
        
        return (int)totalCount;
    }
};