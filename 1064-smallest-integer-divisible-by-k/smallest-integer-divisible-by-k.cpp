class Solution {
public:
    int smallestRepunitDivByK(int k) {
        set<int> st;
        int start=1,cnt=1;
        while(1){
            int rem=start%k;
            if(rem==0) return cnt;
            if(st.count(rem)) break;
            st.insert(rem);
            cnt++;
            start=(rem*10+1)%k;

        }
        return -1;


        
    }
};