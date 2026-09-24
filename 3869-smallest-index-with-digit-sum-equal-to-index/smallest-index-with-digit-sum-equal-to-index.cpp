class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n;i++){
            int sum=0;
            
            while(nums[i]>0){
                sum+=nums[i]%10;
                nums[i]/=10;
            }

            if(i==sum) return i;
        }

        return -1;
    }

private:
    int sumDigits(int n){
        int sum=0;

        while(n>0){
            sum+=n%10;
            n/=10;
        }

        return sum;
    }
};