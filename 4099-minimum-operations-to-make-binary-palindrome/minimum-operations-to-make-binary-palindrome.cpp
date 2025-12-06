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

bool is_palindrome(int n){
    string str,t;
    while(n){
        if(n%2) str.push_back('1');
        else str.push_back('0');
        n>>=1;
    }
    t=str;
    reverse(all(str));
    return t==str;
}
class Solution {
public:
    vector<int> minOperations(vector<int>& nums) {
        set<int> st;
        vector<int> ans;
        st.insert(0);
        loop(i,1,10001){
            if(is_palindrome(i)) st.insert(i);
        }
        for(auto &i:nums){
            auto it=st.upper_bound(i);
            int x=abs(i-(*it));
            it--;
             x=min(x,abs(i-(*it)));
             ans.push_back(x);
        }
        return ans;
        
        
    }
};