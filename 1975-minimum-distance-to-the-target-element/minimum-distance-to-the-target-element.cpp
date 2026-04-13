class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minIndex=INT_MAX;
        int i=0;

        while(i<nums.size()){
            if(nums[i]==target){
                minIndex=min(minIndex,abs(i-start));
            }
            i++;
        }

        return minIndex;
    }
};