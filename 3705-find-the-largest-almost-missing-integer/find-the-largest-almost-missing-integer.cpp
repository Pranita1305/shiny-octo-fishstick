class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {  

        int n = nums.size();
        int max_elem = -1;


        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        if (k == 1) {
            unordered_map<int, int> freq_map;
            for (int num : nums) {
                freq_map[num]++;
            }
            for (auto& [num, freq] : freq_map) {
                if (freq == 1) {
                    max_elem = max(max_elem, num);
                }
            }
            return max_elem;
        }
        int count_first = 0;
        int count_last = 0;

        for (int num : nums) {
            if (num == nums[0]) {
                count_first++;
            }
            if (num == nums[n - 1]) {
                count_last++;
            }
        }

        if (count_first == 1) {
            max_elem = max(max_elem, nums[0]);
        }
        if (count_last == 1) {
            max_elem = max(max_elem, nums[n - 1]);
        }

        return max_elem;
        
    }
};
