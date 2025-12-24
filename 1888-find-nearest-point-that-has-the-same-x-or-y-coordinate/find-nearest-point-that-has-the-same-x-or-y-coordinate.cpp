class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int n=points.size();

        int min_dist=INT_MAX;
        int index=-1;
        for(int i=0;i<n;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            if(x1==x || y1==y){
                int distance=dist(x,x1,y,y1);
                // if(distance==min_dist){
                //     index=min
                // }
                if(distance<min_dist){
                    min_dist=distance;
                    index=i;
                }
            }
        }

        return index;
    }
private:
    int dist(int x1,int x2,int y1,int y2){
        return (abs(x1-x2)+abs(y1-y2));
    }
};