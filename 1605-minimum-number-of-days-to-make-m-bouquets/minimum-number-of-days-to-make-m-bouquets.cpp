int check(vector<int>&vec,int m,int k,int p)
{
    int cnt=0,ans=0;
    for(auto &i:vec)
    {
        if(i<=p)
        {
            cnt++;
        }
        else cnt=0;
        if(cnt==k)
        {
            ans++;
            cnt=0;
        }
    }
    if(ans>=m) return 1;
    return 0;

}
class Solution {
public:
    int minDays(vector<int>& vec, int m, int k) {
        int n=vec.size();
        int low=0;
        int high=1e9+1;
        int ans=high;
        while(low<=high)
        {
            int mid=low +(high-low)/2;
            if(check(vec,m,k,mid))
            {
                ans=min(ans,mid);
                high=mid-1;
            }
            else low=mid+1;

        }

        return ans==1e9+1?-1:ans;
        
        
    }
};