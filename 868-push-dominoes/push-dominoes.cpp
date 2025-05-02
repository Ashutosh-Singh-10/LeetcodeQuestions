class Solution {
public:
    string pushDominoes(string d) {
        int start=-2,end;
        for(int i=0;i<d.size();i++)
        {
            if(d[i]=='R')
            {
                if(start>=0)
                {
                    while(start<i)
                    {
                        d[start]='R';
                        start++;
                    }
                }
                start=i;
            }
            else if(i && d[i]=='L')
            {
                if(d[i-1]!='L')
                {
                    end=i-1;
                    start++;
                    while(start<end)
                    {
                        if(d[end]=='.')
                        {
                            d[end]='L';
                        }
                        else break;
                        end--;
                        if(start>=0 )
                        {
                            d[start]='R';
                            start++;

                        }
                    }

                    start=-2;
                    
                }
            }

        }
        if(start>=0)
        {
            while(start<d.length())
            {
                d[start]='R';
                start++;
            }
        }
        return d;
        
    }
};