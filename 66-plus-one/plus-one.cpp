class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        for(auto i=digits.rbegin();i!=digits.rend();i++)
        {

            if(*i==9)
            {
                *i=0;
            }
            else {
                *i+=1;
                return digits;
            }
        }
        digits.emplace(digits.begin(),1);
        return digits;

    }
};