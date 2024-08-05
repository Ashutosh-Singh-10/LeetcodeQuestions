class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        set<string> st,tt;
        for(auto &i:arr)
        {
            if(st.count(i)) tt.insert(i);
            st.insert(i);
        }
        int cnt=0;
        for(auto &i:arr)
        {
            if(tt.count(i)==0)
            {
                cnt++;
            }
            if(cnt==k) return i;
        }
        return "";
        
    }
};