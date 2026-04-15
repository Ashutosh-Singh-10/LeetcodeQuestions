class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
    int idx=0,ans=1e9,n=words.size();
    for(int i=0;i<words.size();i++){
        if(words[i]==target){
        ans=min({ans,abs(i-startIndex),abs(i+n-startIndex),abs(i-n-startIndex)});
        }
    }
    return ans==1e9?-1:ans;
     
        
    }
};