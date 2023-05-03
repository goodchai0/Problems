class Solution {
public:
    static vector<vector<int>> findDifference(const vector<int>& nums1, const vector<int>& nums2) {
        const set<int> s1(begin(nums1), end(nums1));
        const set<int> s2(begin(nums2), end(nums2));
        vector<vector<int>> ans(2);
        ans[0].reserve(size(nums1));
        ans[1].reserve(size(nums2));
        set_difference(begin(s1), end(s1), begin(s2), end(s2), back_inserter(ans[0]));
        set_difference(begin(s2), end(s2), begin(s1), end(s1), back_inserter(ans[1]));
        return ans;
    }
};