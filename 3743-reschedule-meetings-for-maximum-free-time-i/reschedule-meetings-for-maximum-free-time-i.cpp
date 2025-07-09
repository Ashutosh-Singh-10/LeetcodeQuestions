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
	class Solution {
public:

    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        
	
		int n=startTime.size();
	
		vector<ll> vec={startTime[0]};
		ll ans=0;
		for(int i=1;i<startTime.size();i++)
		{
			vec.push_back(startTime[i]-endTime[i-1]);
			
		}
		vec.push_back(eventTime-endTime[n-1]);
		ll cur=0;
		for(int i=0;i<min(n,k);i++)
		{
			cur+=vec[i];
			ans=max(ans,cur);
		}
		for(int i=k;i<n+1;i++)
		{
			cur+=vec[i];
			ans=max(ans,cur);
			cur-=vec[i-k];
		}
        
		
		
		return ans;

        
    }
};
