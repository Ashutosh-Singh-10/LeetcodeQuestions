class Solution {
public:
    int minOperations(vector<int>& nums) {
        int i=nums.size()-1;
        set<int> st;
        for(;i>=0;i--){
            if(st.count(nums[i])) break;
            st.insert(nums[i]);
        }
        
        return (i+3)/3;
        
    }
};