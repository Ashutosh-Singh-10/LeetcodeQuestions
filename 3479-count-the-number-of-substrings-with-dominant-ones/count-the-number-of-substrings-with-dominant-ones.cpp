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
    int numberOfSubstrings(string s) {
        set<ll> st;
        ll n=s.length();
        ll onn=count(all(s),'1');
        // cout<<onn<<"  "<<s.length()-onn<<endl;
        // return 0;

        loop(i,0,n) if(s[i]=='0') st.insert(i);
        ll ans=0;
        loop(i,0,n)
        {
            ll cnt=0;
            ll bit=0;
            ll last=i;
            if(s[i]=='1') 
            {
                bit=1;
                ans++;
            }
            else 
            {
                bit=0; cnt=1;
            }

            while(1)
            {
                auto it=st.upper_bound(last);

                if(it==st.end())
                {

                    ll idx=n;
                    if(bit==1)
                    {
                        ans+=n-last-1;
                        // cout<<"NO";
                    }
                    else if(cnt*cnt+i+cnt<=idx+1)
                    {
                        ans+=idx+1-cnt*cnt-i-cnt;
                    }
                    
                    // cout<<ans<<"->"<<cnt<<"   ";
                    break;
                }
                else 
                {
                    ll idx=*it;
                    if(bit==1)
                    {
                        ans+=idx-last-1;
                    }
                    else if(cnt*cnt+cnt+i<=idx+1)
                    {
                        // cout<<"dd";
                        ans+=idx-cnt*cnt-i-cnt+1;

                    }
                    cnt++;
                    if(cnt*cnt+i+cnt<=idx+1)
                    {
                        // cout<<" ["<<cnt<<" "<<i<<" "<<idx<<"] "; 
                        ans++;
                        bit=1;
                    }
                    else bit=0;
                    last=idx;
                }
                // cout<<ans<<"->"<<cnt<<"->"<<last<<"   ";
                if(cnt*cnt+cnt>n) break;

            }
                // cout<<endl;

        }
        return ans;


        
    }
};