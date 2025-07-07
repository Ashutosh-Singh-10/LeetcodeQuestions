class Solution {
public:
    int check (vector<int> &vec,int mx,int mid)
    {
        if(mid==1)
        {
            int cnt=0;
            for(auto &i:vec) if(i>1) cnt++;
            if(cnt<=mx) return 1;
            return 0;
        }
        int n=vec.size();
        vec.push_back(1);
        int gc=vec[0];
        int prev=0;
        for(int i=0;i<n;i++)
        {
            gc=__gcd(vec[i],gc);
            if(gc==1)
            {

                int t=i;
                prev=t;
                gc=vec[t];
                t--;
                while(t>=0) 
                {
                    int ngc=__gcd(gc,vec[t]);
                    if(ngc==1) break;
                    gc=ngc;
                    prev=t;
                    t--;
                    
                    

                }
                
            }
            else if(i-prev+1>=mid) 
            {
                mx--;
                gc=vec[i+1];
                prev=i+1;
            }
        }
        return mx>=0;
        
        
    }
    int minStable(vector<int>& nums, int maxC) {
        int n=nums.size();
        int l=1,h=n,ans=n,mid;
        while(l<=h)
        {
            mid=l+(h-l)/2;
            if(check(nums,maxC,mid))
            {
                ans=min(ans,mid-1);
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
        
    }
};