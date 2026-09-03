#include <vector>
#include <algorithm>

class Solution {
public:
    bool uniformArray(std::vector<int>& nums1) {
        bool has_odd = false;
        int min_val = nums1[0];

        for (int num : nums1) {
            if (num % 2 != 0) {
                has_odd = true;
            }
            if (num < min_val) {
                min_val = num;
            }
        }

        
        if (!has_odd) {
            return true;
        }

        return (min_val % 2 != 0);
    }
};