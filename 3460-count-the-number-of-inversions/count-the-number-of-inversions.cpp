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
ll mod=1e9+7;
class Solution {
public:
    int numberOfPermutations(int n, vector<vector<int>>& req) {
        vector<vector<ll>> dp(n,vector<ll> (410,0));
        vector<pair<ll,ll> > vec;
        for(auto &i:req)
        {
            vec.push_back({i[0],i[1]});
        }
        So(vec);
        if(vec[0].first==0 && vec[0].second!=0) return 0;
        ll idx=0;
        dp[0][0]=1;
        if(vec[0].first==0) idx++;
        loop(i,1,n)
        {
            loop(j,0,402)
            {
                loop(k,0,i+1)
                {
                    if(k+j<=404)
                    {
                        dp[i][k+j]=(dp[i][k+j]+dp[i-1][j])%mod;
                    }
                }

            }
            if(idx<vec.size())
            {
                
                if(vec[idx].first==i)
                {
                    loop(j,0,402)
                    {
                        if(j!=vec[idx].second)
                        {
                            dp[i][j]=0;
                        }
                    }
                                    // cout<<idx<<" "<<i<<" "<<vec[idx].first<<"      ";
                idx++;
                }
                

            }
            

        }
//         cout<<endl;
//         loop(i,0,n)
//         {
//             loop(j,0,10)
//             {
//                 cout<<dp[i][j]<<" ";
                
//             }
//             cout<<endl;
//         }
//     cout<<endl;
        return dp[vec.back().first][vec.back().second];




        
    }
};