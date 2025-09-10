class Solution {
public:
    
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int p=languages.size();
        vector<set<int>> gr(p+1);
        for(int i=0;i<p;i++){
            for(auto &j:languages[i])
            gr[i+1].insert(j);
        }
        set<int> st;
        for(auto &i:friendships){
            int a=i[0],b=i[1];
            int flag=0;
            for(auto &j:gr[a]){
                if(gr[b].count(j)){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
             st.insert(a);
             st.insert(b);
            }
        }
        int ans=st.size();
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(auto &j:st){
                if(gr[j].count(i)==0)cnt++;
            }
            ans=min(ans,cnt);
        }
        return ans;

        
    }
};