class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        multiset<string> st;
        int ans=0;
        for(auto &i:words)
        {
            auto tmp=i;
            reverse(i.begin(),i.end());
            if(st.count(i))
            {
                ans+=2*i.length();
                st.erase(st.find(i));
            }
            else 
            {
                st.insert(tmp);
            }
        }
        int mx=0;
        cout<<ans<<endl;
        for(auto &i:st)
        {
            int flag=1;
            for(int j=0;j<i.length();j++)
            {
                if(i[j]!=i[i.length()-1-j])
                {
                    flag=0;
                }
            }
            if(flag==1) 
            {
                mx=max(mx,(int)i.length());
            }
        }
        return ans+mx;
        
    }
};