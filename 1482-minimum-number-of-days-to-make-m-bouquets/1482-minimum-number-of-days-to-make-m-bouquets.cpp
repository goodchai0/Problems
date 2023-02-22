class Solution {
public:
     int minDays(vector<int>& A, int m, int k) {
        long long int n = A.size(), left = 1, right = 1e9;
         long long int x=(long long int)m * (long long int)k;
        if (x > n) return -1;
        while (left < right) {
            long long int mid =left+ ( right-left) / 2, flow = 0, bouq = 0;
            for (int j = 0; j < n; ++j) {
                if (A[j] > mid) {
                    flow = 0;
                } else if (++flow >= k) {
                    bouq++;
                    flow = 0;
                }
            }
            if (bouq < m) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};