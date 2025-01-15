	#include <bits/stdc++.h>
	using namespace std;
	using std::cout;
	using std::cin;
	 
	#define ll long long
	#define loop(i,a,b) for(long long i=a;i<b;i++)
	#define roop(i,a,b) for(long long i=a-1;i>=b;i--)
	#define all(p) p.begin(),p.end()
	#define pb(p) push_back(p);
	long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
	template<class T> using _pq = priority_queue<T>;
	template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
	template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
	template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
	#include <ext/pb_ds/assoc_container.hpp>
	#include <ext/pb_ds/tree_policy.hpp>
	using namespace __gnu_pbds;
	#include<iostream>
	template <class T> using OrderSet = tree<T, null_type, 
	less<T>, rb_tree_tag,tree_order_statistics_node_update>;
	ll lcm(ll a, ll b){return (a/__gcd(a,b)*b);}
	const ll INF= LONG_LONG_MAX;
	int mod=1e9+7;

ll gcd(ll x,ll y) 
{
	if(x==0 || y==0) return max(x,y);
	return __gcd(x,y);
}
ll ans=0;
ll dp[201][201][201];
ll fun(ll g1,ll g2,ll idx,vector<int> &nums)
{
	if(idx==nums.size())
	{
        if(g1==0 || g2==0) return 0;
		if(g1==g2) 
        {
            ans=(ans+1)%mod;
            return 1;
        }
		return 0;
		
	}
	if(dp[idx][g1][g2]!=-1)
	{
		ans=(ans+dp[idx][g1][g2])%mod;
		return dp[idx][g1][g2];
	}
	ll n1=gcd(g1,nums[idx]);
	ll n2=gcd(g2,nums[idx]);
	ll x,y,z;

	x=fun(n1,g2,idx+1,nums);
	y=fun(g1,n2,idx+1,nums);
	z=fun(g1,g2,idx+1,nums);

	dp[idx][g1][g2]=(x+y+z)%mod;
	return dp[idx][g1][g2];


}

class Solution {
public:
    int subsequencePairCount(vector<int>& nums) {
        ans=0;
		memset(dp,-1,sizeof(dp));
		fun(0,0,0,nums);
		return ans;

		
        
    }
};