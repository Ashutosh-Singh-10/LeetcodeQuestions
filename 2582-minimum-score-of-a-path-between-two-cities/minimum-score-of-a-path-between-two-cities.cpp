


     #include <bits/stdc++.h>
     using namespace std;
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
 
 void dfs(vector<vector<pair<int,int>>> & gr,int &ans,int cur,vector<int> &vis)
 {
    if(vis[cur]==1) return ;
    vis[cur]=1;
    for(auto &i:gr[cur])
    {
        ans=min(i.second,ans);
        dfs(gr,ans,i.first,vis);
    }
 }
 class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        
        vector<vector<pair<int,int>>> gr(n);
        for(auto &i:roads)
        {
            gr[i[0]-1].push_back({i[1]-1,i[2]});
            gr[i[1]-1].push_back({i[0]-1,i[2]});
        }
        vector<int> vis(n,0);
        int ans=INT_MAX;
        dfs(gr,ans,0,vis);
        return ans;
      

        
    }
};
 

  