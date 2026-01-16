class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (int asteroid : asteroids) {
            bool destroyed = false;
            while (!result.empty() && asteroid < 0 && result.back() > 0) {
                if (result.back() < -asteroid) {
                    result.pop_back();
                    continue;
                } else if (result.back() == -asteroid) {
                    result.pop_back();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) {
                result.push_back(asteroid);
            }
        }
        return result;
    }
};