class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
         int x=target.size();
        cout<<x<<endl;
         int l=target[x-1];
        cout<<l<<endl;
        int j=0;
        for(int i=1;i<=n;i++)
        {   
            if(l==i-1)
                break;
            if(target[j]==i)
            {
                ans.push_back("Push");
                j++;
            }
            
                
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            
        }
        return ans;
    }
};