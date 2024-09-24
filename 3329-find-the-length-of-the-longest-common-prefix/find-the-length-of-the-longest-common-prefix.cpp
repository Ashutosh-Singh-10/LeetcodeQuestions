class Trie{
    public:
    Trie * child[10];
    bool isEnd;
    int cnt;
    Trie()
    {
        isEnd=0;
        cnt=0;
        for(int i=0;i<10;i++)
        {
            child[i]=NULL;
        }
    }
};



void insertion(Trie * root,string s,int index=0)
{
    if(index==s.length())
    {
        root->isEnd=true;   
        return ;
    }
    if(root->child[s[index]-'0']==NULL)
    {
        root->cnt++;
        root->child[s[index]-'0']=new Trie();
    }
    insertion(root->child[s[index]-'0'],s,index+1);
    return ;  
}
bool searchAword(Trie * root,string s,int &ans,int index=0)
{
    if(index==s.length())
    {
        if(root->isEnd) return 1;
        return 0 ;
    }
    if(root->child[s[index]-'0']==NULL)
    {
        return 0;
    }
    ans++;
    return searchAword(root->child[s[index]-'0'],s,ans,index+1);

}
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int ans=0;
        Trie *root=new Trie();
        for(auto &i:arr1)
        {
            insertion(root,to_string(i));
        }
        for(auto &i:arr2)
        {
            int k=0;
            searchAword(root,to_string(i),k);
            ans=max(ans,k);
            
        }
        return ans;
        
    }
};