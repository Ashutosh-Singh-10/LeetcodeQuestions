class Solution {
public:
    int minOperations(vector<int>& nums) {
        set<int> st;
        int ans=0;
        for(auto &i:nums){
            if(i==0) {
                ans+=st.size();
                st.clear();
            }
            else {
                while(st.size() && *st.rbegin()>i){
                    ans++;
                    auto it=st.end();
                    it--;
                    st.erase(it);
                }
                st.insert(i);
            }
        }
        ans+=st.size();
        return ans;
    }
};