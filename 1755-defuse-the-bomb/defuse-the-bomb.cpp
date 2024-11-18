class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        vector<int> ans;
        for(int j=0;j<n;j++)
        {

            int sum=0;
            for(int i=min(k,0);i<=max(k,0);i++)
            {
                if(i==0) continue;
                sum+=code[(j+i+n)%n];

            }
            ans.push_back(sum);
        }
        return ans;
        
    }
};