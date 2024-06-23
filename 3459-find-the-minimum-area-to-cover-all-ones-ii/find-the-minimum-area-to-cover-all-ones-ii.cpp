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
ll calc(vector<ll> x)
{
	if(x[1]==INT_MAX || x[0]==INT_MAX || x[2]==INT_MAX || x[3]==INT_MAX) return 0;
    return (x[1]-x[0]+1) * (x[3]-x[2]+1);

}

    void minimumArea(vector<vector<int>>& grid,vector<vector<ll>> &pre) {
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
				pre.push_back({xl,xs,yl,ys});
			}
    }

	  ll nope(vector<vector<int>>& grid) {
          if(grid.size()==0) return 0;
          ll cnt=0;
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
                        cnt++;
						xl=min(i,xl);
						xs=max(i,xs);
                        
						yl=min(j,yl);
						ys=max(j,ys);
					}
				}
			}
          if(cnt==0)return 0;
			return calc({xl,xs,yl,ys});
    }

    ll fun(vector<vector<int>>& grid) 
	{
		ll ans=INT_MAX;
		vector<vector<ll>> pre;
		minimumArea(grid,pre);
		int n=grid.size();
		int m=grid[0].size();
		for(int i=n-1;i>=0;i--)
		{
			vector<vector<ll>> fix;
			ll xl=INT_MAX;
			ll xs=0;
			ll yl=INT_MAX;
			ll ys=0;
			for(ll j=0;j<m;j++)
			{
				for(ll k=n-1;k>=i;k--)
				{
					if(grid[k][j]==1)
					{
						xl=min(k,xl);
						xs=max(k,xs);
                        
						yl=min(j,yl);
						ys=max(j,ys);
					}
					
				}
                fix.push_back({xl,xs,yl,ys});
			}
			xl=INT_MAX;
			xs=0;
			yl=INT_MAX;
			ys=0;

			for(ll j=m-1;j>=0;j--)
			{
				for(ll k=n-1;k>=i;k--)
				{
					if(grid[k][j]==1)
					{
						xl=min(k,xl);
						xs=max(k,xs);
                        
						yl=min(j,yl);
						ys=max(j,ys);
					}
					
				}
                
                ll a=0;
                if(j) a=calc(fix[j-1]);
                ll b=0;
                if(i) b=calc(pre[i-1]);
				ans=min(ans,a+b+calc({xl,xs,yl,ys})
				);
                // cout<<ans<<"->";
                
			}
            
        // cout<<endl;


		}
        cout<<ans<<endl;
    if(ans==INT_MAX) return 0;
		return ans;
	}

	ll extra(vector<vector<int>>  grid)
	{
		int n=grid.size();
		ll ans=INT_MAX;
		loop(i,0,n)
		{
			loop(j,i,n)
			{
				vector<vector<int>> x,y,z;
				for(int k=0;k<i;k++)
				{
					x.push_back(grid[k]);
				}
				for(int k=i;k<j;k++)
				{
					y.push_back(grid[k]);
				}
				for(int k=j;k<n;k++)
				{
					z.push_back(grid[k]);
				}

				ans=min(ans,nope(x)+nope(y)+nope(z));


			}
				
		}
		

return ans;
	}
class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {

		ll ans=fun(grid);
		ans=min(ans,extra(grid));
		reverse(all(grid));
        
		ans=min(ans,fun(grid));
		int n=grid.size();
		int m=grid[0].size();
		vector<vector<int>> vec(m,vector<int>(n,0));
		loop(i,0,m)
		{
			loop(j,0,n)
			{
				vec[i][j]=grid[j][i];
			}
		}
		ans=min(ans,fun(vec));
		reverse(all(vec));
		ans=min(ans,fun(vec));
		ans=min(ans,extra(vec));

        
		return ans;
		
        
    }
};