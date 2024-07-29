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
ll dist(ll x,ll y,ll a,ll b)
{
    return (x-a)*(x-a)+(y-b)*(y-b);
}


class DSU{public:
    long long size=0;  vector<long long> vec;
    DSU(long long n)
    {
        size=n;   
        for(long long i=0;i<n;i++)        vec.push_back(i);
        
    }
    void join(long long x,long long y,vector<pair<ll,ll>> &area){
        vector<long long> a,b;
        ll e=max(area[x].first,area[y].first),f=max(area[x].second,area[y].second);

        while(vec[x]!=x)
        {
            a.push_back(x);
            x=vec[x];
        e=max(area[x].first,e);
        f=max(area[x].second,f);
            
        }
        while(vec[y]!=y)
        {
            b.push_back(y);
            y=vec[y];
        e=max(e,area[y].first);
        f=max(f,area[y].second);
        }
        for(auto &i:a)    vec[i]=y;
        for(auto &i:b)    vec[i]=y;
        vec[x]=y;
        area[x]={e,f};
        
    }
    long long parent(long long a)
    {
        vector<long long> arr;
        while(vec[a]!=a)
        {

         a=vec[a];
         arr.push_back(a);
        }
        for(auto &i:arr)
        {
            vec[i]=a;

        }
        return a;
    }
    void print()
    {
        for(auto & i:vec)cout<<i<<" ";cout<<endl;
    }
    long long clusters()
    {
        set<long long> st;
        for(long long i=0;i<size;i++)    st.insert(parent(i));
        return st.size();
    }
    void printClusters()
    {
        map<long long,vector<long long>> mp;
        for(int i=0;i<size;i++)
        {
            mp[parent(i)].push_back(i);
        }
        for(auto &[a,b]:mp)
        {
            cout<<a<<"    ->    ";
            for(auto  &j:b)
            {
                cout<<j<<" ";
            }
            cout<<"\n";

        }
    }

};

class Solution {
public:

    bool canReachCorner(int X, int Y, vector<vector<int>>& circles) {
        vector<pair<ll,ll>> vec;
        ll n=circles.size();
        for(auto &i:circles)
        {
            ll a=i[0],b=i[1],r=i[2];
            ll e=0,f=0;
            
            if(dist(a,b,0,0)<r*r) return 0;
            if(dist(a,b,X,Y)<r*r) return 0;
            if(dist(a,b,0,Y)<r*r) e=1;
            if(dist(a,b,X,0)<r*r) f=1;
            if(abs(Y-b)<=r && (a<=X && a>=0)) e=1;
            if(abs(X-a)<=r && (b<=Y && b>=0)) f=1;
            if(abs(b)<=r && (a<=X && a>=0)) f=1;
            if(abs(a)<=r && (b<=Y && b>=0)) e=1;
            if(e && f) return 0;
            vec.push_back({e,f});
        }
        DSU ds(n);
        for(auto &i:vec)
        {
            cout<<i.first<<" "<<i.second<<endl;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                ll q=circles[i][2]+circles[j][2];
                
                
                if(dist(circles[i][0],circles[i][1],circles[j][0],circles[j][1])<=q*q)
                ds.join(i,j,vec);

            }
        }
        for(auto &i:vec) 
        {
            if(i.first && i.second) return 0;
        }
        return 1;
        
        
    }
};


 