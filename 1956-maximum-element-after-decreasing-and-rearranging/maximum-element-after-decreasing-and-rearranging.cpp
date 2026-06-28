class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());

        int maxElem=1;
        if(nums[0]!=1) nums[0]=1;

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>1){
                nums[i]=maxElem+1;
                maxElem++;
            }
            else maxElem=nums[i];
        }

        return maxElem;
    }
};