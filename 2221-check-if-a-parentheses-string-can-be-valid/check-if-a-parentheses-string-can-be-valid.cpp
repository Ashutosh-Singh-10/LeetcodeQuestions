class Solution {
public:
    bool canBeValid(string s, string locked) {
        int l=0,cnt=0;
        if(s.size()%2) return 0;
        for(int i=0;i<s.length();i++)
        {
            if(locked[i]=='0')
            {
                if(l==0)
                {
                    l++;
                }
                else 
                {
                    l--;
                    cnt++;
                }
            }
            else if(s[i]=='(')
            {
                l++;

            }
            else if(s[i]==')')
            {
                l--;

            }
            if(l<0)
            {
                if(cnt>0)
                {
                    cnt--;
                    l+=2;
                }
                else return 0;

            }  

        }
        if(l)return 0;
        return 1;
    }
};