class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long Mass=mass;

        for(long long m:asteroids){
            if(m>Mass) return false;
            Mass+=m;
        }

        return true;
    }
};