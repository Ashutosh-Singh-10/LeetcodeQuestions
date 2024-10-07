class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        string ans="";
        for(const auto &i:s)
        {
            if(st.size())
            {
                if(i=='B' && st.top()=='A')
                {
                    st.pop();
                }
                else if(i=='D' && st.top()=='C')
                {
                    st.pop();
                }
                else st.push(i);
            }
            else st.push(i);
        }
        return st.size();
        // while(st.size())
        // {
        //     ans+=st.top();
        //     st.pop();
        // }
        // reverse(ans.begin(),ans.end());
        // return ans;
        
    }
};