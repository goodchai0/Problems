class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int n=nums.size();
        vector<int>count(n);
        vector<int>temp(102,0);
        for(int i=0;i<n;i++)
        {
            temp[nums[i]]++;
        }
        for(int i=1;i<102;i++)
        {
            temp[i]+=temp[i-1];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                count[i]=0;
            else
            count[i]+=temp[nums[i]-1];
        }
        return count;
    }
};

// class Solution {
// public:
//     vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
//         int n=nums.size();
//         vector<int> ans(n);
//         for(int i=0;i<nums.size();i++)
//         {
//             pair<int,int>p;
//             p.first=nums[i];
//             p.second=i;
//             q.push(p);
//         }
//         int s=0;
//         // pair<int,int>x;
//         // x.first=-1;
//         // x.second=-1;
//         pair<int,int>p=q.top();
//         ans[p.second]=0;
//         q.pop();
//         for(int i=0;i<n;i++)
//         {
//             // cout<<q.top().first<<q.top().second<<endl;
//             // if(q.top().first==x.first)
//             // {
//             //      ans[x.second]=s+1;
//             //      q.pop();
//             //      s--;
//             // }
               
            
            
//                 pair<int,int>x=q.top();
//                 if(x.first==p.first)
//                 {
//                     // while(x.first==p.first)
//                     // {
//                         x=q.top();
//                         ans[x.second]=s;
//                         q.pop();
//                     // }
//                 }
//                 else{
//                     ans[x.second]=s;
//                     s++;
//                     q.pop();
//                 }
//                 p=x;
                
//         }
//         return ans;
        
//     }
// };