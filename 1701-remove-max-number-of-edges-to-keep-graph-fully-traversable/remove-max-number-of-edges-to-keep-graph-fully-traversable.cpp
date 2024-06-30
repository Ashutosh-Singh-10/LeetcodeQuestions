
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

 

    class DSU{public:
        long long size=0;  vector<long long> vec;
        ll comp=0;
        DSU(long long n)
        {
            size=n;
            comp=n;
            for(long long i=0;i<n;i++)        vec.push_back(i);
        }
        void join(long long x,long long y){
            vector<long long> a,b;
            while(vec[x]!=x)
            {
                a.push_back(x);
                x=vec[x];
            }
            while(vec[y]!=y)
            {
                b.push_back(y);
                y=vec[y];
            }
            for(auto &i:a)    vec[i]=y;
            for(auto &i:b)    vec[i]=y;
            vec[x]=y;
            comp--;
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
    ll fun(vector<vector<int>>& edges,DSU ds,ll &x)
    {
          for(auto &i:edges)
            {
                auto a=i[0];
                auto b=i[1];
                if(ds.parent(b)!=ds.parent(a))
                ds.join(a,b);
                else x++;
            }
            if(ds.comp>1) return -1;
            return 0;
    }

    class Solution {
    public:
        int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
            vector<vector<int>> alice,bob;
            DSU ds(n);
            ll x=0;
            for(auto &i:edges)
            {
                auto a=i[0];
                auto b=i[1];
                auto c=i[2];
                b--;c--;
                if(a==3)
                {
                    if(ds.parent(b)!=ds.parent(c))
                    ds.join(c,b);
                    else x++;
                    
                }
                else if(a==1) 
                {
                    alice.push_back({b,c});
                }
                else 
                {
                    bob.push_back({b,c});
                }
            }
            if(fun(alice,ds,x)==-1 || fun(bob,ds,x)==-1) return -1;
            
            return x;
        }
    };































 