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

class Solution {
public:
    long long countOfSubstrings(string word, int k) {
		
		long long start=0;
		ll ans=0,n=word.size();
		ll con=0;
		map<char,ll>mp;
		mp['a']=0;
		mp['e']=0;
		mp['i']=0;
		mp['o']=0;
		mp['u']=0;
		ll vow=0;
		ll lst=0;

		for(ll i=0;i<n;i++)
		{
			if(mp.count(word[i]))
			{
				if(mp[word[i]]==0) vow++;
				mp[word[i]]++;
			}
			else con++;
			while(con>=k && start<i)
			{
				if(mp.count(word[start]))
				{
					if(mp[word[start]]==1) break;
					mp[word[start]]--;
					lst++;
				}
				else if(con==k) break;
				else 
				{
					lst=0;
					con--;
				}
                start++;
			}
			if(con==k && vow==5) ans+=lst+1;
            // cout<<con<<" "<<vow<<" "<<start<<endl;

		}
		return ans;
        
    }
};