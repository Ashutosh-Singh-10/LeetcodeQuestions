class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char a='a',b='b';
        if(y>x)
        {
            swap(a,b);
            swap(x,y);
        }
        stack<int> st,tt;
        int ans=0;
        for(auto &i:s)
        {
            if(i==b)
            {
                if(st.size() && st.top()==a)
                {
                    st.pop();
                    ans+=x;
                }
                else st.push(i);
            }
            else st.push(i);
        }
        while(st.size())
        {
            auto i=st.top();
            st.pop();
            if(i==b)
            {
                if(tt.size() && tt.top()==a)
                {
                    tt.pop();
                    ans+=y;
                }
                else tt.push(i);
            }
            else tt.push(i);

        }
        return ans;


        
    }
};