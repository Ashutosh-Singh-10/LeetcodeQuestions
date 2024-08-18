class Solution {
public:
    int nthUglyNumber(int n) {
        set<long long> st={1};
        while(st.size() && n>1)
        {
            auto sm=*st.begin();
            st.erase(st.begin());
            st.insert(sm*3ll);
            st.insert(sm*2ll);
            st.insert(sm*5ll);
            n--;
        }
        return *st.begin();
       


    }
};