class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        set<int> st;
        for(auto &i:edges)
        {
            if(st.count(i[0])) return i[0];
            if(st.count(i[1])) return i[1];
            st.insert(i[0]);
            st.insert(i[1]);
            
        }
        return -1;
        
    }
};