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

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        int m=grid.size(),n=grid[0].size();
        _pqr<pair<int,pair<int,int>>> pq;
        pq.push({0,{0,0}});
        vector<vector<int>> vis(m,vector<int>(n,0));
        vis[0][0]=1;
        vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
        while(pq.size())
        {
            auto [a,d]=pq.top();
            auto [b,c]=d;
            pq.pop();
            if(b==m-1 && c==n-1) return a;
            vis[b][c]=1;
            for(auto &[e,f]:dir)
            {
                auto g=e+b;
                auto h=f+c;
                if(g<0 || g>=m || h<0 || h>=n || vis[g][h]==1) continue;
                vis[g][h]=1;
                pq.push({a+grid[g][h],{g,h}});
            }

        }
        return 0;

        
     
        
    }
};