class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int count=0;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1){
                    if(check(mat,i,j)){
                        count++;
                    }
                }
            }
        }

        return count;
        
    }
private:
    bool check(vector<vector<int>>& mat, int r,int c){
        int count=0;
        for(int i=0;i<mat[0].size();i++){
            if(mat[r][i]==1) count++;
        }

        if(count>1) return false;

        count=0;
        for(int i=0;i<mat.size();i++){
            if(mat[i][c]==1) count++;
        }

        if(count>1) return false;

        return true;
    }
};