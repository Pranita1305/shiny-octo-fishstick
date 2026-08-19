class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> mp;

        for (auto &seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        int groups = (n - mp.size()) * 2;

        for (auto &[row, seats] : mp) {

            bool left = true;
            bool middle = true;
            bool right = true;

            // 2-5
            for (int col = 2; col <= 5; col++) {
                if (seats.count(col)) {
                    left = false;
                    break;
                }
            }

            // 4-7
            for (int col = 4; col <= 7; col++) {
                if (seats.count(col)) {
                    middle = false;
                    break;
                }
            }

            // 6-9
            for (int col = 6; col <= 9; col++) {
                if (seats.count(col)) {
                    right = false;
                    break;
                }
            }

            if (left && right)
                groups += 2;
            else if (left || middle || right)
                groups += 1;
        }

        return groups;
    }
};