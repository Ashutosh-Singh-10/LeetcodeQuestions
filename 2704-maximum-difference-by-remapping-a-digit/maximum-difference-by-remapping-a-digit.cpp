class Solution {
public:
    int minMaxDifference(int num) {
        string a=to_string(num);
        string b=to_string(num);
        int ch=b[0];
        for(auto &i:b) if(i==ch) i='0';
        ch='9';
        for(auto &i:a) if(i!='9') 
        {
            ch=i;
            break;
        }
        for(auto &i:a) if(i==ch) i='9';
        return stoi(a)-stoi(b);
    }
};