	#include <bits/stdc++.h>
	using namespace std;
	using std::cout;
	using std::cin;
	#define endl '\n'    
	#define Endl '\n'    
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
	ll lcm(ll a, ll b){return (a/__gcd(a,b)*b);}
	const ll INF= LONG_LONG_MAX;
    int mod=1e9+7;


long long pow(long long num,long long degree,long long mod=-1)
{
	if(degree==0) return 1;
	if(degree==1) return num;
	long long ans=pow(num,degree/2,mod);
	if(degree&1)
	{
	 return ((ans*ans)%mod*num)%mod;
	}
	return (ans*ans)%mod;
		
} 
long long Inv(long long num,long long mod=-1)
{
	return pow(num,mod-2,mod);
}
long double  powerInverse(long long num,long long degree,long long mod=-1)
{
	long double ans=1/(double long)pow(num,degree,mod);
	return ans;
}

	// if(INFINITY==powerInverse(2,10000))cout<<"HII";
	// cout<<powerInverse(2,10000);
class Solution {
	public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
		if(multiplier==1) return nums;
		set<pair<ll,ll>> mp;
		ll n=nums.size();
		loop(i,0,n)
		{
			mp.insert({nums[i],i});
		}
        // for(auto &[a,b]:mp) 
        // {
        //     cout<<a<<" "<<b<<endl;
        // }
        // cout<<endl;
		while(k>0 && mp.begin()->first<=mp.rbegin()->first/multiplier)
		{
			auto  it=mp.begin();
			auto a=it->first;
			auto b=it->second;
			mp.erase(it);
			mp.insert({(a*multiplier)%mod,b});
			k--;
		}
       
		ll p=k/n;
		ll rem=k%n;
		ll po=pow(multiplier,p,mod);
        cout<<po;
		vector<pair<ll,ll>> vec;
		for(auto &[a,b]:mp) vec.push_back({a,b});
		sort(vec.begin(),vec.end());
		for(int i=0;i<rem;i++)
		{
			vec[i].first=(vec[i].first*multiplier)%mod;
		}
		for(int i=0;i<n;i++)
		{
			vec[i].first=((ll)vec[i].first*(ll)po)%mod;
		}
		sort(all(vec),[](pair<ll,ll> a,pair<ll,ll> b){
			return a.second<b.second;

		});
		vector<int> ans;
		for(auto &i:vec) ans.push_back(i.first);
		return ans;
    }
};