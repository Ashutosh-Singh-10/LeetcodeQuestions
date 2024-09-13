class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> xo;
        xo={1};
        vector<int> ans;
        for(auto &i:arr) xo.push_back(xo.back()^i);
        for(auto &i:queries)
        {
            ans.push_back(xo[i[1]+1]^xo[i[0]]);
        }
        return ans;
        
    }
};