class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=key) continue;
            for(int j=max(i-k,0);j<=min(i+k,n-1);j++)
            {
                st.insert(j);
            }

        }
        vector<int> vec;
        for(auto &i:st) vec.push_back(i);
        return vec;


    }
};