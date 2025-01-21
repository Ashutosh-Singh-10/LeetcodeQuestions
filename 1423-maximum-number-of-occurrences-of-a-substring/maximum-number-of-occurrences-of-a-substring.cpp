class Solution {
public:
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
		// map to count frequencies.
        unordered_map<string, int> m;
		// keep a count of max frequency found.
        int max_freq = 0;
        
        for (int i = 0; i < s.size() - minSize + 1; i++) {
            string temp = s.substr(i,minSize);
			// make a set and compare size to check unique
			// characters in substrings < maxLetters.
            unordered_set<char> st(temp.begin(), temp.end());
            if (st.size() <= maxLetters) {
                m[temp]++;
                max_freq = max(max_freq, m[temp]);
            }
        }
      
        return max_freq;
    }
};