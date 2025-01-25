class Solution {
public:
    string originalDigits(string s) {
        unordered_map<char, int> m;
        for(char c : s) m[c]++;

        string ans;
        vector<pair<pair<char, char>, string>> v = {{{'z', '0'}, "zero"}, {{'w', '2'}, "two"}, {{'u', '4'}, "four"}, 
                                                    {{'x', '6'}, "six"}, {{'g', '8'}, "eight"}, {{'o', '1'}, "one"}, 
                                                    {{'t', '3'}, "three"}, {{'f', '5'}, "five"}, {{'s', '7'}, "seven"}, 
                                                    {{'i', '9'}, "nine"}};
        for(auto p : v) {
            int n = m[p.first.first];
            for(int i=0; i<n; i++) ans += p.first.second;
            for(char c : p.second) m[c] -= n;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
/*
Unique & Single Characters

one, two, three, four, five, six, seven, eight, nine
z - zero
w - two
u - four
x - six
g - eight

one, three, five, seven, nine
o - one
t - three
f - five
s - seven
i - nine
*/