class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        int one=0;
        
        for(auto &i:arr) if(i==1) one++;
        if(one%3) return {-1,-1};
        if(one==0) return {0,2};
        int one2=0;
        int a,b,c;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]==1) 
            {
                one2++;
                if(one2==1) a=i;
                else if(one2-1==one/3) b=i;
                else if(one2-1==one/3*2)c=i;
            }
        }
        while(c!=arr.size())
        {
            if(arr[a]!=arr[b] || arr[a]!=arr[c]) return {-1,-1};
            a++;b++;c++;

        }
        return {a-1,b};
        
    }
};