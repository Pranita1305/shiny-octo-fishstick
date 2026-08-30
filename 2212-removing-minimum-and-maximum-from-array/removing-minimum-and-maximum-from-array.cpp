#include <vector>
#include <algorithm>

class Solution {
public:
    int minimumDeletions(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) {
            return n; 
        }

        int max_index = 0;
        int min_index = 0;

        
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[max_index]) {
                max_index = i;
            }
            if (nums[i] < nums[min_index]) {
                min_index = i;
            }
        }
  
        int L = std::min(min_index, max_index);
        int R = std::max(min_index, max_index);
        
        int del_left = R + 1;
       
        int del_right = n - L;

        int del_both = (L + 1) + (n - R);

        
        return std::min({del_left, del_right, del_both});
    }
};