class Solution {
public:
    bool isCircularSentence(string sentence) {
        for(int i=0;i<sentence.length();i++)
        {
            if(sentence[i]==' ')
            {
                if(sentence[i-1]!=sentence[i+1]) return 0;
            }

        }
        return sentence[0]==sentence.back();
    }
};