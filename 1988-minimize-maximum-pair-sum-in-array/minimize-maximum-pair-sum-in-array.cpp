class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n=nums.size();
        int maxSum=INT_MIN;

        sort(nums.begin(),nums.end());

        int i=0;
        int j=n-1;

        while(i<j){
            maxSum=max(maxSum,nums[i]+nums[j]);
            i++;
            j--;
        }

        return maxSum;
    }
};