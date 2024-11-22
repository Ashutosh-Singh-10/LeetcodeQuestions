class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        string str1;
        vector<string> vec;
        bool bit=0;
        for(const auto &i:matrix)
        {
            str1="";
            if(i[0]==0) bit=1;
            else bit=0;

            for(const auto &j:i)
            {

                str1+=(j ^ bit)+'0';
            

            }
            vec.push_back(str1);
            
        }
 

        unordered_map<string,int> hashtable;
        int ans=0;
        for(const auto &i:vec)
        {
            hashtable[i]++;
            ans=max(ans,hashtable[i]);

        }
        return ans;

        
    }
};