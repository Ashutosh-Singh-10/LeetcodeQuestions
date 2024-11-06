class Solution {
public:
    int bits(int n)
    {
        int ans=0;
        while(n)
        {
            if(n&1) ans++;
            n>>=1;
        }
        return ans;
    }
    bool canSortArray(vector<int>& nums) {
        vector<int> vec(20,0);
        for(auto &el:nums)
        {
            int b=bits(el);
            for(int i=0;i<10;i++)
            {
                if(i!=b) if(el<vec[i]) return 0;
                

            }
            vec[b]=max(vec[b],el);
         

        }
        return 1;
        
    }
};