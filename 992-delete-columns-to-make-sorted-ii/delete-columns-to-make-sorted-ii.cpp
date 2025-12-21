class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int mn=1e9,mx=0;
        for(auto &i:strs) {
            mn=min((int)i.length(),mn);
            mx=max((int)i.length(),mx);
        }
        vector<int> parity(strs.size(),0);
        int flag=0;
        int ans=mx-mn;
        for(int i=0;i<mn;i++){
            flag=1;
            for(int j=1;j<strs.size();j++){
                if(strs[j][i]<strs[j-1][i] && parity[j]==0){

                ans++;
                flag=0;
                break;

                } 
            }
            if(flag==1){
                for(int j=1;j<strs.size();j++){
                    if(strs[j][i]>strs[j-1][i]) parity[j]=1;
                }

            }
        }
        return ans;
    
        
    }
};