class Solution {
public:
    
    
    
    void settle(vector<int> &nums,vector<pair<int,int>> &vec,set<int> &st,int start)
    {
        
        for(auto &i:st)
        {
            nums[i]=vec[start].first;
            start++;
        }
    }
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<pair<int,int>> vec;
        for(int i=0;i<nums.size();i++)
        {
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        set<int> st;
        int start=0;
        int prev=vec[0].first;
        for(int i=0;i<nums.size();i++)
        {
            if(vec[i].first-prev<=limit)
            {
                st.insert(vec[i].second);
            }
            else 
            {
                settle(nums,vec,st,start);
                start=i;
                st.clear();
                st.insert(vec[i].second);
                // cout<<i<<" ";
            }
            prev=vec[i].first;
        }
        if(st.size())
        {
            settle(nums,vec,st,start);
        }
        return nums;

    }
};