class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        sort(digits.begin(),digits.end());
        vector<int> ans;
        set<int> st;
        int n=digits.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {
                    if(digits[i]==0 || i==j || j==k || i==k || digits[k]%2==1)
                    {
                        continue;
                    }
                    st.insert(digits[i]*100+digits[j]*10+digits[k]);
                }
            }
        }
        for(auto &i:st) 
        {
            ans.push_back(i);
        }
        return ans;
        
    }
};