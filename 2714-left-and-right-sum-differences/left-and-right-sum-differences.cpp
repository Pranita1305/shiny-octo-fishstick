class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum=nums[0];
        int n=nums.size();

        vector<int> leftIndex(n,0),rightIndex(n,0),result(n,0);

        for(int i=1;i<nums.size();i++){
            leftIndex[i]=sum;
            sum+=nums[i];
        }

        sum=nums[n-1];

        for(int i=n-2;i>=0;i--){
            rightIndex[i]=sum;
            sum+=nums[i];
        }

        for(int i=0;i<n;i++){
            result[i]=abs(leftIndex[i]-rightIndex[i]);
        }

        return result;
    }
};