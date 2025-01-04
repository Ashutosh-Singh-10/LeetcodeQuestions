class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>> vec(26,{-1,-1});
        vector<int> count(26,0);
        for(int i=0;i<s.length();i++)
        {
            count[s[i]-'a']=1;
            if(vec[s[i]-'a'].first==-1)
            {
                vec[s[i]-'a'].first=i;
            }
            else 
            vec[s[i]-'a'].second=i;
        }
        int mxu=0;
        for(auto &i:count) mxu+=i;
        vector<unordered_set<int>> ans(26);
        int fi=0;
        for(int i=1;i<s.length()-1;i++)
        {
                if(ans[s[i]-'a'].size()==mxu) continue;
            for(int k=0;k<vec.size();k++)
            {
                auto j=vec[k];
                if(i>j.first && i<j.second )
                {
                    ans[s[i]-'a'].insert(k);
                }
            }
        }
     
        for(auto &i:ans)
        {
            fi+=i.size();
        }
        return fi;


   
        
    }
};