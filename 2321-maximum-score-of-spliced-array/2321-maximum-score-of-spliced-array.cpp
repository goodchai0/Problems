class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int arr1Major=0;
        int arr2Major=0;
        int n=nums1.size();
        vector<int>diff(n);
        
        for(int i=0;i<n;i++){
            arr1Major+=nums1[i];
            arr2Major+=nums2[i];
        }
        
        // Treating array 1 major
		// More delta to be added in array 1 from array 2
        
        for(int i=0;i<n;i++){
            diff[i]=nums2[i]-nums1[i];
        }
        
        int ma=0, curr=0;
        
        for(int el:diff)
        {
            curr+=el;
            ma=max(curr,ma);
            if(curr<0)
                curr=0;
        }
        arr1Major+=ma;
        
        // Treating array 2 major
		// More delta to be added in array 2 from array 1
        
        for(int i=0;i<n;i++){
            diff[i]=nums1[i]-nums2[i];
        }
        
        ma=0;curr=0;
        
        for(int el:diff)
        {
            curr+=el;
            ma=max(ma,curr);
            if(curr<0)
                curr=0;
        }
        arr2Major+=ma;
        
        return max(arr2Major,arr1Major);
    }
};