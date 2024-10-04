#define ll long long
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        ll sum=accumulate(skill.begin(),skill.end(),0ll);
        ll n=skill.size();
        ll avg=(sum*2ll)/n;
        sort(skill.begin(),skill.end());
        ll ans=0;
        for(int i=0;i<n/2;i++)
        {
            if(skill[i]+skill[n-1-i]!=avg) return -1;
            ans+=skill[i]*skill[n-1-i];
        }
        return ans;

        
    }
};