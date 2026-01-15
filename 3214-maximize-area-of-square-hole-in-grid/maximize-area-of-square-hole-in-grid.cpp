class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int len=1+min(maxLen(hBars),maxLen(vBars));

        return len*len;
    }
private:
    int maxLen(vector<int>& bars){
        sort(bars.begin(),bars.end());
        int n=bars.size();
        int length=1;

        int max_Len=1;
        for(int i=1;i<n;i++){
            length=1+(-(bars[i-1]+1==bars[i]) & length);
            max_Len=max(max_Len,length);
        }

        return max_Len;
    }
};