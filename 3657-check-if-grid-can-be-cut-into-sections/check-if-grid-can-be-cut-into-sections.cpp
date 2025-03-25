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
		#include <ext/pb_ds/assoc_container.hpp>
		#include <ext/pb_ds/tree_policy.hpp>
		using namespace __gnu_pbds;
		#include<iostream>
		template <class T> using OrderSet = tree<T, null_type, 
		less<T>, rb_tree_tag,tree_order_statistics_node_update>;
		ll lcm(ll a, ll b){return (a/__gcd(a,b)*b);}
		const ll INF= LONG_LONG_MAX;
		int mod=1e9+7;


int check(vector<pair<ll,ll>> vec,ll n)
{
	So(vec);
	ll cmx=vec[0].second;
	ll cnt=0;
	for(auto &i:vec)
	{
		if(cmx<=i.first) 
		{
			cnt++;
		}
		cmx=max(cmx,i.second);
	}
    cout<<cnt<<" ";
	if(cnt>=2) return 1;
	return 0;

}
class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& re) {
		vector<pair<ll,ll>> x(re.size());
		vector<pair<ll,ll>> y(re.size());
		loop(i,0,re.size()) 
		{
			x[i]={re[i][0],re[i][2]};
			y[i]={re[i][1],re[i][3]};
		}
		return check(x,n) || check(y,n);      
    }
};