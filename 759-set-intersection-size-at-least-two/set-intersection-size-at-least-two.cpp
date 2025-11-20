    #include <bits/stdc++.h>
    using namespace std;
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
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        OrderSet<int> st;
        vector<pair<int,int>> vec;
        for(auto &i:intervals) vec.push_back({i[1],i[0]});
        sort(vec.begin(),vec.end());
        for(auto &i:vec){
            int order=st.order_of_key(i.second);
            int diff=st.size()-order;
            if(diff==0){
                st.insert(i.first);
                st.insert(i.first-1);
            }            
            if(diff==1){
                if(st.find(i.first)==st.end()){
                    st.insert(i.first);
                }
                else st.insert(i.first-1);
            }
        }
        return st.size();
    }
};