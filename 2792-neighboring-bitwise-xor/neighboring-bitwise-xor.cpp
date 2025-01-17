class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        bool bit=0;
        for(const auto &i:derived)
        {
            bit=bit^i;
        }
        return bit^1;
        
    }
};