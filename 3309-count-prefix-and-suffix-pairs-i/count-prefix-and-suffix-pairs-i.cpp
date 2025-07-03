class Solution {
public:
    int check(string &a,string &b)
    {
        if(a.size()>b.size() )return 0;
        
        for(int i=0;i<a.size();i++) if(a[i]!=b[i] || b[b.size()-i-1]!=a[a.size()-i-1]) return 0;
        return 1;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans=0,n=words.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++) 
            {
                ans+=check(words[i],words[j]);
            }
        }
        return ans;
        
    }
};