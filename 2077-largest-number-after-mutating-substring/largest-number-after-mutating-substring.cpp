#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::string maximumNumber(std::string num, std::vector<int>& change) {
        bool mutating = false;

        for (int i = 0; i < num.size(); i++) {
            int original_digit = num[i] - '0';
            int mutated_digit = change[original_digit];

            if (mutated_digit > original_digit) {
                num[i] = mutated_digit + '0';
                mutating = true;
            } else if (mutated_digit < original_digit) {
                if (mutating) {
                    break;
                }
            }
            
        }

        return num;
    }
};