// class Solution {
//     public:
//         vector<int>dp;
//         int solve(int n) {

//             if (n <= 3)  
//                 return n;
      
//             if(dp[n]!=-1)
//                 return dp[n];
//             int ans = n;
         
            
//             for (int i = 1; i * i <= n; i++) {
//                 ans = min(ans, 1 + solve(n - i * i));
//             }
            
//             dp[n] = ans;
//             return ans;
//         }
    
//     int numSquares(int n) {
//         dp.resize(n+1,-1);
//         int ans = solve(n);
//         return ans;
//     }
// };



















//////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



class Solution {
    public:
        int numSquares(int n) {
            int dp[n + 1];
            dp[0] = 0;
            for (int i = 1; i <= n; i++) {
                dp[i] = i;
                
                for (int j = 1; j * j <= i; j++) {
                    int sq = j * j;
                    dp[i] = min(dp[i], 1 + dp[i - sq]);
                }
            }
            return dp[n];
        }
};