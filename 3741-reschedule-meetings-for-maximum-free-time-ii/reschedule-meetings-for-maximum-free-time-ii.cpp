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
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
		multiset<ll> st;
		int n=startTime.size();
		st.insert(startTime[0]);
		ll ans=0;
		for(int i=1;i<startTime.size();i++)
		{
			st.insert(startTime[i]-endTime[i-1]);
			ans=max((ll)startTime[i]-endTime[i-1],ans);
		}
        st.insert(eventTime-endTime[n-1]);
		for(int i=0;i<n;i++)
		{
			ll l=0,r=0;
			if(i>0)
			{
				l=startTime[i]-endTime[i-1];

			}
			else 
			{
				l=startTime[i];
			}
			
			if(i<n-1)
			{
				r=startTime[i+1]-endTime[i];

			}
			else 
			{
				r=eventTime-endTime[i];
			}
			ans=max(r+l,ans);
			st.erase(st.find(l));
			st.erase(st.find(r));
			auto it=st.lower_bound(endTime[i]-startTime[i]);
			if(it!=st.end())
			{
				ans=max((ll)l+r+endTime[i]-startTime[i],ans);
			}
			st.insert(r);
			st.insert(l);
			

		}
		return ans;

        
    }
};
