class Solution {
public:
    char kthCharacter(int k) {
        string word="a";
        while(word.size()<k)
        {
            int x=word.size();
            for(int i=0;i<x;i++)
            {
                if(word[i]=='z') 
                {
                    word.push_back('a');
                }
                else word.push_back(word[i]+1);

            }
        }
        return word[k-1];
        
    }
};