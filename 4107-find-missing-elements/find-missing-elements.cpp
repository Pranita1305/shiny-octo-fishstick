class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<int> result;

        int start = nums[0];

        for(int i = 0; i < nums.size(); i++) {

            if(i > 0 && nums[i] == nums[i-1])
                continue;          

            while(start < nums[i]) {
                result.push_back(start);
                start++;
            }

            start = nums[i] + 1;
        }

        return result;
    }
};