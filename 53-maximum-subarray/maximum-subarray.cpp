class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;

        int curr_max=0;
        int max=INT_MIN;

        for(int num:nums){
            curr_max+=num;
            if(curr_max>max) max=curr_max;
            if(curr_max<0) curr_max=0;
        }

        return max;
    }
};