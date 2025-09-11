class Solution {
public:
    string sortVowels(string s) {
        unordered_set<char> st={'A','E','I','O','U','a','e','i','o','u'};
        vector<char> vec;
        vector<int> tec;
        for(int i=0;i<s.length();i++)
        {
            if(st.count(s[i]))
            {
                vec.push_back(s[i]);
                tec.push_back(i);
            }
        }
        sort(vec.begin(),vec.end());
        int idx=0;
        for(int i=0;i<tec.size();i++)
        {
           s[tec[i]]=vec[i];
        }




        return s;
        

        
        
    }
};