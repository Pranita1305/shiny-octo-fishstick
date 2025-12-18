#include <vector>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        
        // Partition the elements into three groups
        for (int num : nums) {
            if (num < pivot)
                less.push_back(num);
            else if (num == pivot)
                equal.push_back(num);
            else
                greater.push_back(num);
        }
        
        // Concatenate the groups to form the result
        vector<int> result;
        result.reserve(nums.size());
        result.insert(result.end(), less.begin(), less.end());
        result.insert(result.end(), equal.begin(), equal.end());
        result.insert(result.end(), greater.begin(), greater.end());
        
        return result;
    }
};