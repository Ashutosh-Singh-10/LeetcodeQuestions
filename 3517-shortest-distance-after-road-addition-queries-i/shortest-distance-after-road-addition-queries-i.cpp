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
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dp(n+1,0);
        loop(i,1,n+1)
        {
            dp[i]=i;
        }
        vector<int> ans;
        vector<vector<int>> gr(n);
        for(auto &i:queries)
        {
            int x=i[0],y=i[1];
            dp[y]=min(dp[x]+1,dp[y]);
            for(int j=0;j<n;j++)
            {
                if(j!=0)
                dp[j]=min(dp[j-1]+1,dp[j]);
                for(auto &k:gr[j])
                {
                    dp[k]=min(dp[j]+1,dp[k]);

                }
            }
            ans.push_back(dp[n-1]);
            // for(int k=0;k<n;k++) cout<<dp[k];cout<<endl;
            gr[x].push_back(y);

        }
        return ans;
        
    }
};