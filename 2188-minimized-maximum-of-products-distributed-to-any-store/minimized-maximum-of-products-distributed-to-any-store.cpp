class Solution {
public:
    int minimizedMaximum(int n, vector<int>& vec) {
        sort(vec.begin(),vec.end());
        int h=2e5,l=1,mid;
        int ans=2e5;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            int bit=1;
            auto fn=[&]()
            {
                int cnt=0;
                for(int i=vec.size()-1;i>=0;i--)
                {
                    cnt+=vec[i]/mid;
                    if(vec[i]%mid)cnt++;
                    if(cnt>n) 
                    {
                        bit=0;
                        break;
                    }
                    
                }
                
            };
            fn();
            if(bit)
            {
                ans=min(ans,mid);
                h=mid-1;
            }
            else 
            {
                l=mid+1;
            }
            

        }
        return ans;
        
    }
};