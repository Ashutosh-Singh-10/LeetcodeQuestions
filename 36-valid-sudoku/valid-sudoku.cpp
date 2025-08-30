class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> elements;
        for(auto &k:board)
        {
            
            for(auto &i:k)
            {
                if(i=='.') continue;
                if(elements.count(i)) return 0;
                elements.insert(i);
            }
            elements.clear();
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                if(board[j][i]=='.') continue;
                if(elements.count(board[j][i])) return 0;
                elements.insert(board[j][i]) ;
            }
            elements.clear();

        }
        
        for(int i=0;i<board.size();i+=3)
        {
            for(int j=0;j<board.size();j+=3)
            {
                for(int k=0;k<3;k++)
                {
                    for(int l=0;l<3;l++)
                    {
                        // cout<<i+k<<"  "<<j+l<<endl;
                        if(board[i+k][j+l]=='.') continue;
                        if(elements.count(board[i+k][j+l])) return 0;
                        elements.insert(board[i+k][j+l]);
                    }
                }
                elements.clear();
            }
        }



return 1;






    }
};