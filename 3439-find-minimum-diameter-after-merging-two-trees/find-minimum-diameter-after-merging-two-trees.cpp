//     #include <bits/stdc++.h>
//     using namespace std;
//     #ifndef ONLINE_JUDGE
//     #include "debug1.cpp"
//     #define debug(...) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printer(#__VA_ARGS__, __VA_ARGS__)
//     #define debugArr(arr, size) std::cerr << __LINE__ << ": [", __DEBUG_UTIL__::printerArr(#arr, arr,size)
//     #endif
//     #ifndef ONLINE_JUDGE
//     #include "debug.h"
//     #else
//     #define dbg(x...)
//     #endif
//     using std::cout;
//     using std::cin;
//     #define endl '\n'    
//     #define Endl '\n'    
//     #define ll long long
//     #define loop(i,a,b) for(long long i=a;i<b;i++)
//     #define roop(i,a,b) for(long long i=a-1;i>=b;i--)
//     #define all(p) p.begin(),p.end()
//     #define pb(p) push_back(p);
//     long long pop_count(long long a){int res=0;while(a){res+=(a&1),a>>=1;}return res;}
//     template<class T> using _pq = priority_queue<T>;
//     template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
//     template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
//     template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
//     #include <ext/pb_ds/assoc_container.hpp>
//     #include <ext/pb_ds/tree_policy.hpp>
//     using namespace __gnu_pbds;
//     #include<iostream>
//     template <class T> using OrderSet = tree<T, null_type, 
//     less<T>, rb_tree_tag,tree_order_statistics_node_update>;
//     ll lcm(ll a, ll b){return (a/__gcd(a,b)*b);}
//     const ll INF= LONG_LONG_MAX;


// void solve(ll tc);
// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0); cout.tie(0);
//     ll t;
//     cin>>t;
//     loop(i,1,t+1)
//     {

//         solve(i);
//     }
    
//     return 0;
// }

// void solve(ll tc)
// {   
//     ll n;
//     cin>>n;
//     vector<ll> a(n),b(n);
//     loop(i,0,n)cin>>a[i];
//     loop(i,0,n)cin>>b[i];
//     int x=0,y=0,z=0,am=0;
//     loop(i,0,n)
//     {
//         if(a[i]==1 && b[i]<a[i])
//         {
//             x++;
//         }
//         else if(b[i]==1 && b[i]>a[i])
//         {
//             y++;
//         }
//     }
//     loop(i,0,n)
//     {
//         if(a[i]==1 && b[i]==1) 
//         {
//             if(x>y) 
//             {
//                 y++;
//             }
//             else x++;
            
//         }
//         if(a[i]==-1 && b[i]==-1)
//         {
//             if(x>y)
//             {
//                 x--;
//             }
//             else y--;
//         }
//     }
//     cout<<min(x,y)<<endl;   
// }














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

 
int fun(vector<vector<int>> & gr,int n)
{
    if(n==2) return 2;
    vector<int> deg(n,0),vis(n,0);
    loop(i,0,n)
    {
        for(auto &j:gr[i])
        {
            if(i<j)
            {
                deg[i]++;
                deg[j]++;
            }
        }
    }
    queue<int> qu;
    loop(i,0,n) 
    {
        if(deg[i]==1)
        qu.push(i);
    }
    qu.push(-1);
    int ans=0;
    while(qu.size()>1)
    {
        auto x=qu.front();
        qu.pop();
        if(x==-1)
        {
            qu.push(-1);
            ans++;
            continue;
        }
        vis[x]=1;
        for(auto &i:gr[x])
        {
            deg[i]--;
            if(vis[i]==0 && deg[i]<=1)
            {
                qu.push(i);
            }
        }

    }
    return ans+1;
    

}
void dfs(vector<vector<int>> &gr,int u,int v,int &cnt,int &ans,int d)
{
    if(d>cnt) 
    {
        cnt=d;ans=u;
    }
    for(auto &i:gr[u])
    {
        if(i!=v)
        {
            dfs(gr,i,u,cnt,ans,d+1);
        }
    }

}
int dfs2(vector<vector<int>> &gr,int u,int v)
{
    int x=0;
       for(auto &i:gr[u])
    {
        if(i!=v)
        {
            x=max(x,dfs2(gr,i,u));
        }
    }
    return x+1;
}
int dia(vector<vector<int>> &gr,int n)
{
    int ans=0,cnt=0;
    dfs(gr,0,-1,cnt,ans,0);
    return dfs2(gr,ans,-1)-1;

}
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        vector<vector<int>> a(n),b(m);
        for(auto &i:edges1)
        {
            a[i[0]].push_back(i[1]);
            a[i[1]].push_back(i[0]);
        }
        for(auto &i:edges2)
        {
            b[i[0]].push_back(i[1]);
            b[i[1]].push_back(i[0]);
        }
        auto x=fun(a,n);
        auto y=fun(b,m);
        cout<<x<<" "<<y<<endl;
        auto o=dia(a,n);
        auto p=dia(b,m);
        return max(max(o,p),x+y-1);
        return 0;
        
    }
};