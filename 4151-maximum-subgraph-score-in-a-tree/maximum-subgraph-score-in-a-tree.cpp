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

ll dfs(int par,int cur,vector<vector<ll>> &vec,vector<vector<ll>> &gr,vector<int> &good)
{
    for(auto &i:gr[cur]){
        if(i!=par){
            vec[cur].push_back(dfs(cur,i,vec,gr,good));
        }
        else vec[cur].push_back(-1);
    }
    int sum=0;
    for(auto &i:vec[cur]) if(i>0) sum+=i;;
    if(good[cur]==0) sum--;
    else sum++;
    return sum;    
}
void dfs2(int par,int cur,vector<vector<ll>> &vec,vector<vector<ll>> &gr,vector<int> &good,ll val)
{
    val=max(val,0ll);
    int sum=0;
    vec[cur].push_back(val);
    for(auto &i:vec[cur]) if(i>0) sum+=i;
    if(good[cur]==0) sum--;
    else sum++;
    if(good[cur]==0) val--;
    else val++;
    
    for(int i=0;i<gr[cur].size();i++){
        if(gr[cur][i]==par) continue;
        int x=vec[cur][i];
        ll tmp=sum;
        if(x>0) tmp-=x;
        tmp=max(tmp,val);
        dfs2(cur,gr[cur][i],vec,gr,good,tmp);
    }
    
}

class Solution {
public:
    vector<int> maxSubgraphScore(int n, vector<vector<int>>& edges, vector<int>& good) {
        vector<vector<ll>> vec(n);
        vector<vector<ll>> gr(n);
        for(auto &i:edges){
            gr[i[0]].push_back(i[1]);
            gr[i[1]].push_back(i[0]);
        }
        dfs(-1,0,vec,gr,good);
        // loop(i,0,n){
        //     cout<<i<<" ---> ";
        //     for(auto &j:vec[i]) cout<<j<< " ";
        //     cout<<endl;
        // }
        dfs2(-1,0,vec,gr,good,0);
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int cnt=0;
            for(auto &j:vec[i]) if(j>0) cnt+=j;
            if(good[i]==0) cnt--;
            else cnt++;
            ans[i]=cnt;

        }
        // loop(i,0,n){
        //     cout<<i<<" ---> ";
        //     for(auto &j:vec[i]) cout<<j<< " ";
        //     cout<<endl;
        // }
        return ans;

        
    }
};