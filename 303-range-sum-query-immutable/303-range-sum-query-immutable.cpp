class NumArray {
public:
    vector<int>seg;
    int n;
    int build(const vector<int> &nums, int l, int r, int node) {     
        int mid;
        int ls,rs;
        if(l==r)return seg[node]=nums[l];
        
        mid=l+(r-l)/2;
        ls=build(nums,l,mid,2*node+1);
        rs=build(nums,mid+1,r,2*node+2);
        return seg[node]=ls+rs;
    }
    int sumRange(int left, int right, int ss, int se, int node) {
        int leftSum, rightSum;
        int middle;

        if (right < ss || left > se) return 0;
        if (left <= ss && se <= right) return seg[node];

        middle = (ss + se) / 2;
        leftSum = sumRange(left, right, ss, middle, 2 * node + 1);
        rightSum = sumRange(left, right, middle+1, se, 2 * node + 2);

        return leftSum + rightSum;
    }
    NumArray(vector<int> &nums) {
        n = nums.size();
        seg.resize(4 * n);
        build(nums, 0, n-1, 0);
    }
    
    int sumRange(int left, int right) {
        return sumRange(left, right, 0, n-1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */