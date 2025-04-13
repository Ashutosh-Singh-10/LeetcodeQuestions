#define ll long long
ll mod=1e9+7;
ll pow(ll n,ll x,ll mod)
{
    if(x==0) return 1;
    if(x==1) return n%mod;
    ll tmp=pow(n,x/2ll,mod);
    ll ret=(tmp*tmp)%mod;
    if(x%2) 
    {
        return (ret*n)%mod;
    }
    return ret;

}
class Solution {
public:
    int countGoodNumbers(long long n) {
        ll ev=(n+1)/2ll,od=n/2ll;
        
        
        return (pow(5,ev,mod)*pow(4,od,mod))%mod;
        
        
        
        
    }
};