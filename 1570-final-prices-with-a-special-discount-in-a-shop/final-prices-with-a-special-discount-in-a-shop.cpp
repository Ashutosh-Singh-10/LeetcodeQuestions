class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && st.top()>prices[i])
            {
                st.pop();
            }
            if(st.size())
            {
                ans[i]=prices[i]-st.top();
            }
            else ans[i]=prices[i];
            st.push(prices[i]);
            
        }
        return ans;

        
        
        
    }
};