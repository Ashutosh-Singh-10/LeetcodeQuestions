class Solution {
public:
    int findTheLongestSubstring(string s) {

        map<int,int> mp,index;
        mp[0]=-1;
        int mask=0;
        index['a']=0;
        index['i']=1;
        index['e']=2;
        index['o']=3;
        index['u']=4;
        int ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(index.count(s[i]))
            {
                mask=mask^(1<<index[s[i]]);
            }
            if(mp.count(mask))
            {
                ans=max(ans,i-mp[mask]);
            }
            else mp[mask]=i;
            
        }
        return ans;
        


    }
};