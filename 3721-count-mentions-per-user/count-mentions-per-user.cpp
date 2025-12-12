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
	int mod=1e9+7;
class Solution {
public:
    vector<int> countMentions(int n, vector<vector<string>>& events) {

		vector<pair<int,vector<string>>> vec;
		for(auto &i:events)
		{
            if(i[0]=="OFFLINE")
            {
			vec.push_back({stoi(i[1]),{"A",i[2]}});
                
            }
            else			vec.push_back({stoi(i[1]),{i[0],i[2]}});
		}
		So(vec);
		_pqr<pair<int,int>> pq;
		set<int> online;
		vector<int> cnt(n);
		for(int i=0;i<n;i++) online.insert(i);
		for(auto i:vec)
		{
            while(pq.size() && pq.top().first<=i.first)
                {
                    online.insert(pq.top().second);
                    pq.pop();
                }

			if(i.second[0]=="A")
			{
                int x=stoi(i.second[1]);
                pq.push({ i.first + 60, x });
				online.erase(x);
			}
			else 
			{
				if(i.second[1]=="ALL")
				{
					for(int j=0;j<n;j++) cnt[j]++;
				}
				else if(i.second[1]=="HERE")
				{
					for(auto &j:online) cnt[j]++;
				}
				else 
				{
					string str=i.second[1];
					str.push_back(' ');
                    string s;
                    for(auto &i:str)
                        {
                            if(i==' ')
                            {
                                string t=s.substr(2);
                                cnt[stoi(t)]++;
                                s="";
                            }
                            else s.push_back(i);
                        }
                  

				}

			}
		}
		return cnt;
        
    }
};