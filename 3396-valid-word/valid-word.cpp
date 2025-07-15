    #include <bits/stdc++.h>
    using namespace std;
    using std::cout;
    using std::cin;
    #define endl '\n'    
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




class Solution {
public:
    bool isValid(string word) {
        set<int> st={'a','e','i','o','u','A','E','I','O','U'};
        set<int> bt;
        
        int v=0,c=0;
        int l=0,u=0,d=0;
        for(auto  &i:word)
        {
            if(st.count(i))
            {
                v=1;
            }
            else  if( isalpha(i))c=1;

            if(i>='0' && i<='9')
            {
                d=1;
            }
            else if(islower(i))
            {
                l=1;
            }
            else if(isupper(i)) u=1;
            else return 0;
        }
        if(v && c &&  ( l || u || d) && word.length()>=3)
        {
            return 1;
        }
        return 0;

        

        
    }
};











