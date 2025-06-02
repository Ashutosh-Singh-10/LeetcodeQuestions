class Solution {
public:
    int candy(vector<int>& rat) {
        int n=rat.size();
        vector<int> vec(n,0);
        for(int i=1;i<n;i++)
        {
            if(rat[i]>rat[i-1])
            vec[i]=max(vec[i-1]+1,vec[i]);

        }
        for(int i=n-2;i>=0;i--)
        {
            if(rat[i]>rat[i+1])
            {
                vec[i]=max(vec[i+1]+1,vec[i]);
            }
        }
        // for(auto &i:vec) cout<<i<<" ";
        return accumulate(vec.begin(),vec.end(),0)+n;
        
    }
};