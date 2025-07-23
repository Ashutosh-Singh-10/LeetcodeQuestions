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
class Solution {
public:
    ll pop_count(ll x)
    {
        if(x==1) return 0;
        int next=0;       
        while(x)
        {
            next+=x&1;
            x>>=1;
        }
        return 1+pop_count(next);
    }
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        vector<OrderSet<ll>> vec(7);
        ll n=nums.size();
        ll q=queries.size();
        for(ll i=0;i<n;i++)
        {
            vec[pop_count(nums[i])].insert(i);
        }
        
        vector<int> ans;
        for(auto &i:queries)
        {
            if(i[0]==1)
            {
                ll l=i[1],r=i[2],k=i[3];
                ans.push_back(vec[k].order_of_key(r+1)-vec[k].order_of_key(l));

            }
            else 
            {
                ll idx=i[1],el=i[2];
                ll tmp=nums[idx];
                vec[pop_count(tmp)].erase(idx);
                nums[idx]=el;
                vec[pop_count(el)].insert(idx);

            }
        }
        // for(auto &i:nums) cout<<i<<" ";cout<<endl;
        // for(int i=0;i<7;i++)
        // {   
        //     cout<<i<< "-->";
        //     for(auto &j:vec[i])
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        return ans;
        
    }
};