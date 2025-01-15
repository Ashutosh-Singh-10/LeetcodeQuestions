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
    vector<vector<int>> constructGridLayout(int n, vector<vector<int>>& edges) {
		vector<vector<int>> grid(2,{-1,-1});
		vector<set<int>> gr(n);
		vector<int> cnt(n,0);
		for(auto &i:edges)
		{
			gr[i[0]].insert(i[1]);
			gr[i[1]].insert(i[0]);
			cnt[i[0]]++;
			cnt[i[1]]++;
		}
		int corner=1;
		for(int i=0;i<n;i++) 
		{
			if(cnt[i]==1)
			{
				vector<int> ans; 
				int p=-1,cur=i;
				while(1)
				{
					ans.push_back(cur);
					for(auto &x:gr[cur])
					{
						if(x==p) continue;
					    p=cur;
						cur=x;
						break;
					}
                    if(cur==ans.back()) break;
				}
				return {ans};
			}
			if(cnt[i]==2) corner=i;

		}
		grid[0][0]=corner;
		grid[0][1]=*gr[corner].begin();
		grid[1][0]=*gr[corner].rbegin();
		gr[*gr[corner].begin()].erase(corner);
		gr[*gr[corner].rbegin()].erase(corner);
		int node=n;
		n=2;
		int m=2;
			int idx=1;
		while(1)
		{
			int x=idx-m+1;
            if(x>=n) break;
			int y=min(idx,m-1);
			int xc=x,yc=y;
            // cout<<"BBBBBB"<<endl;
			if(y>0 && x<n-1)
			{
                // cout<<"CCCC";
                // cout<<x<<" "<<y<<endl;
                //    for(auto &i:grid)
                //         {
                //             for(auto &j:i) 
                //             {
                //                 cout<<j<<" ";
                //             }
                //             cout<<endl;
                //         }
				for(auto &i:gr[grid[x][y]])
				{
					int bit=1;
					for(auto &j:gr[i])
					{
                        // cout<<"DDDDD";
						if(j==grid[x+1][y-1])
						{
							bit=0;
							break;
						}
					}
					if(bit)
					{
                        // cout<<endl<<"EEEEE  -> "<<i<<" "<<grid[x][y]<<endl;
                        // for(auto &i:grid)
                        // {
                        //     for(auto &j:i) 
                        //     {
                        //         cout<<j<<" ";
                        //     }
                        //     cout<<endl;
                        // }
                        // cout<<x+1<<" "<<m<<" "<<n<<endl;
                        // cout<<endl;
						grid[0].push_back(i);
						m++;
						gr[i].erase(gr[i].find(grid[x][y]));
						gr[grid[x][y]].erase(i);
                   
                        
                        
						break;
					}

				}
			}
            // cout<<endl<<"QQQQQQ"<<endl;;
			while(1)
			{
				if(gr[grid[x][y]].size()==0) 
                {
                    // cout<<"done here "<<x<<" "<<y<<endl;
                    break;
                }

				if(x+1==n)
				{
					grid.push_back(vector<int>(m,-1));
                    n++;
				}
                // for(auto &i:grid)
                // {
                //     for(auto &j:i) 
                //     {
                //         cout<<j<<" ";
                //     }
                //     cout<<endl;
                // }
                // // cout<<x+1<<" "<<m<<" "<<n<<endl;
                // cout<<endl;
				grid[x+1].resize(m,-1);
				grid[x].resize(m,-1);
                // cout<<y<<" "<<x<<"  "<<grid[x].size()<<" "<<x+1<<"  "<<grid[x+1].size()<<" "<<n<<" "<<m<<endl;
                
				assert(n>x+1 && m>y);
                assert(gr[grid[x][y]].size()>0);
				grid[x+1][y]=*gr[grid[x][y]].begin();
				
				// gr[grid[x][y]].erase(gr[grid[x][y]].begin());
                assert(gr[grid[x+1][y]].count(grid[x][y])>0);
				gr[grid[x+1][y]].erase(grid[x][y]);
                gr[grid[x][y]].erase(grid[x+1][y]);
                int tmp=0;
                // for(auto &i:grid)
                // {
                //     for(auto &j:i) 
                //     {
                //         cout<<j<<" ";
                //     }
                //     cout<<endl;
                // }
                // // cout<<x+1<<" "<<m<<" "<<n<<endl;
                // cout<<endl;
                // for(auto &i:gr) 
                // {
                //     cout<<tmp<<"->";
                //     for(auto &j:i) cout<<j<<" ";
                //     cout<<endl;
                //     tmp++;
                // }
                // cout<<x<<" "<<y<<endl;
				if(y!=0)
				{

					gr[grid[x+1][y]].erase(grid[x+1][y-1]);
					gr[grid[x+1][y-1]].erase(grid[x+1][y]);

				}
				
				x++; 
				y--;
                if(y==-1 || x==n) break;
				// if(y==0 || x==n) break;
				
				

			}
            // cout<<endl<<"ZZZZZZ"<<endl;;
			idx++;
			// if(n*m>=node) break;


			

		}





	return grid;

        
    }
};