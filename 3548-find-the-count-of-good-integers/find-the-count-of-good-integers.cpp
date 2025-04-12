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
		vector<ll> fact(15,1);

ll ncr(ll n,ll r )
{
	ll ans=fact[n]/(fact[r]*fact[n-r]);
    return ans;
}
ll conv(string &s)
{
    ll ans=0;
    for(auto &i:s)
    {
        ans*=10;
        ans+=i-'0';

    }
    return ans;

}
class Solution {
public:
    long long countGoodIntegers(int n, int k) {
		ll low=1,high;
		for(int i=1;i<(n+1)/2;i++)
		{
			low*=10;
		}
		high=low*10-1;
        unordered_set<string> tp;
		for(ll i=1;i<15;i++)
		{
			fact[i]=fact[i-1]*i;
		}
        ll ans=0;
        ll mx=0;
        cout<<"low->"<<low<<"  high->"<<high<<endl;
		for(ll i=low;i<=high;i++)
		{
			string s=to_string(i);
			string t=s;
			if(n%2)
			{
				s.pop_back();
			}
			reverse(s.begin(),s.end());
			t+=s;

			ll num=conv(t);
            
			if(num%k==0)
			{
                sort(t.begin(),t.end());
                tp.insert(t);
		
			
			}
		
			

		}
        // cout<<endl<<"tp size->"<<tp.size()<<endl;
        for(auto &t:tp)
        {
            		map<ll,ll> mp;
				for(auto &i:t)
				{
					mp[i]++;
				}
				ll pos=n;
				ll tmp=1;
				if(mp.count('0'))
				{
                    mx=max(mx,mp['0']);
                    // cout<<pos<<" "<<mp['0']<<"    ";
					tmp*=ncr(pos-1,mp['0']);
					pos-=mp['0'];
					mp.erase('0');
				}
				for(auto  &[a,b]:mp)
				{
					tmp*=ncr(pos,b);
					pos-=b;

				}
				ans+=tmp;

        }
            // cout<<mx<<endl;

        
		return ans;
    }

};