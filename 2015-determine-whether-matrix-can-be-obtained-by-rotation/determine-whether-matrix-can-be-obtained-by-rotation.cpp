class Solution {
public:
    void diagonalFlip(vector<vector<int>> &vec,int n){
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(vec[i][j],vec[j][i]);
            }
        }
    }
    void verticalFlip(vector<vector<int>> &vec,int n){
        for(int i=0;i<n/2;i++){
            for(int j=0;j<n;j++){
                swap(vec[i][j],vec[n-1-i][j]);
            }
        }
    }
    void rotate(vector<vector<int>> &vec,int n){
        verticalFlip(vec,n);
        // print(vec);
        diagonalFlip(vec,n);

    }
    bool equal(vector<vector<int>> &vec,vector<vector<int>> &target,int n){
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++){
                if(vec[i][j]!=target[i][j]) return 0;
            }
        }
        return 1;
    }
    void print(vector<vector<int>> &vec){
        for(auto &i:vec){
            for(auto &j:i) cout<<j<< " ";
            cout<<endl;
        }
        cout<<endl<<endl;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n=mat.size();
        for(int i=0;i<=3;i++){
            rotate(mat,n);
            if(equal(mat,target,n)) return 1;
            // print(mat);
        }
        return 0;
        
    }
};