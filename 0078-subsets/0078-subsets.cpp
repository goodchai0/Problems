class Solution {
public:
    vector<vector<int>> ans;
//     void generate(vector<int>& nums,int i,vector<int>& v){
//         if(i==nums.size()){
//             ans.push_back(v);
//             return ;
//         }
        
//         v.push_back(nums[i]);
        
//         generate(nums,i+1,v);
//         v.pop_back();            
//         generate(nums,i+1,v);
        
//     }
    vector<vector<int>> subsets(vector<int>& s) {
        vector<int>v;
        // generate(nums,0,v);
        int n=1<<s.size();
		    
		    for(int i=0;i<n;i++){
		        vector<int>temp;;
		        for(int j=0;j<s.size();j++){
		            if(i&(1<<j)){
		                temp.push_back(s[j]);
		            }
		        }
		        ans.push_back(temp);
		    }
		    sort(ans.begin(),ans.end());
		    return ans;
    }
};