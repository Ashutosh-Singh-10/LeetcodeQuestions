class Solution {
public:
    string compressedString(string word) {
        
        int i=0;
        string ans;
        int n=word.size();
        while(i<n)
        {
            char curr=word[i];
            int cnt=0;
            while(i<n && word[i]==curr && cnt<9)
            {
                cnt++;i++;
            }
            ans+=to_string(cnt);
            ans+=curr;
        }
        return ans;
    }
};