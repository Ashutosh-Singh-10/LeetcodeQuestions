class Solution {
public:
    int minOperations(string s) {
        char ch='z'+1;
        for(auto &i:s) if(i!='a') ch=min(ch,i);
        return 26-(ch-'a');
        
    }
};