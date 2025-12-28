class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int count=0;
        for(int i=0;i<n;i++){
            int index=BS_Upper(grid[i],m);
            count+=(m-index);
        }

        return count;
    }
private:
    int BS_Upper(vector<int>& v, int n){
        int l=0,r=n;
        while(l<r){
            int mid=l+(r-l)/2;
            if(v[mid]<0){
                r=mid;
            }
            else l=mid+1;
        }
        return r;
    }
};