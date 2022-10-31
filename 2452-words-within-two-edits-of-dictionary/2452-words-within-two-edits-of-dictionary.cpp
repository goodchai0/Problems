class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        set<int>ans;
        vector<string>ans1;
        for(int i=0;i<queries.size();i++){
            
            string y=queries[i];
            for(int j=0;j<dictionary.size();j++){
                
                string x=dictionary[j];
                int count=0;
                for(int k=0;k<queries[i].size();k++){
                    if(x[k]!=y[k])
                        count++;
                    
                    if(count>2)
                        break;
                    
                }
                if(count<=2)
                    ans.insert(i);
            }
        }
        // sort(ans.begin(),ans.end());
        
        for(auto x:ans)
            ans1.push_back(queries[x]);
        return ans1;
    }
};