class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int pos=0;
        int n=nums.size();

        if(target>nums[n-1]) return n;

        int l=0;
        int h=n-1;

        while(l<=h){
            int m=l+(h-l)/2;

            if(nums[m]>=target){
                pos=m;
                h=m-1;
            }
            else if(nums[m]<target){
                l=m+1;
            }
        }

        return pos;
    }
};