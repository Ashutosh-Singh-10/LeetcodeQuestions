class Solution {
public:
    int maximum69Number (int num) {
        
        string str=to_string(num);
        for(int i=0;i<str.length();i++)
        {
            if(str[i]=='6')
            {
                str[i]='9';
                break;
            }
        }
        // cout<<str;
        int ans=0;
        for(auto &i:str)
        {
            ans*=10;
            if(i=='9') ans+=9;
            else ans+=6;
        }
        return ans;

    }
};