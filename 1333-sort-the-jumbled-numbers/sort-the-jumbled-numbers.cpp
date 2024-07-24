#define ll long long
ll val(ll n,vector<int> &mp)
{
    if(n==0) return mp[0];
    ll ans=0;
    int dig=0;
    int tmp=n;
    while(tmp) 
    {
        dig++;
        tmp/=10;
    }
    int mx=1;
    for(int i=1;i<dig;i++)mx*=10;
    for(ll i=1;i<=dig;i++)
    {
        ll el=n/mx;
        ans*=10;
        mx/=10;
        ans+=mp[el%10];
    }
    return ans;
    
    

}
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> vec(n);
        for(int i=0;i<n;i++)
        {
            vec[i]={val(nums[i],mapping),i};
        }
        sort(vec.begin(),vec.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){ ans[i]=nums[vec[i].second]; cout<<vec[i].first<<" ";}
        return ans;
        
    }
};