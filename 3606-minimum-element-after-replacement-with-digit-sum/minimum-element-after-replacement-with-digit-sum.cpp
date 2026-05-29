class Solution {
public:
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;

        for(int num:nums){
            mini=min(mini,digit_sum(num));
        }

        return mini;
    }
private:
    int digit_sum(int n){
        int sum=0;

        while(n>0){
            sum+=n%10;
            n=n/10;
        }

        return sum;
    }
};