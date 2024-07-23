
bool compare(pair<int,int>& a,pair<int,int>& b)
{
    if(a.second==b.second)
    {
        if(a.first>b.first) return 1;
        else return 0;
    }
    else if(a.second>b.second) return 0;
    else return 1;
}
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) { 
        unordered_map<int,int> hashmap;
        for(const auto &i:nums)
        {
            if(hashmap.count(i)) hashmap[i]++;
            else hashmap[i]=1;

        }
        vector<pair<int,int>> vec;
        for(const auto &i:hashmap)
        {
            vec.push_back({i.first,i.second});
        }
        sort(vec.begin(),vec.end(),compare);
        vector<int> ans;
        for(int i=0;i<vec.size();i++)
        {
            while(vec[i].second--)
            {
                ans.push_back(vec[i].first);
            }
        }
        return ans;
        
    }
};