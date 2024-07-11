class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        stack<char> st;
        queue<char> qu;
        for(const auto &i:s)
        {
            if(i==')')
            {
                while(st.top()!='(')
                {
                    qu.push(st.top());
                    st.pop();
                }
                st.pop();
                while(qu.size())
                {
                    st.push(qu.front());
                    qu.pop();
                }

            }
            else 
            {
                st.push(i);
            }

        }
        while(st.size())
        {
            ans=st.top()+ans;
            st.pop();
        
        }
        return ans;
        
    }
};