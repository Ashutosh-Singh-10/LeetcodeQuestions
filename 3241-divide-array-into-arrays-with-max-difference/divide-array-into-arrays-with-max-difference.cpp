class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& vec, int k) {
        int n=vec.size();
        sort(vec.begin(),vec.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i+=3)
        {
            if(vec[i+2]-vec[i]>k) return {};
            ans.push_back({vec[i],vec[i+1],vec[i+2]});
        }
        return ans;
    }
};