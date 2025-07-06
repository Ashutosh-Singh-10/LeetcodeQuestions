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

	class DSU{
    public: 
    vector<long long> par,rank;
    long long components=0;
    long long sz=0;
    DSU(long long n)
    {
        sz=n;
        components=n;   
        par.resize(n+1);
        rank.resize(n+1,0);
        for(long long i=1;i<=n;i++) par[i]=i;
    }
    long long clusters()
    {
        return components;

    }
    long long parent(long long x)
    {
        if(par[x]!=x) 
        {
            par[x]=parent(par[x]);
        }
        return par[x];
    }
    void join(long long x,long long y)
    {
        long long a=parent(x),b=parent(y);
        if(a==b) 
        {
            return; 
        }
        components--;
        if(rank[a]>rank[b])
        {
            par[b]=a;

        }
        else if(rank[a]<rank[b])
        {
            par[a]=b;

        }
        else 
        {
            par[a]=b;
            rank[b]++;
        }
    }
    void printClusters()
    {
        map<long long,vector<long long>> mp;
        for(int i=1;i<=sz;i++) mp[par[i]].push_back(i);
        for(auto &[a,b]:mp)
        {
            cout<<a<<" | ";
            for(auto &i:b)
            {
                cout<<i<<" ";
            }
            cout<<endl;
        }

    }
};
	
class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, int k) {
		DSU ds(n);
		vector<pair<int,pair<int,int>> > vec;
		for(auto &i:edges)
		{
			vec.push_back({i[2],{i[0]+1,i[1]+1}});
		}
		Sore(vec);
		for(auto &i:vec)
		{
			ds.join(i.second.first,i.second.second);
            
			if(ds.components<k) return i.first;
            
		}
		
        
        return 0;
    }
};