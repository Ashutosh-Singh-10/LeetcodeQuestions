
int check(vector<int> &vec,int k,int m)
{
    int x=vec[0];
    for(auto &i:vec)
    {
        if(i-x>=k)
        {
            m--;
            x=i;
        }
    }
    return m<=1?1:0;

}
class Solution {
public:
    int maxDistance(vector<int>& vec, int m) {
        sort(vec.begin(),vec.end());
        int high=vec.back();
        int low=0;
        int mid;
        int ans=0;
        while(low<=high)
        {
            mid=low+(high-low)/2;
            if(check(vec,mid,m))
            {
                low=mid+1;
                ans=mid;

            }
            else high=mid-1;

        }
        return ans;
        
        
    }
};