

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
 
int   dfs(vector<vector<int>> & gr,vector<int> & ans,int cur,int prev,int ch,string &s)

 {
        ll cnt=0;
      
        for(auto &i:gr[cur])
        {
            if(i!=prev)
            {
                cnt+=dfs(gr,ans,i,cur,ch,s);
            }
        }
        if(s[cur]==ch)
        {
            cnt++;
            ans[cur]=cnt;

        }
        return cnt;
    
 }
 class Solution {
public:
 vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {

        vector<vector<int>> gr(n);
        for(auto &i:edges)
        {
            gr[i[0]].push_back(i[1]);
            gr[i[1]].push_back(i[0]);
        }
        vector<int> ans(n);
        for(int i='a';i<='z';i++)
        {
            dfs(gr,ans,0,-1,i,labels);
        }
        return ans;
        
        
      

        
    }
};

