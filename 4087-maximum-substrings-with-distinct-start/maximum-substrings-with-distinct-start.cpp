class Solution {
public:
    int maxDistinct(string s) {
        
        set<int> st;
        for(auto &i:s) st.insert(i);
        return st.size();
    }
};