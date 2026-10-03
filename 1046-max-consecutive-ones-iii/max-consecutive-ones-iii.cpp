class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int i = 0;
        int max_count = 0;
        int zeros = 0;

        for (int j = 0; j < n; j++) {

            if (nums[j] == 0)
                zeros++;

            while (zeros > k) {
                if (nums[i] == 0)
                    zeros--;

                i++;
            }

            max_count = max(max_count, j - i + 1);
        }

        return max_count;
    }
};