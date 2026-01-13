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
			double separateSquares(vector<vector<int>>& squares) {
				double l=0,h=1e13,ans=1e13,mid;
				while(h-l>1e-6)
				{
					mid=(h+l)/(double)2;
					double a=0,b=0;
					for(auto &i:squares)
					{
						double y=i[1],len=i[2];
						if(y<mid)
						{
							b+=len*(min(mid-y,len));
						}
						if(y+len>mid)
						{
							a+=len*(min(len+y-mid,len));
						}

					}
					if(a>b)
					{
						l=mid;
						

					}
					else 
					{
						h=mid;
						ans=min(ans,mid);

					}

				}
				return ans;

				
			}
		};