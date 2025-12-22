class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int n=strs[0].size(),m=strs.size();
        vector<set<int>> gr(n);
        for(auto &s:strs){
            for(int i=0;i<n;i++){
                for(int j=0;j<i;j++){
                    if(s[i]<s[j]){
                        gr[i].insert(j);
                    }

                }
            }
        }
        vector<int> vec(n,0) ;
        int ans=0;
        for(int i=0;i<n;i++){
            int mx=0;
            for(int j=0;j<i;j++){
                if(gr[i].count(j)==0){
                    mx=max(mx,vec[j]);
                }

            }
            vec[i]=mx+1;
            ans=max(vec[i],ans);
        }
        
        return n-ans;



        
    }
};