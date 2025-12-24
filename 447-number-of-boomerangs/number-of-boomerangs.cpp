class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int count=0;

        for(int i=0;i<n;i++){
            unordered_map<double,int> distances;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                double dist=distance(points[i][0],points[j][0],points[i][1],points[j][1]);
                distances[dist]++;
            }
            for(const auto& k:distances){
                int freq=k.second;
                if(freq) count+=freq*(freq-1);
            }
        }

        return count;
    }
private:
    double distance(int x1,int x2,int y1,int y2){
        return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
    }
};