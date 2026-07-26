class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<3) return -1;

        if(n==3) return nums[0]*nums[1]*nums[2];

        if(nums[0]<0){
            int min1=nums[0];
            int min2=nums[1];

            int max1=nums[n-3];
            int max2=nums[n-2];
            int max3=nums[n-1];

            int prod1=min1*min2*max3;
            int prod2=max1*max2*max3;

            if(prod1>prod2) return prod1;
            return prod2;
            
        }
        else{
            return nums[n-1]*nums[n-2]*nums[n-3];
        }
    }

};