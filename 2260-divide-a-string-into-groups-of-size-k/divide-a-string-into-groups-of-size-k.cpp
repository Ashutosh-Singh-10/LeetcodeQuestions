class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> vec={""};
        for(auto &i:s)
        {
            if(vec.back().size()>=k)
            {
                vec.push_back("");
            }
            vec.back().push_back(i);
        }
        while(vec.back().size()<k)
        {
            vec.back().push_back(fill);
        }
        return vec;
        
    }
};