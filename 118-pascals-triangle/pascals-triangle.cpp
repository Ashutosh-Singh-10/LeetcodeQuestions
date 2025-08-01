class Solution {
public:
   
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        ans.push_back({1});
        for(int i=1;i<numRows;i++)
        {
            
            ans.push_back({1});
           
            for(int k=1;k<i;k++)
            {
                ans[i].push_back(ans[i-1][k-1]+ans[i-1][k]);

            }
            ans[i].push_back(1);
        }        
        return ans;
    }
};