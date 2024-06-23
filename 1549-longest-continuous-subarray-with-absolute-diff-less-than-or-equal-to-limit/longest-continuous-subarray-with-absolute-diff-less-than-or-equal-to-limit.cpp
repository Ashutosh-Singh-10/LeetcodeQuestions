class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        multiset<int> st;
        int start=0,n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++)
        {
            st.insert(nums[i]);
            while(*st.rbegin()-*st.begin()>limit)
            {
                st.erase(st.find(nums[start]));
                start++;
            }
            ans=max(ans,i-start+1);
        }
        return ans;


        
    }
};