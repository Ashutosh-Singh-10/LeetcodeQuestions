class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>> vec;
        int x;
        int temp;
        for(auto &i:arr)
        {
            x=0;
            temp=i;
            while(i)
            {
                if(i%2) x++;
                i/=2;
            }
            vec.push_back({x,temp});
        }
        sort(vec.begin(),vec.end());
        vector<int> ans;
        for(auto &i:vec)
        {
            ans.push_back(i.second);
        }
        return ans;
        
    }
};