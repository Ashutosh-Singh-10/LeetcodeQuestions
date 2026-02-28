class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        return (str1+str2)==(str2+str1)?(str1.length()>str2.length()?str1:str2).substr(0,__gcd(str1.length(),str2.length())):"";
        
    }
};