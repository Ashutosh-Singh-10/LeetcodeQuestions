

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
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
		int cnt=1;;
		int n=nums.size();
		vector<int> vec;
		for(int i=1;i<n;i++)
		{
			if(nums[i]>nums[i-1])
			{
				cnt++;
			}
			else 
			{
				vec.push_back(cnt);
				cnt=1;
			}

		}
        vec.push_back(cnt);
		int ans=vec[0]/2;
		for(int i=1;i<vec.size();i++)
		{
			ans=max(ans,vec[i]/2);
			ans=max(ans,min(vec[i],vec[i-1]));
		}
		return ans>=k;
	
        
    }
};
