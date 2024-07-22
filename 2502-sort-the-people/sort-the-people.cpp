class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> vec;
        vector<string> ans;
        for(int i=0;i<names.size();i++)
        {
            vec.push_back({heights[i],names[i]});
        }
        sort(vec.begin(),vec.end());
        while(vec.size())
        {
            ans.push_back(vec.back().second);
            vec.pop_back();
        }
        return ans;
        
    }
};