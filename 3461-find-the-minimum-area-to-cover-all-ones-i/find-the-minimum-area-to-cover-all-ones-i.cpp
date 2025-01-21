	#include <bits/stdc++.h>
	using namespace std;
	using std::cout;
	using std::cin;
	#define endl '\n'    
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
	
	
class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
			ll xl=INT_MAX;
			ll xs=0;
			ll yl=INT_MAX;
			ll ys=0;
			int n=grid.size();
            int m=grid[0].size();
			loop(i,0,n)
			{
				loop(j,0,m)
				{
					if(grid[i][j]==1)
					{
						xl=min(i,xl);
						xs=max(i,xs);
                        
						yl=min(j,yl);
						ys=max(j,ys);
					}
				}
			}
        


			return (xs-xl+1)*(ys-yl+1);


        
    }
};