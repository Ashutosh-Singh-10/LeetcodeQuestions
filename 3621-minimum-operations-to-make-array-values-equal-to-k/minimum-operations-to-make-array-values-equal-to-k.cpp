class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]<k) return -1;
        set<int> st;
        for(auto &i:nums) st.insert(i);
        if(st.count(k)) return st.size()-1;
        return st.size();
        
    }
};