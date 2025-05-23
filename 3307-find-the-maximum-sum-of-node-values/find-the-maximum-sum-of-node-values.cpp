#define ll long long
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        vector<int> vec,tec;
        ll sum=0;
        for(auto &i:nums)
        {
            if((i^k)>i)
            {
                vec.push_back(i^k);
                sum+=i^k;
            }
            else 
            {

            tec.push_back(i);
            sum+=i;
            }
        }
        
        ll ans=sum;
        if(vec.size()%2 ) 
        {
            ll x=vec.back()^k;
            ll y=vec.back();
            sum+=x-y;
            ans=sum;
            vec.pop_back();
            for(auto &i:vec)
            {
                ll temp=sum+(i^k)-i+y-x;
                ans=max(ans,temp);
            }
            for(auto &i:tec)
            {
                ll temp=sum+(i^k)-i+y-x;
                ans=max(ans,temp);
            }


        
        }
        return ans;
        
    }
};



