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
		ll mx=50009;
    	vector<vector<int>> fact(mx+1);
class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        ll p=5;
		if(fact[1].size()==0)
        {
            for(ll i=1;i<mx;i++)
            {
                int cur=0;
                while(cur+i<=mx)
                {
                    cur+=i;
                    fact[cur].push_back(i);
                }
            }
        }
	
		unordered_map<ll,ll>mp;
		for(auto &i:nums) mp[i]++;
		vector<ll> freq(mx+1,0);
		
		
		for(auto &[a,b]:mp) for(auto &i:fact[a]) freq[i]+=b;
        vector<ll> ans(mx+1,0);
      	for(ll i=mx;i>=1;i--)
		{
			    ans[i]=ans[i]+max(0ll,(freq[i]*(freq[i]-1))/2ll);
           
			for(ll j=0;j+1<fact[i].size();j++)
			{
            	ans[fact[i][j]]-=ans[i];    
			}
            
		}
        map<ll,ll> tp;
        ll cnt=0;
        for(int i=1;i<=mx;i++)
        {
            if(ans[i]>0)
            {
                cnt+=ans[i];
                tp[cnt]=i;
            }
        }
        
        vector<int> fi;
        
        for(auto &i:queries)
        {
            fi.push_back(tp.lower_bound(i+1)->second);
        }
        return fi;
		// for(int i=0;i<p;i++) cout<<freq[i]<<" ";cout<<endl;

		return {};
		
        
    }
};