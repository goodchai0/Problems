class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        long long ans = 0, n = nums.size(), i = 0;
        map<int, int> m;
        
        for(int j=0; j<n; j++) {
            m[nums[j]]++;
            
            while(i < j && m.rbegin() -> first - m.begin() -> first > 2) {
                cout<<m.rbegin() -> first<<" "<<m.begin() -> first<<endl;
                if(!--m[nums[i]]) m.erase(nums[i]);
                i++;
            }
            ans += j - i + 1;
        }
        return ans;
    }
};