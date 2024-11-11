class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        set<int> prime ;
        vector<int> vec(2000,0);
        for(int i=2;i<2000;i++)
        {
            if(vec[i]==0)
            {
                prime.insert(i);
                int diff=i,x=i;
                while(x<2000)
                {
                    vec[x]=1;
                    x+=diff;
                }
            }
        }
        int last=0;
        for(auto &i:nums)
        {
            if(i<=last) return 0 ;
            auto it=prime.lower_bound(i-last);
            int nxt;
            if(it==prime.begin())
            {
                nxt=i;
            }
            else 
            {
                it--;
                nxt=i-*it;
            }
            if(nxt<=last) return 0;
            last=nxt;

        }
        return 1;


        
    }
};