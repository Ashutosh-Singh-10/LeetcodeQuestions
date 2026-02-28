class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int> count(n,0);
        for(auto &i:edges){
            if(i!=-1) count[i]++;
        }
        stack<int> st;
        for(int i=0;i<n;i++){
            if(count[i]==0) st.push(i);
        }
        while(st.size()){
            int x=st.top();
            st.pop();
            if(edges[x]==-1) continue;
            count[edges[x]]--;
            if(count[edges[x]]==0) st.push(edges[x]);
        }
        int ans=-1;
        unordered_set<int> vis;
        for(int i=0;i<n;i++){
            if(count[i]>=1 && vis.count(i)==0){
                int x=edges[i];
                set<int> st;
                while(st.count(x)==0){
                    vis.insert(x);
                    st.insert(x);
                    x=edges[x];
                }
                ans=max(ans,(int)st.size());
            }
        }
        return ans;
        
    }
};