class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        long long totalSum = 0;
        for (int num : nums) {
            int count = 0;
            int sum = 0;
            for (int i = 1; i * i <= num; ++i) {
                if (num % i == 0) {
                    int j = num / i;
                    if (i == j) {
                        count++;
                        sum += i;
                    } else {
                        count += 2;
                        sum += i + j;
                    }
                    if (count > 4) break;
                }
            }
            if (count == 4) {
                totalSum += sum;
            }
        }
        return (int)totalSum;
    }
};