class Solution {
public:
    int fun(int d,vector<int> &vec,int k)
    {
        int cnt=0;
        int n=vec.size();
        for(int i=0;i<n/2;i++)
        {
            int x=vec[i],y=vec[n-i-1];
            if(x>y) swap(x,y);
            if(abs(y-x)==d) continue;
            else if(y-d>=0 && y-d<=k) cnt++;
            else if(x+d>=0 && x+d<=k) cnt++;
            else cnt+=2;
            
        }
        

        return cnt;
    }
    int minChanges(vector<int>& nums, int k) {
        map<int,int> mp,tp;
        int ans=INT_MAX;
        int n=nums.size();
        for(int i=0;i<n/2;i++)
        {
            mp[abs(nums[i]-nums[n-1-i])]++;
        }
        for(auto &[a,b]:mp)
        {
            if(tp.count(b)==0)
            {
                tp[b]=a;
            }
           
        }
        for(auto &[a,b]:tp)
        {
            ans=min(ans,fun(b,nums,k));
        }
        return ans;
    }
};