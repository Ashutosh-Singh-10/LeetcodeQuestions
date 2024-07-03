template<class T> using _pqr = priority_queue<T, vector<T>, greater<T>>;
#define ll long long
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        set<ll> st;
        _pqr<ll> pq;
        pq.push(1);
        
        while(n)
        {
            auto i=pq.top();
            pq.pop();
            if(st.count(i))
            {continue;}
            n--;
            if(n==0) return i;
            st.insert(i);
            for(auto &pr:primes)
            {
                pq.push(pr*i);

            }
            // cout<<i<<"-->"<<n<<endl;
            
        }
        return pq.top();
        

        
    }
};