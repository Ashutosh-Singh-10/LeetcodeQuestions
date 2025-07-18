#include <bits/stdc++.h>
    using namespace std;
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
    long long minimumDifference(vector<int>& nums) {
        // reverse(nums.begin(),nums.end());
        ll sz=nums.size();
        ll n=sz/3;
        
        vector<ll> pr(sz,1e11);
        _pq<ll> pq;
        ll sm=0;
        for(int i=0;i<=n-1;i++)
        {
            pq.push(nums[i]);
            sm+=nums[i];
        }
        pr[n-1]=sm;
        
        for(int i=n;i<sz;i++)
        {
            pq.push(nums[i]);
            sm+=nums[i];
            sm-=pq.top();
            pq.pop();
            pr[i]=sm;
        }
        _pqr<ll> tp;
        sm=0;
        for(int i=sz-1;i>=sz-n;i--)
        {
            tp.push(nums[i]);
            sm+=nums[i];
        }
        ll ans=pr[sz-n-1]-sm;
        cout<<"last "<<sm<<endl;
       
        for(int i=sz-n-1;i>=n;i--)
        {
            tp.push(nums[i]);
            sm+=nums[i];
            sm-=tp.top();
            tp.pop();
            ans=min(ans,pr[i-1]-sm);
            cout<<sm<<" ";
        }
        cout<<endl;
        for(auto &i:pr) cout<<i<<" ";
        
        return ans;

        
        

        
    }
};