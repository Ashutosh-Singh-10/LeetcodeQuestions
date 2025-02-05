class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return 1;
        int n=s1.size();
        int i=0,j=n-1;
        while(i<n) 
        {
            if(s1[i]!=s2[i]) break;
            i++;
        }
        while(j>=0)
        {
            if(s1[j]!=s2[j]) break;
            j--;
        }
        if(j<i) return 1;
        swap(s1[i],s1[j]);
        return s1==s2;
        
    }
};